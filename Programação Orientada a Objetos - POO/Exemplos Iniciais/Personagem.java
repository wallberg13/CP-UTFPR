public abstract class Personagem{
    private int id;
    private String nome;
    
    public Personagem(int i, String n){
	this.id = i;
	this.nome = n;
    }
    
    public String obterNome(){
	return this.nome;
    }
    
    public void imprimirDados(){
	System.out.println("Id: " + this.id + ", Nome: " + this.nome);
    }
    
    //metodo abstrato que deve ser implementado na subclasse
    public abstract void atacar(float intensidade);
}