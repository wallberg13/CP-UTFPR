#include "headers.h"

void ini_Coluna(Coluna **col){
  *col = NULL;
}

void ini_Linha(Linha **lin){
  *lin = NULL;
}

int add_Coluna_Fim(Coluna **col,int i, int j, int val){
  Coluna *aux;
  aux = (Coluna *)malloc(sizeof(Coluna));
  aux->prox = NULL;
  aux->i = i;
  aux->j = j;
  aux->val = val;
  if(*col == NULL)
    *col = aux;
  else{
    Coluna *aux2;
    aux2 = *col;
    while(aux2->prox != NULL)
      aux2 = aux2->prox;
    aux2->prox = aux;
  }
  return 1;
}

int add_Linha_Fim(Linha **lin, int i, Coluna *col){
  Linha *aux;
  aux = (Linha *)malloc(sizeof(Linha));
  aux->prox = NULL;
  aux->i = i;
  aux->col = col;
  if(*lin == NULL)
    *lin = aux;
  else{
    Linha *aux2;
    aux2 = *lin;
    while(aux2->prox != NULL)
      aux2 = aux2->prox;
    aux2->prox = aux;
  }
  return 1;
}

void print_Matriz(Linha *lin){
  Linha *auxL = lin;
  Coluna *auxC;

  while(auxL != NULL){
    auxC = auxL->col;
    while(auxC != NULL){
      printf("(%d,%d) %d\t",auxC->i,auxC->j,auxC->val);
      auxC = auxC->prox;
    }
    printf("\n");
    auxL = auxL->prox;
  }
}


int** converte_Matriz(Linha **lin,int *dim){
  Linha *auxL = *lin;
  int **mtz;
  mtz = cria_Matriz(dim[0],dim[1]);
  Coluna *auxC;

  while(auxL != NULL){
    auxC = auxL->col;
    while(auxC != NULL){
      mtz[auxC->i][auxC->j] = auxC->val;
      auxC = auxC->prox;
    }
    auxL = auxL->prox;
  }
  return mtz;
}


int** cria_Matriz(int i, int j){
  int **mtz;
  mtz = (int **)malloc(i*sizeof(int *));
  int x;
  for(x = 0; x < i; x++){
    mtz[x] = (int *)malloc(j*sizeof(int));
  }
  return mtz;
}

int cont_Coluna(Linha **lin){
  Coluna *aux = (*lin)->col;
  int x = 0;
  while(aux != NULL){
    aux = aux->prox;
    x++;
  }
  return x;
}

void print_Matriz2(int **mtz, int *dim){
  int i,j;
  for(i = 0; i < dim[0]; i++){
    for(j = 0; j < dim[1]; j++){
      printf("%d ",mtz[i][j]);
    }
    printf("\n");
  }
}

int rem_Coluna_Ini(Coluna **col){
  Coluna *aux;
  if(*col == NULL)
    return 0;
  aux = (*col)->prox;
  free(*col);
  *col = aux;
  return 1;
}

int rem_Linha_Ini(Linha **lin){
  Linha *aux;
  if(*lin == NULL)
    return 0;
  aux = (*lin)->prox;
  free(*lin);
  *lin = aux;
  return 1;
}

int limpa_Coluna(Coluna **col){
  while(rem_Coluna_Ini(col));
}

int limpa_Linha(Linha **lin){
  Linha *aux;
  aux = *lin;
  while(*lin != NULL){
    limpa_Coluna(&((*lin)->col));
    rem_Linha_Ini(lin);
  }
}
