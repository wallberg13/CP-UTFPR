library ieee;
use ieee.std_logic_1164.all;

entity cmp_com_sinal is
	port( a, b: in std_logic;
				x: out std_logic);
end cmp_com_sinal;

architecture arq of cmp_com_sinal is
	signal s0, s1: std_logic;
begin
	 x <= s0 or s1;
	s0 <= not(a) and not(b);
	s1 <= a and b;
end arq;