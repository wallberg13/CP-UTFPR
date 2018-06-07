/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author sir-berg
 */
public class Servidor {
    private int porta = 0;
    private IMatematica mat = null;
    
    public Servidor(int porta){
        this.porta = porta;
        mat = new MatematicaImple();
        init();
    }
    
    public void init(){
        try{
            ServerSocket serverSock = new ServerSocket(porta);
            System.out.println("Servidor inicializado na porta: " + porta);
            
            while(true){
                Socket conexaoCli = serverSock.accept();
                Thread threadCliente = new Thread(new ServerThread(conexaoCli));
                threadCliente.start();
            }
            
        } catch (IOException ex) {
            System.out.println("Um erro desconhecido de IO aconteceu " + ex.getMessage());
        }
        
    }
    
    public static void main(String[] args){
        Servidor serv = new Servidor(4321);
    }
}
