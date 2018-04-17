library ieee;
use ieee.std_logic_1164.all;

entity ccto_1 is
	port( a, b, c:  in std_logic;
					y: out std_logic);
end ccto_1;

architecture arq of ccto_1 is
signal s0: std_logic;
begin
	 y <= c or s0;
	s0 <= a and b;
end ccto_1;