public class Main{
    
    public static void main(String[] args){
	Rational rat = new Rational(20,24);
	
	rat.imprimeNumero();
	
	Rational rat1 = new Rational(1,2);
	
	Rational rat2 = new Rational();
	
	rat2.soma(rat,rat1);
	rat2.subtracao(rat,rat1);
	rat2.multiplicacao(rat,rat1);
	rat2.divisao(rat,rat1);
    }
}