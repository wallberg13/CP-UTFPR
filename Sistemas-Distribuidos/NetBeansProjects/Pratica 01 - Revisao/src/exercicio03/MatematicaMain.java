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
public class MatematicaMain {
    MatematicaImple mt = null;
    
    public MatematicaMain(){
        mt = new MatematicaImple();
        iniciar();
    }
    
    public void iniciar(){
        
        double a = 6;
        double b = 2;
        
        double ma[][] = {{1, 0, 2}, {-1, 3, 1}};
        double mb[][] = {{1, 0, 2}, {-1, 3, 1}};
        double mc[][] = {{3, 1}, {2, 1}, {1, 0}};
        double mx[][] = {};

        double md[][] = {{1, 0, 2, 0}, {-1, 3, 1, 2}};
        
        System.out.println(a + " + " + b + " = " + mt.somar(a, b));
        System.out.println(a + " - " + b + " = " + mt.subtrair(a, b));
        System.out.println(a + " x " + b + " = " + mt.multiplicar(a, b));
        
        try {
            System.out.println(a + " / " + b + " = " + mt.dividir(a,b));
        } catch (ArithmeticException e) {
            System.out.println("Houve divisão por zero");
        }
        
        System.out.println();
        System.out.println("Matriz A");
        imprimeMatriz(ma);
        System.out.println("Matriz B");
        imprimeMatriz(mb);
        
        System.out.println("Matriz Soma");
        
        try{
            imprimeMatriz(mt.somar(ma, mx));
        }catch(MatrizIncompativelException e){
            e.getMessage();
        }
                
            
        
        System.out.println("Matriz Substracao");
        imprimeMatriz(mt.subtrair(ma, mb));

        System.out.println("Matriz A");
        imprimeMatriz(ma);
        System.out.println("Matriz C");
        imprimeMatriz(mc);
        System.out.println("Matriz Multiplicacao");
        
        try {
            imprimeMatriz(mt.multiplicar(ma, mc));
        } catch (MatrizIncompativelException ex) {
            ex.printStackTrace();
        }

        System.out.println("Matriz A");
        imprimeMatriz(ma);
        System.out.println("Matriz Multiplicacao Escalar 2");
        imprimeMatriz(mt.multiplicar(ma, 2));
    }
    
    public static void main(String[] args){
        MatematicaMain main = new MatematicaMain();
    }
    
    private void imprimeMatriz(double m[][]){
        for(double[] x : m){
            for(double y: x){
                System.out.print(y + " ");
            }
            System.out.println();
        }
    }
}
