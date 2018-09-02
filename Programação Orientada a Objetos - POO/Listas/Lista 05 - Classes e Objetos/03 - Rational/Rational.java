public class Rational{

    private int numerador;
    private int denominador;
    
    public Rational(){
	numerador = 1;
	denominador = 2;
    }
    
    public Rational(int numerador,int denominador){
	this.numerador = numerador;
	this.denominador = denominador;
	simplificar();
    }
    
    private int mdc_euclides(int a,int b){
	int q, r;
	while(b != 0){
	    q = a/b;
	    r = a%b;
	    a = b;
	    b = r;
	}
	return a;
    }
    
    public void simplificar(){
	int i = mdc_euclides(numerador,denominador);
	numerador = numerador/i;
	denominador = denominador/i;
    }
    
    public void soma(Rational s1,Rational s2){
	int a,b,c;
	
	c = mdc_euclides(s1.denominador,s2.denominador); //c o mdc
	a = s1.denominador/c; //a é um dos pivores
	b = a*(s2.denominador); //b é o denominador e MMC
	
	this.numerador = (b/(s1.denominador))*(s1.numerador) + (b/(s2.denominador))*(s2.numerador);
	this.denominador = b;
	simplificar();
	System.out.println("A soma simplificada: "+this.numerador+"/"+this.denominador);
    }
    
    public void imprimeNumero(){
	System.out.println(numerador+"/"+denominador);
    }
    
    public void subtracao(Rational s1,Rational s2){
	int a,b,c;
	c = mdc_euclides(s1.denominador,s2.denominador); //c o mdc
	a = s1.denominador/c; //a é um dos pivores
	b = a*(s2.denominador); //b é o denominador e MMC
	this.numerador = (b/(s1.denominador))*(s1.numerador) - (b/(s2.denominador))*(s2.numerador);
	this.denominador = b;
	simplificar();
	System.out.println("A subtração simplificada: "+this.numerador+"/"+this.denominador);
    }
    
    public void multiplicacao(Rational s1,Rational s2){
	this.numerador = (s1.numerador)*(s2.numerador);
	this.denominador = (s1.denominador)*(s2.denominador);
	simplificar();
	System.out.println("A multiplicacao simplificada: "+this.numerador+"/"+this.denominador);
    }
    
    public void divisao(Rational s1,Rational s2){
	this.numerador = (s1.numerador)*(s2.denominador);
	this.denominador = (s1.denominador)*(s2.numerador);
	simplificar();
	System.out.println("A divisão simplificada: "+this.numerador+"/"+this.denominador);
    }
}