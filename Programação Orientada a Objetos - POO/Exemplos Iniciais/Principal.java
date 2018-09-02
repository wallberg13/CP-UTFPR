public class Principal{
    private double valor;
    
    public void imprimirValor(){
	System.out.println(this.valor);
    }
    
    public void teste(){
	Bicicleta b = new Bicicleta();
	b.imprimirValor();
    }
    
    public static void main(String[] args){
	Principal p = new Principal();
	p.imprimirValor();
	p.teste();
    }
}