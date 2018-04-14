#include<stdio.h>
#include<time.h>

int main(){
  int num;
  srand(time(NULL));
  printf("Digite um numero de 1 a 10");
  scanf("%d",&num);
  
  if(num == 1 + rand()%10)
    printf("Parabéns, vocêm acertou. \n");
  else
    printf("Tente outra vez");
}