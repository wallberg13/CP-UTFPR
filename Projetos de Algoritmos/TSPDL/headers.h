#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

#define infinito 999999

typedef struct{
  int demand;
  int draft;
  int visited;
}TSP;

typedef struct{
  int prox;
  int peso;
}tsp_dynamic;

/**
  Estutura que ficará melhor para se trabalhar na hora da
  ordenação da lista privada, pois trabalhar com uma estrutura é
  melhor.
*/
typedef struct{
  int peso;
  int prox;
}LRC;

/**
  Funções para tratar o arquivo.
*/
int import(char *in, char *out1);
char* cap_first(char *txt);
int cap_N(char *txt);

/**
  Funções de povoamento das estruturas de dados.
*/
void povoamento_Mtz(int **mtz, char *text,int n, int y);
void povo_demand(TSP *tsp,int n, char *text);
void povo_draft(TSP *tsp,int n, char *text);

/**
  Funções de Criação e inicialização de estruturas
*/
void initialize(TSP **tsp, int n);
void limpa_tsp(TSP *tsp);
int** cria_matriz(int n);
void limpa_matriz(int **mtz, int n);
int* cria_vetor(int n);
void limpa_vetor(int *vet);
void cria_lrc(LRC **lrc, int n);
void limpa_lrc(LRC *lrc);

/**
  Funções do arquivo until.c
*/
void print_matriz(int **mtz,int n);
void print_TSP(TSP *tsp,int n);
void print_vetor(int *vet, int n);
int zera_visita(TSP *tsp, int n);
int cal_demand(TSP *tsp, int n);
int valorSol(int *sol, int n, int **mtz);
void print_LRC(LRC *lrc, int n);
double probSort();


/**
  Funções do arquivo Track_Greedy.c
*/
int pegar_menor(TSP *tsp, int **mtz, int n, int carga, int y);
int greedy_algorithm(TSP *tsp,int **mtz,int n);

/**
  Funções do arquivo Track_Dynamic.c
*/

/**
  Funções do arquivo Track_Simulated_Annealing.c
*/
int update(int *sol, int *novo, int n);
int SA(TSP *tsp, int **mtz, int n, int *sol_ini);
double probP(int vc, int vn, double T);
double novoT(double t);
int* neighborhood(int *nov,TSP *tsp, int *sol,int n);
int verPosDes(int posDes,int vert, TSP *tsp, int n);
int troca(int *sol,int x, int y);
int posMin(TSP  *tsp, int n, int y);

/**
  Funções do arquivo GRASP.c
*/
int* construcao(TSP *tsp, int **mtz, int n, double alpha);
void Merge(LRC *lrc, int p, int q, int r); // ALGORITMO NÃO IMPLEMENTADO POR MIM
void Merge_sort(LRC *lrc, int p, int r);
int const_lrc(TSP *tsp, int n, int **mtz, int y, int dmd, double alpha);
int cont_lrc(TSP *tsp,int n, int dmd, int y);
int cont_lrc_alpha(LRC *lrc, int n, double alpha);

void sorteio();

#endif //ARQUIVOS_H_INCLUDED
