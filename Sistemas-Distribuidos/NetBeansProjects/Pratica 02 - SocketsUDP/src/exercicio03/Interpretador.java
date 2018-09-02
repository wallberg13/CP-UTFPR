/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

/**
 *
 * @author sir-berg
 */
public class Interpretador {
    private String requisicao;
    private String origem;
    
    public Interpretador(String requisicao, String origem){
        this.requisicao = requisicao.trim();
        this.origem = origem;
    }
    
    public String[] trata_mensagem(DNSImple dns){
        String[] ret = null;
        String[] param = requisicao.split(" ");
        System.out.println("Mensagem recebida: " + this.requisicao + " e IP de origem: " + this.origem);
        /**  
         * No bind, o vetor param 
         * tem que ter 4 posicoes.
         */
        if(param[0].equals("bind")){
            ret = new String[1];
            ret[0] = dns.bind(param[1], param[2], Integer.parseInt(param[3]));
            return ret;
        }
        
        if(param[0].equals("lookup")){
            ret = new String[1];
            ret[0] = dns.lookup(param[1]);
            return ret;
        }
        
        if(param[0].equals("unbind")){
            ret = new String[1];
            ret[0] = dns.unbind(param[1]);
            return ret;
        }
        
        if(param[0].equals("list")){
            ret = dns.list();
            return ret;
        }
        
        ret = new String[1];
        ret[0] = "Função não reconhecida!!";
        
        return ret;
    }

    public String getRequisicao() {
        return requisicao;
    }
    
}
