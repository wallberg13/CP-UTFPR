#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFINITO 99999
#define VELOCIDADE 13.89
#define MAX 5

/**
 * Limpar Buffer do teclado, limpar tela e aperta,
 * é necessario uma função para poder ter o mesmo efeito tanto se
 * o programa for executado no linux como no windows.
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

int quant_vertices;


//Biblioteca para Cabeçalhos
typedef struct NoTag{
  int desc;
  int ini;
  struct NoTag *link;  
  int peso;
  int cong; //Flag que diz se a aresta esta ou não congestionada
}Arestas;

typedef struct NoLink{
  /** Grafo ORIGINAL*/
  struct NoLink *link; //Lista de vertices
  int Vert; //Descrição do Vertice
  Arestas *arest;
  int Grau;
  char nome[50];
  /** Variaveis que ira ser reutilizadas em todo o codigo*/
  struct NoLink *pai;
  int d; 
  int flag; 
  
}Vertices;

typedef struct { 
  Vertices *vert;
  int quant_vertices;
  int quant_arestas;
}Grafo;

typedef struct No{
  struct No *link;
  Vertices *vert;
}Pilha;

/**
 * Inicia o grafo, apenas apontando para o primeiro vertice dele;
 */
void inicia_grafo(Grafo *grafo);

/**
 * Add Vertices em um grafo, sabendo que não se pode add vertices repetidas
 * Ela apenas chama a add_vert
 */
int add_vertices(Grafo *grafo,int desc,char nome[50]);

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
int add_vert(Vertices **vert, int desc,char nome[50]);

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
int imprime_vertices_grafo(Grafo *grafo);

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
void interface1(Grafo *grafo); //Adicionar Locais
void interface2(Grafo *grafo); //Adicionar Vizinhos
void interface3(Grafo *grafo); //Remover Locais
void interface4(Grafo *grafo); //Remover Vizinhos
void interface5(Grafo *grafo); //Exibir GPS
void interface6(Grafo *grafo); //Traçar Rota
void interface7(Grafo *grafo); //Adiciona Congestionamento
void interface8(Grafo *grafo); //"Importar" Grafo proposto para correção.

/**
 * Funções basicas de uma Fila, Inicia, add inicio e remove fila
 * Essas funções são utilizadas somente na hora de imprimir o caminho, pois o algoritmo de Dijkstra
 * ele da o caminho de tras para frente, mas para exibir o caminho na ordem certa, é necessaria o 
 * uso de uma pilha.
 */
int inicia_pilha(Pilha **f);
int add_pilha(Pilha **f,Vertices *v);
Vertices* remove_pilha(Pilha **f);


/**
 * Funções NECESSARIAS para o algoritmo de Dijkstra (Para executar o caminho minimo).
 */
/**
 * Função para tratar os dados vindos da sua interface,retorna 0 se não for
 * possivel executar o algoritmo(caso em que um dos vertices não exista).
 */
int CaminhoMinimo(Grafo *g, int i, int j,int flag, int k);

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
 * Função que altera o mapa fazendo assim um consestionamento.
 * 	flag = Resposta do Usuario;
 * 	i = Local de Inicio
 * 	j = Local de Chegada
 */
int adiciona_remove_congestionamento(Grafo *grafo,int flag,int i, int j);

/**
 * Função para generalizar na hora de dobrar o peso entre dois vizinhos ou dividir(retirar o Congestionamento).
 */
int muda_peso(Arestas *arest,int flag);

/**
 * Função para imprimir somente os vertices.
 */
void print_vertice(Grafo *grafo);

/**
 * Função para destruir o grafo.
 * Utilizada quando encerrar o programa
 */
void destroi_grafo(Grafo *g);

/**
 * Função que sera utilizada no destroi_grafo, basicamente essa função 
 * exclui o primeiro elemento da lista de arestas, pois na hora de destruir todas as listas
 * é mais rapido para excluir o primeiro.
 */
void rem_are(Arestas **arest);

/**
 * Na Struct dos Vertices, possui as variaveis:
 * 	pai, d, e flag.
 * quando é executado o algoritmo de Dijkstra, essas variaveis ganham valores, para não dá
 * problemas futuros, esses valores são retirados, assim, o pai de todos vertices
 * igual a nulo, flag = 0 e d = 0;
 */
void limpa(Vertices *v);

#endif //BIBLIO_H_INCLUDED
