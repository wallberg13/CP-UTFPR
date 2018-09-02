/* Funcao para achar o maior e 
 *menor valor de uma matriz qualquer de inteiros.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxc 10
#define maxl 10

void sorteio(){
  srand(time(NULL));
}

int povoando_matriz(int matriz[maxl][maxc],int lin, int col){
  sorteio();
  for(int i = 0; i < lin; i++){
    for(int j = 0; j < col; j++){
      matriz[i][j] = 1 + rand()%(1000);
      printf("%d \t", matriz[i][j]);
    }
    printf("\n");
  }
}

int maior_menor(int matriz[maxl][maxc]){
  int maior = 0, menor = 1001;
 
  for(int i = 0; i < maxl; i++){
    for(int j = 0; j < maxc; j++){
   
      if(matriz[i][j] <= menor)
	menor = matriz[i][j];
      
      if(matriz[i][j] >= maior)
	maior = matriz[i][j];
    
      
    }
  }
  
  printf("O menor numero é: %d \n",menor);
  printf("O maior numero é: %d \n",maior);
}