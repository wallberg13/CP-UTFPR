public class Animal{

    private String nome;
    private String especie;
    private Boolean vertebrado;
    
    public Animal(String nome, String especie,Boolean vertebrado){
	this.nome = nome;
	this.especie = especie;
	this.vertebrado = vertebrado;
    }
    
    public void imprime(){
	if(this.vertebrado == true)
	    System.out.println(this.nome+" "+this.especie+" é vertebrado. ");
	else
	    System.out.println(this.nome+" "+this.especie+" é invertebrado. ");
    }
    
}