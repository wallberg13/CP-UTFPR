/**
  Leia um numero do teclado e informe se este numero e primo ou nao
*/
import java.util.Scanner;

public class Q02{
  
  public static void main(String[] args){
    Scanner teclado = new Scanner(System.in);
    
    System.out.print("Digite um valor: ");
    int num = teclado.nextInt();
    
    int j = 0;
    for(int i = 1;i<=num;i++){
      if(num%i == 0)
	j++;
      if(j>2)
	break;
    }
    if(j>2)
      System.out.println("Este numero "+num+ " não é primo. ");
    else
      System.out.println("Este numero "+num+ " é primo. ");
    
  }

}