public class ContaPoupanca{
    private float taxaJurosAnual;
    private float saldo;
    
    public ContaPoupanca(float saldo){
	this.saldo = saldo;
	taxaJurosAnual = 4.0f;
    }
    
    public void jurosMensais(){
	float juros;
	juros = taxaJurosAnual/1200;
	saldo = saldo + saldo*juros;
	System.out.printf("Rendimento do Mês: %.2f \n",saldo*juros);
	System.out.printf("Saldo após o rendimento: %.2f \n",saldo);
    }
    
    public void set_taxaJurosAnual(float taxaJurosAnual){
	this.taxaJurosAnual = taxaJurosAnual;
    }
}