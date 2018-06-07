/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author sir-berg
 */
public interface IMatematica extends Remote{
    
    /**
     * Função para somar dois números double.
     *      a + b
     * @param a
     * @param b
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public double somar(double a, double b) throws RemoteException;
    
    /**
     * Função para subtrair dois números double.
     * 
     *      a - b
     * @param a
     * @param b
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public double subtrair(double a, double b) throws RemoteException;
    
    /**
     * Função para multiplicar dois números double.
     *      a*b
     * @param a
     * @param b
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public double multiplicar(double a, double b) throws RemoteException;
    
    /**
     * Função para dividir dois numeros double sendo que divisão por zero
     * gera exception.
     * 
     *      a/b
     * @param a
     * @param b
     * @return
     * @throws ArithmeticException 
     * @throws java.rmi.RemoteException 
     */
    public double dividir(double a, double b) throws RemoteException;
    
    
    // Operações com matrizes
    
    /**
     * Função para soma de matrizes.
     * Caso as matrizes sejam incompativeis para soma, gera-se uma Exception.
     *      A + B
     * @param a
     * @param b
     * @return 
     * @throws exercicio03.MatrizIncompativelException
     * @throws java.rmi.RemoteException
     */
    public double[][] somar(double a[][], double b[][]) throws RemoteException;
    
    /**
     * Função que subtrai duas matrizes.
     * Caso as matrizes sejam incompativeis para subtracao, gera-se uma Exception.
     *      A - B
     * @param a
     * @param b
     * @return
     * @throws MatrizIncompativelException 
     * @throws java.rmi.RemoteException 
     */
    public double[][] subtrair(double a[][], double b[][]) throws RemoteException;
    
    /**
     * Multiplicao de matrizes.
     * Gera exception caso o numero de colunas da matriz A for incompativel com o numero de 
     * linhas da matriz B.
     *      A.B
     * @param a
     * @param b
     * @return
     * @throws MatrizIncompativelException 
     * @throws java.rmi.RemoteException 
     */
    public double[][] multiplicar(double a[][], double b[][]) throws RemoteException;
    
    /**
     * Multiplicacao de matriz por numero escalar.
     *      b*a, onde A é uma matriz e o B um numero qualquer.
     * @param a
     * @param b
     * @return 
     * @throws java.rmi.RemoteException 
     */
    public double[][] multiplicar(double a[][], double b) throws RemoteException;
    
}