#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

typedef struct{
  int cont;
  sem_t mutex; //Um semaforo binario
  sem_t prod;
  sem_t cons;
}Shared_Memory;

#define cod_key 1234
#define buffer 5
#define n_consumidores 2
#define n_produtores 3
#define path "arq.txt"
