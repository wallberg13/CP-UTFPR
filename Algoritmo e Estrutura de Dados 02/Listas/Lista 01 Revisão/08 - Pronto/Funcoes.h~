/*
 * Escreva um algoritmo que leia um numero indeterminado de 
 * valores inteiros. O valor 0(zero) finaliza a entrada de dados.
 * Para cada valor lido, determinar se ele e um numero par ou ımpar. 
 * Se o numero for par, entao incluı-lo na FILA PAR; 
 * caso contrario, incluı-lo na FILA  ́IMPAR. Apos o termino da entrada
 * de dados, retirar um elemento de cada fila alternadamente 
 * (iniciando-se pela FILA  ́IMPAR) ate que ambas as filas 
 * estejam vazias. Se o elemento retirado de uma das filas 
 * for um valor positivo, entao incluı-lo em uma PILHA; caso 
 * contrario, remover um elemento da PILHA. 
 * Finalmente, escrever o conteudo da pilha.
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct lista_encadeada{
  struct lista_encadeada *link;
  int info;
}ListaSE;

void inicia_lista(ListaSE **l){
  *l = NULL;
}

int remove_inicio(ListaSE **l){
  ListaSE *aux; int x;
  
  if(*l == NULL)
    return 0;
  else{
    aux = (*l)->link;
    x = (*l)->info;
    free(*l);
    *l = aux;
    return x;
  }
}

int remove_final(ListaSE **l){
  ListaSE *aux1;
  int x;
  
  if(*l != NULL){
    aux1 = *l;
    if(aux1->link == NULL){
      x = aux1->info;
      free(aux1);
      *l = NULL;
    }else{
      while(aux1->link->link != NULL)
	aux1 = aux1->link;
      x = aux1->link->info;
      free(aux1->link);
      aux1->link = NULL;
    }
  }else{
    return 0;
  }
  return x;
}

int add_inicio(ListaSE **l, int info){
  ListaSE *p;
  p = (ListaSE *)malloc(sizeof(ListaSE));
  p->info = info;
  p->link = *l;
  *l = p;
  return (p->info);
}

int add_fim(ListaSE **l, int info){
  ListaSE *p, *aux;
  p = (ListaSE *)malloc(sizeof(ListaSE));
  p->info = info;
  p->link = NULL;
  aux = *l;
  if(*l != NULL){
    while(aux->link != NULL)
      aux = aux->link;
    aux->link = p;
  }else{
    *l = p;
  }
  return(p->info);
}

int verifica_vazia(ListaSE **l){
  if(*l == NULL)
    return 1;
  else
    return 0;
}

int imprime_pilha(ListaSE **l){
  ListaSE *p, *aux;
  inicia_lista(&p);
  if(verifica_vazia(l))
    printf("Lista Vazia");
  while(*l != NULL){
    int x = remove_final(l);
    printf("%d \n",x);
    add_inicio(&p,x);
  }

  while(p != NULL){
    add_inicio(l,remove_final(&p));
  }
}

/** A resposta da questão de fato*/

int sub_main(){
  int num;
  ListaSE *fila_par, *fila_impar;
  ListaSE *pilha;
  inicia_lista(&fila_par);
  inicia_lista(&fila_impar);
  inicia_lista(&pilha);
  
  do{
    printf("Digite um numero: ");
    scanf("%d",&num);
    
    if(num == 0)
      break;
    
    if(num%2 == 0){
      add_fim(&fila_par,num);
    }else{
      if((num%2 == 1)||(num%2 == -1))
	add_fim(&fila_impar,num);
    }
  }while(num != 0);
  
  
  do{
    if(!verifica_vazia(&fila_impar)){
      int i;
      i = remove_inicio(&fila_impar);
      if(i != 0){
	if(i > 0){
	  add_fim(&pilha,i);
	}else{
	  remove_final(&pilha);
	}
      }
    }
    if(!verifica_vazia(&fila_par)){
      int i;
      i = remove_inicio(&fila_par);
      if(i != 0){
	if(i > 0){
	  add_fim(&pilha,i);
	}else{
	  remove_final(&pilha);
	}
      }
    }
  }while(!verifica_vazia(&fila_impar)||!verifica_vazia(&fila_par));
  
  imprime_pilha(&pilha);
  
}
