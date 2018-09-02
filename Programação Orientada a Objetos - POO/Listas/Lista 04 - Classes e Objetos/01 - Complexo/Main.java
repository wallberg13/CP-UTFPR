public class Main{

  public static void main(String[] args){
    Complexo c1 = new Complexo(3,4);
    Complexo c2 = new Complexo(2);
    Complexo c3 = new Complexo(7,6);
    
    System.out.println("c1");
    c1.imprime();
    System.out.println("c2");
    c2.imprime();
    System.out.println("c3");
    c3.imprime();
    
    System.out.println("c1 = c1 + c3");
    c1.soma(c3);
    c1.imprime();
    
    System.out.println("c1 = c1 - c3");
    c1.subtrai(c3);
    c1.imprime();
    
  }
  
}