#include<stdio.h>

int main(){
  int num,par = 0,impar = 0,pos = 0,neg = 0,i;
  
  for(i = 0; i < 10; i++){
    printf("Digite um numero: ");
    scanf("%d",&num);
    if(num%2 == 0)
      par++;
    else
      impar++;
    if(num>0)
      pos++;
    else
      neg++;
  }
  printf("Relatorio dos numeros.\n");
  printf("Par: %d .\n",par);
  printf("Impar: %d .\n",impar);
  printf("Positivo: %d .\n",pos);
  printf("Negativo: %d .\n",neg);
}