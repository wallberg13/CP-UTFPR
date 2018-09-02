/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 * Criar sock
 * enviar e receber mensagem
 * tem que saber o IP e a porta.
 * @author sir-berg
 */
public class Cliente {
    public String ip_serv;
    public int porta_serv;
    
    public Cliente(String ip_serv, int porta_serv){
        this.ip_serv = ip_serv;
        this.porta_serv = porta_serv;
        init();
    }
    
    /** 
     *  Metodo que tem como funcao mandar uma requisicao para o servidor
     */
    private String requisicao(DatagramSocket sock, String msg){
        DatagramPacket dgEnv, dgRec;
        String aux = null;
        // Primeiro envia
        try{
            dgEnv = new DatagramPacket(msg.getBytes(), msg.getBytes().length, InetAddress.getByName(this.ip_serv), this.porta_serv);
            sock.send(dgEnv);
            
            //Agora a requisicao e recebida.
            dgRec = new DatagramPacket(new byte[1024], 1024);
            sock.receive(dgRec);
            aux = new String(dgRec.getData(), 0, dgRec.getLength());
        }catch(IOException ex){
            System.out.println("Erro de IO desconhecido: " + ex.getMessage());
        }
        
        return aux;
        
    }
    
    public void init(){
        DatagramSocket sock; 
        DatagramPacket dgEnv, dgRec;
        String msg_env, msg_rec;
        try{
            sock = new DatagramSocket(); //Atribui a porta automatica
            
            System.out.println("Retorno da resposta do horaAtual: " + requisicao(sock, "horaAtual"));
            System.out.println("Retorno da resposta do dataAtual: " + requisicao(sock, "dataAtual"));
            
        } catch(SocketException ex){
            System.out.println("Erro de socket: " + ex.getMessage());
        } catch(IOException ex){
            System.out.println("Erro envio/recepcao datagram: " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Cliente cli = new Cliente("127.0.0.1", 4321);
    }
    
}
