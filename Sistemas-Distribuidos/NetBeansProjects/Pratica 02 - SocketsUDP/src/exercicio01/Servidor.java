/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.UnknownHostException;


/**
 * O servidor precisa de uma porta para ficar ouvindo, essa porta deve ser
 * conhecida pela aplicacao cliente.
 * 
 * O cliente tambem deve saber qual o endereco do servidor.
 * 
 * @author sir-berg
 */
public class Servidor {
    private int porta = 0;
    private Interpretador inter = null;
    
    public Servidor(int porta){
        this.porta = porta;
        iniciar();
    }
    
    public void iniciar(){
        DatagramSocket socket;
        DatagramPacket dgRec, dgEnvio;
        String msg_rec, msg_env;
        
        try {
            /**
             * Primeiro Passo é criar um socket.
             */
            socket = new DatagramSocket(porta);
            System.out.println("Socket Criado! \nOuvindo a Porta: " + porta);
            boolean saida = false;
            
            do{
                dgRec = new DatagramPacket(new byte[1024], 1024);
                socket.receive(dgRec);
                
                msg_rec = new String(dgRec.getData());
                inter = new Interpretador(msg_rec, dgRec.getAddress().getHostAddress());
                msg_env = inter.trata_mensagem();
                
                try {
                    dgEnvio = new DatagramPacket(msg_env.getBytes(), msg_env.getBytes().length, dgRec.getAddress(), dgRec.getPort());
                    socket.send(dgEnvio);
                }catch(IOException ex){
                    System.out.println("Erro no envio do datagrama: " + ex.getMessage());
                }
            }while(!saida);
            
            /**
             * Terceiro passo, fechar o socket.
             */
            socket.close();
            System.out.println("Servidor Fechado!!");
        } catch(UnknownHostException ex) {
           System.out.println("Erro de Host Desconhecido: " + ex.getMessage());
        } catch(SocketException ex){
            System.out.println("Erro de socket: " + ex.getMessage());
        } catch(IOException ex){
            System.out.println("Erro envio/recepcao datagram: " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Servidor ser = new Servidor(4321);
    }
}
