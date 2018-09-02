/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

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
            registro = LocateRegistry.createRegistry(porta); // Aqui cria, em cima localiza um servidor que exerce a funcao
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
        
        init();
    }

    public final void init(){
        try{
            // Dando um bind no servidor de registro para que aquele meu objeto seja publico.
            // Para todos que olham para o servidor de registros.
            IMatematica mate = new MatematicaImple();
            registro.bind("Mati", mate);
            System.out.println("O servidor esta rodando");
        } catch(RemoteException ex){
            System.out.println("Remote exception: " + ex.getMessage());
        } catch (AlreadyBoundException ex) {
            System.out.println("Ja existe um objeto com esse nome registrado!! " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Servidor s = new Servidor(4444);
    }
    
}
