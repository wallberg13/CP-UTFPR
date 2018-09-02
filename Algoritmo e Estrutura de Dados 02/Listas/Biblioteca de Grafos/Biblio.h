#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

int quant_vertices;
int tempo;

/**
 * Funções para limpar Buffer, apagar e aperta tanto do windows como linux;
 */
void buffer(){
#ifdef __unix__
  __fpurge(stdin);
#elif defined (_WIN32) || defined(WIN32)
  fflush(stdin);
#endif  
}

void clear(){
#ifdef __unix__
  system("clear");
#elif defined (_WIN32) || defined(WIN32)
  system("cls");
#endif 
}

void aperta(){
#ifdef __unix__
  system("read a");
#elif defined (_WIN32) || defined(WIN32)
  getchar();
#endif
}

//Biblioteca para Cabeçalhos
typedef struct NoTag{
  int desc;
  int ini;
  struct NoTag *link;  
  int peso;
}Arestas;

typedef struct NoLink{
  /** Grafo ORIGINAL*/
  struct NoLink *link; //Lista de vertices
  int Vert; //Descrição do Vertice
  Arestas *arest;
  int Grau;
  
  /** Variaveis que ira ser reutilizadas em todo o codigo*/
  struct NoLink *pai;
  int d; //Distancia da origem
  int cor; //0 p/ Vertice nunca visitado, 1 p/ vertice visitado, 2 p/ todas a
  //arestas já tenha sida visitada. No Dijkstra, ira servir de flag. (0 para esta na 
  //fila de prioridades e 1 para esta no conjunto solução)
  
  /** SUBGRAFO - PESQUISA - PROFUNDIDADE*/
  int tim[2]; //Posição 0 para tempo de descoberta e posição 1 para tempo final
}Vertices;

typedef struct { 
  Vertices *vert;
  int quant_vertices;
  int quant_arestas;
}Grafo;

typedef struct No{
  struct No *link;
  Vertices *vert;
}Fila;

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
int add_arestas(Grafo *grafo, int ini, int fim,int peso);

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
int add_arest(Arestas **arest,int desc,int ini,int peso);

/**
 * A propria função para remover somente as arestas.
 * RETORNA 0 SE NÃO DER CERTO E 1 SE DER
 */
int rem_arest(Arestas **arest,int desc);

/**
 * Função que imprime os vertices e suas arestas;
 */
int imprime_vertices_grafo_original(Vertices **vert);

/**
 * Função de teste para imprimir arestas!
 */
int imprime_arestas(Arestas **arest);

/**
 * Função que retorna NULL caso a vertice não existir e retorna o ponteiro 
 * de Vertice caso existir
 */
Vertices* get_vertices(Vertices **vert,int desc);

/** FUNÇÕES DE MENU*/
void menu();

void interface1(Grafo *grafo); //Adicionar Vertices
void interface2(Grafo *grafo); //Adicionar Arestas
void interface3(Grafo *grafo); //Remover Vertices
void interface4(Grafo *grafo); //Remover Arestas
void interface5(Grafo *grafo); //Exibir Grafo
void interface6(Grafo *grafo); //Menu para Busca em Largura
void interface7(Grafo *grafo); //Verificar se o Grafo é Conexo
void sub_interface1(Grafo *grafo); //Sub Menu para o Menu de Busca em Largura
void interface8(Grafo *grafo); //Transforma o grafo em matriz de adjacencias.
void interface9(Grafo *grafo); //Gerar grafo de busca em Profundidade
void interface10(Grafo *grafo); //Interface para o caminho minimo. Alg. de Dijkstra
void interface11(Grafo *grafo); //Interface do algoritmo de Primm.
void interface12(Grafo *grafo); //"Importar" Grafo proposto para correção.

/** FUNÇÕES NECESSARIAS PARA BUSCA EM PROFUNDIDADE E EM LARGURA **/

/** Funções basicas de uma Fila, Inicia, add inicio e remove fila*/
int add_inicio(Fila **f,Vertices *v);
int inicia_fila(Fila **f);
int add_pilha(Fila **f,Vertices *v);
Vertices* remove_fila(Fila **f);
Vertices* remove_pilha(Fila **f);

/**Algoritmos de busca em largura */
int busca_em_largura(Grafo *g, Vertices *s);
int inicia_busca_largura(Grafo *g, Vertices *s);

/** Função para gerar e imprimir o Grafo de Busca em largura e como 
 argumento, o vertice desejado.*/
int imprime_vertices_grafo_largura(Grafo *g,int desc);


/**
 * Funções necessarias para o algoritmo de busca em profundidade.
 */

/**
 * Função para imprimir o pai de todos os Vertices de busca em
 * profundidade.
 */
int imprime_busca_em_profundidade(Grafo *g);
int inicia_b_em_prof(Vertices *v);
int busca_em_profundidade(Grafo *g);
int busca_em_prof_visit(Vertices *v, Grafo *g);



/**
 * Função para verificar se o grafo é Conexo
 * O grafo é conexo se estiver todo interligado, ou seja,
 * se as suas listas de adjacencias não estiverem vazia;
 */
int verifica_conexo(Grafo *grafo);

/**
 * Funções para gerar a matriz de adjacencias do grafo.
 */
int gerar_matriz(Grafo *grafo);
int imprime_matriz(int v[quant_vertices][quant_vertices], int i, int j);

/*
 * Retorna a posição que devo adicionar cada item da matriz
 * de adjacencias.
 */
int get_posicao(int matriz[quant_vertices][quant_vertices],int i,int j, int *k, int *h);

/**
 * Funções NECESSARIAS para o algoritmo de Dijkstra.
 */


/**
 * Função para tratar os dados vindos da sua interface,retorna 0 se não for
 * possivel executar o algoritmo(caso em que um dos vertices não exista).
 */
int CaminhoMinimo(Grafo *g, int i, int j);

/**
 * Executa o algoritmo de Dijkstra, ele configura os pais de cada vertice e 
 * tem como origem o vertice que é passado pelo o argumento.
 */
void Dijkstra(Grafo *g,Vertices *ini);

/**
 * Função para aplicar o relaxamento em dois vertices.
 */
void relax(Vertices *u, Vertices *v);

/**
 * Função de inicialização do algoritmo de Dijkstra.
 */
void inicia_dijkstra(Grafo *g,Vertices *v);

/**
 * Função para imprimir o caminho minimo percorrido entre um vertice e outro.
 */
void imprimir_caminho(Vertices **ini, Vertices **fim);

/**
 * Função que extrai o caminho minimo, ele tira o vertice da fila de prioridades
 * minima mudando a flag(variavel cor) de 0 para 1, assim, esse vertice extraido
 * já esta no conjunto solução não podendo ser alterado.
 */
Vertices* extrair_minimo(Grafo *g);

/**
 * Função que ira fazer uma verificação da flag em todas as vertices.
 * Se a flag estiver em 0, é porque ainda tem elementos na fila de prioridades.
 * Retorna 0 se ainda tiver elementos, e retorna 1 caso não tiver.
 */
int verifica_fila_vazia(Vertices **v);

/**
 * Funções NECESSARIAS para Primm
 */
int arvore_minima(Grafo *g);

void Primm(Grafo *g);

int get_peso(Vertices *ini,Vertices *fim);
#endif //BIBLIO_H_INCLUDED