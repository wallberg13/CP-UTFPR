#include<stdio.h>
#include<string.h>

int printInverso(char vetor[]);

int main(){
  char vetor[] = "Caquinha";
  printInverso(vetor);
  
}


int printInverso(char vetor[]){
  if(vetor[0] == '\0')
    return (0);
  if(vetor[0] != '\0'){
    printInverso(++vetor);
    printf("%c \n", vetor[0]);
  }
}