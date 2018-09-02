library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.my_pack.all;

entity top is
	generic(freq : integer := 1000);
	port(	 mclk:  in std_logic;
			 disp: out std_logic_vector(0 to 7);
			sel_d: out std_logic_vector(3 downto 0));
end top;

architecture arq of top is
	TYPE matriz is array (0 to 3) of std_logic_vector(3 downto 0);
	-- Sinais referentes ao Display
	signal num: std_logic_vector(3 downto 0);
	signal sel: std_logic := '1';
	signal n_d: std_logic_vector(1 downto 0) := "00"; 
	-- Sinais referentes ao Clk_generate
	signal clk: std_logic;
	
	-- Sinais arbitrarios
	signal mtz: matriz;
begin
	mtz(0) <= "0010";
	mtz(1) <= "1010";
	mtz(2) <= "0100";
	mtz(3) <= "1100";
	
	-- Display 7 seg
	map_disp: entity work.disp_7seg(arq)
				 port map(num, sel, n_d, sel_d, disp);
	
	map_clk: entity work.clk_generate(arq)
				generic map (freq) port map(mclk,clk);
	
	process(clk)
	begin
		if(clk'event and clk = '1') then
			n_d <= std_logic_vector(unsigned(n_d) + 1);
		end if;
	end process;
	
	num <= mtz(to_integer(unsigned(n_d)));
	
end arq;