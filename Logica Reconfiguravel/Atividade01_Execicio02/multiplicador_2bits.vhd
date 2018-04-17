library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mlt_2bits is
	port( a, b: in std_logic_vector(1 downto 0);
				y: out std_logic_vector(3 downto 0));
end mlt_2bits;

architecture arq of mlt_2bits is
	signal sa, sb, sy: integer;
begin
	y <= std_logic_vector(to_unsigned(to_integer(unsigned(a)) * to_integer(unsigned(b)),4));
end arq;