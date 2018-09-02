#include<stdlib.h>
#include<stdio.h>

#define JOINHA 1

/**
 * struct da lista encadeada
 */
typedef struct noTag{
 int info;
 struct noTag *link; 
}no;

/**
 * struct da lista duplamente encadeada
 */
typedef struct noTagD{
  int info;
  struct noTagD *ant;
  struct noTagD *prox;
}noD;



/** 
 * Funções para listas encadeadas!!
 * 
 */
void iniLista(no **L){
  *L = NULL;
}

/**
 * Função para imprimir uma lista.
 */
void imprimeLista(no **L){
  no *p;
  p = *L;
  while(p != NULL){
    printf("%03d %p \n",p->info, p->link);
    p = p->link;
  }
}

/**
 * Função para adicionar um elemento no final de uma
 * lista encadeada
 */
int addFinalLista(no **L, int info){
  no *p, *n;
 
  p = (no *)malloc(sizeof(no));
  p->info = info;
  p->link = NULL;
  
  if(*L == NULL){
    *L = p;
  }else{
    n = *L;
    while(n->link != NULL){
      n = n->link;
    }
    n->link = p;
  }
  return 1;
}

/**
 * Função para adicionar ordenadamente em uma lista encadeada simples
 */
int addOrd(no **l, int info){
  no *n, *p, *aux;
  n = (no *)malloc(sizeof(no));
  n->info = info;
  if(*l == NULL){
    *l = n;
    n->link = NULL;
  }else{
    p=*l;
    aux = NULL;
    while((p!=NULL)&&(n->info > p->info)){
      aux = p;
      p = p->link;
    }
    if(p==*l){
      n->link =*l;
      *l = n;
    }else{
      n->link = p;
      aux->link = n;
    }
  }
}


/**
 * Função para adicionar um elemento no inicio de uma lista
 * encadeada
 */
int addIniLista(no **L,int info){
  no *p;
  p = (no *)malloc(sizeof(no));
  p->link = *L;
  p->info = info;
  *L = p;
}
/**
 * Função para remover um elemento no inicio de uma lista
 * encadeada
 */
int removeIniLista(no **L){
  no *p; int x;
  if(*L != NULL){
    p = (*L)->link;
    x = (*L)->info;
    free(*L);
    *L = p;
    return x;
  }else
    return -1;
}

/**
 * Remove no final da lista!
 */
int removeFimLista(no **L){
  no *p; int x;
  
  if(*L != NULL){
    p = *L;
    if(p->link == NULL){
      x = p->info;
      free(p); 
      *L = NULL;
      return x;
    }else{
      while(p->link->link != NULL)
	p = p->link;
      x = p->link->info;
      free(p->link);
      p->link = NULL;
    }
    return x;
  }else
    return -1;
}

/**
 * Função para inserir no inicio de uma lista duplamente encadeada;
 */
int addIniD(noD **L,int info){
  noD *p;
  p = (noD *)malloc(sizeof(noD));
  p->info = info;
  p->ant = NULL;
  
  if(*L == NULL){
    p->prox = NULL;
    *L = p;
  }else{
    p->prox = *L;
    (*L)->ant = p;
    *L = p;
  }
  return JOINHA;
}

/**
 * Função para inserir no final de uma lista duplamente encadeada
 */
int addFimD(noD **L,int info){
  noD *p, *n;
  p = (noD *)malloc(sizeof(noD));
  p->prox = NULL;
  p->info = info;
  if(*L == NULL){
    *L = p;
    p->ant = NULL;
  }else{
    n = *L;
    while (n->prox != NULL)
      n = n->prox;
    n->prox = p;
    p->ant = n;
  }
  return JOINHA;
}

/**
 * Função para inserir ordenado em uma lista duplamente encadeada;
 */
int addOrdd(noD **l, int info){
    
}


/**
 * Função para remover no inicio da lista duplamente encadeada
 */
int removeIniD(noD **L){
  noD *p; p = *L;
  if(*L != NULL){
    *L = p->prox;
    if(*L != NULL)
      (*L)->ant = NULL;
    free(p);
  }
  return JOINHA;
}

/**
 * Função para remover no final da lista duplamente encadeada
 */
int removeFimD(noD **L){
  noD *p;
  p = *L;
  if(*L != NULL){
    while(p->prox != NULL)
      p = p->prox;
    if(p->ant == NULL)
      *L = NULL;
    else
      p->ant->prox = NULL;
    free(p);
  }
}
