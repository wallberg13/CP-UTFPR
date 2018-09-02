library ieee;
use ieee.std_logic_1164.all;

entity cmp_xnor is
	port( a, b: in std_logic;
				x: out std_logic);
end cmp_xnor;

architecture arq of cmp_xnor is
begin
	 x <= a xnor b;
end arq;