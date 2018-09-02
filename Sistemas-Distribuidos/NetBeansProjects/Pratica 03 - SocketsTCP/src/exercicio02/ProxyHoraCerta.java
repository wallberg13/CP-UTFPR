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
public class ProxyHoraCerta implements IHoraCerta{
    private String ip;
    private int porta;
    private Socket sock;
    
    private DataOutputStream out = null;
    private DataInputStream in = null;
    
    public ProxyHoraCerta(String ip, int porta){
        this.ip = ip;
        this.porta = porta;
        
        // Cria o socket do objeto hora certa
        try{
            sock = new Socket(ip, porta);

            this.in = new DataInputStream(sock.getInputStream());
            this.out = new DataOutputStream(sock.getOutputStream());
        }catch(IOException ex){
            System.out.println("Erro desconhecido de IO " + ex.getMessage());
        }
    }
    
    @Override
    public String dataAtual() {
        String ret = null;

        try{
            out.writeUTF("dataAtual");
            ret = in.readUTF();
        }catch(IOException ex){
            System.out.println("Error deconhecido de IO " + ex.getMessage());
        }        
        
        return ret;
    }

    @Override
    public String horaAtual() {
        String ret = null;
        
        try{
            out.writeUTF("horaAtual");
            ret = in.readUTF();
        }catch(IOException ex){
            System.out.println("Error desconhecido de IO " + ex.getMessage());
        }
        
        return ret;
    }
    
}
