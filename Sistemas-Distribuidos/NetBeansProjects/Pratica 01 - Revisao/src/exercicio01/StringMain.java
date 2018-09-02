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
public class StringMain {
    
    private MyStringUtilImple obj = null;
    
    public StringMain(){
        obj = new MyStringUtilImple();
        iniciar();
    }
    
    public void iniciar(){
        String str = "Uma mensagem para aparecer na tela";
        System.out.println(obj.ecoar(str));
        System.out.println(obj.inverter(str));
        System.out.println(obj.inverterPalavra(str));
        System.out.println("Palindroma - Frase 01: " + obj.isPalindroma("O galo ama o lago"));
        System.out.println("Palindroma - Frase 02: " + obj.isPalindroma("O galo ama o lago X"));
        System.out.println("Pangram - Frase 01: " + obj.isPangram(str));
        System.out.println("Pangram - Frase 01: " + obj.isPangram("The quick brown fox jumps over the lazy dog"));
    }
    
    public static void main(String[] args){
        StringMain apl = new StringMain();
    }
    
}
