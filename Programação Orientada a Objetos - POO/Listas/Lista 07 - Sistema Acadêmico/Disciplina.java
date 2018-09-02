import java.io.Serializable;

public class Disciplina implements Serializable{
    private String nome;
    private String conceito;
    
    public Disciplina(String nome,String conceito){
	this.nome = nome;
	this.conceito = conceito;
    }
    
    public void imprimir(){
	System.out.println(nome+"\t\t "+conceito);
    }
}