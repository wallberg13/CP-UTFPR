/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 *
 * @author sir-berg
 */
public class Servidor {
    
    private int porta;
    private Interpretador inter = null;
    private DNSImple dns = null;
    
    public Servidor(int porta){
        this.porta = porta;
        dns = new DNSImple();
        init();
    }
    
    public void init(){
        DatagramSocket sock;
        DatagramPacket dgRec, dgEnv;
        String[] msg_env;
        String msg_rec;
        
        try{
            // Criando o Socket do servidor
            sock = new DatagramSocket(porta);
            System.out.println("Socket Criado!! \nOuvindo a Porta: " + porta);
            boolean saida = false;
            
            do{
                // Recebe a mensagem -  A requisicao
                dgRec = new DatagramPacket(new byte[1024], 1024);
                sock.receive(dgRec);
                
                //Agora trata a requisicao
                msg_rec = new String(dgRec.getData());
                // Cria um interpretador para a mensagem recebida
                inter = new Interpretador(msg_rec, dgRec.getAddress().getHostAddress()); 
                msg_env = inter.trata_mensagem(dns);
                
                // Preparacao para envio das mensagens, já que agora são varias Strings, dependendo
                // Da requisicao.
                
                if(!inter.getRequisicao().split(" ")[0].equals("list")){
                    dgEnv = new DatagramPacket(msg_env[0].getBytes(), msg_env[0].getBytes().length, dgRec.getAddress(), dgRec.getPort());
                    sock.send(dgEnv);
                }else{
                    String aux = "inicio";
                    dgEnv = new DatagramPacket(aux.getBytes(),aux.getBytes().length, dgRec.getAddress(), dgRec.getPort());
                    sock.send(dgEnv);
                    
                    for(int i = 0; i < msg_env.length; i++){
                        dgEnv = new DatagramPacket(msg_env[i].getBytes(),msg_env[i].getBytes().length, dgRec.getAddress(), dgRec.getPort());
                        sock.send(dgEnv);
                    }
                    
                    aux = "fim";
                    dgEnv = new DatagramPacket(aux.getBytes(),aux.getBytes().length, dgRec.getAddress(), dgRec.getPort());
                    sock.send(dgEnv);
                }
            }while(!saida);
            
        }catch(UnknownHostException ex) {
           System.out.println("Erro de Host Desconhecido: " + ex.getMessage());
        } catch(SocketException ex){
            System.out.println("Erro de socket: " + ex.getMessage());
        } catch(IOException ex){
            System.out.println("Erro envio/recepcao datagram: " + ex.getMessage());
        }
    }
    
    public static void main(String[] args){
        Servidor serv = new Servidor(4321);
    }
}
