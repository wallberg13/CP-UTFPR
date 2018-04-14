/** Preencha um vetor com 10 numeros pseudo-aleatorios e imprima este vetor
de forma ordenada. Faca uso do algoritmo de ordenacao bolha. */

import java.util.Random;

public class Q05{
  
  public static void main(String[] args){
    Random rand = new Random();
    int i[] = new int[10];
    
    for(int j = 0; j < 10; j++){
      i[j] = rand.nextInt(100) + 1;
    }
    
    for(int j = 0; j < 10; j++){
      for(int k = j + 1; k < 10; k++){
	int aux;
	if(i[k]<i[j]){
	  aux = i[k];
	  i[k] = i[j];
	  i[j] = aux;
	}
      }
    }
    
    for(int j = 0; j < 10; j++){
      System.out.println(i[j]);
    }
  }

}