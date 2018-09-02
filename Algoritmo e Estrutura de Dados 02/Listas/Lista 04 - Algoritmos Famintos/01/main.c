#include "funcoes.h"

int main(){
  Item *item_bag;
  char texto[] = {"arquivo.txt"};
  inicializa_item(&item_bag);
  importar_arquivo_item(&item_bag,texto);
  imprimir_lista(&item_bag);
  sub_main(&item_bag);
}