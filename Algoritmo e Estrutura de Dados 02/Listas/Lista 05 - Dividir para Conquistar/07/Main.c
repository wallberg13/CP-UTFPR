#include "Funcoes.h"

int main(){
  int *v;
  
  v = (int *)malloc(1000000*sizeof(int));
  povoa_vet(v,1000000);
  clock_t t;

  t = clock();
  printf("A soma pelo metodo recurviso é: %d \n",soma_div(v,0,1000000));
  t = clock() - t;
  printf("O tempo de execução da função recursiva é: %f \n",((float)t/CLOCKS_PER_SEC));
  
  t = clock();
  printf("A soma pelo metodo convecional é: %d \n",soma_conv(v,1000000));
  t = clock() - t;
  printf("O tempo de execução da função convecional é: %f \n",((float)t/CLOCKS_PER_SEC));
}