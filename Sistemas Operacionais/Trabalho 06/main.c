#include "headers.h"

Shared_Memory *sm;

void init_semaforo(Shared_Memory *sm){
  sem_init(&(sm->cons),1,0); // Consumidor começa dormindo
  sem_init(&(sm->mutex),1,1); // Mutex começa fora da região critica
  sem_init(&(sm->prod),1,buffer); // Consumidor na sua capacidade maxima
  sm->cont = 0;
  printf("Semaforos Inicializados\n");
}

/**
  Arquivo dedicado a criar a shared memory
  como também para chamar os processos.
  Esse processo também irá inicializar os semaforos que
  estão na memoria compartilhada.
*/
int main(){
  int shmid;
  // Criando um arquivo tentando abrir um arquivo já existente
  // Caso ele não exista ainda, é criado
  key_t key = ftok(path,cod_key); //Criando um chave
  // Alocando uma memoria compartilhada com o tamanho da estrutura definida
  // Como o Shared_Memory
  shmid = shmget(key,sizeof(Shared_Memory), IPC_CREAT|SHM_R|SHM_W);

  if(shmid == -1){ // Deu erro
    perror("Erro no shmget");
    exit(1);
  }

  printf("%d\n",shmid);
  printf("%d\n",ftok("arq.txt",cod_key));

  /**
    Agora é preciso achar aonde a mémoria foi alocada
    para poder fazer a inicialização dos semaforos.
  */
  sm = (Shared_Memory *)shmat(shmid, NULL, 0); // Attach, Parecendo com o malloc
  init_semaforo(sm);

  pid_t pid;
  if((pid = fork()) == 0){
    execl("consumidor",NULL);
  }else{
    if((pid = fork()) == 0){
      execl("produtor",NULL);
    }
  }

  /**
    Trecho que só vai permitir do programa
    terminar quanto os seus filhos terminarem também.
  */
  pid_t child;
  for(;;){
    child = wait(NULL);
    if((child == -1) && (errno != EINTR))
      break;
  }

  shmctl(shmid, IPC_RMID, NULL); //Destruindo ou desalocando o segmento de memoria
  printf("Segmento de Memoria destruido\n");
  return 0;
}
