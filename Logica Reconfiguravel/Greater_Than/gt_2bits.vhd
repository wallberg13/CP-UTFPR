library ieee;
use ieee.std_logic_1164.all;

entity greater_2bits is
	port( a, b: in std_logic_vector(1 downto 0); -- Vetor de 4 posicoes indicando que a(1) é o mais significativo
				y: out std_logic);
end greater_2bits;

architecture arq of greater_2bits is
	signal s0, s1, s2: std_logic;
begin
	s2 <= a(1) and not(b(1));
	s0 <= a(0) and not(b(1)) and not(b(0));
	s1 <= a(1) and     a(0)  and not(b(0));
	y  <= s0 or s1 or s2;
end arq;