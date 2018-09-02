library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

----------------------------------------------------------------
-- num: Entrada de um numero entre 0 e F (ou 0 a 9).
-- sel: Modo de operacao.
	-- 0 : BCD
	-- 1 : HEX
-- n_dis: Numero do display que será usado
----------------------------------------------------------------
entity disp_7seg is
	port(	 num:  in std_logic_vector(3 downto 0); 
			 sel:  in std_logic;
		  n_dis:  in std_logic_vector(1 downto 0);
		  sel_d: out std_logic_vector(3 downto 0);
			disp: out std_logic_vector(0 to 7)
		 );
end disp_7seg;

architecture arq of disp_7seg is
	signal count: integer := 0;
begin
	disp <= "00000011" when (unsigned(num) = 0) else 
			  "10011111" when (unsigned(num) = 1) else 
			  "00100101" when (unsigned(num) = 2) else 
			  "00001101" when (unsigned(num) = 3) else 
			  "10011001" when (unsigned(num) = 4) else 
			  "01001001" when (unsigned(num) = 5) else 
			  "01000001" when (unsigned(num) = 6) else 
			  "00011111" when (unsigned(num) = 7) else 
			  "00000001" when (unsigned(num) = 8) else 
			  "00011001" when (unsigned(num) = 9) else 
			  "00010001" when (unsigned(num) = 10 and sel = '1') else 
			  "11000001" when (unsigned(num) = 11 and sel = '1') else 
			  "01100011" when (unsigned(num) = 12 and sel = '1') else 
			  "10000101" when (unsigned(num) = 13 and sel = '1') else 
			  "01100001" when (unsigned(num) = 14 and sel = '1') else 
			  "01110001" when (unsigned(num) = 15 and sel = '1') else
			  "11111111" when (unsigned(num) > 9 and sel = '0');
			  
	sel_d <= "0111" when (unsigned(n_dis) = 0) else
				"1011" when (unsigned(n_dis) = 1) else
				"1101" when (unsigned(n_dis) = 2) else
				"1110" when (unsigned(n_dis) = 3);
end arq;