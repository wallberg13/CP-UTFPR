#include "headers.h"

/**
  Todas as funções de exibições e tambem de calculo comuns as metaheuristicas
  estara contemplada neste arquivo.c
*/

void print_vetor(int *vet, int n){
  int i;
  for(i = 0; i < n-1; i++){
    printf("%2i ",vet[i]);
  }
    printf("%2i %2i \t",vet[i],vet[0]);
}

void print_matriz(int **mtz,int n){
  int i,j;

  printf("----- ");
  for(i = 0; i < n; i++){
    printf("%3d ",i);
  }
  printf("\n\n");
  for(i = 0; i < n; i++){
    printf("%3d : ",i);
    for(j = 0; j < n; j++){
      printf("%3d ",mtz[i][j]);
    }
    printf("\n");
  }

}

void print_TSP(TSP *tsp,int n){
  int i;
  for(i = 0; i < n; i++)
    printf("Node:%d , Demand: %d, Draft: %d \n",i,tsp[i].demand,tsp[i].draft);
}

void print_LRC(LRC *lrc, int n){
  int i;
  for(i = 0; i < n; i++)
    printf("%d ",lrc[i].prox);
  printf("\n");
}

/**
  Algoritmo que gera o valor total da solução.
  Complexidade: O(n)
*/
int valorSol(int *sol, int n, int **mtz){
  int soma = 0;
  int i;
  for(i = 0; i < n-1;i++){
    soma += mtz[sol[i]][sol[i+1]];
  }
  soma += mtz[sol[i]][sol[0]];
  return soma;
}

/**
  Algoritmo que calcula a demanda total das entregas.
  Complexidade: O(n)
*/
int cal_demand(TSP *tsp, int n){
  int i,j;

  for(i = 0,j = 0; i < n; i++){
    j += tsp[i].demand;
  }
  return j;
}

/**
  Algoritmo que zera o estado de visitado de um elemento.
  Complexidade: O(n)
*/
int zera_visita(TSP *tsp, int n){
  int i;
  for(i = 0; i < n; i++){
    tsp[i].visited = 0;
  }
}

double probSort(){
  double x;
  x = (double)(0 + rand()%1001);
  return x/1000;
}
