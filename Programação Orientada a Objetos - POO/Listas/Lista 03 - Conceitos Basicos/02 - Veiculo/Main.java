public class Main{

  public static void main(String[] args){
    Veiculo vei = new Veiculo("Lamborghini",350,"Terrestre",4,2);
    
    vei.dadosVeiculo();
    
    vei.acelerar(50);
    vei.embarcar();
    vei.embarcar();
    
    vei.dadosVeiculo();
    
    vei.acelerar(350);
    vei.acelerar(300);
    
    vei.dadosVeiculo();
    
    vei.desacelerar(200);
    
    vei.dadosVeiculo();
  }
  
}