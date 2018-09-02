#include "Funcoes.h"

int main(){
  int vetor[1000];
  povoa_vetor(vetor,1000);
  int i; 
  
  do{
    //Como é só para teste, o vetor tem numeros entre 0 e 999;
    //E esta ordenado
    system("clear"); //Ubuntu
    printf("O que deseja pesquisar: ");
    scanf("%d",&i);
    busca_binaria(vetor,i,0,1000);
    
    printf("Deseja pesquisar novamente? (0 para não pesquisar, digite numeros): ");
    scanf("%d",&i);
  }while(i != 0);
  
}