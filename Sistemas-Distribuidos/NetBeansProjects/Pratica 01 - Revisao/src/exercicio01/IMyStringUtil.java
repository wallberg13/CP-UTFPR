package exercicio01;

public interface IMyStringUtil {
    /**
     * Retorna a mesma string de entradada
     * @param str
     * @return 
     */
    public String ecoar(String str);
    
    /**
     * 
     * @param str
     * @return 
     */
    public String inverter(String str);
    
    /** 
     * Inverte cada palavra de uma string.
     * 
     * @param str
     * @return 
     */
    public String inverterPalavra(String str);
    
    /**
     * Verifica se uma string é igual em sua ordem direta e inversa
     * @param str
     * @return 
     */
    public boolean isPalindroma(String str);
    
    /** 
     * Verifica de uma string é Pangram.
     * Pangram são frases que possuem todas as letras
     * do alfabeto contidas nela.
     * @param str String de verificação
     * @return É ou não pangram
     */
    public boolean isPangram(String str);
}
