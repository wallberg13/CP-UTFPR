import java.util.Scanner;

public class Segundo{
  
  public static void main(String[] args){
  
    Scanner teclado = new Scanner(System.in);
    
    int i = teclado.nextInt(); //Lendo inteiro
    double r = teclado.nextDouble(); //Lendo real.
    String s = teclado.nextLine(); //Lendo cadeia de caracteres
    s = teclado.nextLine();
    
    System.out.println("Inteiro: "+ i + ",Real: " + r);
    System.out.println("Frase: " + s);
  }

}