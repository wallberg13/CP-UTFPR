/**
Leia um numero do teclado e imprima todos os numeros ımpares de 0 ate o numero lido;
*/
import java.util.Scanner;

public class Q01{
  
  public static void main(String[] args){
    Scanner teclado = new Scanner(System.in);
    
    System.out.print("Digite um valor: ");
    int num = teclado.nextInt();
    
    for(int i = 0; i < num; i++){
      if(i%2 == 1)
	System.out.println(i);
    }
  }

}