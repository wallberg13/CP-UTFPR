#include<stdio.h>
#include<stdlib.h>
#include "WallV02.h"


/**
 * Função para realizar as trocas necessarias.
 */

void troca(int *a, int *b){
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}


/**
 * Algoritmo de ordenação BubleSort
 */
int bubleSort(int vet[], int ult){
  for(int i = 0; i < ult; i++){
    for(int j = ult - 1; j>i; j--){
      if(vet[j]>vet[j+1])
			troca(&vet[i],&vet[j]);
    }
  }
}


/**
 * Algoritmo de ordenação por Seleção Direta
 */
int selDireta(int vet[], int ultimo){
  for(int i = 0; i < ultimo;i++){
    for(int j = i + 1; j < ultimo; j++)
      if(vet[i]>vet[j])
			troca(&vet[i],&vet[j]);
  }
}

/**
 * Algoritmo de ordenação por inserção
 */
int ordInsercao(int vet[],int ultimo){
  int i, j, elem;
  for(j = 1; j < ultimo; j++){
    elem = vet[j];
    i = j - 1;
    while((i >= 0)&&(vet[i]>elem)){
      vet[i + 1] = vet[i];
      i--;
    }
    vet[i+1] = elem;
  }
}

/**
 * Metodo de ordenação ShellSort
 */
int shellSort(int vet[], int ultimo){
  
}

/**
 * Metodo de ordenação QuickSort
 */
int quickSort(int vet[],int min, int max){
  if(min >= max) //Vetor esta ordenado;
    return 1;
  int i = min;
  int j = max;
  int pivo = vet[(i+j)/2]; //Vetor do Elemento Central
  
  do{//divide o vetor em duas partes
    while(vet[i]<pivo) i++; 	//O capeta entende esse codigo, eu não
    while(vet[j]>pivo) j--;
    if(i<=j){
      if(vet[i]!=vet[j])
			troca(&vet[i],&vet[j]);
      i++;
      j--;
    }
  }while(i<=j);
  quickSort(vet,min,j); //Ordenar parte Esquerda
  quickSort(vet,i,max); //Ordenar parte Direita
}	

/**
 * METODOS DE ORDENAÇÃO PARA LISTAS ENCADEADAS!!!! 
 */

void trocaD(no **l,no *p1, no *p2){
  no *p1ant, *p2ant, *paux;
  p1ant = *l; p2ant = *l;
  while(p1ant->link != p1) p1ant = p1ant->link;
  while(p2ant->link != p2) p2ant = p2ant->link;
  paux = p1->link;
  p1->link = p2->link;
  p2->link = paux;
  p1ant->link = p2;
  p2ant->link = p1;
}

void ordenaD(no **l){
  no *p1, *p2;
  if(*l != NULL && (*l)->link != NULL){
    p1 = *l;
    p2 = (*l)->link;
    while(p1->link != NULL){
      while(p2 != NULL){
	if(p1->info > p2->info)
 	  trocaD(l,p1,p2);
	p2 = p2->link;
      }
      p1 = p1->link;
      p2 = p1->link;
    }
  }
}