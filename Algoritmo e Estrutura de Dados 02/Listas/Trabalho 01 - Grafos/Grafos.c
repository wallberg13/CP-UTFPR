#ifndef GRAFOS_C_INCLUDED
#define GRAFOS_C_INCLUDED

#include "Biblio.h"


//Inicializa grafo apontando para um vertice;
void inicia_grafo(Grafo *grafo){
  grafo->vert = NULL;
}

/** PARTE PARA ADICIONAR!!! */
int add_vertices(Grafo *grafo,int desc){
  return add_vert(&grafo->vert,desc);
}

int pesquisa_vert(Grafo *grafo,int desc){
  return pesq_vert(&grafo->vert,desc);
}

int add_vert(Vertices **vert, int desc){
  Vertices *v, *aux;
  
  if(pesq_vert(vert,desc) != 0)
    return 0;
  
  v = (Vertices *)malloc(sizeof(Vertices));
  v->Vert = desc;
  v->link = NULL;
  v->arest = NULL;
  
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

int imprime_vertices(Vertices **vert){
  Vertices *aux;
  aux = *vert;
  
  if(aux == NULL){
    printf("Grafo Vazio!! \n");
    return 0;
  }
  
  
  printf("V. Arestas\n");
  while(aux != NULL){
    printf("%d ",aux->Vert);
    imprime_arestas(&aux->arest);
    printf("\n");
    aux = aux->link;
  };
}

int add_arestas(Grafo *grafo, int ini, int fim){
  Vertices *v;
  int i = pesquisa_arestas(grafo,ini,fim);
  if(i || i == -1)
    return 0;
  
  if(ini == fim){
    v = get_vertices(&grafo->vert,fim);
    add_arest(&v->arest,ini);
  }else{
    v = get_vertices(&grafo->vert,ini);
    add_arest(&v->arest,fim);
    
    v = get_vertices(&grafo->vert,fim);
    add_arest(&v->arest,ini);
  }
  return 1;    
}

int add_arest(Arestas **arest,int desc){
  Arestas *aux, *v;
  
  v = (Arestas *)malloc(sizeof(Arestas));
  v->link = NULL;
  v->desc = desc;

  if(*arest == NULL)
    *arest = v;
  else{
    aux = *arest;
    while(aux->link != NULL)
      aux = aux->link;
    aux->link = v;
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
    rem_arest(&vert1->arest,fim);
    
    vert2 = get_vertices(&grafo->vert,fim);
    rem_arest(&vert2->arest,ini);
  }else{
    if(i == -1 || !i)
      return 0;
  }
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
      rem_arest(&v->arest,Vert);
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
    return 1;
  }
}

#endif //GRAFOS_C_INCLUDED