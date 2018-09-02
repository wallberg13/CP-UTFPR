public class Peixe extends Animal,Mamifero{
    private String tipo;
    private double tamanho;
    
    public Peixe(String tip,double tam,String nom, String esp, Boolean v){
	super(nom,esp,v);
	this.tipo = tip;
	this.tamanho = tam;
    }
    
    public void imprime(){
	super.imprime();
	System.out.println(tipo+" "+tamanho);
    }
    
    public void nada(){
	System.out.println("zzzzzzzZZzzzZzZzZZZZZZZzzzZZzZZzz\n");
    }
}