#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

	Como Usar: Só colocar Load(nomeArquivo, vetorDeDuasPosicoes);
	Vetor de duas posições irá definir a dimensão do vetor.
	O que retorna: Uma matriz de int.
	Como fazer para ignorar a ultima coluna: diminui a dimensão da
	coluna, que é a a posicao 1 do vetor.
	As vezes a matriz vem com rotulo, e as vezes não, então tomar cuidado,
	no programa, colocar uma frag.
*/

typedef struct Next{
  struct Next *prox;
  int i;
  int j;
  int val;
}Coluna;

/**
  Cabeça da estrutura.
*/
typedef struct NextLin{
  struct NextLin *prox;
  Coluna *col;
  int i;
}Linha;


typedef struct NextChar{
  struct NextChar *prox;
  char *val;
}CharZao;

/**
  Funções em Load.c
*/
int** loadInt(char *arq,int *dim);
Coluna* cata_Colu(char *text, int y);

/**
  Funções em Matriz.c
*/
void ini_Coluna(Coluna **col);
void ini_Linha(Linha **lin);
int add_Coluna_Fim(Coluna **col,int i, int j, int val);
int add_Linha_Fim(Linha **lin, int i, Coluna *col);
void print_Matriz(Linha *lin);
int** converte_Matriz(Linha **lin,int *dim);
int** cria_Matriz(int i, int j);
int cont_Coluna(Linha **lin);
void print_Matriz2(int **mtz, int *dim);
int rem_Coluna_Ini(Coluna **col);
int rem_Linha_Ini(Linha **lin);
int limpa_Coluna(Coluna **col);
int limpa_Linha(Linha **lin);


/**
  Funções em LoadChar.c
*/
CharZao* loadStr(char *arq,int *x);
int cata_Colu_char(char *text, CharZao **cz);

/**
  Funções em CharZao.c
*/
int ini_CharZao(CharZao **cz);
int add_CharZao_Fim(CharZao **cz, char *c);
int rem_CharZao_ini(CharZao **cz);
void limpa_CharZao(CharZao **cz);
void print_CharZao(CharZao *cz);
#endif
