/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

/**
 *
 * @author sir-berg
 */
public class ProxyDNS implements IDNS{
    private String ip;
    private int porta;
    private Socket sock;
    
    private ObjectInputStream in = null;
    private ObjectOutputStream out = null;
    
    public ProxyDNS(String ip, int porta){
        this.ip = ip;
        this.porta = porta;
        
        try{
            sock = new Socket(ip, porta);

            //this.outS = new DataOutputStream(sock.getOutputStream());
            this.in = new ObjectInputStream(sock.getInputStream());
            this.out = new ObjectOutputStream(sock.getOutputStream());
        }catch(IOException ex){
            System.out.println("Erro desconhecido de IO " + ex.getMessage());
        } 
    }

    @Override
    public String bind(String dominio, String IP, int porta) throws DominioJaRegistrado {
        String ret = null;
        try {
            out.writeObject("bind " + dominio + " " + IP + " " + porta);
            ret = (String) in.readObject();
        } catch(IOException ex){
            System.out.println("Erro desconhecido de IO + " + ex.getMessage());
        } catch (ClassNotFoundException ex) {
            System.out.println("Classe desconhecida " + ex.getMessage());
        }
        
        if(ret.equals("dominioJaRegistradoExc")){
            throw new DominioJaRegistrado("Erro: Dominio ja esta registrado");
        }else{
            ret = "OK. Dominio Registrado";
        }
        
        return ret;
    }

    @Override
    public String lookup(String dominio) throws DominioNaoRegistrado {
        String ret = null;
        try {
            out.writeObject("lookup " + dominio);
            ret = (String) in.readObject();
        } catch(IOException ex){
            System.out.println("Erro desconhecido de IO + " + ex.getMessage());
        } catch (ClassNotFoundException ex) {
            System.out.println("Classe desconhecida " + ex.getMessage());
        }
        
        if(ret.equals("dominioJaRegistradoExc")){
            throw new DominioNaoRegistrado();
        }
        
        return ret;
    }

    @Override
    public String unbind(String dominio) throws DominioNaoRegistrado {
        String ret = null;
        try {
            out.writeObject("unbind " + dominio);
            ret = (String) in.readObject();
        } catch(IOException ex){
            System.out.println("Erro desconhecido de IO + " + ex.getMessage());
        } catch (ClassNotFoundException ex) {
            System.out.println("Classe desconhecida " + ex.getMessage());
        }
        
        if(ret.equals("dominioNaoRegistradoExc")){
            throw new DominioNaoRegistrado("Erro: Dominio nao existe");
        }else{
            ret = "OK. Dominio Removido";
        }
        
        return ret;
    }

    @Override
    public String[] list() {
        String[] ret = null;
        try{
            out.writeObject("list");
            ret = (String []) in.readObject();
        } catch(IOException ex){
            System.out.println("Erro desconhecido de IO + " + ex.getMessage());
        } catch (ClassNotFoundException ex) {
            System.out.println("Classe desconhecida " + ex.getMessage());
        }
        return ret;
    }
}
