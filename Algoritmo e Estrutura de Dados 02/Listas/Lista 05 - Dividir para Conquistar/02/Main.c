#include "Funcoes.h"

int main(){
  int i;
  
  do{
    system("clear");
    printf("Digite quantos termos deseja ver da seguencia Fibonacci: ");
    scanf("%d",&i);
    
    exibe_sequencia(i);
    
    printf("Deseja ver novamente? (0 Para Não, Digite Numeros): ");
    scanf("%d",&i);
    
  }while(i != 0);
}