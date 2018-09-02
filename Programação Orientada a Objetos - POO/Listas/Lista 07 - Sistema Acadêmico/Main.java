import java.util.Scanner;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;

public class Main{

    public static void main(String[] args){
	Scanner teclado = new Scanner(System.in);
	Estudante[] vetor = new Estudante[10];

	menuPrincipal(vetor,teclado);
    }

    private static void menuPrincipal(Estudante[] vetor, Scanner teclado){
	int resp = 1;
	File arq = new File("Estudante.dat");

	do{
	    System.out.println("01 - Incluir Aluno");
	    System.out.println("02 - Remover Aluno");
	    System.out.println("03 - Alterar dados do Aluno");
	    System.out.println("04 - Listar todos os Alunos");
	    System.out.println("05 - Listar dados de um Aluno");
	    System.out.println("06 - Gravar dados em arquivo");
	    System.out.println("07 - Ler dados de um arquivo");
	    System.out.println("00 - Sair");
	    System.out.print("Digite sua resposta: ");
	    resp = teclado.nextInt();
	    System.out.println("\n\n\n");

	    switch(resp){
		case 1:
		    incluirAluno(vetor,teclado);
		    break;
		case 2:
		    removerAluno(vetor,teclado);
		    break;
		case 3:
		    alterarDados(vetor,teclado);
		    break;
		case 4:
		    listarAlunos(vetor);
		    break;
		case 5:
		    imprimirAluno(vetor,teclado);
		    break;
		case 6:
		    gravarAlunoArquivo(vetor,arq);
		    break;
		case 7:
		    vetor = lerAlunoArquivo(arq);
		    break;
	    }

	}while(resp != 0);
	System.out.println("\n\n\n");
    }

    private static void incluirAluno(Estudante[] vetor,Scanner teclado){
	int i,dia,mes,ano;
	if(verificaCheio(vetor) == false){
	    System.out.print("Digite o nome do aluno: ");
	    String nome = teclado.nextLine();
	    nome = teclado.nextLine();
	    do{
		System.out.println("Digite a data de nascimento do aluno: ");
		System.out.print("Dia: "); dia = teclado.nextInt();
		System.out.print("Mês: "); mes = teclado.nextInt();
		System.out.print("Ano: "); ano = teclado.nextInt();
		if(Data.validaEntrada(dia,mes,ano) == false){
		    System.out.println("Digite novamente! Data Invalida\n");
		}

	    }while(Data.validaEntrada(dia,mes,ano) == false);

	    Data dNasc = new Data(dia,mes,ano);
	    for(i = 0; i < vetor.length; i++){
		if(vetor[i] == null || vetor[i].getMatricula() == 0)
		    break;
	    }
	    vetor[i] = new Estudante(i+1,nome,dNasc);
	}else
	    System.out.println("Limite de alunos exercido.");
	
	System.out.println("\n\n");
    }
    
    private static void removerAluno(Estudante[] vetor, Scanner teclado){
	if(verificaVazio(vetor) == false){
	    listarAlunos(vetor);
	    
	    System.out.print("Digite o numero da matricula do aluno que deseja remover: ");
	    int i = teclado.nextInt();
	    
	    if(vetor[i-1] != null){
		System.out.println("Aluno removido com sucesso. \n\n");
		vetor[i-1] = null;
	    }else
		System.out.println("Não foi possivel remover o aluno. \n\n");
	}else
	    System.out.println("Sem alunos para poder remover.");
    }
    
