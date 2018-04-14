#include "headers.h"

#define MAX 8

int id;
int channel;

void rts_Alarm(int numSig){
  printf("Produtor %d Finalizando\n",id);
  close(channel);
  exit(0);
}

int main(int argc, char *args[]){
  id = atoi(args[2]);
  channel = atoi(args[1]);
  char trans[MAX];
  srand(time(NULL));

  // Para que o programa tenha algum final.
  signal(SIGALRM, rts_Alarm);
  alarm(10);

  while(1){
    sprintf(trans,"%d",id);
    write(channel,trans,MAX);
    printf("Produtor %d acabou de produzir! \n",id);
    sleep(1);
  }

  return 0;
}
