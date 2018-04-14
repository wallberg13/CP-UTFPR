#include<stdlib.h>
#define quantidade 1000

typedef struct NoTag{
  int info;
  struct NoTag *link;
}no;

/**
 * Primeiro numero a ser verificado, é o 1, e o prox. numero dele, o dois, é primo
 * então, o primeiro a ser add na lista é o 2, e o resto é verificado, 
 * como um numero primo não é divisivel pelo os numeros primos, o aux sempre tem que ser
 * igual a zero para o numero ser primo.
 */
int verificaPrimo(no **l, int num){
  int aux = 0;
  no *p;
  p = *l;

	if(num == 1)
	  return 0;
	else{
		if(*l == NULL)
			return 1;
		else{
			while(p != NULL){
				if(num%(p->info)==0)
					aux++;
				p = p->link;
			}
		}
	}
	if(!aux)
		return 1;
	else
		return 0;
}

int addLista(no **l,int num){
  no *p, *n;
  p = (no *)malloc(sizeof(no));
  p->info = num;
  p->link = NULL;
  if(*l == NULL)
    *l = p;
  else{
    n = *l;
    while(n->link != NULL)
      n = n->link;
    n->link = p;
  }
  return 1;
}

void addPrimos(no **l){
	int j = 0;
	for(int i = 1; i <= quantidade; i++){
    if(verificaPrimo(l,i)){
      addLista(l,i);
		j++;
	 }
  }
  printf("%d \n\n\n",j);
}

void iniLista(no **l){
  *l = NULL;
}

void imprimeLista(no **L){
  no *p;
  p = *L;
  while(p != NULL){
    printf("%03d %p \n",p->info, p->link);
    p = p->link;
  }
}

int destruirLista(no **l){
  no *aux;
  while(*l!=NULL){
	  aux = (*l)->link;
	  free(*l);
	  *l = aux;
  }
}