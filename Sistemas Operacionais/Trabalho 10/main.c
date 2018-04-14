#include <mpi.h>
#include <omp.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define n_consumidores 1
#define n_produtores 1
#define rank_prod 0
#define rank_cons 1
#define buffer 5
#define men_buff 100

void sorteio(){
  srand(time(NULL));
}

int main(){

  // Inicializando o MPI
  MPI_Init(NULL, NULL);
  sorteio();

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  alarm(10); // Cada Rank possui 10 segundos para executar, logo apos, como rotina padrao do alarm,
            // o programa sera finalizado

  int mens;
  if(rank == rank_prod){ // Codigo referente ao Produtor


    #pragma omp parallel num_threads(n_produtores)
    {
      int id = omp_get_thread_num(); //Obtem o identificador no produtor
      while(1){
        sleep(1 + rand()%4);
        MPI_Recv();

        MPI_Send();
      }
    }

  }else{
    if(rank == rank_cons){ // Codigo referente ao consumidor
      int i;


      for(i = 0; i < buffer; i++){
        // Manda mensagem vazia para o produtor
        // para simular que ha consumidor parado
        MPI_Send();

      }

      #pragma omp parallel num_threads(n_consumidores)
      {
        int id = omp_get_thread_num(); // Obtem o identificador do consumidor
        while(1){
          sleep(1 + rand()%4);
          MPI_Recv();

          MPI_Send();
        }
      }
    }
  }
}
