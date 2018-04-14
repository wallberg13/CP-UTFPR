#include "Funcoes.h"

int main(){
  Ponto p1,p2;
  
  printf("Digite a coordenada X do primeiro ponto: ");
  scanf("%d",&p1.x);
  printf("Digite a coordenada Y do primeiro ponto: ");
  scanf("%d",&p1.y);
  printf("Digite a coordenada X do segundo ponto: ");
  scanf("%d",&p2.x);
  printf("Digite a coordenada X do segundo ponto: ");
  scanf("%d",&p2.y);
  
  printf("\n\nA distancia entre os pontos é: %.2f \n\n",distancia(&p1,&p2));
  
}