library ieee;
use ieee.std_logic_1164.all;

entity cmp_sem_sinal is
	port( a, b: in std_logic;
				x: out std_logic);
end cmp_sem_sinal;

architecture arq of cmp_sem_sinal is
begin
	x <= (not(a) and not(b)) or (a and b);
end arq;