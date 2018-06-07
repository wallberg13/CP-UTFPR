/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio04;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author sir-berg
 */
public interface IDNS extends Remote{
    
    /**
     * Faz cadastro de um nome de domínio, isto é, faz a associação de um nome para um IP.
     * @param dominio
     * @param IP
     * @param porta
     * @throws DominioJaRegistrado 
     */
    public void bind(String dominio, String IP, int porta) throws RemoteException;
    
    /**
     * Faz a resolução de um nome de dominio, isto é, retorna o IP para o nome.
     * @param dominio
     * @throws DominioNaoRegistrado 
     */
    public String lookup(String dominio) throws RemoteException;
     
    /**
     * Faz a remoção de um nome de domínio.
     * @param dominio
     * @throws DominioNaoRegistrado 
     */
    public void unbind(String dominio) throws RemoteException;
     
    /**
     * Lista todos os nomes de dominio ja registrados.
     * @return 
     */
    public String[] list() throws RemoteException;;
}
