library ieee;
use ieee.std_logic_1164.all;

entity comparador is
	port(a, b: in std_logic;
			  y: out std_logic);
end comparador;

architecture arq_comp of comparador is
begin
	y <= (not(a) and not(b)) or (a and b);
end arq_comp;