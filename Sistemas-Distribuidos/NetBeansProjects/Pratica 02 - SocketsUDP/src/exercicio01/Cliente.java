/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 *
 * @author sir-berg
 */
public class Cliente {
    /**
     * O Cliente precisa saber a porta do servidor, e o IP do servidor.
     * E localmente nao precisa atribuir uma porta, pois o sistema operacional 
     * faz isso sozinho.
     */
    public String IP_serv = "";
    public int porta_serv = 0;
    
    public Cliente(String IP_serv, int porta_serv){
        this.IP_serv = IP_serv;
        this.porta_serv = porta_serv;
        iniciar();
    }
    
    public void iniciar(){
        try{
            /**
            * Primeira coisa, criar o sock do cliente
            */
            DatagramSocket socket = new DatagramSocket(); // Sem parametro, cria um sock com a porta automatica
            DatagramPacket dgRec, dgEnvio; // Datagram para recebimento e envio
            String msg_env, msg_rec;
            /**
             * Segunda coisa, criar a mensagem: Teste Ecoar
             */
            msg_env = "ecoar Meu Pastel de frango é do caralho";
            System.out.println("Mensagem enviada: " + msg_env);
            // Envia a mensagem
            dgEnvio = new DatagramPacket(msg_env.getBytes(), msg_env.getBytes().length, InetAddress.getByName(IP_serv), porta_serv);
            socket.send(dgEnvio);
            // Agora recebe a mensagem
            dgRec = new DatagramPacket(new byte[1024], 1024);
            socket.receive(dgRec);
            msg_rec = new String(dgRec.getData(), 0, dgRec.getLength());
            System.out.println("Ecoar: " + msg_rec + "\n\n");
            
            /**
             * Teste: inverter
             */
            msg_env = "inverter Meu Pastel de frango é do caralho";
            System.out.println("Mensagem enviada: " + msg_env);
            dgEnvio = new DatagramPacket(msg_env.getBytes(), msg_env.getBytes().length, InetAddress.getByName(IP_serv), porta_serv);
            socket.send(dgEnvio);
            dgRec = new DatagramPacket(new byte[1024], 1024);
            socket.receive(dgRec);
            msg_rec = new String(dgRec.getData(), 0, dgRec.getLength());
            System.out.println("Palavra Invertida: " + msg_rec + "\n\n");
            
            /**
             * Teste: inverterPalavra
             */
            msg_env = "inverterPalavra Meu Pastel de frango é do caralho";
            System.out.println("Mensagem enviada: " + msg_env);
            dgEnvio = new DatagramPacket(msg_env.getBytes(), msg_env.getBytes().length, InetAddress.getByName(IP_serv), porta_serv);
            socket.send(dgEnvio);
            dgRec = new DatagramPacket(new byte[1024], 1024);
            socket.receive(dgRec);
            msg_rec = new String(dgRec.getData(), 0, dgRec.getLength());
            System.out.println("Palavra InvertidaPalavra: " + msg_rec + "\n\n");
            
            /**
             * Teste: isPalindrona
             */
            msg_env = "isPalindroma Meu Pastel de frango é do caralho";
            System.out.println("Mensagem enviada: " + msg_env);
            dgEnvio = new DatagramPacket(msg_env.getBytes(), msg_env.getBytes().length, InetAddress.getByName(IP_serv), porta_serv);
            socket.send(dgEnvio);
            dgRec = new DatagramPacket(new byte[1024], 1024);
            socket.receive(dgRec);
            msg_rec = new String(dgRec.getData(), 0, dgRec.getLength());
            System.out.println("É Palindroma: " + msg_rec + "\n\n");

            msg_env = "isPangram Meu Pastel de frango é do caralho";
            System.out.println("Mensagem enviada: " + msg_env);
            dgEnvio = new DatagramPacket(msg_env.getBytes(), msg_env.getBytes().length, InetAddress.getByName(IP_serv), porta_serv);
            socket.send(dgEnvio);
            dgRec = new DatagramPacket(new byte[1024], 1024);
            socket.receive(dgRec);
            msg_rec = new String(dgRec.getData(), 0, dgRec.getLength());
            System.out.println("É Palindroma: " + msg_rec + "\n\n");  
            
            // Fechar o socket
            socket.close();
        } catch(UnknownHostException ex){
            System.out.println("Erro de Host Desconhecido: " + ex.getMessage());
        } catch(SocketException ex){
            System.out.println("Erro de socket " + ex.getMessage());
        } catch(IOException ex){
            System.out.println("Erro envio/recepcao datagrama: " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Cliente cli = new Cliente("127.0.0.0", 4321);
    }
}
