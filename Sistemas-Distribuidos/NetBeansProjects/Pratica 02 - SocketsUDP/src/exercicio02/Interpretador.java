/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

/**
 *
 * @author sir-berg
 */
public class Interpretador {
    private String msg;
    private String orig;
    
    public Interpretador(String msg, String orig){
        this.msg = msg.trim();
        this.orig = orig;
        System.out.println("Mensagem recebida: " + msg + " do IP: " + orig);
    }
    
    public String trata_mensagem(){
        String aux = null;
        IHoraCertaImpl hora = new IHoraCertaImpl();
        
        String funcao = this.msg;
        
        if(funcao.equals("dataAtual")){
            aux = hora.dataAtual();
        }
        
        if(funcao.equals("horaAtual")){
            aux = hora.horaAtual();
        }
        
        
        if(aux == null){
            aux = "Funcionalidade nao permitida na aplicacao";
        }
        
        return aux;
    }
}
