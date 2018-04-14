#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<omp.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>

#define n_consumidores 4
#define n_produtores 3
#define buffer 5

sem_t prod;
sem_t consumo;

int init_sem(){
    sem_init(&consumo,0,0);
    sem_init(&prod,0,buffer);
}

void rts_Alarm(int numSig){
  printf("Programa produtor e consumidor encerrado\n");
  exit(0);
}

void sorteio(){
  srand(time(NULL));
}

int main(){
    int n = 0;
    init_sem();
    sorteio();
    signal(SIGALRM,rts_Alarm);
    alarm(20); // Programa encerra em 10 segundos
    #pragma omp parallel num_threads(n_consumidores + n_produtores)
    {
      int id = omp_get_thread_num();

      if(id < n_consumidores){ // Lugar de consumo
        while(1){
          sleep(1 + rand()%4);
          sem_wait(&consumo);
          #pragma omp critical
          {
            printf("O Consumidor %d consumiu o produto %d\n",id,n);
            n--;
          }
          sem_post(&prod);
        }
      }else{ // Senao, e o lugar de producao
        while(1){
          sleep(1 + rand()%4);
          sem_wait(&prod);
          #pragma omp critical
          {
            n++;
            printf("O Produtor %d produziu o produto %d\n",id - n_consumidores,n);
          }
          sem_post(&consumo);
        }
      }

    }
}
