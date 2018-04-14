public class Circulo implements ObjetoGeometrico{
    
    private Ponto2D centro;
    private double raio;
    
    public Circulo(Ponto2D centro, double raio){
	this.centro = centro;
	this.raio = raio;
    }
    
    public Ponto2D centro(){
	return centro;
    }
    
    public double calculaArea(){
	return pi*raio*raio; //pi vezes o quadrado do raio
    }
    
    public double calculaPerimetro(){
	return 2.0*pi*raio; //dois vezes pi vezes o raio
    }
   
    public String toString(){
	return "Circulo com centro em "+centro+" e raio "+raio;
    }
}