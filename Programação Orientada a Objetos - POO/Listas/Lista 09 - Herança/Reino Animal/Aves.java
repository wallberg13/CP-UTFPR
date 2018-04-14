public class Aves extends Animal{
    private String cor; //Das penas
    private String formato_bico;
    private Boolean voa;
    
    public Aves(String cor,String f_b,Boolean voa,String nom, String esp,Boolean v){
	super(nom,esp,v);
	this.cor = cor;
	this.formato_bico = f_b;
	this.voa = voa;
    }
    
    public void imprime(){
	super.imprime();
	if(voa == true)
	    System.out.println(cor+" "+formato_bico+" e voa. ");
	else
	    System.out.println(cor+" "+formato_bico+" e não voa. ");
    }
    
    public void Gralhar(){
	System.out.println("Glu glu glu glu\n");
    }
}