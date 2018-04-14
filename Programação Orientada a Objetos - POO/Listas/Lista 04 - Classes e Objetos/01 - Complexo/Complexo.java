public class Complexo{

  private int a; //Parte Real
  private int b; //Parte Imaginaria
  
  public Complexo(int a,int b){
    this.a = a;
    this.b = b;
  }
  
  public Complexo(int a){
    this.a = a;
    this.b = 0;
  }

  public void soma(Complexo n2){
    this.a += n2.a;
    this.b += n2.b;
  }
  
  public void subtrai(Complexo n2){
    this.a -= n2.a;
    this.b -= n2.b;
  }
  
  public void imprime(){
    if(b != 0)
      System.out.println("O número é: "+ a + " + "+ b +"i");
    else
      System.out.println("O número é: " + a);
    
  }
}