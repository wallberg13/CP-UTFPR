#include<stdio.h>

#DEFINE SENHA 12345

int main(){
  int senha;
  
  printf("Digite a Senha: ");
  scanf("%d",&senha);
  
  if(senha == SENHA)
    printf("Acesso autorizado. \n");
  else
    printf("Acesso negado. \n");
  
}