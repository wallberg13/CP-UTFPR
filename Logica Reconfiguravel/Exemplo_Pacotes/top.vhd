library ieee;
use ieee.std_logic_1164.all;
use work.meu_pacote.all;

entity top is 
	port( a, b, c, d, e:  in std_logic;
							w: out std_logic);
end top;

architecture arq of top is
	signal y, z: std_logic;
begin 
	-- ccto_1
	map_1: entity work.ccto_1(arq)
			 port map(a => a, b => b, c => c, y => y);
	
	-- ccto_2
	map_2: entity work.ccto_2(arq)
			 port map(d => d, e => e, z => z);
 
	-- ccto_3
	map_3: entity work.ccto_3(arq)
			 port map(f => y, g => z, w => w);
end arq;