package exercicio01;

import java.rmi.Remote;
import java.rmi.RemoteException;


public interface IMyStringUtil extends Remote {
    /**
     * Retorna a mesma string de entradada
     * @param str
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public String ecoar(String str) throws RemoteException;
    
    /**
     * 
     * @param str
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public String inverter(String str) throws RemoteException;
    
    
    /** 
     * Inverte cada palavra de uma string.
     * 
     * @param str
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public String inverterPalavra(String str) throws RemoteException;
    
    /**
     * Verifica se uma string é igual em sua ordem direta e inversa
     * @param str
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public boolean isPalindroma(String str) throws RemoteException;
    
    /** 
     * Verifica de uma string é Pangram.
     * Pangram são frases que possuem todas as letras
     * do alfabeto contidas nela.
     * @param str String de verificação
     * @return É ou não pangram
     * @throws java.rmi.RemoteException
     */
    public boolean isPangram(String str) throws RemoteException;
}
