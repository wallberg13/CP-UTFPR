#include "headers.h"

/**
  ALGORITMO BASICO PARA SQL -> CONEXAO:
  PRIMEIRO: mysql_init(conexao)
  DPS: Verificar se realmente conectou o banco.
    mysql_real_connect(CONEXAO,HOST,USER,PASSWORD,BANCO,PORT,
      SOCKET,FLAGS)
  ---faz o que se quer no banco, que no caso será no PROGRAMA
     inteiro
  ULTIMO: mysql_close(conexao);
*/
int main(int argc, char *argv[]){

  MYSQL conexao;
  mysql_init(&conexao);

  if(mysql_real_connect(&conexao,HOST,USER,PASS,DB,0,NULL,0)){
    printf("Banco conectado! \n");
    if(argc > 1)
      import(argv[1], &conexao);
    mysql_close(&conexao);
  }else
    printf("Deu ruim na conexão com o banco \n");
}
