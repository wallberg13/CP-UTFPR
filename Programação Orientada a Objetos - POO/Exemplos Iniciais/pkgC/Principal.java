package pkgC;

import pkgA.*;
import pkgB.*;

public class Principal{
    public static void main(String[] args){
	Telefone t = new Telefone();
	
	SemFio sf = new SemFio();
	
	t.peso = (float) 0.6;
	t.modelo = "DEF";
	sf.modelo = "wqa";
	sf.modificador(); //através do método correto!
	//invocando um membro private
	//t.marca = "GT"; //Membro
    }
}