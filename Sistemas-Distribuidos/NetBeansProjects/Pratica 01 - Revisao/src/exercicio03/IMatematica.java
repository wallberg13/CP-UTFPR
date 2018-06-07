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
public interface IMatematica {
    
    /**
     * Função para somar dois números double.
     *      a + b
     * @param a
     * @param b
     * @return 
     */
    public double somar(double a, double b);
    
    /**
     * Função para subtrair dois números double.
     * 
     *      a - b
     * @param a
     * @param b
     * @return 
     */
    public double subtrair(double a, double b);
    
    /**
     * Função para multiplicar dois números double.
     *      a*b
     * @param a
     * @param b
     * @return 
     */
    public double multiplicar(double a, double b);
    
    /**
     * Função para dividir dois numeros double sendo que divisão por zero
     * gera exception.
     * 
     *      a/b
     * @param a
     * @param b
     * @return
     * @throws ArithmeticException 
     */
    public double dividir(double a, double b) throws ArithmeticException;
    
    
    // Operações com matrizes
    
    /**
     * Função para soma de matrizes.
     * Caso as matrizes sejam incompativeis para soma, gera-se uma Exception.
     *      A + B
     * @param a
     * @param b
     * @return 
     * @throws exercicio03.MatrizIncompativelException
     */
    public double[][] somar(double a[][], double b[][]) throws MatrizIncompativelException;
    
    /**
     * Função que subtrai duas matrizes.
     * Caso as matrizes sejam incompativeis para subtracao, gera-se uma Exception.
     *      A - B
     * @param a
     * @param b
     * @return
     * @throws MatrizIncompativelException 
     */
    public double[][] subtrair(double a[][], double b[][]) throws MatrizIncompativelException;
    
    /**
     * Multiplicao de matrizes.
     * Gera exception caso o numero de colunas da matriz A for incompativel com o numero de 
     * linhas da matriz B.
     *      A.B
     * @param a
     * @param b
     * @return
     * @throws MatrizIncompativelException 
     */
    public double[][] multiplicar(double a[][], double b[][]) throws MatrizIncompativelException;
    
    /**
     * Multiplicacao de matriz por numero escalar.
     *      b*a, onde A é uma matriz e o B um numero qualquer.
     * @param a
     * @param b
     * @return 
     */
    public double[][] multiplicar(double a[][], double b);
    
}