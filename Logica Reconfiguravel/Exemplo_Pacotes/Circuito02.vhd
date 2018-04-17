library ieee;
use ieee.std_logic_1164.all;

entity ccto_2 is 
	port( d, e:  in std_logic;
				z: out std_logic);
end ccto_2;

architecture arq of ccto_2 is
signal s1: std_logic;
begin
	 z <= s1 and e;
	s1 <= not(d xor e);
end arq;