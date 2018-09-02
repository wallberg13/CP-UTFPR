import java.lang.Math;

public class Retangulo implements ObjetoGeometrico{
    
    private Ponto2D primeiroCanto, segundoCanto;
    
    Retangulo(Ponto2D pc,Ponto2D sc){
	primeiroCanto = pc;
	segundoCanto = sc;
    }
    
    public Ponto2D centro(){
	double coordX = (primeiroCanto.getX() + segundoCanto.getX())/2.0;
	double coordY = (primeiroCanto.getY() + segundoCanto.getY())/2.0;
	return new Ponto2D(coordX,coordY);
    }
    
    public double calculaArea(){
	double ladoX = Math.abs(primeiroCanto.getX()-segundoCanto.getX());
	double ladoY = Math.abs(primeiroCanto.getY()-segundoCanto.getY());
	return ladoX*ladoY;
    }
}