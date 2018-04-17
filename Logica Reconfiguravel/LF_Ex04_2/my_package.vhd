-- Mypack
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
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
	
	function to_bcd (bin : std_logic_vector(7 downto 0) ) return std_logic_vector;
end my_pack;

package body my_pack is 

	function to_bcd ( bin : std_logic_vector(7 downto 0) ) return std_logic_vector is
		variable i : integer:=0;
		variable bcd : std_logic_vector(11 downto 0) := (others => '0');
		variable bint : std_logic_vector(7 downto 0) := bin;
	begin
		for i in 0 to 7 loop -- repeating 8 times.
			bcd(11 downto 1) := bcd(10 downto 0); --shifting the bits.
			bcd(0) := bint(7);
			bint(7 downto 1) := bint(6 downto 0);
			bint(0) :='0';
			
			if(i < 7 and bcd(3 downto 0) > "0100") then
				--add 3 if BCD digit is greater than 4.
				bcd(3 downto 0) := bcd(3 downto 0) + "0011";
			end if;
			
			if(i < 7 and bcd(7 downto 4) > "0100") then
				--add 3 if BCD digit is greater than 4.
				bcd(7 downto 4) := bcd(7 downto 4) + "0011";
			end if;
			
			if(i < 7 and bcd(11 downto 8) > "0100") then
				--add 3 if BCD digit is greater than 4.
				bcd(11 downto 8) := bcd(11 downto 8) + "0011";
			end if;
			
		end loop;
		
		return bcd;
	end to_bcd;
	
end my_pack;