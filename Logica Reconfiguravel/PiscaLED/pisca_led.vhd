library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
--- PISCANDO LED A ALGUNS HERTZ
entity pisca_led is
	port( clk :  in std_logic;
			led : out std_logic_vector(3 downto 0));
end pisca_led;

architecture arq of pisca_led is
	signal count: integer := 0;
	signal led_aux: std_logic_vector (3 downto 0) := (others => '0');
	--signal aux: std_logic_vector(3 downto 0) := (others => '0');
begin

	process (clk)
	begin
		if(clk'event and clk = '1') then
			if(count = 50000000) then
				count <= 0;
				led_aux <= std_logic_vector(unsigned(led_aux) + 1);
				if(unsigned(led_aux) = 16) then
					led_aux <= (others => '0');
				end if;
			else
				count <= count + 1;
			end if;
		end if;
	end process;
	led <= led_aux;
	
end arq;
