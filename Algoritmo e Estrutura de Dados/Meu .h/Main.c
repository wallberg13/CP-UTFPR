#include "WallV03.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10
int main(void){
  
  no *l;
  iniLista(&l);
  
  
  //Enche o vetor de dados randomicos
  srand(time(NULL));
  for(int i = 0; i<MAX; i++)
    addFinalLista(&l,rand()%100);
  
  imprimeLista(&l);
  
  ordenaD(&l);
  
  printf("\n\n");
  imprimeLista(&l);
    
}