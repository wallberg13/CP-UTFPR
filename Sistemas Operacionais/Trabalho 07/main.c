#include "headers.h"

int pfd[2];

int main(){

  pipe(pfd);
  pid_t pid;
  int i = 0;

  for(i = 0; i < n_produtores; i++){
    if((pid = fork()) == 0){
      close(pfd[READ]);
      char channel[8], id[8];
      sprintf(id,"%d",i+1);
      sprintf(channel,"%d",pfd[WRITE]);
      execl("./produtor","produtor",channel,id,NULL);
    }
  }

  for(i = 0; i < n_consumidores; i++){
    if((pid = fork()) == 0){
        close(pfd[WRITE]);
        char channel[8], id[8];
        sprintf(id,"%d",i+1);
        sprintf(channel,"%d",pfd[READ]);
        execl("./consumidor","consumidor",channel,id,NULL);
    }
  }


  /**
    Trecho que só vai permitir do programa
    terminar quanto os seus filhos terminarem também.
  */
  pid_t child;
  for(;;){
    child = wait(NULL);
    if((child == -1) && (errno != EINTR))
      break;
  }

  return 0;
}
