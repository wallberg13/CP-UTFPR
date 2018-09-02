library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.my_pack.all;

-- Serve como o Ex3_2 e Ex3_3: Pois o mesmo codigo e flexivel para operar em 1 Hz ou em 3 Hz.

entity disp_1hz is
	generic(freq: integer := 3);
	port(	 mclk:  in std_logic;
			sel_d: out std_logic_vector(3 downto 0);
			 disp: out std_logic_vector(0 to 7));
end disp_1hz;

architecture arq of disp_1hz is
	-- Sinais do Display
	signal n_d : std_logic_vector(1 downto 0) := "00"; -- Vai permitir a escrita somente no display que e preciso
	signal num : std_logic_vector(3 downto 0); -- Inicial
	signal sel : std_logic := '1'; -- Operar em hexadecimal.
	-- Sinais do Clk_Generate
	signal clk: std_logic;
	-- Demais sinais
	signal cont: std_logic_vector(3 downto 0) := "0000";
begin

	map_disp: entity work.disp_7seg(arq)
				 port map(num, sel, n_d, sel_d, disp);
	
	map_clk:  entity work.clk_generate(arq)
				 generic map (freq) port map(mclk, clk);
				 
   process(clk)
	begin
		if(clk'event and clk = '1') then
			cont <= std_logic_vector(unsigned(cont) + 1);
		end if;
	end process;
	
	num <= cont;
end arq;