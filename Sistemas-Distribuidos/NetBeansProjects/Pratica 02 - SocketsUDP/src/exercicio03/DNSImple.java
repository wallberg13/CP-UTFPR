/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

import java.util.ArrayList;

/**
 *
 * @author sir-berg
 */
public class DNSImple implements IDNS{
    
    private ArrayList<String> IPs;
    private ArrayList<String> dominio;
    private ArrayList<Integer> porta;

    public DNSImple() {
        IPs = new ArrayList();
        dominio = new ArrayList();
        porta = new ArrayList();
    }

    @Override
    public String bind(String dominio, String IP, int porta){
        if(verificaDominio(dominio) != -1){
            return "Erro: Domínio já está registrado";
        }else{
            this.IPs.add(IP);
            this.dominio.add(dominio);
            this.porta.add(porta);
            return "Ok. Domínio Registrado";
        }        
    }

    @Override
    public String lookup(String dominio) {
        String ret;
        int pos;
        
        if((pos = verificaDominio(dominio)) == -1){
            return "Erro: Domínio não registrado!";
        }
        ret = this.IPs.get(pos) + " " + this.porta.get(pos).toString();
        return ret;               
    }

    @Override
    public String unbind(String dominio) {
        int pos;
        if((pos = verificaDominio(dominio)) == -1){
            return "Erro: domínio não existe";
        }else{
            this.IPs.remove(pos);
            this.dominio.remove(pos);
            this.porta.remove(pos);
        }
        return "Ok. Domínio Removido";
    }

    @Override
    public String[] list() {
        int size = this.dominio.size();
        
        String[] str = new String[size];
        
        for(int i = 0; i < size; i++){
            str[i] = this.dominio.get(i);
        }
        
        return str;
    }
    
    private int verificaDominio(String dominio){
        for(int i = 0; i < this.dominio.size(); i++){
            if(dominio.equals(this.dominio.get(i))){
                return i;
            }
        }
        return -1;
    }
}
