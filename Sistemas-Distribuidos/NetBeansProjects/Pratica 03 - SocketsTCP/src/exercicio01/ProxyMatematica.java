/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

/**
 *
 * @author sir-berg
 */
public class ProxyMatematica implements IMatematica{
	private String ip;
	private int porta;
	private Socket sock;

	private ObjectInputStream inO = null;
	private ObjectOutputStream outO = null;

	public ProxyMatematica(String ip, int porta){
		this.ip = ip;
		this.porta = porta;

		try{
			sock = new Socket(ip, porta);

			//this.outS = new DataOutputStream(sock.getOutputStream());
			this.inO = new ObjectInputStream(sock.getInputStream());
			this.outO = new ObjectOutputStream(sock.getOutputStream());
		}catch(IOException ex){
			System.out.println("Erro desconhecido de IO " + ex.getMessage());
		}
	}

	@Override
	public double somar(double a, double b) {
		double ret = 0.0;

		try{
			outO.writeObject("somar " + String.valueOf(a) + " " + String.valueOf(b));
			ret = (double) inO.readObject();
		} catch(IOException ex){
			System.out.println("Erro desconhecido de IO + " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Classe desconhecida " + ex.getMessage());
		}

		return ret;
	}

	@Override
	public double subtrair(double a, double b) {
		double ret = 0.0;

		try{
			outO.writeObject("subtrair " + a + " " + b);
			ret = (double) inO.readObject();
		} catch(IOException ex){
			System.out.println("Erro desconhecido de IO + " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Classe desconhecida " + ex.getMessage());
		}
		return ret;
	}

	@Override
	public double multiplicar(double a, double b) {
		double ret = 0.0;
		
		try{
			outO.writeObject("multiplicar " + a + " " + b);
			ret = (double) inO.readObject();
		} catch(IOException ex){
			System.out.println("Erro desconhecido de IO + " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Classe desconhecida " + ex.getMessage());
		}
		
		return ret;
	}

	@Override
	public double dividir(double a, double b) throws ArithmeticException {
		double ret = 0.0;
		Object aux = null;
		
		try{
			outO.writeObject("dividir " + a + " " + b);
			aux = inO.readObject();
		} catch(IOException ex){
			System.out.println("Erro desconhecido de IO " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Erro desconhecido de IO " + ex.getMessage());
		}
		
		if(!String.valueOf(aux).equals("arithmeticException")){
			ret = (double) aux;
		}else{
			throw new ArithmeticException("Parametro Invalido");
		}
		
		return ret;
	}

	@Override
	public double[][] somar(double[][] a, double[][] b) throws MatrizIncompativelException {
		double ret[][] = null;
		Object aux = null;
		try{
			//Requisicao
			outO.writeObject("somarM");
			outO.writeObject(a);
			outO.flush();
			outO.writeObject(b);
			//Resposta
			aux = inO.readObject();
		}catch(IOException ex){
			System.out.println("Erro desconhecido de IO " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Classe desconhecida " + ex.getMessage());
		}
		
		if(String.valueOf(aux).equals("matrizException")) {
			throw new MatrizIncompativelException(1);
		} else {
			ret = (double [][]) aux;
		}
		return ret;
	}

	@Override
	public double[][] subtrair(double[][] a, double[][] b) throws MatrizIncompativelException {
		double ret[][] = null;
		Object aux = null;

		try{
			//Requisicao
			outO.writeObject("subtrairM");
			outO.writeObject(a);
			outO.writeObject(b);
			//Resposta
			aux = inO.readObject();
		}catch(IOException ex){
			System.out.println("Erro desconhecido de IO " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Classe desconhecida " + ex.getMessage());
		}

		if(String.valueOf(aux).equals("matrizException")){
			throw new MatrizIncompativelException(1);
		} else {
			ret = (double [][]) aux;
		}

		return ret;
	}

	@Override
	public double[][] multiplicar(double[][] a, double[][] b) throws MatrizIncompativelException {
		double ret[][] = null;
		Object aux = null;

		try{
			// Requisicao
			outO.writeObject("multiplicarM");
			outO.writeObject(a);
			outO.writeObject(b);
			//Resposta
			aux = inO.readObject();
		}catch(IOException ex){
			System.out.println("Erro desconhecido de IO " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Classe desconhecida " + ex.getMessage());
		}

		if(String.valueOf(aux).equals("matrizException")){
			throw new MatrizIncompativelException(1);
		} else {
			ret = (double [][]) aux;
		}

		return ret;
	}

	@Override
	public double[][] multiplicar(double[][] a, double b) {
		double ret[][] = null;
		Object aux = null;		

		try{
			// Requisicao
			outO.writeObject("multiplicarE");
			outO.writeObject(a);
			outO.writeObject(b);
			//Resposta
			aux = inO.readObject();
		}catch(IOException ex){
			System.out.println("Erro desconhecido de IO " + ex.getMessage());
		} catch (ClassNotFoundException ex) {
			System.out.println("Classe desconhecida " + ex.getMessage());
		}

		if(String.valueOf(aux).equals("matrizException")){
			throw new MatrizIncompativelException(1);
		} else {
			ret = (double [][]) aux;
		}

		return ret;
	}

}
