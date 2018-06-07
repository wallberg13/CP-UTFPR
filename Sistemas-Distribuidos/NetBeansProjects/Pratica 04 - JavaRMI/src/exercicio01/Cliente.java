/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author sir-berg
 */
public class Cliente {
    
    private IMyStringUtil str;
    
    public Cliente(String ip, int porta){
        try{
            // Buscar objeto remoto
            Registry registro = LocateRegistry.getRegistry(ip, porta);
            // Do servidor de registros, ele obtem o objeto que la foi cadastrado.
            str = (IMyStringUtil) registro.lookup("str");
        } catch (NotBoundException ex){
            System.out.println("Objeto nao encontrado: " + ex.getMessage());
        } catch (RemoteException ex) {
            System.out.println("RemoteException: " + ex.getMessage());
        }
        init();
    }
    
    private void init(){
        try{
            System.out.println(str.ecoar("O meu pastel de frando e mais barato"));
            System.out.println(str.inverter("O meu pastel de frando e mais barato"));
            System.out.println(str.inverterPalavra("O meu pastel de frando e mais barato"));
            System.out.println(str.isPalindroma("O meu pastel de frando e mais barato"));
            System.out.println(str.isPangram("O meu pastel de frando e mais barato"));
        } catch (RemoteException ex) {
            System.out.println("RemoteException: " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Cliente c = new Cliente("127.0.0.1", 4321);
    }
    
}
