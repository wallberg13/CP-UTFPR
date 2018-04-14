import java.util.ArrayList;
import java.util.Collections;

public class Sorteio{
    
    public static void main(String[] args){
	ArrayList<Integer> numeros = new ArrayList<Integer>(60);
	
	for(int i = 1; i < 60; i++) numeros.add(i);
	
	Collections.shuffle(numeros);
	
	for(int i = 0; i < 6; i++) System.out.print(numeros.get(i)+" ");
    }
}