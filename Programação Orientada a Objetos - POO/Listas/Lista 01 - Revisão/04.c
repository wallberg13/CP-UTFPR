#include<stdio.h>

int main(){
    int i,j,k;
    
    printf("Lado 1: ");
    scanf("%d",&i);
    
    printf("Lado 2: ");
    scanf("%d",&j);
    
    printf("Lado 3: ");
    scanf("%d",&k);
    
    if(i <= j+k && j <= k+i && k <= i+j){
      
      if(i == j && j == k && k == i)
	printf("Triangulo Equilatero. \n");
      else{
	if(i != j && j != k && k != i)
	  printf("Triangulo escaleno \n");
	else
	  printf("Triangulo Isoceles. \n");
      }
    }
}