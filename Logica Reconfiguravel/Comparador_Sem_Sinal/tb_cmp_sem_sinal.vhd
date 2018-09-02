library ieee;
use ieee.std_logic_1164.all;

entity tb_cmp_sem is
end tb_cmp_sem;

architecture arq of tb_cmp_sem is
	signal ta, tb, tx: std_logic;
begin
	uut: entity work.cmp_sem_sinal(arq)
	port map(a => ta, b => tb, x => tx);
	process begin
		ta <= '0'; tb <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '1'; wait for 10 ns;
	end process;
end arq;