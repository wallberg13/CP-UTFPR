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
class MatrizIncompativelException extends IllegalArgumentException {
    private int i;
    
    public MatrizIncompativelException(){
    }
    
    public MatrizIncompativelException(int x){
        i = x;
    }
    
    public String getI(){
        if(i == 1){
            return "As dimensões de ambas matrizes devem ser iguais!!";
        }else{
            if(i == 2){
                return "Error de dimensionamento na multiplicao, coluna da matriz A diferente da linha da matriz B";
            }
        }
        return "Algo esta errado";
    }
    
    @Override
    public String getMessage(){
        return "Exceção causada por" + getI();
    }
}
