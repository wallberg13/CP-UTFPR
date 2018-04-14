#include<stdio.h>

int main(){
  int num;
  
  printf("Digite um numero: ");
  scanf("%d",&num);
  
  if(!num%2)
    printf("O numero é par. \n");
  else
    printf("O numero é impar. \n");
  
}