#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h> //inet_add
#include<pthread.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<pthread.h>

#define n_connect 1
/**
  Estruturas envolvidas:
    sockaddr_in e sockaddr
  Pode ser feito typecast de sockaddr_in para sockaddr.
  Struct sockaddr_in composta por:
    sin_family >>> Internet protocolo
    sin_port >>> Porta que sera utilizada para Comunicacao
    sin_addr.s_addr >>> IP de onde se deseja conectar, como é um servidor, qualquer IP deseja-se
                 conectar a ele.
*/

int main(){
  /**
    Primeiro se cria os inteiros que será a descricao do arquivo de sockets.
      sck_ser: Descritor do socket servidor
      sck_cli: Descritor do socket cliente
      c: guarda o tamanho da estrutura sockaddr_in
      tam_lei: Tamanho da leitura recebida pelo o cliente
  */
  int sck_ser, sck_cli, c, tam_lei;
  struct sockaddr_in server, client;
  char mens[100];
  /**
    Primeiro, deve-se abrir o socket com a funcao: socket, e um inteiro deve receber a sua
    descricao.
      socket(familia, tipo, protocolo)
        Familia: PF_INET - Comunicacao entre endereco de internet.
        Tipo: SOCK_STREAM - Orientado a conexão
        Protocolo: 0 - Padrao TCP
  */
  sck_ser = socket(PF_INET, SOCK_STREAM, 0);

  if(sck_ser == -1){
    printf("Deu pau no socket\n");
    return 0;
  }
  printf("Socket Aberto\n");
  server.sin_family = PF_INET; // Protocolo de internet.
  server.sin_port = htons(1080); // Atribui a porta 1080 para ser a porta do socket
  server.sin_addr.s_addr = INADDR_ANY; // Permite qualquer um fazer a conexão no socket
  /**
    Segundo, o socket deve reservar uma porta para ser usada, atraves da funcao bind.
    bind(sockid, &addrport, size).
      sockid: Descritor do socket
      addrport: é um sockaddr_in convertido para ponteiro de sockaddr
      size: Tamanho da estrutura que quero abrir o socket, que no caso é tamanho de server.
  */
  if(bind(sck_ser,(struct sockaddr *)&server, sizeof(server)) == -1){
    printf("Deu Pau no Bind\n");
  }

  printf("Sucesso no Bind\n");

  /**
    Terceiro passo, o Listen.
    É preciso avisar ao Socket quantas conexões ele "ira querer pra ele".
    Para que ele faca isso, é preciso da funcao listen.
    listen(sockid, TamanhoConexao)
      sockid: Descritor do socket
      TamanhoConexao: Quantidade de conexoes simutaneas que o socket suporta.
  */
  if(listen(sck_ser, n_connect) == -1){
    printf("Deu Pau no Listen\n");
  }
  printf("Sucesso no Listen\n");

  /**
    Espera-se o cliente se conectar, com o accept, neste caso, só será permitido uma conexao.
    Logo que essa conexao for feita e receber uma mensagem, o socket será fechado.
  */
  c = sizeof(struct sockaddr_in);
  sck_cli = accept(sck_ser, (struct sockaddr *)&client, &c);

  if(sck_cli < 0){
      printf("Deu ruim\n");
      return 0;
  }

  /**
    Para descobrir o IP do cliente que se conectou, basta fazer uma manipulacao
    de deslocamento de bits na variavel de endereço no cliente.sin_addr.s_addr.
    Como é uma variavel de 32 bits, entao é preciso separar em "lotes" de 8 bits.
  */
  int a1, a2, a3, a4;
  a1 = client.sin_addr.s_addr >> 24;
  a2 = (client.sin_addr.s_addr << 8) >> 24;
  a3 = (client.sin_addr.s_addr << 16) >> 24;
  a4 = (client.sin_addr.s_addr << 24) >> 24;
  printf("O cliente conectado foi: %d.%d.%d.%d\n",a4,a3,a2,a1);

  while(1){
    tam_lei = recv(sck_cli, mens, sizeof(mens), 0); // Recebendo uma mensagem
    if(tam_lei == 0){
      break;
    }
    mens[tam_lei] = '\0';
    printf("Cliente %d.%d.%d.%d, Consumidor %s quer um produto. \n",a4,a3,a2,a1,mens);
    sprintf(mens,"produzido");
    send(sck_cli, mens, sizeof(mens), 0);
    mens[0] = '\0';
  }

  if(close(sck_ser) == -1){
    printf("Deu pau para fechar o socket\n");
  }



  printf("Servidor Fechado\n");
  return 0;
}
