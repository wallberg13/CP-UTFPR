public class Calculadora{
    private double i;
    private double j;
    private char op;
    
    public Calculadora(double i, int j, char op){
	this.i = i;
	this.j = j;
	this.op = op;
    }
    
    public void calcular(){
	switch(op){
	    case '+': 
		System.out.printf("Resultado da soma: %.2f \n",(i+j));
		break;
	    case '/':
		if(j == 0) System.out.printf("Não é possivel dividir por zero. \n");
		else System.out.printf("Resultado da divisão: %.2f \n", (i/j));
		break;
	    case '*':
		System.out.printf("Resultado da multiplicação: %.2f \n",(i*j));
		break;
	    case '-':
		System.out.printf("Resultado da subtração: %.2f \n",(i-j));
		break;
	}
    }
}
