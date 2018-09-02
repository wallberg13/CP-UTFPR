public class Revista{
    private String nome;
    private int edicao;
    private int mes;
    private int ano;
    
    public Revista(String nome, int edicao, int mes, int ano){
	this.nome = nome;
	this.edicao = edicao;
	this.mes = mes;
	this.ano = ano;
    }
    
    public void imprime(){
	System.out.println("Nome: "+nome+" Edicao: "+edicao+" Mes: "+mes+" Ano: "+ano);
    }
}