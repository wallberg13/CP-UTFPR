#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
  Quinta coluna da instancia é a classificação dela.
  Se tivesse os valores de dimensões, pegaria uma matriz e faria
  uma forma geral de fazer calculos de distancias eucledianas.
*/

void sorteio();

typedef struct{
  int pos;
  double f1;
  double f2;
  double f3;
  double f4;
  int clas;
}IRIS;

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


typedef struct{
  double p1;
  double p2;
  double p3;
  double p4;
  int rot;
}CM;

/** Funções em Funcoes.c*/
void import(char *arq);

void K_Means(IRIS *iris, double **mtz, int *rotList);


double distEucl(IRIS i1, IRIS i2);
double distEucl2(IRIS i1, CM cm);
double distMahalanobis(IRIS i1, IRIS i2, Metrica met);
double distMahalanobis2(IRIS i1, CM cm, Metrica met);

/** Funções para mostragem*/
void printIris(IRIS *iris);
void printSol(int *sol, IRIS *iris);
void print_CM(CM *cm);

/** Funções de normalização */
void normalize(IRIS *iris, Metrica *met);
void metrica(IRIS *iris, Metrica *met);
void inicia_cm(CM *cm, IRIS *iris);
void print_vet(int *vet);

/** Funções de analize de clusters*/
double distancias_cluster(IRIS *iris, int *rotList, int x, int y);
void mtz_distancias(IRIS *iris, int *rotList, double **mtz);
double** cria_matriz(int x);
void print_Matriz(double **mtz);P
double* val_obj(double **mtz);
int verf_neg(double **mtz);
void cop_Matriz(double **org, double **dest);
void cop_vet(int *org, int *dest);
