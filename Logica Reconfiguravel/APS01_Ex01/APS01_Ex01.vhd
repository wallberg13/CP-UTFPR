library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity som_sub_2bit is
	port( b,a:  in std_logic_vector(1 downto 0);
			  x: out std_logic_vector(2 downto 0));
end som_sub_2bit;

architecture arq of som_sub_2bit is
	signal sa,sb: std_logic_vector(2 downto 0);
begin
	sa <= '0' & a;
	sb <= '0' & b;
	x <= std_logic_vector(signed(sb) - signed(sa));
end arq;