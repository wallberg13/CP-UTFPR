import java.io.File;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;

public class Main{
    public static void main(String[] args){
	Pessoa[] agenda = new Pessoa[3];
	
	//Criando 2 objetos da classe Pessoa
	agenda[0] = new Pessoa("Jão da Tapioca","123456");
	agenda[1] = new Pessoa("Maria das Doida","456456");
	agenda[2] = new Pessoa("Jusefa","9887654");
	
	File arquivo = new File("agenda.dat");
	
	//Exportando arquivo
	try{
	    FileOutputStream fout = new FileOutputStream(arquivo);
	    ObjectOutputStream oos = new ObjectOutputStream(fout);
	    
	    //Gravando o vetor de pessoas no arquivo;
	    oos.writeObject(agenda);
	    
	    oos.flush();
	    oos.close();
	    fout.close();
	}catch(Exception ex){
	    System.err.println("erro: " + ex.toString());
	}
	

	//Leitura de dados em arquivo
	try{
	    FileInputStream fin = new FileInputStream(arquivo);
	    ObjectInputStream oin = new ObjectInputStream(fin);
	    
	    //Lendo os objetos de um arquivo e fazendo a coercao de tipos
	    Pessoa[] agendaArq = (Pessoa[]) oin.readObject();
	    oin.close();
	    fin.close();
	    
	    //Uma forma de diferente do for para percorrer vetores
	    for(Pessoa p: agendaArq)
		p.imprimirDados();
	}catch(Exception ex){
	    System.err.println("Erro: " + ex.toString());
	}
    }
}
