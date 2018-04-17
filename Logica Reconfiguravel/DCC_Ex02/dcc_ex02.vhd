library ieee;
use ieee.std_logic_1164.all;

entity ccto is
	port( a:  in std_logic_vector(3 downto 0);
			y: out std_logic_vector(2 downto 0));
end ccto;

architecture arq of ccto is
begin
	with a select
		y <= "100" when "1000" | "1001" | "1010" |
							 "1011" | "1100" | "1101" |
							 "1110" | "1111",
			  "011" when "0100" | "0101" | "0110" |
							 "0111",
			  "010" when "0010" | "0011",
			  "001" when "0001",
			  "000" when others;
end arq;