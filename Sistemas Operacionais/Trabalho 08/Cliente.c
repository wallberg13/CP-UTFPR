#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<time.h>

#define ip_maquina "172.20.221.2"
#define n_consumidores 2

int sock; // Descritor de arquivo
struct sockaddr_in servidor; // Servidor com quem deseja-se conectar
pthread_t threads[n_consumidores];
char mensagem[100], aux[100];
int tam_men;

void sorteio(){
    srand(time(NULL));
}

void *consumo(void *i){
  long id = (long)i;

  while(1){
    sleep(1 + rand()%5);
    /**
      Primeiro envia a mensagem vazia com o id solicitando o consumo.
    */
    sprintf(mensagem,"%d",id);
    if(send(sock, mensagem, sizeof(mensagem), 0) < 0){
      printf("Erro na mensagem\n");
    }

    tam_men = recv(sock, mensagem, sizeof(mensagem), 0);
    mensagem[tam_men] = '\0';

    if(!strcmp(mensagem,"produzido")){
      printf("Consumidor %d consumiu um produto produzido\n",id);
    }
  }

}

/**
  Arquivo cliente, onde ele deve saber aonde o Servidor
  esta localizado, para que ele possa se conectar a ele.

*/
int main(){
  /**
    Primeira a coisa para fazer é abrir um descritor de arquivo socket
  */
  sorteio();
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

  long i;
  for(i = 0; i < n_consumidores; i++){
    pthread_create(&threads[i], NULL, consumo, (void *)i);
  }
  sleep(30);

  close(sock);
  return 0;
}
