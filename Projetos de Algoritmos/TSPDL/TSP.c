#include "headers.h"

void initialize(TSP **tsp, int n){
  *tsp = (TSP *)malloc(n*sizeof(TSP));
}

int** cria_matriz(int n){
  int i;
  int **mtz;
  mtz = (int **)malloc(n*sizeof(int *));

  for(i = 0; i < n; i++){
    mtz[i] = (int *)malloc(n*sizeof(int));
  }
  return mtz;
}

int* cria_vetor(int n){
  return (int *)malloc(n*sizeof(int));
}

void limpa_vetor(int *vet){
  free(vet);
}

void limpa_matriz(int **mtz, int n){
  int i = 0;
  for(i = 0; i < n; i++){
    free(mtz[i]);
  }
  free(mtz);
}

void limpa_tsp(TSP *tsp){
  free(tsp);
}

void cria_lrc(LRC **lrc, int n){
  *lrc = (LRC *)malloc(n*sizeof(LRC));
}

void limpa_lrc(LRC *lrc){
  free(lrc);
}
