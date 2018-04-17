library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_mlt_2bits is
end tb_mlt_2bits;

architecture arq of tb_mlt_2bits is
	signal ta, tb: std_logic_vector(1 downto 0);
	signal 	  ty: std_logic_vector(3 downto 0);
begin
	uut: entity work.mlt_2bits(arq)
	port map(a => ta, b => tb, y => ty);
	
	process 
		variable i,j: integer := 0;
	begin
		for i in 0 to 3 loop
			for j in 0 to 3 loop
				ta <= std_logic_vector(to_unsigned(i,2));
				tb <= std_logic_vector(to_unsigned(j,2));
				wait for 10 ns;
			end loop;
		end loop;
	end process;
end arq;
