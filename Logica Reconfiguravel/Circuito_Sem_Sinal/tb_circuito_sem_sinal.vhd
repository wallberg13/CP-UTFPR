library ieee;
use ieee.std_logic_1164.all;

entity tb_ccto_sem_sinal is
end tb_ccto_sem_sinal;

architecture arq of tb_ccto_sem_sinal is
	signal ta, tb, tc, tx: std_logic;
begin
	uut: entity work.ccto_sem_sinal(arq)
	port map(a => ta, b => tb, c => tc, x => tx);
	process begin
		ta <= '0'; tb <= '0'; tc <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '1'; wait for 10 ns;
	end process;
end arq;