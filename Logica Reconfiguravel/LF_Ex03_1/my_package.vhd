library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

package my_pack is
	
	----------------------------------------------------------------
	-- num: Entrada de um numero entre 0 e F (ou 0 a 9).
	-- sel: Modo de operacao.
		-- 0 : BCD
		-- 1 : HEX
	-- n_dis: Numero do display que será usado
	----------------------------------------------------------------
	component disp_7seg is
		port(	 num:  in std_logic_vector(3 downto 0); 
				 sel:  in std_logic;
			  n_dis:  in std_logic_vector(1 downto 0);
			  sel_d: out std_logic_vector(3 downto 0);
				disp: out std_logic_vector(0 to 7)
			 );
	end component;
	
	--------------------------------------------------------
	-- freq: Frequencia desejada do clock em Hz
	-- mclk: Clock oriundo da fonte de clock da Basys.
	-- clk: Clock de saida na frequecia desejada na entrada.
	--------------------------------------------------------
	component clk_generate is 
		generic( freq: integer := 1);
		port(	mclk:		 in std_logic;
			    clk: buffer std_logic);
	end component;
	
end my_pack;