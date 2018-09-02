#include "Funcoes.h"

int main(){
  int vetor[max];
  int numero;
  
  povoando_vetor(vetor);
  do{
    printf("Digite um numero entre 0 e 1000: ");
    scanf("%d",&numero);
  }while((numero < 0)||(numero>1000));
  
  mais_prox(vetor, numero);
}