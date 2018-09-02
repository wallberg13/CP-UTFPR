library ieee;
use ieee.std_logic_1164.all;

entity circ_com_sinal is
	port( a, b, c: in std_logic;
	            x: out std_logic);
end circ_com_sinal;

architecture arq of circ_com_sinal is
	signal s0, s1, s2, s3: std_logic;
begin
	s0 <= not(a);
	s1 <= not(b);
	s2 <= s0 or s1;
	s3 <= not(s2);
	x <= s3 and b and c; 
end arq;