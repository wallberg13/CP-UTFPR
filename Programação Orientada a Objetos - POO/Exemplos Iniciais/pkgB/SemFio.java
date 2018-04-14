package pkgB;
import pkgA.*;

public class SemFio extends Telefone{
    private float frequencia;
    
    public void modificador(){
	this.frequencia = 900;
	this.modelo = "ABC";
	this.peso = (float) 0.5000000;
	//this.marca = "GrandTel"; //Erro, não permitido
    }
    
}