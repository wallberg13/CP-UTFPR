#include"headers.h"

#define MAX 8

int channel;
int id;

void rts_Alarm(int numSig){
  printf("Consumidor %d Finalizando\n",id);
  close(channel);
  exit(0);
}

int main(int argc, char *args[]){
  id = atoi(args[2]);
  channel = atoi(args[1]);
  char produtor[MAX];
  srand(time(NULL));
  // Para que o programa tenha algum final
  signal(SIGALRM, rts_Alarm);
  alarm(10);

  while(1){
    read(channel,produtor,MAX);
    printf("O consumidor %d acabada de consumir do produtor %d \n",id,atoi(produtor));
    sleep(1);
  }

  return 0;
}
