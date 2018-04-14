#ifndef BUSCAS_C_INCLUDED
#define BUSCAS_C_INCLUDED
#include "Biblio.h"
#include "Grafos.c"

/** Função para iniciar uma fila.*/
int inicia_pilha(Pilha **f){
  *f = NULL;
}

/**
 * Função para adicionar um elemento em uma pilha, nesse caso, os elementos
 * dentro desta pilha são ponteiros de vertices.
 * É util na hora de imprimir o caminho minimo na ordem de inicio para fim,
 */
int add_pilha(Pilha **f, Vertices *v){
  Pilha *aux, *ele;
  ele = (Pilha *)malloc(sizeof(Pilha));
  ele->vert = v;
  ele->link = NULL;
  aux = *f;
  if(aux == NULL){
    *f = ele;
  }else{
    while(aux->link != NULL)
      aux = aux->link;
    aux->link = ele;
  }
  return 1;
}

/**
 * Função para remover em uma pilha, usada na hora de mostrar os caminhos minimos,
 * pois depois que empilhar, é preciso desipilhar todos os elementos da pilha.
 */
Vertices* remove_pilha(Pilha **f){
  Pilha *aux,*aux2;
  Vertices *r;
  if(*f == NULL){
    return NULL;
  }else{
    aux = *f;
    aux2 = NULL;
    while(aux->link != NULL){
      aux2 = aux;
      aux = aux->link;
    }
    if(aux2 != NULL){
      aux2->link = NULL;
    }else
      *f = NULL;
    r = aux->vert;
    free(aux);
    return r;
  }
}

/** FUNÇÕES PARA O ALGORITMO DE DIJKTRA!! */
/**
 * A questão do Caminho minimo, foi usado o algoritmo de Dijkstra, pois o retorno
 * deste algoritmo gera o caminho minimo entre dois pontos.
 */
int CaminhoMinimo(Grafo *g, int i, int j,int flag, int k){
  Vertices *ini, *fim, *inter;
  float t; int rest;
  ini = get_vertices(&g->vert,i);
  fim = get_vertices(&g->vert,j);
  clear();
  if(flag)
    inter = get_vertices(&g->vert,k);
  
  if(ini == NULL || fim == NULL)
    return 0;
  if(!flag){
    Dijkstra(g,ini);
    if(fim->pai == NULL){
      printf("Não é possivel traçar uma rota entre os dois locais.\n");
      return 0;
    }else{ 
      printf("Caminho percorrido: \n");
      imprimir_caminho(&ini,&fim);
      t = ((fim->d)/VELOCIDADE)/60;
      printf("A distancia entre o ponto inicial e final é de: %d m\n",fim->d);
      printf("Mantendo a velocidade de 50km/h, o tempo total do trajeto é de: %.2f min\n",t);
    }
  }else{
    Dijkstra(g,ini);
    if(fim->pai == NULL){
      printf("Não é possivel traçar uma rota entre os dois locais.\n");
      return 0;
    }else{ 
      printf("Caminho percorrido (Do inicio ao Intermediario): \n");
      imprimir_caminho(&ini,&inter);
      t = ((inter->d)/VELOCIDADE)/60;
      printf("A distancia entre o inicio e intermediario é de: %d m\n",inter->d);
      printf("Mantendo a velocidade de 50km/h, o tempo até o ponto intermediario é de: %.2f min \n",t);
    }
    limpa(g->vert);
    printf("\n\n");
    
    Dijkstra(g,inter);
    if(fim->pai == NULL){
      printf("Não é possivel traçar uma rota entre os dois locais.\n");
      return 0;
    }else{ 
      printf("Caminho percorrido (Do intermediario ate o final): \n");
      imprimir_caminho(&inter,&fim);
      t += ((fim->d)/VELOCIDADE)/60;
      printf("A distancia entre o intermediario e o fim é de: %d m\n",fim->d);
      printf("Mantendo a velocidade de 50km/h, o tempo total entre o inicio e o fim é de: %.2f min \n",t);
    }
  }
  
  limpa(g->vert);
  
  return 1;
}

/**
 * Esta função é a função que gera os caminhos minimos.
 * Ela consiste no seguinte, quando eu chamo o inicia_dijkstra, ela ira setar
 * todos os valores de d,pai e flag da struct Vertices, como INFINITO, NULL  e 0 respectivamente
 * menos no vertice de inicio que o D = 0;
 * 	Pai = é o local mais proximo a partir de outro local.
 * 
 *	flag = é a variavel que vai dizer se eu já analisei todos os vizinhos de um 
 * 	determinado vertice(se isso acontecer, o seu valor é 1,e se isso acontecer
 * 	significa que este local esta no conjunto solução do algoritmo.);
 *
 * 	d = distancia entre o local que eu estou ate a origem que eu escolhi como 
 * 	o local inicial.
 * 
 * Este algoritmo usa a tecnica de relaxamento que consiste no seguinte: Quando eu 
 * analisar um vertice, eu eu vi que a distancia que esse local(vertice) esta setado
 * é maior do que a distancia do vertice que eu estou(local) + o peso entre os locais, ou seja,
 * as distancias, aplica-se o relaxamento.
 * 
 * extrair_minimo minimo é a função que sempre tira da lista de prioridade minima(os elementos
 * que estão nessa lista, são aqueles que tem flag = 0.), depois de tirar o elemento desta
 * "lista", ele seta a flag para 1 (dizendo que esse local já foi analisado.)
 * 
 * Lembrando que esse algoritmo ira ser executado em quanto tiver locais com a flag = 0;
 */
