/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio04;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author sir-berg
 */
public class Servidor {
    Registry registro;
    
    public Servidor(int porta){
        try{
            registro = LocateRegistry.createRegistry(porta);
        } catch(RemoteException ex){
            System.out.println("Erro no Remote Exception: " + ex.getMessage());
        }
        init();
    }
    
    public final void init(){
        try{
            IDNS dns = new DNSImple();
            registro.bind("DNS", dns);
            System.out.println("Servido inicializado e registro cadastrado");
        } catch(RemoteException ex){
            System.out.println("Remote exception: " + ex.getMessage());
        } catch (AlreadyBoundException ex) {
            System.out.println("Ja existe um objeto com esse nome registrado!! " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Servidor s = new Servidor(4321);
    }
}
