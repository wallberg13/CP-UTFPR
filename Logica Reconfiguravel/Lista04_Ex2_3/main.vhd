library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

use work.my_pack.all;

entity top is
	port( mclk:  in std_logic;
			disp: out std_logic_vector(0 to 7);
		  sel_d: out std_logic_vector(3 downto 0));
end top;

architecture arq of top is
	-- Sinais referentes ao display
	signal sel: std_logic := '1';
	signal n_disp: std_logic_vector(1 downto 0) := "00";
	signal num: std_logic_vector(3 downto 0) := "0000";
	
	-- Sinais referentes ao Clock gerado.
	signal clk: std_logic;
	signal freq: integer := 1;
begin

	-- Disp_7seg.
	map_disp: entity work.disp_7seg(arq)
				 port map(num, sel, n_disp, sel_d, disp);
				 
	-- Clk_Generate
	map_clk: entity work.clk_generate(arq)
				generic map (1000) port map(mclk, clk);
	
	
	process(clk)
	begin
		if(clk'event and clk = '1') then
			n_disp <= std_logic_vector(unsigned(n_disp) + 1);
		end if;
	end process;

end arq;