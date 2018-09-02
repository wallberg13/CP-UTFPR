public class Conta{
    protected double saldo;
    
    public void deposita(double valor){
	this.saldo += valor;
    }
    
    public void saca(double valor){
	this.saldo -= valor;
    }
    
    public double getSaldo(){
	return this.saldo;
    }
    
    public void atualiza(double taxa){
	this.saldo += this.saldo*taxa;
    }
}