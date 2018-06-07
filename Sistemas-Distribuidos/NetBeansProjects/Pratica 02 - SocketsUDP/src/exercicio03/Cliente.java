package exercicio03;


import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sir-berg
 */
public class Cliente {
    private String ip_serv;
    private int port_serv;
    
    public Cliente(String ip_serv, int port_serv){
        this.ip_serv = ip_serv;
        this.port_serv = port_serv;
        init();
    }
    
    
    public void init(){
        DatagramSocket socket;
        try{
            socket = new DatagramSocket();
            // Na funcao requisicao ja imprime so, nao faz retornos.
            requisicao(socket, "bind www.pebanet.br 255.234.111.46 8080"); 
            requisicao(socket, "bind www.utfpr.edu.br 200.134.81.46 8080");
            requisicao(socket, "bind www.oxente.net 166.233.121.32 8080");
            requisicao(socket, "bind www.oxente.net 166.233.121.32 8080");
            requisicao(socket, "list"); // Para mostrar todos registrados
            
            requisicao(socket, "lookup www.utfpr.edu.br");
            requisicao(socket, "lookup www.utfpr.edu.br.2"); 
            
            requisicao(socket, "unbind www.utfpr.edu.br");
            requisicao(socket, "unbind www.utfpr.edu.br");
            
            requisicao(socket, "list"); // Pra mostrar que deu certo remover o que falta
            
            
        } catch(SocketException ex){
            System.out.println("Erro de socket: " + ex.getMessage());
        } catch(IOException ex){
            System.out.println("Erro envio/recepcao datagram: " + ex.getMessage());
        }     
        
    }
    
    
    private void requisicao(DatagramSocket socket, String msg) throws IOException{
        DatagramPacket dgRec, dgEnv;
        String msg_rec;
        System.out.println("\nRequisicao: " + msg);
        try{
            dgEnv = new DatagramPacket(msg.getBytes(),msg.getBytes().length, InetAddress.getByName(ip_serv), port_serv);
            socket.send(dgEnv);
            
            /**
             * Agora esterar uma resposta, mas se na mensagem tiver so um list, o tratamento 
             * e especial;
             */            
            dgRec = new DatagramPacket(new byte[1024], 1024);
            socket.receive(dgRec);
            msg_rec = (new String(dgRec.getData())).trim();
            
            if(msg_rec.equals("inicio")){
                
                System.out.println("Lista de DNS registrados: ");
                
                do{
                    dgRec = new DatagramPacket(new byte[1024], 1024);
                    socket.receive(dgRec);
                    msg_rec = (new String(dgRec.getData())).trim();
                    if(msg_rec.equals("fim"))
                        System.out.println("FIM DE LISTA");
                    else
                        System.out.println("\t"+msg_rec);
                    
                }while(!msg_rec.equals("fim"));
                
            }else{
                System.out.println("Resposta: " + msg_rec);
            }
            
        }catch(UnknownHostException ex) {
           System.out.println("Erro de Host Desconhecido: " + ex.getMessage());
        }catch(IOException ex){
            System.out.println("Erro de IO desconhecido: " + ex.getMessage());
        }

    }
    
    public static void main(String[] args){
        Cliente cli = new Cliente("127.0.0.1", 4321);
    }
}
