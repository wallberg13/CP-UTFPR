/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author sir-berg
 */
public class Servidor {
    private int porta = 0;
    private IHoraCerta hCerta = null;
    
    public Servidor(int porta){
        this.porta = porta;
        hCerta = new HoraCertaServer();
        init();
    }
    
    public final void init(){
        //Primeiro cria um socket servidor.
        try{
            ServerSocket serverSock = new ServerSocket(porta);
            System.out.println("Servido inicialiazado ouvindo a porta: " + porta);
            
            while(true){
                /**
                 * Agora é aguardar alguem se conectar.
                 */
                Socket conexaoCli = serverSock.accept();
                
                /**
                 * Agora é so chamar a thread que é destinada para o cliente.
                 */
                Thread threadCliente = new Thread(new ThreadServidor(conexaoCli));
                threadCliente.start();  
            }
            
        }catch(IOException ex){
            System.out.println("Um erro desconhecido de IO aconteceu " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Servidor serv = new Servidor(4321);
    }
    
}
