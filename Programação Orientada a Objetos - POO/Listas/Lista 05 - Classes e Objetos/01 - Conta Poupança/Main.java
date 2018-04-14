public class Main{
    
    public static void main(String[] args){
	ContaPoupanca p1 = new ContaPoupanca(2000.0f);
	ContaPoupanca p2 = new ContaPoupanca(3000.0f);
	
	p1.jurosMensais();
	p2.jurosMensais();
	
	p1.set_taxaJurosAnual(5.0f);
	p2.set_taxaJurosAnual(5.0f);
	
	p1.jurosMensais();
	p2.jurosMensais();
    }
}