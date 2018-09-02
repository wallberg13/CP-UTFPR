library IEEE;
use ieee.std_logic_1164.all;

entity ccto_sem_sinal is
	port( a, b, c: in std_logic;
					x: out std_logic);
end;

architecture arq of ccto_sem_sinal is
begin
	x <= not(not(a) or not(b)) and b and c;
end arq;