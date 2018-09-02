#include<stdio.h>

int main(){
  float n1,n2,t1;
  
  do{
    printf("Digite a primeira nota: ");
    scanf("%f",&n1);
    if(n1 < 0.0 || n1 > 10.0)
      printf("Digite novamente. \n");
  }while(n1 < 0.0 || n1 > 10.0);
  
  do{
    printf("Digite a segunda nota: ");
    scanf("%f",&n2);
    if(n2 < 0.0 || n2 > 10.0)
      printf("Digite novamente. \n");
  }while(n2 < 0.0 || n2 > 10.0);
  
  do{
    printf("Digite a nota do projeto final: ");
    scanf("%f",&t1);
    if(t1 < 0.0 || t1 > 10.0)
      printf("Digite novamente. \n");
  }while(t1 < 0.0 || t1 > 10.0);
  
  printf("Média Final: %.2f",n1*0.3 + n2*0.3 + t1*0.4);
  
}