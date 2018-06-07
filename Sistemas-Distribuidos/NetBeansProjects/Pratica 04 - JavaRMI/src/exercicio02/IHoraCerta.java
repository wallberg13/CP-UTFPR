/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author sir-berg
 */
public interface IHoraCerta extends Remote{
    
    /**
     * Função que retorna a data atual do sistema.
     * @return String
     */
    public String dataAtual() throws RemoteException;

    /**
     * Função que retorna a hora atual do sistema.
     * @return 
     */
    public String horaAtual() throws RemoteException;
    
}
