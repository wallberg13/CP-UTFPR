/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

/**
 *
 * @author sir-berg
 */
public class ServerThread implements Runnable{
    
    private Socket cli = null;
    
    public ServerThread(Socket cli){
        this.cli = cli;
    }
    
    @Override
    public void run() {
        System.out.println("Conectado com: " + cli.getInetAddress().getHostAddress() + " e Porta: " + cli.getPort());
        String requisicao = null;
        IMatematica mat = new MatematicaImple();
        
        try{
            /*
                Aqui só entra texto e sai objeto, lá na requisicao que é permitido a entrada de 
                objeto.
            */
            ObjectOutputStream out = new ObjectOutputStream(cli.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(cli.getInputStream());
            Requisicao req = null;
            
            do{
                requisicao = (String) in.readObject();
                req = new Requisicao(requisicao, cli.getInetAddress().getHostAddress());
                out.writeObject(req.trata_requisicao(mat, cli, in));
                
            }while(requisicao.trim().split(" ")[0] != null);
            
        } catch(IOException ex){
            System.out.println("Ocorreu um erro de IO " + ex.getMessage());
        } catch (ClassNotFoundException ex) {
            System.out.println("Classe desconhecida " + ex.getMessage());
        }
    }
    
}
