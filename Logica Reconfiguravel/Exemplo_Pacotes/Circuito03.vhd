library ieee;
use ieee.std_logic_1164.all;

entity ccto_3 is
	port( f, g:  in std_logic;
				w: out std_logic);
end ccto_3;

architecture arq of ccto_3 is
begin
	w <= f xor g;
end ccto_3;