#include"headers.h"

Shared_Memory *sm;
pthread_t thread[n_consumidores];
/**
  Cada processo primeiro deve saber qual a chave da memoria
  compartilhada pra dps fazer o attach.

  Também deve-se dá o get e etc.
*/

void *Consumo(void* i){
  long id = (long)i;
  while(1){
    sleep(2);
    sem_wait(&(sm->cons)); //Down no consumo
    sem_wait(&(sm->mutex)); //Down no mutex
    if(sm->cont > 0){
      printf("Consumidor %d consumiu o produto %d\n",id,sm->cont);
      sm->cont--;
    }
    sem_post(&(sm->mutex));
    sem_post(&(sm->prod));
  }
}

int main(){
  int shmid;

  key_t key = ftok(path, cod_key);
  // Pegando a chave da memoria que quero utilizar
  shmid = shmget(key, sizeof(Shared_Memory),IPC_CREAT|SHM_R|SHM_W);
  sm = (Shared_Memory *)shmat(shmid,NULL, 0); // Attach

  printf("Tudo pronto no Consumidor para poder consumir\n");
  long i;
  for(i = 0; i < n_consumidores; i++){
    pthread_create(&thread[i], NULL, Consumo, (void *)i);
  }

  sleep(14);
  printf("Consumidor Finalizando\n");
  return 0;
}
