/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

/**
 *
 * @author sir-berg
 */
public class Cliente {
    private IHoraCerta pHora = null;
    
    public Cliente(String ip, int porta){
        pHora = new ProxyHoraCerta(ip, porta);
        init();
    }
    
    public final void init(){
        System.out.println(pHora.dataAtual());
        System.out.println(pHora.horaAtual());
    }
    
    public static void main(String[] args){
        Cliente c = new Cliente("127.0.0.1", 4321);
    }
}
