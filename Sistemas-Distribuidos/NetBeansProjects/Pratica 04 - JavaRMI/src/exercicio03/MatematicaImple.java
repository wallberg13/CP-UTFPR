/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

/**
 *
 * @author sir-berg
 */
public class MatematicaImple extends UnicastRemoteObject implements IMatematica{

    public MatematicaImple() throws RemoteException{
        super();
    }
    
    @Override
    public double somar(double a, double b) throws RemoteException{
        return a + b;
    }

    @Override
    public double subtrair(double a, double b) throws RemoteException{
        return a - b;
    }

    @Override
    public double multiplicar(double a, double b) throws RemoteException{
        return a*b;
    }

    @Override
    public double dividir(double a, double b) throws RemoteException {
       if(b == 0)
           throw new ArithmeticException("Parametro Invalido");
       else{
           return a/b;
       }
    }

    @Override
    public double[][] somar(double[][] a, double[][] b) throws RemoteException {
        
        double[][] retorno;
        
        if(a.length == 0 || b.length == 0 || a.length != b.length || a[0].length != b[0].length){
            throw new MatrizIncompativelException(1);
        }else{
            int xa = a[0].length, ya = a.length;
            int xb = b[0].length, yb = b.length;
            retorno = new double[ya][xa];
            for(int i = 0; i < ya; i++){
                for(int j = 0; j < xa; j++){
                    retorno[i][j] = a[i][j] + b[i][j];
                }
            }     
        }
        return retorno;
    }

    @Override
    public double[][] subtrair(double[][] a, double[][] b) throws RemoteException{
        double[][] retorno;
        
        if(a.length == 0 || b.length == 0 || a.length != b.length || a[0].length != b[0].length){
            throw new MatrizIncompativelException(1);
        }else{
            int xa = a[0].length, ya = a.length;
            int xb = b[0].length, yb = b.length;
            retorno = new double[ya][xa];
            for(int i = 0; i < ya; i++){
                for(int j = 0; j < xa; j++){
                    retorno[i][j] = a[i][j] - b[i][j];
                }
            }     
        }
        return retorno;
    }

    @Override
    public double[][] multiplicar(double[][] a, double[][] b) throws RemoteException {
        double[][] retorno;
        
        if(a.length == 0 || b.length == 0 || a.length != b[0].length){
            throw new MatrizIncompativelException(2);
        }else{
            int xa = a[0].length, ya = a.length;
            int xb = b[0].length, yb = b.length;
            retorno = new double[ya][xb];
            for(int i = 0; i < ya; i++){
                for(int j = 0; j < xb; j++){
                    retorno[i][j] = 0;
                    for(int h = 0; h < xa; h++){
                        retorno[i][j] += a[i][h]*b[h][j];
                    }
                }
            }
        }
        return retorno;
    }

    @Override
    public double[][] multiplicar(double[][] a, double b) throws RemoteException{
        int xa = a[0].length, ya = a.length;
        double[][] retorno = new double[ya][xa];
        
        for(int i = 0; i < ya; i++){
            for(int j = 0; j < xa; j++){
                retorno[i][j] = b*a[i][j];
            }
        }
        
        return retorno;
    }
    
}
