library ieee;
use ieee.std_logic_1164.all;

entity ccto is
	port( a, b:  in std_logic_vector(3 downto 0);
				y: out std_logic);
end ccto;

architecture arq of ccto is
begin
	y <= '1' when a > b else
		  '0';
end arq;