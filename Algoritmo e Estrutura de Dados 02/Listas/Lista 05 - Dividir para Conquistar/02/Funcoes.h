#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n){
  if(n == 0)
    return 1;
  if(n == 1)
    return 1;
  if(n > 1){
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int exibe_sequencia(int n){
  for(int i = 0; i < n; i++){
    if(!(i+1 == n))
      printf("%d, ",fibonacci(i));
    else
      printf("%d.",fibonacci(i));
  }
  printf("\n");
}