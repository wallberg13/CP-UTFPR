library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BCD_7SEG is
	port(  num:  in std_logic_vector(3 downto 0);	
			 sel:  in integer range 0 to 3;
			disp: out std_logic_vector(0 to 7));
end BCD_7SEG;

