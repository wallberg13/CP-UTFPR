#include "headers.h"

int ini_CharZao(CharZao **cz){
  *cz = NULL;
}

int add_CharZao_Fim(CharZao **cz, char *c){
  CharZao *aux,*aux1;

  aux = (CharZao *)malloc(sizeof(CharZao));
  aux->val = (char *)malloc((strlen(c)+1)*sizeof(char));
  aux->val = c;
  aux->prox = NULL;

  if(*cz == NULL){
    *cz = aux;
  }else{
    aux1 = *cz;
    while(aux1->prox != NULL){
      aux1 = aux1->prox;
    }
    aux1->prox = aux;
  }
  return 1;
}

int rem_CharZao_ini(CharZao **cz){
  if(*cz == NULL)
    return 0;
  CharZao *aux;

  aux = (*cz)->prox;
  free((*cz)->val);
  free(*cz);
  *cz = aux;
  return 1;
}

void limpa_CharZao(CharZao **cz){
  while(rem_CharZao_ini(cz));
}

void print_CharZao(CharZao *cz){
  CharZao *aux;
  aux = cz;
  while(aux != NULL){
    printf("%s\n",aux->val);
    aux = aux->prox;
  }
}
