/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author sir-berg
 */
public class Cliente {
    IHoraCerta hora;
    
    /**
     * Para o cliente utilizar o objeto declarado remotamente, ele deve achar a referencia do
     * objeto, para isso, precisa-se fazer um lookup do objeto
     */
     
    public Cliente(String ip, int porta){
        try{
            Registry registro = LocateRegistry.getRegistry(ip, porta);
            hora = (IHoraCerta) registro.lookup("Hora");
        } catch (NotBoundException ex){
            System.out.println("Objeto nao encontrado: " + ex.getMessage());
        } catch (RemoteException ex) {
            System.out.println("RemoteException: " + ex.getMessage());
        }
        init();
    }

    private void init() {
        try{
            System.out.println(hora.dataAtual());
            System.out.println(hora.horaAtual());
        } catch (RemoteException ex) {
            System.out.println("RemoteException: " + ex.getMessage());
        }
    }
    
    
    public static void main(String[] args){
        Cliente cli = new Cliente("127.0.0.1", 4321);
    }
}
