public abstract class RoboAbstrato{
    
    private String nomeDoRobo;
    private int posicaoXAtual, posicaoYAtual;
    private short direcaoAtual;
    
    public RoboAbstrato(String n, int px, int py, short d){
	nomeDoRobo = n;
	posicaoXAtual = px;
	posicaoYAtual = py;
	direcaoAtual = d;
    }
    
    public void move(){
	move(1);
    }
    
    /** 
	Esta versão do método move modiifca a posicao do robô em um 
	número de unidades na direção em que o robô está. O método é 
	declarado como abstrato e não tem corpo, pois não sabemos 
	exatamento como um robô(instância de classe que herda desta)
	irá implementar seus movimentos.
	@param passos o numero de "passos" para o robô.
    */
    
    public abstract void move(int passos);
    
    public void moveX(int passos){
	posicaoXAtual += passos;
    }
    
    public void moveY(int passos){
	posicaoYAtual += passos;
    }
    
    public void mudaDirecao(short novaDirecao){
	direcaoAtual = novaDirecao;
    }
    
    public short qualDirecaoAtual(){
	return direcaoAtual;
    }
    
    public String toString(){
	String resultado = "Nome do robô: "+ nomeDoRobo + "\n";
	resultado += "Posição do robô: (" + posicaoXAtual + "," + posicaoYAtual + ")\n";
	resultado += "Direção do robô: "+direcaoAtual;
	return resultado;
    }
    
}