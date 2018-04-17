library ieee;
use ieee.std_logic_1164.all;

entity and2bit is 
	port (a, b: in std_logic;
				y: out std_logic);
end and2bit;

architecture arq of and2bit is
begin
	y <= a and b;
end arq;