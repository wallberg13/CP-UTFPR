/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;
import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
/**
 *
 * @author sir-berg
 */
public class Servidor {
    Registry registro;
    
    /** 
     * Cria o servidor de registro na propria aplicacao
     */
    public Servidor(int porta){
        try{
            registro = LocateRegistry.createRegistry(porta);
        } catch(Exception e){
            System.err.println("Erro: " + e.getMessage());
        }
        init();
    }
    
    public final void init(){
        /**
         *  Registra os objetos que poderam ser executados remotamente
         */
        try{
           IHoraCerta hora = new IHoraCertaImpl();
           registro.bind("Hora", hora);
           System.out.println("Servidor inicializado e registro cadastrado!");
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
