/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 * O que fazer: 
 * Abrir um sock.
 * Colocar ele pra receber mensagens sem fim.
 * Fechar o Sock.
 * @author sir-berg
 */
public class Servidor {
    private int porta;
    
    public Servidor(int porta){
        this.porta = porta;
        init();
    }
    
    public void init(){
        DatagramSocket sock;
        DatagramPacket dgEnv, dgRec;
        String msgEnv, msgRec;
        Interpretador inter = null;
        
        try{
            sock = new DatagramSocket(porta);
            System.out.println("Socket aberto e ouvindo a porta " + porta);
            boolean saida = false;
            
            do{
                // Preparo o Sock para receber a mensagem
                dgRec = new DatagramPacket(new byte[1024], 1024);
                sock.receive(dgRec);
                msgRec = new String(dgRec.getData()); // Teste se funciona: msgRec = new String(dgRec.getData())
                inter = new Interpretador(msgRec, dgRec.getAddress().getHostAddress());
                
                // Prepato o Sock para enviar a resposta da mensagem
                msgEnv = inter.trata_mensagem();
                try{
                    dgEnv = new DatagramPacket(msgEnv.getBytes(), msgEnv.getBytes().length, dgRec.getAddress(), dgRec.getPort());
                    sock.send(dgEnv);
                }catch(IOException ex) {
                    System.out.println("Erro de IO desconhecido: " + ex.getMessage());
                }
                
            }while(!saida);
            
            // Fecha o Sock
            sock.close();
            System.out.println("Servidor fechado!!");
        } catch(UnknownHostException ex) {
           System.out.println("Erro de Host Desconhecido: " + ex.getMessage());
        } catch(SocketException ex){
            System.out.println("Erro de socket: " + ex.getMessage());
        } catch(IOException ex){
            System.out.println("Erro envio/recepcao datagram: " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Servidor s = new Servidor(4321);
    }
}
