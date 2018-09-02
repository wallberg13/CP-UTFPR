#include<stdio.h>
#include<Wall.h>

int main(void){
  Stack2 lista;
  inicializar(&lista);
  pushStack1(&lista,4);
  pushStack1(&lista,10);
  pushStack1(&lista,3);
  pushStack1(&lista,75);
  pushStack1(&lista,1);
  
  pushStack2(&lista,9);
  pushStack2(&lista,11);
  pushStack2(&lista,5);
  pushStack2(&lista,12);
  pushStack2(&lista,50);

  pushStack1(&lista,5);
  pushStack2(&lista,32);
  
  popStack1(&lista);
  popStack2(&lista);

  printf("\n\n\n");
  printStack1(&lista);
  printf("\n\n\n");
  printStack2(&lista);
  
}
