#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  Quinta coluna da instancia é a classificação dela.
  Se tivesse os valores de dimensões, pegaria uma matriz e faria
  uma forma geral de fazer calculos de distancias eucledianas.
*/


typedef struct{
  int pos;
  double f1;
  double f2;
  double f3;
  double f4;
  int clas;
}IRIS;

typedef struct{
  int pos;
  double dist;
}Dist;

typedef struct{
  double maiorf1;
  double menorf1;
  double maiorf2;
  double menorf2;
  double maiorf3;
  double menorf3;
  double maiorf4;
  double menorf4;
  double mediaf1;
  double mediaf2;
  double mediaf3;
  double mediaf4;
  double dp1;
  double dp2;
  double dp3;
  double dp4;
}Metrica;

/** Funções em Funcoes.c*/
void import(char *arq);

double distEucl(IRIS i1, IRIS i2);
double distMahalanobis(IRIS i1, IRIS i2, Metrica met);

void K_NN(IRIS *iris);
void vetZeros(int *j);
int classifica(IRIS *iris, Dist *dist);

/** Funções para mostragem*/
void printDist(Dist *dist, IRIS *iris);
void printIris(IRIS *iris);
void printSol(int *sol, IRIS *iris);

void Merge_sort(Dist v[], int p, int r);
void Merge(Dist v[], int p, int q, int r);

/** Funções de normalização */
void normalize(IRIS *iris, Metrica met);
void metrica(IRIS *iris, Metrica *met);

/** Funções Para Acuracia*/
double contPerAcert(int *sol, IRIS *iris);
void mtzConfu(int *sol, IRIS *iris);
int** cria_matriz(int x);
int pega_maior(int *vet);
