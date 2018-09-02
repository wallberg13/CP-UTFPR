#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sorteio(){
  srand(time(NULL));
}

int povoa_vetor(int v[],int tam){
  sorteio();
  for(int i = 0; i < tam; i++){
    v[i] = 1 + rand()%(1000);
    if(tam-i != 1)
      printf("%d, ",v[i]);
    else
      printf("%d.",v[i]);
  }
  printf("\n");
}

int max(int i, int j){
  if(i > j)
    return i;
  else
    return j;
}

int maior(int vet[],int i, int f){
  int v1,v2,m;
  if((f-i) <= 1)
    return max(vet[i],vet[f]);
  else{
    m = (i + f)/2;
    v1 = maior(vet,i,m);
    v2 = maior(vet,m+1,f);
  }
  return max(v1,v2);
}
