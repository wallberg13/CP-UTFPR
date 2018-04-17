library ieee;
use ieee.std_logic_1164.all;

entity ccto is
	port( a:  in std_logic_vector(1 downto 0);
		  en:  in std_logic;
			y: out std_logic_vector(3 downto 0));
end ccto;

architecture arq of ccto is
	signal x: std_logic_vector(3 downto 0);
begin
	with a select
		x <= "0001" when "00",
			  "0010" when "01",
			  "0100" when "10",
			  "1000" when "11",
			  "0000" when others;
	with en select
		y <=    x   when '1',
			  "0000" when others;
end arq;