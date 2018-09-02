public class Mamifero extends Animal{
    private String tempo_gestacao;
    
    public Mamifero(String tg,String nome,String especie,Boolean vertebrado){
	super(nome,especie,vertebrado);
	this.tempo_gestacao = tg;
    }
    
    public void imprime(){
	super.toString();
	System.out.println(tempo_gestacao);
    }
}