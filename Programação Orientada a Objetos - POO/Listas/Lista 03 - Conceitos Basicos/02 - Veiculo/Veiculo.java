public class Veiculo{
  
  private String nome;
  private int velocidade;
  private int vel_max;
  private String tipo;
  private int num_rodas;
  private String marca;
  private int num_passageiros;
  private int max_passageiros;
  
  public Veiculo(String nome, int vel_max, String tipo, int num_rodas,int max_passageiros){
    this.nome = nome;
    this.vel_max = vel_max;
    this.tipo = tipo;
    this.num_rodas = num_rodas;
    this.max_passageiros = max_passageiros;
    velocidade = 0;
    num_passageiros = 1;
  }
  
  
  public void acelerar(int velocidade){
    if(this.velocidade + velocidade <= vel_max)
      this.velocidade += velocidade;
    else
      System.out.println("Não foi possivel acelerar.");
  }
  
  public void desacelerar(int velocidade){
    if(this.velocidade - velocidade >= 0)
      this.velocidade -= velocidade;
    else
      System.out.println("Não foi possivel freiar o veiculo.");
  }
  
  public void embarcar(){
    if(num_passageiros + 1 <= max_passageiros)
      num_passageiros++;
    else
      System.out.println("Veiculo Cheio.");
  }
  
  public void desembarcar(){
    if(num_passageiros - 1 >= 1)
      num_passageiros--;
    else
      System.out.println("O Veiculo tem que ter no minimo o motorista.");
  }
  
  public void dadosVeiculo(){
    System.out.println("Nome do Veiculo: "+ nome);
    System.out.println("Velocidade Máxima: "+ vel_max);
    System.out.println("Tipo: "+tipo);
    System.out.println("Numero de rodas: "+num_rodas);
    System.out.println("Maximo de passageiros: "+max_passageiros);
    System.out.println("Velocidade atual: "+velocidade);
    System.out.println("Numero de Passageiros: "+num_passageiros);
    
    System.out.println("\n");
  }
}