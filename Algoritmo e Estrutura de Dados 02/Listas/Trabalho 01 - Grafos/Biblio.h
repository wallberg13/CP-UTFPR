#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

//Biblioteca para Cabeçalhos

typedef struct NoTag{
  int desc;
  struct NoTag *link;  
}Arestas;

typedef struct NoLink{
  struct NoLink *link;
  Arestas *arest;
  int Vert;
}Vertices;

typedef struct{
  Vertices *vert;
}Grafo;

/**
 * Inicia o grafo, apenas apontando para o primeiro vertice dele;
 */
void inicia_grafo(Grafo *grafo);

/**
 * Add Vertices em um grafo, sabendo que não se pode add vertices repetidas
 * Ela apenas chama a add_vert
 */
int add_vertices(Grafo *grafo,int desc);

/**
 * Add Aresta em um grafo (Grafo sem direção)
 * RETORNA 0 CASO ENCONTRE ERROS
 */
int add_arestas(Grafo *grafo, int ini, int fim);

/**
 * Função para verificar uma vertice do grafo
 */
int pesquisa_vert(Grafo *grafo, int desc);

/**
 * Função para verificar uma aresta do grafo;
 * RETORNA 1 SE ACHAR, 0 SE NÃO ENCONTRAR E -1 CASO NÃO EXISTIR
 */
int pesquisa_arestas(Grafo *grafo, int ini, int fim);

/**
 * Função para remover arestas.
 * 
 */
int remover_arestas(Grafo *grafo,int ini, int fim);

/**
 * Função para remover Vertices(nós).
 */
int remover_vertices(Grafo *grafo, int Vert);

/**
 * A propria função de adicionar os vertices,
 * pois trabanho assim, só se usa toda a estrutura do grafo
 * RETORNA 0 SE NÃO CONSEGUIU, E 1 SE CONSEGUIU
 */
int add_vert(Vertices **vert, int desc);

/**
 * A Propria função de pesquisa o vertice, ele que ira fazer a verificação
 * RETORNA O NUMERO DO VERTICE SE ACHAR, E 0 SE NÃO ENCONTRAR
 */
int pesq_vert(Vertices **vert, int desc);

/**
 * A propria função de pesquisa a aresta dada, ele que ira fazer a verificação
 * RETORNA 0 DE NÃO EXISTIR E DESC SE ENCONTRAR
 */
int pesq_arest(Arestas **arest, int desc);

/**
 * A propria função que faz add as arestas
 * RETORNA 1 CASO SE DEU CERTO
 */
int add_arest(Arestas **arest,int desc);

/**
 * A propria função para remover somente as arestas.
 * RETORNA 0 SE NÃO DER CERTO E 1 SE DER
 */
int rem_arest(Arestas **arest,int desc);

/**
 * Função de teste dos vertices;
 */
int imprime_vertices(Vertices **vert);

/**
 * Função de teste para imprimir arestas!
 */
int imprime_arestas(Arestas **arest);

/**
 * Função que retorna 0 caso a vertice existir e retorna o ponteiro 
 * de Vertice caso existir
 */
Vertices* get_vertices(Vertices **vert,int desc);

/** FUNÇÕES DE MENU*/
void menu();

void interface1(Grafo *grafo);
void interface2(Grafo *grafo);
void interface3(Grafo *grafo);
void interface4(Grafo *grafo);
void interface5(Grafo *grafo);

void aperta(){
  system("read a");
}

#endif //BIBLIO_H_INCLUDED