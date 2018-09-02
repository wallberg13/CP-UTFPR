library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity cont_4bits is 
	port( clk:  in std_logic;
			led: out std_logic_vector(4 downto 0));
end cont_4bits;

architecture arq of cont_4bits is
	signal cont: std_logic_vector(26 downto 0) := (others => '0');
	signal aux: std_logic_vector(4 downto 0) := (others => '0');
begin
	process(clk)
	begin
		if(clk'event and clk = '1') then
			cont <= std_logic_vector(unsigned(cont) + 1);
			if(cont(26) = '1') then
				cont <= (others => '0');
				aux <= std_logic_vector(unsigned(aux) + 1);
				if(unsigned(aux) = 2**4 - 1)then
					aux <= (others => '0');
				end if;
			end if;
		end if;
	end process;
	led <= aux;
end arq;