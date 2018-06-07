/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author sir-berg
 */
public class Cliente {
    IMatematica mt;
    
    public Cliente(String ip, int porta){   
        try{
            Registry registro = LocateRegistry.getRegistry(ip, porta);
            mt = (IMatematica) registro.lookup("Mati");
        } catch (NotBoundException ex){
            System.out.println("Objeto nao encontrado: " + ex.getMessage());
        } catch (RemoteException ex) {
            System.out.println("Erro do alem: " + ex.getMessage());
        }
        
        init();
    }
    
    public void init(){
        
        double a = 6.0;
        double b = 2.0;
        
        double ma[][] = {{1.0, 0.0, 2.0}, {-1.0, 3.0, 1.0}};
        double mb[][] = {{1.0, 0.0, 2.0}, {-1.0, 3.0, 1.0}};
        double mc[][] = {{3.0, 1.0}, {2.0, 1.0}, {1.0, 0.0}};
        double mx[][] = {};

        double md[][] = {{1.0, 0.0, 2.0, 0.0}, {-1.0, 3.0, 1.0, 2.0}};
        try{
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
            
        } catch (RemoteException ex) {
            System.out.println("cabeluda: " + ex.getMessage());
        }
        
    }
    
    public static void main(String[] args){
        Cliente cli = new Cliente("127.0.0.1", 4444);
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
