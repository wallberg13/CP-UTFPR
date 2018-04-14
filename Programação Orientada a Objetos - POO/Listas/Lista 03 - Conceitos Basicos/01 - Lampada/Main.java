import java.util.Scanner;

public class Main{
  
  public static void main(String[] args){
    Scanner teclado = new Scanner(System.in);
    
    System.out.println("Descrição da lampada: ");
    System.out.print("Digite a potencia: ");
    int potencia = teclado.nextInt();
    
    System.out.print("Digite o preço: ");
    double preco = teclado.nextDouble();
    
    teclado.nextLine(); //Limpar Buffer do teclado.
    
    System.out.print("Digite a marca: ");
    String marca = teclado.nextLine();
    
    System.out.print("Digite a cor: ");
    String cor = teclado.nextLine();
    
    Lampada lamp = new Lampada(potencia,preco,marca,cor);
    
    int resp = 0;
    do{
      System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      System.out.println("Estado da Lampada: ");
      System.out.println("Potencia: " + lamp.get_potencia() + "\nPreço: "+ lamp.get_preco() +
      "\nMarca: "+ lamp.get_marca() + "\nCor: " + lamp.get_cor() + "\nIntensidade: " + lamp.get_intensidade());
      if(lamp.get_estado())
	System.out.println("Estado: Ligado.");
      else
	System.out.println("Estado: Desligado.");
	
      System.out.println("/*** Menu da Lampada ***\\");
      System.out.println("01 - Mudar de cor. ");
      System.out.println("02 - Ligar. ");
      System.out.println("03 - Desligar.");
      System.out.println("04 - Meia Luz.");
      System.out.println("00 - Sair.");
      System.out.print("Resposta: ");
      resp = teclado.nextInt();
      
      switch(resp){
	case 1:
	  teclado.nextLine();
	  System.out.print("Digite o nome da cor: ");
	  cor = teclado.nextLine();
	  lamp.set_cor(cor);
	  break;
	case 2:
	  lamp.ligar();
	  break;
	case 3:
	  lamp.desligar();
	  break;
	case 4:
	  lamp.meiaLuz();
	  break;
      }
    }while(resp != 0);
  
  }
}