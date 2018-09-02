import java.util.Scanner;

public class Q06{
  
  public static void main(String[] args){
    
    Scanner teclado = new Scanner(System.in);
    int num;
    
    do{
      System.out.print("Digite um numero: ");
      num = teclado.nextInt();
      if(num < 0 || num%2 == 0)
	System.out.println("Digite Novamente.");
    }while(num < 0 || num%2 == 0);
    
    int col = 2*num - 1; 
    int cont;
    
    cont = 0;
    for(int i = 0; i < num; i++){
      for(int j = 0; j < col; j++){
	if(j >= cont && j < col - cont)
	  System.out.print("1 ");
	else
	  System.out.print("0 ");
      }
      cont++;
      System.out.println();
    }
  }

}