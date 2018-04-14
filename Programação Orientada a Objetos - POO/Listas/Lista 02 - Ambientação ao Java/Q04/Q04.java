/**Leia um numero do teclado e informe todos os numeros 
primos entre 0 e este numero; */

import java.util.Scanner;

public class Q04{

  public static void main(String[] args){
    Scanner teclado = new Scanner(System.in);
    int num,j; //Num = Numero Lido, J = variavel de controle
    
    System.out.print("Digite um numero: ");
    num = teclado.nextInt();
    
    for(int i = 1; i <= num; i++){
      j = 0;
      for(int k = 1; k <= i; k++){
	if(i%k == 0)
	  j++;
	if(j>2)
	  break;
      }
      if(j==2)
	System.out.println(i);
    }
  }
}