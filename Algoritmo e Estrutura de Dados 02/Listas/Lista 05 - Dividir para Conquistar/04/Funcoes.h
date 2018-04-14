#include<stdio.h>
#include<stdlib.h>

int potencia(int num, int exp){
  if(exp == 1)
    return num;
  if(exp%2 == 0)
    return potencia(num,exp/2)*potencia(num,exp/2);
  else
    return potencia(num,exp/2)*potencia(num,exp/2)*num;
}