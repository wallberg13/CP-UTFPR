#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>

#define ip_maquina "192.168.100.18"
/**
  Arquivo cliente, onde ele deve saber aonde o Servidor
  esta localizado, para que ele possa se conectar a ele.

*/
int main(){
  char mensagem[100] = {"E a tampa??\0"};

  int sock; // Descritor de arquivo
  struct sockaddr_in servidor; // Servidor com quem deseja-se conectar

  /**
    Primeira a coisa para fazer é abrir um descritor de arquivo socket
  */
  if((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1){
      printf("Deu pau no socket\n");
      return 0;
  }

  /**
    Definir como vai ser a transmissao, numero de porta e o ip destino.
  */
  servidor.sin_family = PF_INET;
  servidor.sin_port = htons(1080);
  servidor.sin_addr.s_addr = inet_addr(ip_maquina);

  if(connect(sock, (struct sockaddr *)&servidor, sizeof(servidor)) == -1){
    printf("Falha ao tentar conectar\n");
    return 0;
  }
  printf("Conectado\n");

  printf("%s\n",mensagem);
  if(send(sock, mensagem, sizeof(mensagem), 0) < 0){
    printf("Erro na mensagem\n");
  }

  close(sock);
  return 0;
}
