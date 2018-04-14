#include "headers.h"

#define alpha 0.65
#define AMOSTRA 2

/*
  Veja o artigo do VNS. Ao inves de mostrar tudo mostrar a media de cada grupo de 10 instancias
  Outro dado que seria legal era uma coluna para mostrar a fase de construção do grasp
  Dai a gente pode escrever o artigo como uma solução hibrida
*/
void povo_demand(TSP *tsp,int n, char *text){
  int i,j;
  char *aux;
  for(i = 0; i < n; i++,text++){
    for(j = 0; text[j] != ' ' && text[j] != '\n' && text[j] != '\0';j++);
    aux = (char *)malloc(j*sizeof(char));

    for(j = 0; text[0] != ' ' && text[0] != '\n' && text[0] != '\0';j++,text++){
      aux[j] = text[0];
    }

    tsp[i].demand = atoi(aux);
    free(aux);
  }
}

void povo_draft(TSP *tsp,int n, char *text){
  int i,j;
  char *aux;
  for(i = 0; i < n; i++,text++){
    for(j = 0; text[j] != ' ' && text[j] != '\n' && text[j] != '\0';j++);
    aux = (char *)malloc(j*sizeof(char));

    for(j = 0; text[0] != ' ' && text[0] != '\n' && text[0] != '\0';j++,text++){
      aux[j] = text[0];
    }

    tsp[i].draft = atoi(aux);
    tsp[i].visited = 0;
    free(aux);
  }
}

void povoamento_Mtz(int **mtz, char *text,int n, int y){
  int i,j;
  char *aux;
  for(i = 0; i < n; i++,text++){
    for(j = 0; text[j] != ' ' && text[j] != '\n' && text[j] != '\0';j++);
    aux = (char *)malloc(j*sizeof(char));

    for(j = 0; text[0] != ' ' && text[0] != '\n' && text[0] != '\0';j++,text++){
      aux[j] = text[0];
    }

    mtz[i][y] = atoi(aux);
    free(aux);
  }
}

int import(char *in, char *out1){
  FILE *arq = fopen(in,"rt");
  int x,y,n;
  FILE *out = fopen(out1,"a");
  //Para leitura do arquivo;
  char aux[200];
  char *text;

  //Dados do problema.
  TSP *tsp;
  int **mtz;

  if(arq == NULL){
    printf("Deu zika \n");
    return 1;
  }

  //fprintf(out,"\\multicolumn{1}{c}{\\multirow{2}{*}{Instancia}} & \\multicolumn{2}{l}{GRASP} & \\multicolumn{4}{c}{Simulated Annealing} \\\\ \n");
  //fprintf(out,"\\multicolumn{1}{c}{} & Sol & Tempo & Maior & Menor & Media & Tempo \\\\ \\midrule \n");

  while(!feof(arq)){

    text = fgets(aux,200,arq);
    if(text != NULL && text[0] != '!'){

      if(!strcmp(cap_first(text),"N")){
        n = cap_N(text);
        initialize(&tsp,n);
        mtz = cria_matriz(n);
      }

      if(!strcmp(cap_first(text),"Distance")){
        y = 0;
        while(text[0] != ']' && y < n){
          text = fgets(aux,200,arq);
          if(text[0] != ']')
            povoamento_Mtz(mtz,text,n,y);
          y++;
        }
      }

      if(!strcmp(cap_first(text),"Demand")){
        text = fgets(aux,200,arq);
        povo_demand(tsp,n,text);
      }

      if(!strcmp(cap_first(text),"Draft")){
        text = fgets(aux,200,arq);
        povo_draft(tsp,n,text);
      }
    }
  };

  int a;
  int menor, maior;
  long int somaSA;
  long int somaCGrasp;
  int *sol = cria_vetor(n);
  double tempoGrasp;
  //double alpha = 0.05;
  //SIMULATED ANNEALING
  //while(alpha <= 1.0){
    menor = 99999;
    maior = 0;
    somaSA = 0;
    somaCGrasp = 0;
    tempoGrasp = 0.0;
    clock_t tsa = clock(), grasp;

    for(a = 0; a < AMOSTRA; a++){
      grasp = clock();
      sol = construcao(tsp,mtz,n,alpha);
      grasp = clock() - grasp;
      tempoGrasp += grasp/(double)CLOCKS_PER_SEC;

      y = valorSol(sol,n,mtz);
      x = SA(tsp,mtz,n,sol);
      somaSA = somaSA + x;
      somaCGrasp = somaCGrasp + y;
      if(x < menor)
        menor = x;
      if(x > maior)
        maior = x;
    }

    tsa = clock() - tsa;
    double t_med = tsa/(double)(CLOCKS_PER_SEC*AMOSTRA);
    double media = somaSA/(double)AMOSTRA;
    double mediaGrasp = somaCGrasp/(double)AMOSTRA;
    double t_med_G = tempoGrasp/AMOSTRA;
    printf("File: %s\t\t T_Grasp: %.2f \t S_GRASP: %.2f \tMenor: %5d \tMedia: %.2f \tTempo: %.2f \n",in,t_med_G,mediaGrasp,menor, media,t_med);

    fprintf(out,"%s %.2f %.2f %d %d %.2f %.2f\n",in,mediaGrasp,t_med_G,maior,menor,media,t_med);
    //alpha += 0.05;
  //}
//  fclose(out);
  fclose(arq);
  fclose(out);

  /**
    Limpar aquilo que foi alocado na memoria.
  */
  limpa_tsp(tsp);
  limpa_matriz(mtz,n);
  return 1;
}

char* cap_first(char *txt){
  char *aux;
  int i;

  for(i = 0;txt[i] != '\n' && txt[i] != '\0' && txt[i] != ':';i++);
  aux = (char *)malloc(i*sizeof(char));

  for(i = 0;txt[0] != '\n' && txt[0] != '\0' && txt[0] != ':';i++,txt++)
    aux[i] = txt[0];
  return aux;
}

int cap_N(char *txt){
  int i;
  char *aux;

  for(i = 0;txt[i] != '\n' && txt[i] != '\0';i++);
  aux = (char *)malloc(i*sizeof(char));
  for(i = 0;txt[0] != ' ' && txt[0] != '\n' && txt[0] != '\0'; txt++,i++)
    aux[i] = txt[0];

  if(!strcmp(aux,"N:")){
    txt++;
    free(aux);
    for(i = 0; txt[i] != '\n' && txt[i] != '\0';i++);
    aux = (char *)malloc(i*sizeof(char));
    for(i = 0; txt[0] != ' ' && txt[0] != '\n' && txt[0] != '\0';i++,txt++)
      aux[i] = txt[0];
    i = atoi(aux);
    free(aux);
    return i;
  }
  return 0;
}
