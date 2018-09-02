/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemploaula12.mar;

/**
 *
 * @author sir-berg
 */
public class AloMundoImpl implements IAloMundo{

    @Override
    public String digaAloMundo(int n) {
        String aux = "";
        for(int i = 1; i <= n; i++){
            aux = aux + "Alo Mundo...\n";
        }
        return aux;
    }
    
}
