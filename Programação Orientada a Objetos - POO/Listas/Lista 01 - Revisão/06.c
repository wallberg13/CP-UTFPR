#include<stdio.h>
#define SENHA 12345
#define TENTATIVAS 3

int main(){
  int i;
  int senha;
  
  for(i = 0; i < TENTATIVAS; i++){
    printf("Digite a senha de acesso: ");
    scanf("%d",&senha);
    if(senha == SENHA){
      printf("Acesso autorizado. \n");
      break;
    }else{
      if(i != TENTATIVAS - 1)
	printf("Tente novamente. \n");
      else
	 printf("Conta bloqueada. \n");
    }
  }
}