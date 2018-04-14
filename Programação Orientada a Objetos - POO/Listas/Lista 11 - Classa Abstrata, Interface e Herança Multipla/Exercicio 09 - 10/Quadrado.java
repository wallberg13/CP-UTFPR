public class Quadrado implements ObjetoGeometrico{
    private Ponto2D cp;
    private int lado;
    
    public Quadrado(Ponto2D cp,int lado){
	this.cp = cp;
	this.lado = lado;
    }
     
    public Ponto2D centro(){
	double cx = (cp.getX() + lado)/2;
	double cy = (cp.getY() + lado)/2;
	return new Ponto2D(cx,cy);
    }
    
    public double calculaArea(){
	return this.lado*this.lado;
    }
    
    public double calculaPerimetro(){
	return 4*this.lado;
    }
    
    public String toString(){
	return "Quadrado com "+ lado +" de lado.";
    }
}