/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio04;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

/**
 *
 * @author sir-berg
 */
public class DNSImple extends UnicastRemoteObject implements IDNS{
    
    private ArrayList<String> IPs;
    private ArrayList<String> dominio;
    private ArrayList<Integer> porta;

    public DNSImple() throws RemoteException{
        super();
        IPs = new ArrayList();
        dominio = new ArrayList();
        porta = new ArrayList();
    }
    
    
    @Override
    public void bind(String dominio, String IP, int porta) throws RemoteException {
        if(verificaDominio(dominio) != -1){
            throw new DominioJaRegistrado("Dominio já registrado");
        }else{
            this.IPs.add(IP);
            this.dominio.add(dominio);
            this.porta.add(porta);
        }
    }

    @Override
    public String lookup(String dominio) throws RemoteException {
        int pos;
        if((pos = verificaDominio(dominio)) == -1){
           throw new DominioNaoRegistrado("Dominio não registrado");
        }
        return this.IPs.get(pos);
    }

    @Override
    public void unbind(String dominio) throws RemoteException {
        int pos;
        if((pos = verificaDominio(dominio)) == -1){
            throw new DominioNaoRegistrado("Dominio não registrado");
        }else{
            this.IPs.remove(pos);
            this.dominio.remove(pos);
            this.porta.remove(pos);
        }
    }

    @Override
    public String[] list() throws RemoteException {
        int size = this.dominio.size();
        
        String[] str = new String[size];
        
        for(int i = 0; i < size; i++){
            str[i] = this.dominio.get(i);
        }
        
        return str;
    }
    
    private int verificaDominio(String dominio) throws RemoteException {
        for(int i = 0; i < this.dominio.size(); i++){
            if(dominio.equals(this.dominio.get(i))){
                return i;
            }
        }
        return -1;
    }
}
