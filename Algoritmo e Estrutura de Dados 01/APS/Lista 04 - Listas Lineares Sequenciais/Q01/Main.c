#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int varreVetor(int vetor[MAX],int i);

int main(void){
  int vetor[MAX];
  
  vetor[0] = 10;
  vetor[1] = 9;
  vetor[2] = 8;
  vetor[3] = 7;
  vetor[4] = 5;
  vetor[5] = 5;
  vetor[6] = 4;
  vetor[7] = 3;
  vetor[8] = 2;
  vetor[9] = 1;
  
  printf("%d \n\n ",varreVetor(vetor,0));
  
}

int varreVetor(int vetor[MAX],int i){
  
  if(i == MAX - 1){
    if(vetor[i]>vetor[i-1])
      return 1;
    else
      return 2;
  }
  if(i>0){
    if(vetor[i]<=vetor[i+1] && vetor[i] >= vetor[i-1])
      return varreVetor(vetor,++i);
    if(vetor[i]>=vetor[i+1] && vetor[i]<=vetor[i-1])
      return varreVetor(vetor, ++i);
    else
      return -1;
    
  }else{
    return varreVetor(vetor,++i);
  }
  
}