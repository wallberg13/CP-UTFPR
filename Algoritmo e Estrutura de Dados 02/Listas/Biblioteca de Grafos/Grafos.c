#ifndef GRAFOS_C_INCLUDED
#define GRAFOS_C_INCLUDED

#include "Biblio.h"


//Inicializa grafo apontando para um vertice;
void inicia_grafo(Grafo *grafo){
  grafo->vert = NULL;
  grafo->quant_arestas = 0;
  grafo->quant_vertices = 0;
}

/** PARTE PARA ADICIONAR!!! */
int add_vertices(Grafo *grafo,int desc){
  if(add_vert(&grafo->vert,desc))
    grafo->quant_vertices++;
  else
    return 0;
  return 1;
}

int pesquisa_vert(Grafo *grafo,int desc){
  return pesq_vert(&grafo->vert,desc);
}

/** É a mesma coisa de add em lista encadeada, a diferença é que não 
 pode ser adicioando vertice que já existe */
int add_vert(Vertices **vert, int desc){
  Vertices *v, *aux;
  
  if(pesq_vert(vert,desc) != 0)
    return 0;
  
  v = (Vertices *)malloc(sizeof(Vertices));
  v->Vert = desc;
  v->link = NULL;
  v->arest = NULL;
  v->Grau = 0;
  
  if(*vert == NULL){
    *vert = v;
  }else{
    aux = *vert;
    while(aux->link != NULL)
      aux = aux->link;
    aux->link = v;
  }
  return 1;
}

/** 
 * Função que verifica se o vertice existe, retorna a descrição do vertice caso
 * ele exista, e 
 */
int pesq_vert(Vertices **vert, int desc){
  Vertices *aux;
  aux = *vert;
  while(aux != NULL && aux->Vert != desc)
    aux = aux->link;
  if(aux != NULL)
    return desc;
  else
    return 0;
}

int imprime_vertices_grafo_original(Vertices **vert){
  Vertices *aux;
  aux = *vert;
  
  if(aux == NULL){
    printf("Grafo Vazio!! \n");
    return 0;
  }
  
  printf("V. Arestas\n");
  while(aux != NULL){
    printf("%d: ",aux->Vert);
    printf(" Vertice de grau: %d \n ",aux->Grau);
    imprime_arestas(&aux->arest);
    printf("\n");
    aux = aux->link;
  };
}

int add_arestas(Grafo *grafo, int ini, int fim,int peso){
  Vertices *v;
  
  int i = pesquisa_arestas(grafo,ini,fim);
  if(i || i == -1)
    return 0;
  
  if(ini == fim){
    v = get_vertices(&grafo->vert,fim);
    v->Grau++;
    add_arest(&v->arest,ini,ini,peso);
  }else{
    v = get_vertices(&grafo->vert,ini);
    v->Grau++;
    add_arest(&v->arest,fim,ini,peso);
    
    v = get_vertices(&grafo->vert,fim);
    v->Grau++;
    add_arest(&v->arest,ini,fim,peso);
  }
  grafo->quant_arestas++;
  return 1;    
}

int add_arest(Arestas **arest,int desc,int ini,int peso){
  Arestas *aux, *v,*aux1;
  
  v = (Arestas *)malloc(sizeof(Arestas));
  v->desc = desc;
  v->peso = peso;
  v->ini = ini;

  if(*arest == NULL){
    *arest = v;
    v->link = NULL;
  }else{
    aux = *arest;
    aux1 = NULL;
    while(aux != NULL && aux->peso <= peso){
      aux1 = aux;
      aux = aux->link;
    }
    if(aux1 == NULL){
      v->link = aux;
      *arest = v;
    }else{
      v->link = aux;
      aux1->link = v;
    }
    
    
  }
  return 1;
}

int imprime_arestas(Arestas **arest){
  Arestas *aux;
  aux = *arest;
  
  if(*arest != NULL)
    printf("->");
  
  while(aux != NULL){
    if(aux->link != NULL)
      printf(" %d -> ",aux->desc);
    else
      printf(" %d.",aux->desc);
    aux = aux->link;
  }
  
}

//Função para verificar se a aresta existe;
int pesquisa_arestas(Grafo *grafo, int ini, int fim){
  Vertices *v;
  
  v = grafo->vert;
  while(v!=NULL && v->Vert != ini)
    v = v->link;
  
  if(v == NULL)
    return -1;
  
  int i = pesq_arest(&v->arest,fim);
    
  v = grafo->vert;
  while(v != NULL && v->Vert != fim)
    v = v->link;
  
  if(v == NULL)
    return -1; // Não existe o vertice
  
  int j = pesq_arest(&v->arest,ini);
  
  if(j != 0 && i != 0)
    return 1; //Se achar, retorna verdadeiro
  else
    return 0; //Se não, retorna falso;
}

