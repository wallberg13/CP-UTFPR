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
public class Cliente {
    private IMatematica mat = null;

    public Cliente(String ip, int porta){
        this.mat = new ProxyMatematica(ip, porta);
        init();
    }

    public void init(){
        double a = 3.0;
        double b = 4.0;
        
        System.out.println("Operacao de Numeros Escalares");
        System.out.println("A: " + a + " B: " + b);
        System.out.println("A + B : " + mat.somar(a, b));
        System.out.println("A - B : " + mat.subtrair(a, b));
        System.out.println("A * B : " + mat.multiplicar(a, b));
        System.out.println("A / B : " + mat.dividir(a, b));
        
        try{
            System.out.println("A / B : " + mat.dividir(a, 0.0));                
        }catch(ArithmeticException ex){
            System.out.println("Deu divisão por zero");
        }
        
        System.out.println("Operacao de Matrizes");
        double ma[][] = {{10, 21, 2}, {1, 31, 1}, {3, 42, 2} };
        double mb[][] = {{1, 1, 2}, {1, 33, 1}, {32, 1,-1} };
        System.out.println("Matriz A");
        imprimeMatriz(ma);
        
        System.out.println("Matriz B");
        imprimeMatriz(mb);
        
        System.out.println("A + B");
        double c[][] = mat.somar(ma, mb);
        imprimeMatriz(c);
        
        System.out.println("A - B");
        c = mat.subtrair(ma, mb);
        imprimeMatriz(c);
        
        System.out.println("A * B");
        c = mat.subtrair(ma, mb);
        imprimeMatriz(c);
        
        System.out.println("A * 2");
        c = mat.multiplicar(ma, 2);
        imprimeMatriz(c);
    }
    
    public static void main(String[] args){
        Cliente c = new Cliente("127.0.0.1", 4321);
    }
    
    private void imprimeMatriz(double m[][]){
        for(double[] x : m){
            for(double y: x){
                System.out.print(y + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
