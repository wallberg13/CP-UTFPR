#include "headers.h"

void initialize(AUX **aux){
  (*aux) = NULL;
}

int addFinal(AUX **aux,int idPalTex, int idPal){
  AUX *aux1, *aux2;

  aux1 = (AUX *)malloc(sizeof(AUX));
  aux1->prox = NULL;
  aux1->idPalTex = idPalTex;
  aux1->idPal = idPal;

  if(*aux == NULL){
    *aux = aux1;
    return 1;
  }
  aux2 = *aux;
  while(aux2->prox != NULL)
    aux2 = aux2->prox;
  aux2->prox = aux1;
  return 1;
}

int limpa(AUX **aux){
  AUX *aux1;
  while(*aux != NULL){
    aux1 = (*aux)->prox;
    free(*aux);
    *aux = aux1;
  }
  return 1;
}

int print_AUX(AUX **aux){
  AUX *aux1;
  aux1 = *aux;
  while(aux1 != NULL){
    printf("(PalTex: %d)\t(Pal: %d)\n",aux1->idPalTex, aux1->idPal);
    aux1 = aux1->prox;
  }
}

int pal_tex_prox_povo(MYSQL *conexao, AUX **aux){
  AUX *a;
  a = *aux;
  int codPalTexProx = 0;
  while(a->prox != NULL){
    codPalTexProx = get_cod_pal_tex_prox(conexao,a->idPalTex,a->prox->idPal);
    if(!codPalTexProx)
      insert_pal_tex_prox(conexao,a->idPalTex,a->prox->idPal);
    else
      update_ocor_pal_tex_prox(conexao,codPalTexProx);
    a = a->prox;
  }
}
