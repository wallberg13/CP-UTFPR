#include "Funcoes.h"

char Menu();

int main(){
  no *l;
  char resp;
  iniLista(&l);
  float valor = 0.0;
  char descricao[30];
  
  resp = 'M'; 
  while(resp != 'X' && resp != 'x'){
    resp = Menu();
    resp = toupper(resp);
    valor = 0.0;
    if(resp == 'D'){
      printf("Digite o valor que deseja depositar: ");
      scanf("%f",&valor);
      printf("Digite a descricao da operacao: ");
      __fpurge(stdin);
      scanf("%[^\n]s",descricao);
      realizaOperacao(&l,'D',valor,descricao);
    }
    if(resp == 'S'){
      printf("Digite o valor que deseja sacar: ");
      scanf("%f",&valor);
      printf("Digite a descricao da operacao: ");
      __fpurge(stdin);
      scanf("%[^\n]s",descricao);
      realizaOperacao(&l,'S',valor,descricao);
    }
    if(resp == 'E'){
      extrato(&l);
      system("read a");
    }
  }
}

char Menu(){
  char resp;
  system("clear");
  printf("[D]eposito \n");
  printf("[S]aque \n");
  printf("[E]xtrato \n");
  printf("[X]Sair \n");
  printf("Resposta: ");
  __fpurge(stdin);
  scanf("%c",&resp);
  return resp;
}
