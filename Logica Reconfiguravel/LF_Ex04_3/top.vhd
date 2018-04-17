library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.my_pack.all;

entity cronometro is
	generic(freq_d : integer := 1000;
			  freq_c : integer := 1);
   port( mclk:  in std_logic;
		   swt1:  in std_logic; -- Start
			swt2:  in std_logic; -- Stop
			swt3:  in std_logic; -- Reset
		  sel_d: out std_logic_vector(3 downto 0);
		   disp: out std_logic_vector(0 to 7));
end cronometro;

architecture arq of cronometro is
	-- Estruturas
	TYPE matriz is array (0 to 3) of std_logic_vector(3 downto 0);	
	TYPE estado is (stop, run);
	
	-- Sinais referentes ao Display
	signal sel : std_logic := '0';
	signal n_d : std_logic_vector(1 downto 0); 
	signal num : std_logic_vector(3 downto 0);
	
	-- Sinais referentes ao Clk
	signal clk_d : std_logic;
	signal clk_c : std_logic;
	
	-- Outros Sinais
	signal mtz : matriz;
			
	signal dgt_u : std_logic_vector(3 downto 0) := "0000";
	signal dgt_d : std_logic_vector(3 downto 0) := "0000";
	signal dgt_um : std_logic_vector(3 downto 0) := "0000";
	signal dgt_dm : std_logic_vector(3 downto 0) := "0000";
	
	signal flag : estado := stop;
begin
	mtz(3) <= dgt_u;
	mtz(2) <= dgt_d;
	mtz(1) <= dgt_um;
	mtz(0) <= dgt_dm;
	
	-- Mapeamento de componentes
	map_display : entity work.disp_7seg(arq)
					  port map(num, sel, n_d, sel_d, disp);
	
	map_clk_d: entity work.clk_generate(arq)
				  generic map (freq_d) port map(mclk, clk_d);
				  
   map_clk_c: entity work.clk_generate(arq)
				  generic map (freq_c) port map(mclk, clk_c);
				  
	-- Process de varredura do display
	process(clk_d)
	begin
		if(clk_d'event and clk_d = '1') then
			n_d <= std_logic_vector(unsigned(n_d) + 1);
		end if;
	end process;
	
	-- Lower Section
	process(clk_c)
	begin
		if(swt1 = '1')then
			flag <= run;
		end if;
		if(swt2 = '1')then
			flag <= stop;
		end if;
		if(swt3 = '1')then
			dgt_u <= (others => '0');
			dgt_um <= (others => '0');
			dgt_d <= (others => '0');
			dgt_dm <= (others => '0');
			flag <= stop;
		elsif(clk_c'event and clk_c = '1' and flag = run) then
			dgt_u <= std_logic_vector(unsigned(dgt_u) + 1);
			if(unsigned(dgt_u) = 9) then
				dgt_u <= (others => '0');
				dgt_d <= std_logic_vector(unsigned(dgt_d) + 1);
				if(unsigned(dgt_d) = 5) then
					dgt_d <= (others => '0');
					dgt_um <= std_logic_vector(unsigned(dgt_um) + 1);
					if(unsigned(dgt_um) = 9) then
						dgt_um <= (others => '0');
						dgt_dm <= std_logic_vector(unsigned(dgt_dm) + 1);
						if (unsigned(dgt_dm) = 9) then 
							dgt_dm <= (others => '0');
						end if;
					end if;
				end if;
			end if;
		end if;
	end process;
	
	num <= mtz(to_integer(unsigned(n_d)));
end arq;