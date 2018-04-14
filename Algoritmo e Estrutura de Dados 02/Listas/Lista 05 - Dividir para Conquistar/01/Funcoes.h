#include <stdio.h>
#include <stdlib.h>

/** Algoritmo para realizar a busca binaria */

int busca_binaria(int vetor[],int valor,int inicio, int fim){
  if(inicio > fim){
    printf("O valor pesquisado é: %d Não Foi Encontrado!!  \n", valor);
    return -1;
  }
  
  int meio = (inicio + fim)/2;
  
  if(vetor[meio] == valor){
    printf("O valor pesquisado é: %d Foi Encontrado!! \n", valor);
    return valor;
  }
  
  if(vetor[meio] > valor)
    busca_binaria(vetor,valor,inicio,meio-1);
  
  if(vetor[meio] < valor)
    busca_binaria(vetor,valor,meio+1,fim);
}

int povoa_vetor(int vetor[],int tam){
  for(int i = 0; i < tam; i++){
    vetor[i] = i;
    printf("%d \t",vetor[i]);
  }
  printf("\n");
}
