library ieee;
use ieee.std_logic_1164.all;

entity ccto is
	port( a:  in std_logic_vector(3 downto 0);
			y: out std_logic_vector(2 downto 0));
end ccto;

architecture arq of ccto is
begin
	y <= "100" when (a(3) = '1') else
	     "011" when (a(2) = '1') else
		  "010" when (a(1) = '1') else
		  "001" when (a(0) = '1') else
		  "000";
end arq;