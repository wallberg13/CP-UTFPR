library ieee;
use ieee.std_logic_1164.all;

entity gt_th_2bit is
	port( a1, a0, b1, b0: in std_logic;
							 x: out std_logic);
end;

architecture arq of gt_th_2bit is
begin	
	x <= (a0 and not(b1) and not(b0)) or (a1 and a0 and not(b0)) or (a1 and not(b1));
end arq;