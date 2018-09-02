library ieee;
use ieee.std_logic_1164.all;

package meu_pacote is 

	component ccto_1 is
		port( a, b, c:  in std_logic;
						y: out std_logic);
	end component;

	component ccto_2 is 
		port( d, e:  in std_logic;
					z: out std_logic);
	end component;

	component ccto_3 is
		port( f, g:  in std_logic;
					w: out std_logic);
	end component;

end meu_pacote;