#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>

/**
  Problema da contagem
*/

#define cont_per_thread 50 // Contagem que cada threads devem contar
#define n 5 //Numero de threads

int j = 1;
sem_t s[n];

/**
  O primeiro semaforo deve dá um post pra poder funcionar enquanto os
  outros devem da wait.
*/
int init_sem(){
  int i;
  for(i = 0; i < n; i++){
    sem_init(&s[n],0,0);
  }
}

void* incrementa(void* i){
  long id = (long)i;
  sem_wait(&s[id]);

  for(;j <= (id+1)*cont_per_thread;j++){
    sleep(1);
    printf("Thread %d > %d\n",id,j);
  }

  if(id + 1 < n)
    sem_post(&s[id + 1]);

  // Não precisa desativar o semaforo atual, pois aqui ele é finalizado.
}

int main(){
  int time_sleep = 10;
  pthread_t threads[n];
  long i;

  init_sem();
  sem_post(&s[0]); // O Zero é o unico que tem algo pra produzir, enquanto os outros não possuem
  for(i = 0; i < n; i++){
    pthread_create(&threads[i],NULL,incrementa,(void *)i);
  }

  for(i = 0; i < n; i++){
    pthread_join(threads[i],NULL);
  }

  return 0;
}
