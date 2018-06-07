/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio04;

/**
 *
 * @author sir-berg
 */
class DominioJaRegistrado extends Exception {
    
    public DominioJaRegistrado(){
    }
    
    public DominioJaRegistrado(String msg){
        super(msg);
    }
    
    public String toString(){
        return "Dominio já registrado";
    }
}
