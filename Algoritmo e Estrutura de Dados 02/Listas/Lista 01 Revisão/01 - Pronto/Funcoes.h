/* 1. Calcular o fatorial de N, onde N  ́e inteiro. */

#include<stdio.h>

int Calcular_Fatorial(int i){
  int fat = i;
  
  if((i == 0)||(i == 1))
    return 1;
  
  for(int j = i-1; j>= 0; j--){
    
    if(j != 0){
      fat = fat*j;
    }else{
      return fat;
    }
  }
}