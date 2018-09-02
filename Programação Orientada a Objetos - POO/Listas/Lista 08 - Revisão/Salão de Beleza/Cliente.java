public class Cliente{
    private char sexo;
    private String nome;
    
    public Cliente(String nome, char sexo){
	this.nome = nome;
	this.sexo = sexo;
	this.ID = ID;
    }
    
    public void imprime(){
	System.out.println("Nome: "+nome+" Sexo: "+sexo);
    }
}