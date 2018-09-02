public class Arqueiro extends Personagem{
    private int habilidade;
    
    public Arqueiro(int i, String n, int h){
	super(i,n);
	this.habilidade = h;
    }
    
    public void imprimirDados(){
	super.imprimirDados();
	System.out.println("Habilidade: "+ this.habilidade);
    }
    
    public void atacar(float intensidade){
	System.out.println("Disparando flechas com a intensidade: " + intensidade);
   }
}