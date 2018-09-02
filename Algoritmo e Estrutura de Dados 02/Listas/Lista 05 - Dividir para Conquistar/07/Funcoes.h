#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sorteio(){
  srand(time(NULL));
}

void povoa_vet(int v[], int tam){
  sorteio();
  for(int i = 0; i < tam; i++){
    v[i] = 1 + rand()%1000;
    printf("%d, ",v[i]);
  }
  printf("\n");
}

int soma_div(int vet[],int i, int f){
  int m = (i+f)/2;
  int s1;
  if((f-i)<1)
    return vet[i];
  s1 = soma_div(vet,i,m) + soma_div(vet,m+1,f);
  return s1;
}

int soma_conv(int vet[],int tam){
  int s1 = 0;
  for(int i = 0; i < tam; i++)
    s1 += vet[i];
  return s1;
}