/**
Leia um numero do teclado e informe se este e um numero perfeito. Numero
perfeito  ́e um numero inteiro cuja soma de todos os seus divisores positivos,
excluindo ele proprio, e igual ao proprio numero
*/
import java.util.Scanner;

public class Q03{
  
  public static void main(String[] args){
    Scanner teclado = new Scanner(System.in);
    
    System.out.print("Digite um numero: ");
    int num = teclado.nextInt();
    
    int soma = 0;
    
    for(int i = 1; i < num; i++){
      if(num%i == 0){
	soma = i + soma;
      }
    }
    
    if(soma == num)
      System.out.println("Esté é um numero perfeito.");
    else
      System.out.println("Esté numero não é perfeito.");
  }
  
}