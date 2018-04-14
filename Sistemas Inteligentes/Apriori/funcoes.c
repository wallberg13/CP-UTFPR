#include "headers.h"

#define sup 0.15
/**
  Criar um vetor dos elementos que ainda estão no algoritmo.

  Criar um suporte minimo.
*/
void import(char *fileM, char *fileList){
  int dim[2];
  int **mtz;
  CharZao *cz;
  mtz = loadInt(fileM,dim);
  int n;
  cz = loadStr(fileList,&n);

  Apriori(mtz,dim,cz);

}

void Apriori(int **mtz, int *dim, CharZao *cz){
  int MIN_SUP = (int)dim[0]*sup;
  int k = 1; //Tamanho dos conjuntos.
  int ele[dim[1]];
  int k_ele; //Elementos ainda "vivos"
  int i,j;
  ini_Elementos(ele,dim);l
  k_ele = cont_Elementos_Live(ele,dim);

  /**
    Teste para dar a primeira passada.
  */
  int sups[k_ele];
  vet_zeros(sups,k_ele);

  for(i = 0; i < dim[0]; i++){
    for(j = 0; j < dim[1]; j++){
      if(mtz[i][j])
        sups[j]++;
    }
  }
  print_vet(sups,k_ele);
  printf("\n\n\nMIN_SUP: %d\n\n\n",MIN_SUP);
  print_Elementos_Live(ele,cz,dim);
  printf("\n\n\n");
  /*
    Verifica quem não tem os sup ideais.
  */
  for(i = 0; i < dim[1]; i++){
    if(sups[i] < MIN_SUP)
      ele[i]--;
  }

  vet_zeros(sups,k_ele);
  for(){
    for(i = 0; i < dim[1]; i++){
      for(j = 0; ele[i] and j < dim[1]; i++){

      }
    }
  }
  print_Elementos_Live(ele,cz,dim);
}

void ini_Elementos(int *ele, int *dim){
  int i;
  for(i = 0; i < dim[1]; i++){
    ele[i] = 1;
  }
}

void vet_zeros(int *vet, int n){
  int i;
  for(i = 0; i < n; i++){
    vet[i] = 0;
  }
}

void print_Elementos_Live(int *ele, CharZao *cz, int *dim){
  int i;
  CharZao *aux = cz;
  for(i = 0; i < dim[1] && aux != NULL; i++){
    if(ele[i] > 0)
      printf("%s\n",aux->val);
    aux = aux->prox;
  }
}

void print_vet(int *ele, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d ",ele[i]);
  }
  printf("\n");
}

int cont_Elementos_Live(int *ele, int *dim){
  int i, cont;
  for(i = 0, cont = 0; i < dim[1]; i++){
    if(ele[i] > 0)
      cont++;
  }
  return cont;
}
