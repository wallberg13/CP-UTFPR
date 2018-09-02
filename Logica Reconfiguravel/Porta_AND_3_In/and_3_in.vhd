library IEEE;
use IEEE.std_logic_1164.all;

entity porta_and is
	port(a, b, c: in std_logic;
				  x: out std_logic);
end porta_and;
  
architecture arq of porta_and is
begin
	x <= a and b and c;
end arq;
