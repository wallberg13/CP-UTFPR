#include<mpi.h>
#include<stdio.h>

int main(){
  // Inicializa o MPI
  MPI_Init(NULL, NULL);

  // Obtem o numero total de processos MPI
  int total_proc;
  MPI_Comm_size(MPI_COMM_WORLD, &total_proc);

  // Obtem o id do processo MPI
  int id_proc;
  MPI_Comm_rank(MPI_COMM_WORLD, &id_proc);

  // Obtem o nome do processador


  // Printa mensagens hello word de cada processador.
  printf("Hello World do processador %d de %d processadores\n", id_proc, total_proc);

  MPI_Finalize();
}
