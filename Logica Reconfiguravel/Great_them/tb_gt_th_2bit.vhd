library ieee;
use ieee.std_logic_1164.all;

entity tb_gt_th is
end tb_gt_th;

architecture arq of tb_gt_th is
	signal ta0, ta1, tb0, tb1, tx: std_logic;
begin
	uut: entity work.gt_th_2bit(arq)
	port map(a0 => ta0, a1 => ta1, b0 => tb0, b1 => tb1, x => tx);
	process begin
		ta1 <= '0'; ta0 <= '0'; tb1 <= '0'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '0'; ta0 <= '0'; tb1 <= '0'; tb0 <= '1'; wait for 10 ns;
		ta1 <= '0'; ta0 <= '0'; tb1 <= '1'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '0'; ta0 <= '0'; tb1 <= '1'; tb0 <= '1'; wait for 10 ns;
		
		ta1 <= '0'; ta0 <= '1'; tb1 <= '0'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '0'; ta0 <= '1'; tb1 <= '0'; tb0 <= '1'; wait for 10 ns;
		ta1 <= '0'; ta0 <= '1'; tb1 <= '1'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '0'; ta0 <= '1'; tb1 <= '1'; tb0 <= '1'; wait for 10 ns;
		
		ta1 <= '1'; ta0 <= '0'; tb1 <= '0'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '1'; ta0 <= '0'; tb1 <= '0'; tb0 <= '1'; wait for 10 ns;
		ta1 <= '1'; ta0 <= '0'; tb1 <= '1'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '1'; ta0 <= '0'; tb1 <= '1'; tb0 <= '1'; wait for 10 ns;
		
		ta1 <= '1'; ta0 <= '1'; tb1 <= '0'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '1'; ta0 <= '1'; tb1 <= '0'; tb0 <= '1'; wait for 10 ns;
		ta1 <= '1'; ta0 <= '1'; tb1 <= '1'; tb0 <= '0'; wait for 10 ns;
		ta1 <= '1'; ta0 <= '1'; tb1 <= '1'; tb0 <= '1'; wait for 10 ns;
	end process;	
end arq;