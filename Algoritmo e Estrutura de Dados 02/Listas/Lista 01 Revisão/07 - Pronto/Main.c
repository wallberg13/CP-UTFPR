/** Escreva um algoritmo, usando uma Pilha, 
 * que inverte as letras de cada palavra de um texto
terminado por ponto (“.”) preservando 
a ordem das palavras. Por exemplo, dado o texto:
  ESTE EXERCICIO E MUITO FACIL
A saıda deve ser:
  ETSEOICICREXEEOTIUMLICAF
*/ 

#include<stdio.h>
#include "funcoes.h"

int main(){
  char texto[] = "ALGORITMOS E ESTRUTURAS DE DADOS 02";
  trata_palavras(texto);
}