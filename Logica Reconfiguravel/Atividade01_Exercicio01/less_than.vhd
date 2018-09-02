library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity LT_2bits is
	port(	a, b: in std_logic_vector(1 downto 0);
				y: out std_logic);
end LT_2bits;

architecture arq of LT_2bits is
begin
	y <= '1' when (a < b) else
		  '0';
end arq;