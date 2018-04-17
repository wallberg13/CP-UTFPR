library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.my_pack.all;

entity main is
	generic(freq_d : integer := 1000;
			  freq_c : integer := 2  );
   port( mclk:  in std_logic;
			 swt:  in std_logic;
		   disp: out std_logic_vector(0 to 7);
		  sel_d: out std_logic_vector(3 downto 0));
end main;

architecture arq of main is 
	type matriz is array (0 to 3) of std_logic_vector(3 downto 0);
	-- Sinais para o display
	signal num: std_logic_vector(3 downto 0);
	signal n_d: std_logic_vector(1 downto 0) := "00";
	signal sel: std_logic := '0';
	
	-- Sinais para o clock
	signal clk_d : std_logic;
	signal clk_c : std_logic;
	
	-- Sinais gerais
	signal mtz : matriz;
	signal count: std_logic_vector(7 downto 0) := (others => '0');
	signal ret_fun: std_logic_vector(11 downto 0) := (others => '0');
	
begin
	-- Inicializacoes	
	mtz(0) <= "1111"; -- Um valor acima de 9 desliga o display caso sel = 0
	mtz(1) <= ret_fun(11 downto 8);
	mtz(2) <= ret_fun(7 downto 4);
	mtz(3) <= ret_fun(3 downto 0);
	
	-- Mapeamento dos componentes
	map_disp: entity work.disp_7seg(arq)
				 port map(num, sel, n_d, sel_d, disp);
	
	map_clk_d: entity work.clk_generate(arq)
				  generic map(freq_d)
				  port map(mclk, clk_d);
   
	map_clk_c: entity work.clk_generate(arq)
				  generic map(freq_c)
				  port map(mclk, clk_c);
				  
	
	-- Process para o display acender os 4 digitos ao mesmo tempo
	process(clk_d)
	begin
		if(clk_d'event and clk_d = '1') then
			n_d <= std_logic_vector(unsigned(n_d) + 1);
		end if;
	end process;
	num <= mtz(to_integer(unsigned(n_d)));
	
	-- Process para fazer o incremento na variavel contadora
	process(clk_c)
	begin
		if (swt = '1') then
			count <= (others => '0');
		elsif (clk_c'event and clk_c = '1') then
			count <= std_logic_vector(unsigned(count) + 1);
		end if;
	end process;
	ret_fun <= to_bcd(count);
	
end arq;