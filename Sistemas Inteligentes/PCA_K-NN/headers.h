#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Engine/headers.h"
/*
  Quinta coluna da instancia é a classificação dela.
  Se tivesse os valores de dimensões, pegaria uma matriz e faria
  uma forma geral de fazer calculos de distancias eucledianas.

  NOVO UPDATE!!!!!!!!
  ESTRUTURA DE DADOS:
    MATRIZ COM AS FEATURES E INSTANCIAS
    MATRIZ DE METRICAS:
      POSICAO   |   FUNCAO
        0       |   MEDIA
        1       |   MAIOR
        2       |   MENOR

    TAMANHO DA MATRIZ DE METRICAS: 3 LINHAS, DIM[POSICAO DE COLUNA] ;

  Vetor DIM[2]
    DIM[0] ==> LINHAS
    DIM[1] ==> COLUNAS
*/

typedef struct{
  int pos;
  double dist;
}Dist;

/** Funções em Funcoes.c*/
void import(char *arq);
void K_NN(double **iris,int *dim);

/* Distancias*/
double distEucl(double *vet1, double *vet2, int *dim);
// double distMahalanobis(IRIS i1, IRIS i2, Metrica met);

void vetZeros(int *j);
int classifica(int *rot, Dist *dist);
int pega_maior(int *vet);

void printSol(int *sol, int *rot, int *dim);
void Merge_sort(Dist v[], int p, int r);
void Merge(Dist v[], int p, int q, int r);

// /** Funções Para Acuracia*/
double contPerAcert(int *sol, int *rot, int *dim);
void mtzConfu(int *sol, int *rot, int *dim);
int** cria_matriz(int x);


/**
  Funções em Metricas.c
*/
void metrica(double **iris, double **met, int *dim, int *dimMet);
double* cria_vet_zeros_double(int tam);
double** cria_Matriz_Metricas(int *dimMet);
void print_vet(double *vet,int tam);
void normalize(double **iris, double **met, int *dim, int *dimMet);
int* vet_Rot(int *dim);

void print_vet_arq(int *sol, int x);
