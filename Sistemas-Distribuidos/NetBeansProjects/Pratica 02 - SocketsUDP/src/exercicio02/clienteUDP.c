#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

#define TAMBUFFER 1024 // Tamanho do buffer de entrada.
#define PORTA 4321 // Porta do servidor.
#define ip_servidor "127.0.0.1"

void requisicao(int sock_desc, struct sockaddr_in *destino, char *msg, char *servidor, char* buffer);
socklen_t slen;

int main(){
	struct sockaddr_in addr_local; // IP local
	struct sockaddr_in addr_remoto; // IP do servidor
	int socket_desc; // Descritor de socket
	
	char buffer[TAMBUFFER];
	slen = sizeof(addr_remoto);
	char *servidor = ip_servidor;

	// PRIMEIRO PASSO é criar um socket e atribuir uma porta a ele (com o bind)
	// Verifica se o sock pode ser criado, se sim, o seu valor é inserido no
	// descritor de socket, o socket_desc.
	if( (socket_desc = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ){
		perror("Socket nao foi possivel de ser criado");
		return -1;
	}

	/**
	 *  Associando o socket a todos IPs locais e escolhendo uma PORTA QUALQUER
	 *  Lembrando que primeiro deve-se da um bind local, para IP local, tudo local
	 *  para dizer o que vai acontecer na maquina host.
	 *
	 *  Quando for pra enviar alguma coisa no ip remoto, utiliza-se outro procedimento, dado a seguir.
	 */
	memset((char *) &addr_local, 0, sizeof(addr_local)); // Zera tudo que esta na variavel addr_local
	
	addr_local.sin_family = AF_INET; // Familia endereco de internet
	addr_local.sin_addr.s_addr = htonl(INADDR_ANY); // Nao me lembro, mas acho que ele pega algum endereco IP
	addr_local.sin_port = htons(0); // Pega uma porta qualquer do sistema operacional (uma porta desoculpada)

	// O bind atribui uma porta para "ouvir" ou fazer alguma comunicacao.
	if(bind(socket_desc, (struct sockaddr *)&addr_local, sizeof(addr_local)) < 0){
		perror("Error no bind");
		return -1;
	}
	
	/**
	 * Associando o endereco do servidor remoto para o addr_remoto do tipo sockaddr_in
	 */
	memset((char *) &addr_remoto, 0, sizeof(addr_remoto)); // Limpa byte a byte da variavel addr_remoto.
	addr_remoto.sin_family = AF_INET;
	addr_remoto.sin_port = htons(PORTA);
	
	if(inet_aton(servidor, &addr_remoto.sin_addr) == 0){ // Faz atribuicao de vetor de char no ip do servidor
		fprintf(stderr, "inet_atom() falho");
		return -1;
	}
	
	/**
	 * SEGUNDO PASSO: Trocando mensagens com o servidor
	 */
	requisicao(socket_desc, &addr_remoto, "horaAtual", servidor, buffer);
	printf("Resposta do Servidor: %s \n", buffer);

	requisicao(socket_desc, &addr_remoto, "dataAtual", servidor, buffer);
	printf("Resposta do Servidor: %s \n", buffer);

	close(socket_desc);
}

/**
 * Sera considerado uma mensagem de 1024 bytes como definidos no comeco do programa.
 */
void requisicao(int sock_desc, struct sockaddr_in *destino, char* msg, char* servidor, char* buffer){
	int tam_recebido;
	printf("Enviando a mensagem \"%s\" para o servidor: %s [%d] \n", msg, servidor, PORTA);
	sprintf(buffer,"%s",msg);
		
	// sendto: descritor do sock, mensagem, tamanho, ip/porta (ja contido no sockaddr_in) e slen (tamanho do addr_remoto)
	if(sendto(sock_desc, buffer, strlen(buffer), 0, (struct sockaddr *)destino, slen) == -1){
		perror("Erro ao enviar pacote!!!");
 		return;
	}
	// Recebendo um pacote, recvfrom: descritor do sock, buffer, tamanho do buffer, um 0, ip de onde veio (so iria aceitar se fosse do servidor)
	// e slen (tamanho do addr_remoto)
	if( (tam_recebido = recvfrom(sock_desc, buffer, TAMBUFFER, 0, (struct sockaddr *)&destino, &slen)) >= 0 ){
		buffer[tam_recebido] = '\0'; // Indicar um fim de string no tamanho de bytes recebido, senao vai imprimir lixo.
	}
}