void Dijkstra(Grafo *g,Vertices *ini){
  Arestas *aux;
  Vertices *aux1,*min;
  inicia_dijkstra(g,ini);
  
  while(!verifica_fila_vazia(&g->vert)){
    min = extrair_minimo(g);
    aux = min->arest;
    while(aux != NULL){
      aux1 = get_vertices(&g->vert,aux->desc);
      if(aux1->flag == 0)
	relax(min,aux1);
      aux = aux->link;
    }
  }
}

/**
 * Função para setar os valores ultilizados no algoritmo de Dijkstra,
 * assim, não dando possibilidade para alguma parte do programa usar o valor dessas
 * variaveis, mas somento no algoritmo do caminho minimo.
 */
void limpa(Vertices *v){
  Vertices *ini;
  ini = v;
  while(ini != NULL){
    ini->pai = NULL;
    ini->d = 0;
    ini->flag = 0;
    ini = ini->link;
  }
}
//U é de inicio, e v para o vertice de chegada
void relax(Vertices *u, Vertices *v){
  int w;
  
  Arestas *aux;
  aux = u->arest;
  
  //Percorrendo a lista de adjacencias do vertice de inicio ate achar
  //O vertice que que ele liga, onde esse vertice será verificado se 
  //precisa fazer o relaxamento ou não.
  
  while(aux != NULL && aux->desc != v->Vert){
    aux = aux->link;
  }
  w = aux->peso;
  
  if(v->d > w + u->d){
    v->d = w + u->d;
    v->pai = u;
  }
}


/**
 * Função para exibir o caminho percorrido. Como não dá para percorrer do inicio para o fim, 
 * e sim do fim para o inicio. É preciso o uso de uma pilha para que o caminho 
 * possa ser visto do inicio para o fim.
 */
void imprimir_caminho(Vertices **ini, Vertices **fim){
  Vertices *aux;
  aux = *fim;
  Pilha *p;
  /**
   * Aqui é onde é adicionando os vertices do fim para o inicio na pilha.
   */
  inicia_pilha(&p);
  while(aux != NULL){
    add_pilha(&p,aux);
    aux = aux->pai;
  }
  
  /**
   * Como o ultimo elemento adicionado na pilha é o elemento de inicio, eu removo
   * ele fora do laço para dar um destaque estetico na hora de exibir os caminhos.
   * A pilha vai removendo do topo assim exibindo os elementos na ordem certa.
   */
  aux = remove_pilha(&p);
  printf("%d - %s \n",aux->Vert,aux->nome);
  
  while(p->link != NULL){
    aux = remove_pilha(&p);
    printf("\t%d - %s\n",aux->Vert,aux->nome);
  }
  aux = remove_pilha(&p);
  printf("%d - %s \n",aux->Vert,aux->nome);
  
}

/**
 * Como mensionado no cabeçalho do algoritmo de Dijkstra, é a função que inicializa
 * as variaveis da struct de Vertices(locais) que será utilizada para a execução do
 * algoritmo de Dijkstra. Lembrando que somente a origem será inicializada com d = 0,
 * o d dos outros elementos será inicializados com um d INFINITO(Os valores de d para 
 * cada local vai mudando quando se aplica a tecnica do relaxamento.).
 */
void inicia_dijkstra(Grafo *g, Vertices *v){
  Vertices *aux;
  aux = g->vert;
  while(aux != NULL){
    if(aux != v){
      aux->d = INFINITO;
      aux->pai = NULL;
      aux->flag = 0; //Flag fica 0 pois esta na lista de prioridades.
    }else{
      aux->d = 0;
      aux->flag = 0;
    }
    aux = aux->link;
  }
}
/**
 * Função para extrair o local com a menor distancia, no momento que esse elemento é 
 * removido da fila de prioridade minima (flag = 0) ele vai para o conjunto solução
 * do problema(flag = 1).
 * Essa função percorre toda a lista sempre procurando o elemento com o menor d.
 */
Vertices* extrair_minimo(Grafo *g){
  Vertices *aux, *min;
  aux = g->vert;
  int Min = INFINITO;
  
  while(aux != NULL){
    if(aux->d < Min && aux->flag == 0){
      min = aux;
      Min = aux->d;
    }
    aux = aux->link;
  }
  min->flag = 1; //Como o min ira sair da fila de prioridade minima,
		//Mudando a flag ele já vai direto para o conjunto solução.
  return min;
}

/** 
 * Verifica as Flags, se ele achar alguma flag setada em 0, a Função retorna
 * 0 informando que a fila de prioridade minima não esta vazia.
 */
int verifica_fila_vazia(Vertices **v){
  Vertices *aux;
  aux = *v;
  while(aux != NULL){
    if(aux->flag == 0)
      return 0;
    aux = aux->link;
  }
  return 1;
}
#endif //BUSCAS_C_INCLUDED
