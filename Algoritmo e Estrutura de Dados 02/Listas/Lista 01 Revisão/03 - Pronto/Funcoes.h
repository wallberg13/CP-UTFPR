/* Dado um vetor de inteiros nao ordenados,
 * faca uma funcao que retorne o valor mais proximo de um numero 
 * fornecido pelo usuario. O vetor nao pode ser ordenado */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 100

void sorteio(){
  srand(time(NULL));
}

int povoando_vetor(int vetor[]){  
  sorteio();
  for(int i = 0; i < max; i++){
    vetor[i] = 1 + rand()%(1000);
    printf("%d \n",vetor[i]);
  }
}

int pesquisa(int vetor[], int i){
  for(int j = 0; j<max; j++){
    if(vetor[j] == i)
      return j;
  }
  return -1;
}

int mais_prox(int vetor[], int i){
  int menor_diferenca = -1;
  int l,k,j;
  int soma = 0;
  printf("\n\n");
  for(j = 0; j < max; j++){
    soma += vetor[j];
    if(vetor[j] == i){
      printf("%d esta no vetor, então não tem numero mais prox. do que ele mesmo!!\n",i);
    }
    if(vetor[j] > i){
      if((menor_diferenca > vetor[j] - i) || (menor_diferenca == -1))
	menor_diferenca = vetor[j] - i;
    }else{
      if((menor_diferenca > i - vetor[j]) || (menor_diferenca == -1))
	menor_diferenca = i - vetor[j];
    }
  }
  
  if(j == max){ //Ele só executara esse comando, caso não tenha achado o valor dado pelo o usuario
    l = pesquisa(vetor,i - menor_diferenca);
    k = pesquisa(vetor,i + menor_diferenca);
    printf("Está é a menor diferença: %d \n",menor_diferenca);
    if(l > -1)
      printf("%d é o numero mais prox. e esta na posicao %d \n",i - menor_diferenca,l);
    if(k > -1)
      printf("%d é o numero mais prox. e esta na posicao %d \n",i + menor_diferenca,k);
  }
  printf("A média dos valores: %d \n",soma/(j+1));
}