#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define passos 1000000000
#define inc j = j*2
#define n 16

double soma_total = 0.0;
long pass_per_thread;
/**
  Este i define o intervalo que será feito a thread. Exemplo, 2
  threads para i = 0, o laço for varia entre 0*pass_per_thread + 1 até (i+1)*pass_per_thread
*/
void* pi_parcial(void* i){
  double soma_parc = 0.0;
  long j,w = (long)i;

  for(j = w*pass_per_thread; j < (w + 1)*pass_per_thread; j++){
    if(j % 2 == 0)
      soma_parc += 1.0/(2.0*j + 1.0);
    else
      soma_parc -= 1.0/(2.0*j + 1.0);
  }

  soma_total += soma_parc;
}

int main(){
  long i;
  int j;
  FILE *out = fopen("out.txt","w+");

  for(j = 1; j <= n; inc){
    pthread_t threads[j];
    pass_per_thread = passos / j;
    soma_total = 0.0;

    struct timespec t1,t2;

    clock_gettime(CLOCK_MONOTONIC, &t1);
    for(i = 0; i < j; i++){
      pthread_create(&threads[i], NULL, pi_parcial, (void *)i);
    }


    for(i = 0; i < j; i++){
      pthread_join(threads[i],NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &t2);

    double temp = (double)(t2.tv_sec - t1.tv_sec) + (t2.tv_nsec - t1.tv_nsec)/1E9;
    printf("Thread: %2d - Pi: %.14f - Tempo: %.3f s\n",j,4*soma_total,temp);
    fprintf(out,"%d %.4f\n",j,temp);
  }

  fclose(out);
  return 0;
}
