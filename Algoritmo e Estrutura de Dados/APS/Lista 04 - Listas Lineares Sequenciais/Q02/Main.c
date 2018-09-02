/**Crie a função copia que recebe como parâmetro duas listas, 
 * sendo uma delas vazia e copia todos os elementos da primeira
 * lista para a segunda. A lista origem está desordenada e 
 * deve assim permanecer. */
#include<stdio.h>
#include<Wall.h>
#define MAX 100

int copia(Lista *origem, Lista *chegada);

int main(void){
  Lista lista1, lista2;
  
  inicializaLista(&lista1);
  inicializaLista(&lista2);
  int j;
  
  for(int i = 0; i<10; i++){
    printf("Digite alguma merda: ");
    scanf("%d",&j);
    inserirDesordenado(&lista1,j);    
  }
  
  copia(&lista1,&lista2);
  printf("Lista 1: \n");
  imprimeLista(&lista1);
  printf("Lista 2: \n");
  imprimeLista(&lista2);
  
  
  return 0;
}

int copia(Lista *origem, Lista *chegada){
  for(int i = 0; i<origem->top; i++)
    inserirOrdenado(chegada,origem->vetor[i]);
  return 1;  
}