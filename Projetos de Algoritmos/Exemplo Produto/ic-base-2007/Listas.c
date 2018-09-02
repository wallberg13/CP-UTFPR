#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include "Util.h"
#include "Estruturas.h"
#include "Listas.h"


/* Insere um registro de forma ordenada (pelo campo 3 de um registro)
   em uma lista duplamente encadeada ordenada */
void insere_ordenado_lista(struct lista *i,       /* novo elemento */
                           struct lista **inicio, /* primeiro elemento da lista */
                           struct lista **final)  /* último elemento da lista */
{
  struct lista *antigo, *ponteiro;

  if (*final==NULL) {  /* primeiro elemento da lista */
     i->proximo = NULL;
     i->anterior = NULL;
     *final = i;
     *inicio = i;
     return;
  }
  ponteiro = *inicio; /* começa no topo da lista */
  antigo = NULL;
  while(ponteiro) {
    if(ponteiro->campo3 < i->campo3) {
      antigo = ponteiro;
      ponteiro = ponteiro->proximo;
    }
    else {
      if(ponteiro->anterior) {
        ponteiro->anterior->proximo = i;
        i->proximo = ponteiro;
        i->anterior = ponteiro->anterior;
        ponteiro->anterior = i;
        return;
      }
      i->proximo = ponteiro; /* novo primeiro elemento */
      i->anterior = NULL;
      ponteiro->anterior = i;
      *inicio = i;
      return;
    }
  }
  antigo->proximo = i; /* coloca no final */
  i->proximo = NULL;
  i->anterior = antigo;
  *final = i;
}


/* Insere o registro i no final de uma lista duplamente encadeada */
void insere_final_lista(struct lista *i,
                        struct lista **inicio,
		        struct lista **final)
{
  struct lista *antigo, *ponteiro;

  if (*final == NULL) {
    i->proximo  = NULL;
    i->anterior = NULL;
    *final = i;
    *inicio = i;
    return;
  }
  ponteiro = *inicio;
  antigo = NULL;
  while (ponteiro) {
    antigo = ponteiro;
    ponteiro = ponteiro->proximo;
  }
  antigo->proximo = i;
  i->proximo = NULL;
  i->anterior = antigo;
  *final = i;
}


/* Mostra o conteudo da lista completa */
void mostra_lista(struct lista **inicio, /* primeiro elemento da lista */
	          struct lista **final)  /* último elemento da lista */
{
  struct lista *registro = *inicio;
  int cont = 0;

  if (!registro) printf("Lista vazia\n");
  while (registro) {
    printf("L[%2d]   campo1 = %2d  campo2 = %2d  campo3 = %8.2f \n",
            cont, registro->campo1, registro->campo2, registro->campo3);
    registro = registro->proximo;   /* obtem próximo endereço */
    cont++;
  }
  printf("\n");
}


/* Mostra o comprimento da lista completa */
int tamanho_lista(struct lista **inicio, /* primeiro elemento da lista */
                  struct lista **final)  /* último elemento da lista */
{
  struct lista *registro = *inicio;
  int cont = 0;

  while(registro) {
    registro = registro->proximo;   /* obtem próximo endereço */
    cont++;
  }
  return cont;
}


/* Encontra o registro de numero posicao */
struct lista *encontra_registro_lista(int posicao,
                                      struct lista **inicio)
{
  struct lista *registro = *inicio;
  int contador = 0;

  while (registro) {
    if (contador == posicao) return registro;
    contador++;
    registro = registro->proximo;  /* obtem novo registro */
  }
  printf("Registro nao encontrado.\n");
  return NULL; /* nao encontrou */
}


/* Encontra o registro em uma lista duplamente encadeada */
struct lista *encontra_registro(int campo1,
                                int campo2,
                                struct lista **inicio)
{
  struct lista *registro = *inicio;

  while (registro) {
    if (registro->campo1 == campo1 && registro->campo2 == campo2)
       return registro;
    registro = registro->proximo;  /* obtem novo registro */
  }
  printf("Registro nao encontrado.\n");
  return NULL; /* nao encontrou */
}



/* Remove o elemento registro da lista */
void apaga_registro(struct lista *registro,
                    struct lista **inicio,
                    struct lista **final)
{
  if (registro) {
    if (*inicio==registro) {
       *inicio=registro->proximo;
       if (*inicio)
          (*inicio)->anterior = NULL;
       else *final = NULL;
    }
    else {
      registro->anterior->proximo = registro->proximo;
      if (registro!=*final)
         registro->proximo->anterior = registro->anterior;
      else
         *final = registro->anterior;
    }
    free(registro); /* devolve memoria para o sistema */
  }
}


/* Apaga TODA a lista */
void apaga_lista(struct lista **inicio,
                 struct lista **final)
{
    struct lista *registro = *inicio;
    while(registro) {
	apaga_registro(registro, inicio, final);
    	if (registro) registro = registro->proximo;   /* obtem próximo endereço */
    }
}

