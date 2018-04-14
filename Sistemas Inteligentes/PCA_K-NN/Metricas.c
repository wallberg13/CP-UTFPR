#include "headers.h"

#define INFINITO 9999.0
#define k_met 3

void metrica(double **iris, double **met, int *dim, int *dimMet){
  int i,j;
  double *soma = cria_vet_zeros_double(dimMet[1]);

  /*
    Primeiro, tirando a media.
  */
  for(i = 0; i < dim[0]; i++){
    for(j = 0; j < dim[1]; j++){
      soma[j] += iris[i][j];
      if(iris[i][j] <= met[2][j])
        met[2][j] = iris[i][j];
      if(iris[i][j] >= met[1][j])
        met[1][j] = iris[i][j];
    }
  }
  for(i = 0; i < dim[1]; i++){
    met[0][i] = soma[i]/dim[0];
  }
  free(soma); //Não preciso mais, uma vez que já tenha tirado a media
}

void normalize(double **iris, double **met, int *dim, int *dimMet){
  int i,j;
  for(i = 0; i < dim[0]; i++){
    for(j = 0; j < dim[1]; j++){
      iris[i][j] = (iris[i][j] - met[2][j])/(met[1][j] - met[2][j]);
    }
  }
}

double* cria_vet_zeros_double(int tam){
  double *vet;
  vet = (double *)malloc(tam*sizeof(double));
  int i;
  for(i = 0; i < tam; i++)
    vet[i] = 0;
  return vet;
}

double** cria_Matriz_Metricas(int *dimMet){
  double **met;
  met = (double **)malloc(dimMet[0]*sizeof(double));
  int i,j;
  for(i = 0; i < dimMet[0]; i++){
    met[i] = (double *)malloc(dimMet[1]*sizeof(double));
  }
  for(i = 0; i < dimMet[0]; i++){
    for(j = 0; j < dimMet[1]; j++){
      switch (i) {
        case 2:
          met[i][j] = INFINITO;
          break;
        default:
          met[i][j] = 0.0;
      }
    }
  }
  return met;
}

void print_vet(double *vet,int tam){
  int i;
  for(i = 0; i < tam; i++){
    printf("%.2f \t",vet[i]);
  }
  printf("\n");
}


/* Distâncias */
double distEucl(double *vet1, double *vet2, int *dim){
  int i;
  double soma = 0;
  for(i = 0; i < dim[1]; i++){
    soma += pow(vet1[i]-vet2[i],2);
  }
  return sqrt(soma);
}
