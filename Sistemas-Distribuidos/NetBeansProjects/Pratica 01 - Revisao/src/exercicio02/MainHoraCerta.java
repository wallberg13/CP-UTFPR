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
public class MainHoraCerta {
    
    IHoraCertaImpl hora = null;
    
    public MainHoraCerta(){
        hora = new IHoraCertaImpl();
        iniciar();
    }
    
    public void iniciar(){
        System.out.println("Data atual : " + hora.dataAtual());
        System.out.println("Hora atual : " + hora.horaAtual());
    }
    
    public static void main(String[] args){
        MainHoraCerta apl = new MainHoraCerta();
    }
}
