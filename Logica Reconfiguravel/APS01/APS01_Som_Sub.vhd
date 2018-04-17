library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity som_sub_2bit is
	port( b,a:  in std_logic_vector(1 downto 0);
			swt:  in std_logic;
			  x: out std_logic_vector(2 downto 0);
			 sd: out std_logic_vector(0 to 3);
		  disp: out std_logic_vector(0 to 7));
end som_sub_2bit;

architecture arq of som_sub_2bit is
	signal sa,sb,sx: std_logic_vector(2 downto 0);
begin
	sa <= '0' & a;
	sb <= '0' & b;
	sx <= std_logic_vector(unsigned(sb) + unsigned(sa)) when (swt = '1') else
		  std_logic_vector(signed(sb) - signed(sa)) when (swt = '0');
	sd <= "1110";
	x <= sx;
	disp <= "00001100" when (signed(sx) = -3 and swt = '0') else
			  "00100100" when (signed(sx) = -2 and swt = '0') else
			  "10011110" when (signed(sx) = -1 and swt = '0') else
			  "00000011" when (unsigned(sx) = 0) else
			  "10011111" when (unsigned(sx) = 1) else
			  "00100101" when (unsigned(sx) = 2) else
			  "00001101" when (unsigned(sx) = 3) else
			  "10011001" when (unsigned(sx) = 4 and swt = '1') else
			  "01001001" when (unsigned(sx) = 5 and swt = '1') else
			  "11000001" when (unsigned(sx) = 6 and swt = '1');
end arq;