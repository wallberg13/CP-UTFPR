--
-- Pratica da Aula 04 - Exemplo 01
--

library ieee;
use ieee.std_logic_1164.all;

entity and_3_in is
	port(a,b,c: in std_logic;
				y: out std_logic);
end and_3_in;

architecture arq of and_3_in is
begin
	y <= a and b and c;
end arq;
