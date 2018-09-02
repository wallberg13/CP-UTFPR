public class Lampada{
  
  private double preco;
  private int potencia;
  private String marca;
  private String cor;
  private int intensidade;
  private boolean estado;
  
  public Lampada(int potencia,double preco,String marca,String cor){
    this.preco = preco;
    this.potencia = potencia;
    this.marca = marca;
    this.cor = cor;
    this.intensidade = 0;
    this.estado = false;
  }
  
  public void ligar(){
    estado = true;
    intensidade = 100;
  }
  
  public void desligar(){
    estado = false;
    intensidade = 0;
  }
  
  public void meiaLuz(){
    estado = true;
    intensidade = 50;
  }
  
  /* Gets e Sets. */
  
  public double get_preco(){
    return preco;
  }
  
  public int get_potencia(){
    return potencia;
  }
  
  public String get_marca(){
    return marca;
  }
  
  public String get_cor(){
    return cor;
  }
  
  public int get_intensidade(){
    return intensidade;
  }
  
  public boolean get_estado(){
    return estado;
  }
  
  public void set_cor(String cor){
    this.cor = cor;
  }
  
  public void set_preco(double preco){
    this.preco = preco;
  }
}