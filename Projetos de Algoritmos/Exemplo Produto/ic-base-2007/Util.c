#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include "Util.h"
#include "Estruturas.h"
#include "Listas.h"

#define MAX(x,y) ((x)<(y) ? (y) : (x))


/* cria memoria para um vetor de tam posicoes */
int *cria_vetor(int tam)
{
  int *vetor;

  vetor = (int *) malloc(tam*sizeof(int));
  if (!vetor){
  	printf("Falta memoria para alocar o vetor de ponteiros");
    exit(1);
  }
  return vetor;
}


/* cria memoria para um vetor de tam posicoes */
float *cria_vetor_float(int tam)
{
  float *vetor;

  vetor = (float *) malloc(tam*sizeof(float));
  if (!vetor){
  	printf("Falta memoria para alocar o vetor de ponteiros");
    exit(1);
  }
  return vetor;
}


/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
int **cria_matriz(int nlinhas, int ncolunas)
{
  register int i;
  int **matriz;

  matriz = (int **) malloc(nlinhas*sizeof(int *));
  if (!matriz) {
        printf("Falta memoria para alocar a matriz de ponteiros\n");
        exit(1);
  }
  for (i=0; i < nlinhas; i++) {
    matriz[i] = (int *) malloc(ncolunas*sizeof(int));
    if (!matriz[i]){
      printf("Falta memoria para alocar a matriz de ponteiros.\n");
      exit(1);
    }
  }
  return matriz;
}

/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
float **cria_matriz_float(int nlinhas, int ncolunas)
{
  register int i;
  float **matriz;

  matriz = (float **) malloc(nlinhas*sizeof(float *));
  if (!matriz) {
        printf("Falta memoria para alocar a matriz de ponteiros\n");
        exit(1);
  }
  for (i=0; i < nlinhas; i++) {
    matriz[i] = (float *) malloc(ncolunas*sizeof(float));
    if (!matriz[i]){
      printf("Falta memoria para alocar a matriz de ponteiros.\n");
      exit(1);
    }
  }
  return matriz;
}


/* libera memoria de um vetor */
void libera_vetor(int *vetor)
{
  free(vetor);
}


void libera_matriz(int **matriz, int nlinhas)
{
  register int i;

  for (i=nlinhas-1; i >= 0; i--)
    free((int *) matriz[i]);
  free((int *) matriz);
}


void libera_matriz_float(float **matriz, int nlinhas)
{
  register int i;

  for (i=nlinhas-1; i >= 0; i--)
    free((float *) matriz[i]);
  free((float *) matriz);
}



/* imprime a solucao */
void imprime_vetor(int *s, int n)
{
    for (int j=0; j < n; j++) printf("s[%2d]=%d \n",j,s[j]);
}


/* imprime a solucao */
void imprime_rota(int *s, int n)
{
    for (int j=0; j < n && s[j] != -1; j++) printf("%d -> ",s[j]);
    printf("%d \n",s[0]);
}


/* calcula a funcao objetivo */
float calcula_fo(int n, int *s, float **distancia)
{
    float dist_percorrida = 0;

    for ( int j=0; j < n-1; j++ ) {
//      printf("+d[%2d,%2d] = %f \n",s[j],s[j+1],distancia[s[j]][s[j+1]]);
      dist_percorrida += distancia[s[j]][s[j+1]];
    }
    dist_percorrida += distancia[s[n-1]][s[0]];
//    printf("Distancia=%f \n",dist_percorrida);
    return dist_percorrida;
}


/* Gera numero aleatorio entre min e max */
float randomico(float min, float max)
{
  if (min == max) return min;
  return ((float) (rand()%10000/10000.0)*(max-min) + min);
}


/* atualiza a melhor solucao */
void atualiza_vetor(int *s_star, int *s, int n)
{
   for (int j=0; j < n; j++) s_star[j] = s[j];
}


void inicializa_vetor(int *vetor, int tam)
{
    for (int j=0; j<tam; j++) vetor[j] = 0;
}


void inicializa_vetor_float(float *vetor, int tam)
{
    for (int j=0; j<tam; j++) vetor[j] = 0;
}


void embaralha_vetor(int *vetor, int n)
{
  int aux, j1, j2;

  for (int i=0; i < n; i++){
    j1 = random(n);
    j2 = random(n);
    while (j1 == j2) j2 = random(n);
    aux = vetor[j1];
    vetor[j1] = vetor[j2];
    vetor[j2] = aux;
  }
}


void insere_meio_vetor(int *vetor, int valor, int pos, int qde)
{
  int i = qde;
  while ((i > 0) && (i != pos)) {
    vetor[i] = vetor[i-1];
    i--;
  }
  vetor[i] = valor;
}


/* Procura a posição da cidade dada no vetor */
int busca_pos_valor(int *vetor, int cidade, int n)
{
  int i = 0;
  while (vetor[i] != cidade && i < n) i++;
  return i;
}

/* Retorna se uma cidade já foi inserida no vetor */
bool foi_inserida(int *vetor, int cidade, int n)
{
  for (int i = 0; i < n; i++)
    if (vetor[i] == cidade) return true;
  return false;
}

/* Calcula o desvio-padrão das fos da população */
float calcula_desvio_padrao(float *fo_pop, int n)
{
  float media, desvio, somatorio;

  somatorio = 0;
  for (int i = 0; i < n; i++)
    somatorio += fo_pop[i];
  media = somatorio / n;
  somatorio = 0;
  for (int i = 0; i < n; i++)
    somatorio += (fo_pop[i] - media) * (fo_pop[i] - media);
  desvio = sqrt(somatorio / (n - 1));

  desvio = desvio / media;
  return desvio;
}


/* Atualiza a matriz de arestas */
void atualiza_arestas(int **arestas, int n, int m, int prox_cid)
{
  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++)
      if (prox_cid == arestas[i][j]) {
        arestas[i][j] = -1;
        arestas[i][0] -= 1;
      }
}



