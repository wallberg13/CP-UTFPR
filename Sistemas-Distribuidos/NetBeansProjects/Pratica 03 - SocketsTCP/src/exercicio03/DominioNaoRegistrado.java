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
class DominioNaoRegistrado extends Exception {
    
    public DominioNaoRegistrado(){       
    }
    
    public DominioNaoRegistrado(String msg){
        super(msg);
    }
    
    public String toString(){
        return "Dominio Não Registrado";
    }
}
