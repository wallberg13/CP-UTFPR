#ifndef BUSCAS_C_INCLUDED
#define BUSCAS_C_INCLUDED
#include "Biblio.h"
#include "Grafos.c"
#define INFINITO 99999

/** Função para iniciar uma fila.*/
int inicia_fila(Fila **f){
  *f = NULL;
}

int add_fila(Fila **f,Vertices *v){
  Fila *aux,*aux1;
  aux = (Fila *)malloc(sizeof(Fila));
  aux->vert = v;
  aux->link = NULL;
  if(*f == NULL)
    *f = aux;
  else{
    aux1 = *f;
    while(aux1->link != NULL)
      aux1 = aux1->link;
    aux1->link = aux;
  }
  return 1;
}

int add_pilha(Fila **f, Vertices *v){
  Fila *aux, *ele;
  ele = (Fila *)malloc(sizeof(Fila));
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

Vertices* remove_fila(Fila **f){
  Fila *aux;
  Vertices *r;
  if(*f != NULL){
    aux = (*f)->link;
    r = (*f)->vert;
    free(*f);
    *f = aux;
    return r;
  }else
    return NULL;
}

Vertices* remove_pilha(Fila **f){
  Fila *aux,*aux2;
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

int inicia_busca_largura(Grafo *g, Vertices *s){
  Vertices *aux;
  aux = g->vert;
  while(aux != NULL){
    if(aux != s){
      aux->cor = 0;
      aux->pai = NULL;
      aux->d = INFINITO;
    }
    aux = aux->link;
  }
}


int busca_em_largura(Grafo *g, Vertices *s){
  Vertices *aux,*aux2;
  Arestas *aux1;
  Fila *f;
  int d;
  inicia_fila(&f);
  inicia_busca_largura(g,s);
  s->cor = 1;
  s->pai = NULL;
  s->d = 0;
  
  add_fila(&f,s);
  while(f!=NULL){
    aux = remove_fila(&f);
    aux1 = aux->arest;
    while(aux1 != NULL){
      aux2 = get_vertices(&g->vert,aux1->desc); 
      if(aux2->cor == 0){
	aux2->pai = aux;
	aux2->cor = 1;
	aux2->d = aux1->peso + aux2->pai->d;
	add_fila(&f,aux2);
      }
      aux1 = aux1->link;
      aux->cor = 2;
    }
  }
}

int imprime_vertices_grafo_largura(Grafo *g,int desc){
  Vertices *aux,*aux1;
  aux1 = get_vertices(&g->vert,desc);
  
  if(aux1 == NULL || g->vert == NULL)
    return 0;
  
  busca_em_largura(g,aux1);
  
  aux = g->vert;
  
  printf("Vertice  Pai \t Distancia \n");
  while(aux != NULL){
    if(aux->pai == NULL)
      printf("%02d \t Origem.!\n",aux->Vert);
    else{
      if(aux->d == INFINITO)
	printf("%02d \t Inalcançável\n",aux->Vert);
      else
	printf("%02d \t %02d \t %02d \n",aux->Vert,aux->pai->Vert,aux->d);
    }
    aux = aux->link;
  }
  printf("\n");
  
  return 1;
}

int imprime_busca_em_profundidade(Grafo *g){
  Vertices *aux,*aux1;
  
  if(g->vert == NULL)
    return 0;
  
  busca_em_profundidade(g);
  
  aux = g->vert;
  
  printf("V. (T.d,T.f) Pai\n");
  while(aux != NULL){
    if(aux->pai != NULL)
      printf("%d (%d,%d) -> %d",aux->Vert,aux->tim[0],aux->tim[1],aux->pai->Vert);
    else
      printf("%d (%d,%d) -> Sem Pai! ",aux->Vert,aux->tim[0],aux->tim[1]);
    printf("\n");
    aux = aux->link;
  };
  
  return 1;
  
}

int inicia_b_em_prof(Vertices *v){
  Vertices *aux;
  aux = v;
  while(aux != NULL){
    aux->cor = 0;
    aux->pai = NULL;
    aux = aux->link;
  }
}

int busca_em_profundidade(Grafo *g){
  Vertices *aux;
  aux = g->vert;
  tempo = 0;
  inicia_b_em_prof(aux);
  while(aux != NULL){
    if(aux->cor == 0){
      busca_em_prof_visit(aux,g);
    }
    aux = aux->link;
  }
}

int busca_em_prof_visit(Vertices *v, Grafo *g){
  Arestas *aux;
  Vertices *aux1;
  v->cor = 1;
  tempo++;
  v->tim[0] = tempo;
  aux = v->arest;
  while(aux != NULL){
    aux1 = get_vertices(&g->vert,aux->desc);
    if(aux1->cor == 0){
      aux1->pai = v;
      busca_em_prof_visit(aux1,g);
    }
    aux = aux->link;
  }
  v->cor = 2;
  tempo++;
  v->tim[1] = tempo;
}

/** FUNÇÕES PARA O ALGORITMO DE DIJKTRA!! */
int CaminhoMinimo(Grafo *g, int i, int j){
  Vertices *ini, *fim;
  ini = get_vertices(&g->vert,i);
  fim = get_vertices(&g->vert,j);
  
  if(ini == NULL || fim == NULL)
    return 0;
  
  Dijkstra(g,ini);
  if(fim->pai == NULL){
    printf("Vertice não alcanvel pela a origem.");
  }else{ 
    printf("Caminho percorrido: \n");
    imprimir_caminho(&ini,&fim);
    
    printf("A distancia entre %d e %d ´e de: %d \n",i,j,fim->d);
  }
  ini = g->vert;
  while(ini != NULL){
    ini->pai = NULL;
    ini->d = 0;
    ini->cor = 0;
    ini = ini->link;
  }
  return 1;
}

void Dijkstra(Grafo *g,Vertices *ini){
  Arestas *aux;
  Vertices *aux1,*min;
  inicia_dijkstra(g,ini);
  
  while(!verifica_fila_vazia(&g->vert)){
    min = extrair_minimo(g);
    aux = min->arest;
    while(aux != NULL){
      aux1 = get_vertices(&g->vert,aux->desc);
      if(aux1->cor == 0)
	relax(min,aux1);
      aux = aux->link;
    }
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



void imprimir_caminho(Vertices **ini, Vertices **fim){
  Vertices *aux;
  aux = *fim;
  Fila *p;
  inicia_fila(&p);
  while(aux != NULL){
    add_pilha(&p,aux);
    aux = aux->pai;
  }
  while(p->link != NULL){
    aux = remove_pilha(&p);
    printf("%d -> ",aux->Vert);
  }
  aux = remove_pilha(&p);
  printf("%d. \n",aux->Vert);
  
}

void inicia_dijkstra(Grafo *g, Vertices *v){
  Vertices *aux;
  aux = g->vert;
  while(aux != NULL){
    if(aux != v){
      aux->d = INFINITO;
      aux->pai = NULL;
      aux->cor = 0; //Flag fica 0 pois esta na lista de prioridades.
    }else{
      aux->d = 0;
      aux->cor = 0;
    }
    aux = aux->link;
  }
}

Vertices* extrair_minimo(Grafo *g){
  Vertices *aux, *min;
  aux = g->vert;
  int Min = INFINITO;
  
  while(aux != NULL){
    if(aux->d < Min && aux->cor == 0){
      min = aux;
      Min = aux->d;
    }
    aux = aux->link;
  }
  min->cor = 1; //Como o min ira sair da fila de prioridade minima,
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
    if(aux->cor == 0)
      return 0;
    aux = aux->link;
  }
  return 1;
}

/**
 * Funções Referentes ao algoritmo de Primm.
 */
int arvore_minima(Grafo *g){
  if(g->vert == NULL)
    return 0;
  Vertices *aux;
  aux = g->vert;
  
  Primm(g);
  
  printf("Vertice  Pai\n");
  while(aux != NULL){
    if(aux == g->vert)
      printf("%02d \t Origem.!\n",aux->Vert);
    else{
      if(aux->pai == NULL)
	printf("%02d \t Inalcançável\n",aux->Vert);
      else
	printf("%02d \t %02d \n",aux->Vert,aux->pai->Vert);
    }
    aux = aux->link;
  }
  printf("\n");
  aux = g->vert;
  while(aux != NULL){
    aux->pai = NULL;
    aux->d = 0;
    aux->cor = 0;
    aux = aux->link;
  }
}

int get_peso(Vertices *ini, Vertices *fim){
  Arestas *aux;
  aux = ini->arest;
  while(aux != NULL && aux->desc != fim->Vert){
    aux = aux->link;
  }
  return aux->peso;
}

/**
 * Algoritmo de Primm, muito semelhante com Djistra, existe diferenças, e aproveitamento
 * de variaveis presentes na struct de Vertices.
 * Variavel:
 * 	d = Distancia entre o vertice e o seu pai.
 * 	pai = O pai de sempre, cujo aparece tanto em Dijkstra, Busca em Largura e Profundidade
 * 	cor = Flag que define se o vertice esta na fila de prioridade minima ou 
 * 	    = no conjunto solução do algoritmo. (0 = Esta na Fila de prioridades,
 * 	    = 1 = esta no conjunto solução.).
 */
void Primm(Grafo *g){
  Arestas *aux;
  Vertices *aux1,*min;
  inicia_dijkstra(g,g->vert); //A forma que Dijkstra inicia é a mesma forma que
  //o algoritmo de primm inicia tbm. Considero a origem no começo do grafo.
  
  while(!verifica_fila_vazia(&g->vert)){
    min = extrair_minimo(g);
    aux = min->arest;
    while(aux != NULL){
      aux1 = get_vertices(&g->vert,aux->desc);
      if(!aux1->cor && get_peso(min,aux1) < aux1->d){ 
	aux1->pai = min;
	aux1->d = get_peso(min,aux1);
      }
      aux = aux->link;
    }
  }
}

#endif //BUSCAS_C_INCLUDED
