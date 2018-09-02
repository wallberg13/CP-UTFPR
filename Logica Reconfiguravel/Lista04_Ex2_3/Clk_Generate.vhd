library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

--------------------------------------------------------
-- freq: Frequencia desejada do clock em Hz
-- mclk: Clock oriundo da fonte de clock da Basys.
-- clk: Clock de saida na frequecia desejada na entrada.

--------------------------------------------------------

entity clk_generate is 
	generic( freq: integer := 1);
	port(	mclk:		 in std_logic;
			 clk: buffer std_logic);
end clk_generate;

architecture arq of clk_generate is
	signal count: integer := 0;
	signal lim: integer := integer(25000000/freq);
	signal aux: std_logic := '0';
begin
	process(mclk)
	begin
		if(mclk'event and mclk = '1') then
			count <= count + 1;
			if(count = lim) then
				aux <= aux xor '1';
				count <= 0;
			end if;
		end if;
	end process;
	clk <= aux;
end arq;