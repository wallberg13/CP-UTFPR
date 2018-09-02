#include <stdio.h>
#include <signal.h>

int cont = 0;

void rts_Alarm(int numSig){
  printf("\n 5 Segundos se passaram\n Vlw, Flw\n");
  exit(0);
}

void rts_Ctrl_C(int numSig){
  cont++;
  char resp;
  if(cont == 10){
    printf("\nForam Recebidos 10 Sinais do tipo SIGINT \nApós 5 segundo este programa fechará!");
    printf("\n Deseja Sair? (Y/n)\n");
    alarm(5);
    scanf("%c",&resp);
    if(resp == 'Y' || resp == 'y' || resp == 13){
      exit(0);
    }else{
      alarm(0);
      cont = 0;
    }
  }
}

void rts_Ctrl_Z(int numSig){
  printf("\nSinal SIGINT foi recebido %d vezes \n",cont);
}

int main(){
  signal(SIGINT,rts_Ctrl_C);
  signal(SIGTSTP,rts_Ctrl_Z);
  signal(SIGALRM,rts_Alarm);

  printf("Esperando Receber os Sinais\n");
  while(1)
    pause();
}
