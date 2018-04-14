/**Altere a função do exercício anterior para copiar os elementos mas caso existam
elementos repetidos na lista de origem, estes serão copiados apenas uma vez. A lista
origem está desordenada.*/
#include<stdio.h>
#include<Wall.h>

int copia(Lista *origem, Lista *chegada);

int main(){
  Lista lista1, lista2;
  inicializaLista(&lista1);
  inicializaLista(&lista2);
  
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  inserirDesordenado(&lista1,12);
  
  copia(&lista1,&lista2);
  imprimeLista(&lista2);
}

int copia(Lista *origem, Lista *chegada){
  for(int i = 0; i<origem->top; i++){
    if( PLBi(chegada,origem->vetor[i],0,chegada->top) == -1)
      inserirOrdenado(chegada,origem->vetor[i]);
  }
  return 1;  
}

