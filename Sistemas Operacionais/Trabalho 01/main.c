#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid, childpid;

	char id;

	printf("Sou %d, o Pai de todos os processos desse trabalho\n",getpid());
	int i;
	for(i = 0; i < 3; i++){
		if((pid = fork()) <= 0){ //Criou o Filho então fica em break;
			id = i;
			printf("Eu sou: %d Filho de %d e meu id é: %d\n",getpid(),getppid(),id);
			break;
		}
	}

	if(pid == 0){
		if(id == 0){
			pid = fork();
			if(pid == 0){
				printf("Eu sou: %d Filho de %d e meu id maior é 0\n",getpid(),getppid());
			}
		}else{
			if(id == 2){
				for(i = 0; i < 2; i++){
					if((pid = fork()) == 0){
						printf("Eu sou: %d Filho de %d e meu id maior é 2\n",getpid(),getppid());
					}else{
						break;
					}
				}
			}
		}
	}

	for(;;){ // O pai entra em wait até todos os seus filhos terminarem.
		childpid = wait(NULL);
		if((childpid == -1) && (errno != EINTR))
			break;
	}

	printf("Eu sou: %d Filho de %d e estou morrendo\n",getpid(),getppid());
}
