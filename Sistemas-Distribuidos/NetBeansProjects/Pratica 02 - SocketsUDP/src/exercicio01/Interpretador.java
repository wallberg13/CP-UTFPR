/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

/**
 *
 * @author sir-berg
 */
public class Interpretador {
    String msg;
    String local;
    
    /** 
     * O socket não faz o tratamento da mensagem, a unica 
     * coisa que ele faz é transformar de array de bytes pra String.
     * @param msg
     */
    public Interpretador(String msg, String local){
        this.msg = msg.trim();
        this.local = local;
    }
    
    /**
     * Aqui a mensagem é de fato tratada. O servidor tem que 
     * chamar essa função para poder fazer a chamada de função.
     * Padrão: Primeira string é o nome da funcao, e o resto da String são os paramentros.
     * @return 
     */
    public String trata_mensagem(){
        String aux = null;
        String func, param;
        StringUtilImple sui = new StringUtilImple();
        System.out.println("Mensagem recebida: " + this.msg + " IP: " + this.local);
        func = msg.split(" ")[0];
        param = msg.substring(func.length()).trim();
        
        if(func.equals("ecoar")){
            aux = sui.ecoar(param);
        }
        
        if(func.equals("inverter")){
            aux = sui.inverter(param);
        }
        
        if(func.equals("inverterPalavra")){
            aux = sui.inverterPalavra(param);
        }
        
        if(func.equals("isPalindroma")){
            if(sui.isPalindroma(param)){
                aux = "True";
            }else{
                aux = "False";
            }
        }
        
        if(func.equals("isPangram")){
            if(sui.isPangram(param)){
                aux = "True";
            }else{
                aux = "False";
            }
        }
        
        if(aux == null){
            aux = "O servidor não fornece esta funcionalidade";
        }
        return aux;
    }
}
