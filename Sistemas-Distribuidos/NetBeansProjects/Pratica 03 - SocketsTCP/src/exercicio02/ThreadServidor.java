/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

/**
 *
 * @author sir-berg
 */
public class ThreadServidor implements Runnable{
    
    private Socket cli = null;
    
    public ThreadServidor(Socket cli){
        this.cli = cli;
    }
    
    /**
     * Metodo que implementa a thread de coneccao de cada Cliente.
     */
    @Override
    public void run() {
        System.out.println("Conectado com: " + cli.getInetAddress().getHostAddress() + " e Porta: " + cli.getPort());
        String requisicao = null;
        IHoraCerta hc = new HoraCertaServer();

        try{
            DataOutputStream out = new DataOutputStream(cli.getOutputStream());
            DataInputStream in = new DataInputStream(cli.getInputStream());
            Requisicao req = null;
            
            do{
                requisicao = in.readUTF();
                req = new Requisicao(requisicao, cli.getInetAddress().getHostAddress());
                out.writeUTF(req.trata_requisicao(hc));
                
            }while(requisicao.trim().split(" ")[0] != null);
            
        }catch(IOException ex){
            System.out.println("Ocorreu um erro de IO " + ex.getMessage());
        }
        
    }
    
}