    /*
	Função que irá fazer a matricula de disciplinas de um aluno.
    */
    private static void alterarDados(Estudante[] vetor, Scanner teclado){
	if(verificaVazio(vetor) == false){
	    int resp = 1; int dia,mes,ano;
	    Data dNasc;
	    listarAlunos(vetor);
	    
	    System.out.print("Digite o numero de matricula do aluno: ");
	    int i = teclado.nextInt();
	    
	    if(vetor[i-1] == null){
		System.out.println("Não foi possivel alterar o aluno selecionado");
		return ;
	    }
	    
	    do{
		System.out.println("---Menu Alterar---");
		vetor[i-1].imprimirResumido();
		System.out.println("01 - Alterar Nome.");
		System.out.println("02 - Alterar data de nascimento.");
		System.out.println("03 - Matricular em disciplinas e adicionar conceito.");
		System.out.println("00 - Voltar ao menu anterior.");
		System.out.print("Digite a sua resposta: ");
		resp = teclado.nextInt();
		
		System.out.println("\n\n");
		switch(resp){
		    case 1:
			System.out.print("Digite o novo nome: ");
			String nome = teclado.nextLine();
			nome = teclado.nextLine();
			vetor[i-1].setNome(nome);
			break;
		    case 2:
			    do{
				System.out.println("Digite a nova data de nascimento do aluno: ");
				System.out.print("Dia: "); dia = teclado.nextInt(); 
				System.out.print("Mês: "); mes = teclado.nextInt(); 
				System.out.print("Ano: "); ano = teclado.nextInt();
				if(Data.validaEntrada(dia,mes,ano) == false){
				    System.out.println("Digite novamente! Data invalida \n");
				} 
			    }while(Data.validaEntrada(dia,mes,ano) == false);
			    dNasc = new Data(dia,mes,ano);
			vetor[i-1].setDNasc(dNasc);
			break;
		    case 3:
			vetor[i-1].matriculaEmDisc(teclado);
			break;
		}
	    }while(resp != 0);
	    
	}else
	    System.out.println("Sem estudante para alterar dados.");
	    
	System.out.println("\n\n");
    }
    
    private static void listarAlunos(Estudante[] vetor){
	
	if(verificaVazio(vetor) == false){
	    for(int i = 0; i < vetor.length; i++){
		if(vetor[i] != null)
		    vetor[i].imprimirResumido();
	    }
	}else
	    System.out.print("Nenhum estudante matriculado. \n");
	
	System.out.println("\n\n");
    }
    
    private static void imprimirAluno(Estudante[] vetor, Scanner teclado){
	
	if(verificaVazio(vetor) == false){
	    listarAlunos(vetor);
	    System.out.print("Digite a matricula do aluno desejado: ");
	    int matricula = teclado.nextInt();
	    
	    if(vetor[matricula-1] == null)
		System.out.println("Não foi possivel imprimir o aluno. \n");
	    else
		vetor[matricula - 1].imprimirExpandido();
	}else
	    System.out.print("Não foi possivel fazer tal operação pois não existe aluno matriculado \n");
	System.out.println("\n\n");
    }
    
    private static void gravarAlunoArquivo(Estudante[] vetor, File arq){
	try{
	    FileOutputStream fout = new FileOutputStream(arq);
	    ObjectOutputStream oos = new ObjectOutputStream(fout);
	    
	    //Gravando o vetor de estudantes no arquivo
	    oos.writeObject(vetor);
	    oos.flush();
	    oos.close();
	    fout.close();
	    System.out.println("Dados Gravados com sucesso. \n\n");
	}catch(Exception ex){
	    System.err.println("erro: "+ex.toString());
	}
    }
    
    private static Estudante[] lerAlunoArquivo(File arq){
	Estudante[] vetor = null;
	try{
	    FileInputStream fin = new FileInputStream(arq);
	    ObjectInputStream oin = new ObjectInputStream(fin);
	    
	    //Lendo os objetos de um arquivo e fazendo a coercao de tipos.
	    vetor = (Estudante[]) oin.readObject();
	    oin.close();
	    fin.close();
	    
	    for(Estudante p: vetor){
		if(p!= null)
		    p.imprimirResumido();
	    }
		
	    
	    System.out.println("Dados Lidos com sucesso. \n\n");
	}catch(Exception ex){
	    System.err.println("erro: "+ex.toString());
	}
	return vetor;
    }
    
    private static boolean verificaVazio(Estudante[] vetor){
	int j = 0;
	int i;
	for(i = 0; i < vetor.length; i++){
	    if(vetor[i] == null)
		j++;
	    else
		break;
	}
	if(j == vetor.length)
	    return true;
	else
	    return false;
    }
    
    private static boolean verificaCheio(Estudante[] vetor){
	int j = 0;
	int i;
	for(i = 0; i < vetor.length; i++){
	    if(vetor[i] == null)
		break;
	    else
		j++;
	}
	if(j == vetor.length)
	    return true;
	else
	    return false;
    }
}
