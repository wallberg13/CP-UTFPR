import java.util.Scanner;
import java.io.IOException;

public class Salao{
    Cliente[] cliente;
    private static int i = 0;
    
    public Salao(){
	cliente = new Cliente[10];
    }
    
    public void addCliente() throws IOException{
	Scanner teclado = new Scanner(System.in);
	int i;
	
	if(i<=10){
	    System.out.println("Digite o nome do cliente: ");
	    String nome = teclado.nextLine();
	    nome = teclado.nextLine(); //Duas vezes para "limpar" o buffer
	    char sexo;
	    
	    do{
		System.out.println("Digite o sexo: ");
		sexo = (char)System.in.read();
	    while(sexo != 'm' && sexo != 'f');
	    
	    for(i = 0; i < cliente.length; i++){
		if(cliente[i] == null)
		    break;
	    }
	    this.i = this.i + 1;
	    cliente[i] = new Cliente(nome,sexo);
	}else{
	    System.out.println("Salão cheio");
	}
    }
    
    public void atenderCliente(){
	if(i>0){
	    System.out.println("O cliente da vez: ");
	    cliente[0].imprime();
	    
	    for(int j = 0; j<cliente.length - 1; j++){
		cliente[j] = cliente[j+1];
	    }
	    cliente[i] = null;
	}else{
	    System.out.println("Sem cliente para atender.");
	}
    }
}