/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

/**
 *
 * @author sir-berg
 */
public class Requisicao {
    private String req = null;
    private String origem = null;
    
    public Requisicao(String requisicao, String origem){
        this.req = requisicao.trim();
        this.origem = origem;
    } 
    
    /** 
     * 
     * @param mat
     * @param sock
     * @param in
     * @return 
     */
    public Object trata_requisicao(IMatematica mat, Socket sock, ObjectInputStream in){
        Object ret = null;
        System.out.println("Requisição recebida: " + req + " Origem da Requisicao " + origem);
        String[] aux = req.split(" ");
        double a[][] = null, b[][] = null;
        
        switch(aux[0]){
            case("somar"):
                ret = mat.somar(Double.parseDouble(aux[1]), Double.parseDouble(aux[2]));
                break;
                
            case("subtrair"):
                ret = mat.subtrair(Double.parseDouble(aux[1]), Double.parseDouble(aux[2]));
                break;
                
            case("multiplicar"):
                ret = mat.multiplicar(Double.parseDouble(aux[1]), Double.parseDouble(aux[2]));
                break;
                
            case("dividir"):
                try{
                    ret = mat.dividir(Double.parseDouble(aux[1]), Double.parseDouble(aux[2]));
                } catch(ArithmeticException ex){
                    ret = "arithmeticException";
                }
                break;
                
            case("somarM"):
                try{
                    a = (double [][]) in.readObject();
                    b = (double [][]) in.readObject();
                } catch(IOException ex){
                    System.out.println("Erro desconhecido de IO " + ex.getMessage());
                } catch (ClassNotFoundException ex) {
                    System.out.println("Classe desconhecida " + ex.getMessage());
                } 
                                
                try{
                    ret = mat.somar(a, b);
                } catch(MatrizIncompativelException ex){
                    ret = "matrizException";
                }
                break;
                
            case("subtrairM"):
                try{
                    a = (double [][]) in.readObject();

                } catch(IOException ex){
                    System.out.println("Erro desconhecido de IO " + ex.getMessage());
                } catch (ClassNotFoundException ex) {
                    System.out.println("Classe desconhecida " + ex.getMessage());
                } 
                
                try{
                    b = (double [][]) in.readObject();
                } catch(IOException ex){
                    System.out.println("Erro desconhecido de IO " + ex.getMessage());
                } catch (ClassNotFoundException ex) {
                    System.out.println("Classe desconhecida " + ex.getMessage());
                }
                
                try{
                    ret = mat.subtrair(a, b);
                } catch(MatrizIncompativelException ex){
                    ret = "matrizException";
                }  
                break;
            
            case("multiplicarM"):
                try{
                    a = (double [][]) in.readObject();

                } catch(IOException ex){
                    System.out.println("Erro desconhecido de IO " + ex.getMessage());
                } catch (ClassNotFoundException ex) {
                    System.out.println("Classe desconhecida " + ex.getMessage());
                } 
                
                try{
                    b = (double [][]) in.readObject();
                } catch(IOException ex){
                    System.out.println("Erro desconhecido de IO " + ex.getMessage());
                } catch (ClassNotFoundException ex) {
                    System.out.println("Classe desconhecida " + ex.getMessage());
                }
                
                try{
                    ret = mat.multiplicar(a, b);
                } catch(MatrizIncompativelException ex){
                    ret = "matrizException";
                }  
                break;
            
            case("multiplicarE"):
                double bE = 0.0;
                
                
                try{
                    a = (double [][]) in.readObject();
                } catch(IOException ex){
                    System.out.println("Erro desconhecido de IO " + ex.getMessage());
                } catch (ClassNotFoundException ex) {
                    System.out.println("Classe desconhecida " + ex.getMessage());
                } 
                
                try{
                    bE = (double) in.readObject();
                } catch(IOException ex){
                    System.out.println("Erro desconhecido de IO " + ex.getMessage());
                } catch (ClassNotFoundException ex) {
                    System.out.println("Classe desconhecida " + ex.getMessage());
                }
                        ret = mat.multiplicar(a, bE);
                break;
                
            default: 
                System.out.println("Funcao desconhecida");
                ret = "Funcao Desconhecida";
        }
        
        return ret;
    }
    
    private void imprimeMatriz(double m[][]){
        System.out.println("Imprimindo Matriz");
        for(double[] x : m){
            for(double y: x){
                System.out.print(y + " ");
            }
            System.out.println();
        }
    }
}
