#include "headers.h"

/**
  O Programa que irá gerenciar os dois processos,
  tanto o consumidor como o produtor, é quem irá definir
  a Shared Memory.
  Cabe ao produtor e Consumidor
*/
Shared_Memory *sm;
pthread_t thread[n_produtores];

void *Producao(void* i){
  long id = (long)i;
  while(1){
    sleep(1);
    sem_wait(&(sm->prod));
    sem_wait(&(sm->mutex)); //Entrando na região critica
    if(sm->cont < buffer){
      sm->cont++;
      printf("Produtor %d produziu o produto %d \n",id, sm->cont);
    }
    sem_post(&(sm->mutex));
    sem_post(&(sm->cons));
  }
}


int main(){
  int shmid;
  key_t key = ftok(path,cod_key);
  shmid = shmget(key, sizeof(Shared_Memory), IPC_CREAT|SHM_R|SHM_W);
  sm = (Shared_Memory *)shmat(shmid, NULL, 0);

  printf("Tudo pronto no Produtor para poder produzir\n");
  long i;
  for(i = 0; i < n_produtores; i++){
    pthread_create(&thread[i], NULL, Producao, (void *)i);
  }

  sleep(10);
  printf("produtor Finalizando\n");
  return 0;
}