int pesq_arest(Arestas **arest,int desc){
  Arestas *v;
  v = *arest;
  
  while(v != NULL && v->desc != desc)
    v = v->link;
  if(v == NULL)
    return 0;
  else
    return desc;
}

int rem_arest(Arestas **arest, int desc){
  Arestas *v,*aux1;
  v = *arest;
  aux1 = NULL;
  
  if(*arest == NULL)
    return 0;
  
  while((v != NULL)&&(v->desc != desc)){
    aux1 = v;
    v = v->link;
  }
  
  if(aux1 == NULL){
    *arest = v->link;
    free(v);
    return 1;
  }else{
    if(v!=NULL){
      aux1->link = v->link;
      free(v);
      return 1;
    }else
      return 0;
  }
  
}

int remover_arestas(Grafo *grafo,int ini, int fim){
  Vertices *vert1, *vert2;
  int i = pesquisa_arestas(grafo,ini,fim);
  if(i){
    vert1 = get_vertices(&grafo->vert,ini);
    if(rem_arest(&vert1->arest,fim))
      vert1->Grau--;
    
    
    vert2 = get_vertices(&grafo->vert,fim);
    if(rem_arest(&vert2->arest,ini))
      vert2->Grau--;
    
  }else{
    if(i == -1 || !i)
      return 0;
  }
  grafo->quant_arestas--;
  return 1;
}

Vertices* get_vertices(Vertices **vert,int desc){
  Vertices *v;
  v = *vert;
  while(v != NULL && v->Vert != desc)
    v = v->link;
  if(v != NULL)
    return v;
  else
    return NULL;
}

int remover_vertices(Grafo *grafo,int Vert){
  Vertices *v,*aux;
  v = grafo->vert;
  
  if(v == NULL || !pesquisa_vert(grafo,Vert))
    return 0;
  else{
    //Removendo as arestas dos vertices que tem aresta com este vertice
    while(v != NULL){ 
      if(rem_arest(&v->arest,Vert))
	v->Grau--;
      v = v->link;
    }
    
    v = grafo->vert;
    aux = NULL;
    while((v != NULL) && (v->Vert != Vert)){
      aux = v;
      v = v->link;
    }
    if(aux == NULL){
      grafo->vert = v->link;
      free(v);
    }else{
      aux->link = v->link;
      free(v);
    }
    grafo->quant_vertices--;
    return 1;
  }
}

/** Retorna 1 se for conexo, e 0 se não for conexo! */
int verifica_conexo(Grafo *grafo){
  Vertices *aux;
  int i = 0;
  busca_em_profundidade(grafo);
  aux = grafo->vert;
  while(aux != NULL){
    if(aux->pai == NULL)
      i++;
    aux = aux->link;
  }
  if(i>1)
    return 0;
  else
    return 1;
}

int gerar_matriz(Grafo *grafo){
  int i = grafo->quant_vertices + 1;
  quant_vertices = i;
  if(i == 0)
    return 0; //Grafo Vazio
  int matriz[i][i];
  
  //inicializando a matriz
  for(int j = 0; j < i; j++){
    for(int k = 0; k < i; k++){
	matriz[j][k] = 0;
    }
  }
  
  Vertices *aux;
  Arestas *aux1;
  aux = grafo->vert;
  
  //Gravando as arestas no grafo;
  int j = 0;
  int a = 0,b = 0;
  while(aux != NULL){
    matriz[0][j+1] = aux->Vert;
    matriz[j+1][0] = aux->Vert;
    aux1 = aux->arest;    
    while(aux1 != NULL){
      get_posicao(matriz,aux1->ini,aux1->desc,&a,&b);
      matriz[a][b] = aux1->peso;
      aux1 = aux1->link;
    }
    j++;
    aux = aux->link;
  }
  
  
  imprime_matriz(matriz,i,i);
  
  return 1;
}


int imprime_matriz(int v[quant_vertices][quant_vertices],int i, int j){
  
  for(int k = 0; k<i; k++){
    for(int h = 0; h < j; h++){
      if(!k && !h)
	printf("V. \t");
      else{
	if(v[k][h] == 0)
	  printf("-- \t");
	else
	  printf("%d \t",v[k][h]);
      }
	
      if(h == j - 1)
	printf("\n");
    }
  }
}

/**
 * Função que joga os valores nos ponteiros de onde eu devo adicionar cada aresta na matriz
 */

int get_posicao(int matriz[quant_vertices][quant_vertices],int i,int j, int *k, int *h){
  int a,b;
  for(a = 0; a < i; a++){
    if(matriz[a][0] == i)
      break;
  }
  
  for(b = 0; b < j; b++){
    if(matriz[0][b] == j)
      break;
  }
  *k = a; //Linha
  *h = b; //Coluna
}
#endif //GRAFOS_C_INCLUDED
