#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

/**
  Problema do pombo correio,
  Varios produtores e somente um pombo.
*/
#define cont_prod 10
#define cont_pombo 1
#define quant_carta 20

pthread_mutex_t mutex; // Regiao critica
sem_t pomba; // Pomba'
sem_t prod; // Controla o estoque de cartas
int cont_carta = 0;

void *pomba_gira(){
  int i;
  while(1){
    sem_wait(&pomba);

    printf("A pomba-gira acordou - Levando as cartas para B\n");
    sleep(1);
    pthread_mutex_lock(&mutex);
    cont_carta = 0;
    printf("A pomba-gira voltou do ponto B - Voltou a dormir - Mande-me Cartas\n");

    for(i = 0; i < quant_carta; i++){ // "Descolando as cartas"
      sem_post(&prod);
    }
    pthread_mutex_unlock(&mutex);
  }
}

void *produtor(void* i){
  long id = (long)i;
  while(1){
    sem_wait(&prod);
    //sleep(1);
    pthread_mutex_lock(&mutex);
    cont_carta++;
    printf("%d - Carta nº %d postada! \n",id,cont_carta);

    if(cont_carta == quant_carta){
      sem_post(&pomba);
    }
    pthread_mutex_unlock(&mutex);
  }
}

int ini_sem(){
  sem_init(&pomba,0,0); // Começa dormindo.
  printf("A pomba está em A, dormindo e esperando cartas! \n");
  sem_init(&prod,0,quant_carta); // Começa podendo produzir
}

int main(){
  int tempoExec = 12;
  long i;
  srand((unsigned int)time(NULL));

  pthread_t produtores[cont_prod];
  pthread_t pombo;

  ini_sem();

  for(i = 0; i < cont_prod; i++){
    pthread_create(&produtores[i], NULL, produtor, (void *)i);
  }

  pthread_create(&pombo, NULL, pomba_gira, NULL);

  sleep(tempoExec);
  printf("A pomba parou de girar\n");
  exit(0);
  return 0;
}
