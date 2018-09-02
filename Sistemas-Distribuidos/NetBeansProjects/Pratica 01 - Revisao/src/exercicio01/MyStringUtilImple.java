/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio01;

/**
 *
 * @author sir-berg
 */
public class MyStringUtilImple implements IMyStringUtil 
{

    @Override
    public String ecoar(String str) {
        return str;
    }

    @Override
    public String inverter(String str) {
        String aux = "";
        
        for(int i = str.length() - 1; i >= 0; i--){
            aux += str.charAt(i);
        }
        return aux;
    }

    @Override
    public String inverterPalavra(String str) {
        String aux[] = str.split(" ");
        String aux1 = "";
        for(String aux2: aux){
            aux1 += inverter(aux2) + " ";
        }
        return aux1;
    }

    @Override
    public boolean isPalindroma(String str) {
        String aux = inverter(str).replaceAll(" ", "").toLowerCase();
        str = str.replaceAll(" ", "").toLowerCase();
        return str.equals(aux);
    }

    @Override
    public boolean isPangram(String str) {
        String aux = "qwertyuiopasdfghjklzxcvbnm";
        String s = str.toLowerCase();
        for(int i = 0; i < aux.length(); i++){
            if(!s.contains(aux.substring(i, i+1))){
               return false; 
            }
        }
        return true;
    }
    
}
