import java.io.Serializable;
import java.util.Scanner;

public class Estudante implements Serializable{
    
    /**
	Aluno com matricula = 0, é aluno que não existe na lista de alunos
    */
    
    private int matricula;
    private String nome;
    private Data dNasc;
    private Disciplina[] disciplinas;
    
    public Estudante(int matricula,String nome,Data dNasc){
	this.disciplinas = new Disciplina[3];
	this.matricula = matricula;
	this.nome = nome;
	this.dNasc = dNasc;
    }
        
    public void setNome(String nome){
	this.nome = nome;
    }
    
    public void setDNasc(Data dNasc){
	this.dNasc = dNasc;
    }
    
    public String getNome(){
	return nome;
    }
    
    public Data getDNasc(){
	return dNasc;
    }
    
    public int getMatricula(){
	return matricula;
    }

    public void imprimirResumido(){
	System.out.println("Matricula: "+matricula+ "\tNome: "+nome);
    }
    
    public void imprimirExpandido(){
	System.out.println("Matricula: "+matricula+"\tNome: "+nome);
	System.out.print("Data de nascimento: ");
	dNasc.imprimir();
	System.out.println("Disciplina: \t\t Conceito: ");
	for(int i = 0; i < disciplinas.length; i++){
	    if(disciplinas[0] == null){
		System.out.println("Sem disciplina Matriculada");
		break;
	    }
	    if(disciplinas[i] == null)
		break;
	    disciplinas[i].imprimir();
	}
    }
    
    private boolean verificaGradeCheia(){
	int i = 0,j = 0;
	for(;i<disciplinas.length;i++){
	    if(disciplinas[i] != null)
		j++;
	    else
		break;
	}
	if(j == disciplinas.length)
	    return true;
	else
	    return false;
    }
    
    private boolean verificaGradeVazia(){
	int i = 0, j = 0;
	for(;i < disciplinas.length; i++){
	    if(disciplinas[i] == null)
		j++;
	    else
		break;
	}
	if(j == disciplinas.length)
	    return true;
	else
	return false;
    }
    
    public void matriculaEmDisc(Scanner teclado){
	int i;
	
	if(verificaGradeCheia() == false){
	    System.out.print("Digite o nome da disciplina: ");
	    String nome = teclado.nextLine();
	    nome = teclado.nextLine();
	    
	    System.out.print("Digite o conceito da disciplina: ");
	    String conceito = teclado.nextLine();
	    
	    for(i = 0; i < disciplinas.length; i++){
		if(disciplinas[i] == null)
		    break;
	    }
	    disciplinas[i] = new Disciplina(nome,conceito);
	}else
	    System.out.println("A grade do aluno esta cheia.");
	    
	 System.out.println("\n\n");
    }
 }