library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity alarm is 
	port( 	 mclk:  in std_logic;
			controle:  in std_logic;
			  sensor:  in std_logic;
			  status: out std_logic;
			  alarme: out std_logic);
end alarm;

architecture arq of alarm is
begin
	status <= controle;
	process(mclk)
	begin
		if(mclk'event and mclk = '1')then
			if(controle = '1')then
				if(sensor = '1')then
					alarme <= '1';			
				end if;
			else
				alarme <= '0';		
			end if;
		end if;
	end process;
	
end arq;