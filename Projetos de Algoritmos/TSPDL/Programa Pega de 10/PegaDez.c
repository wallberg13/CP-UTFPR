#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Ordem dos paramentros do arquivo de entrada
fprintf(out,"%s & %.2f & %.2f & %d & %d & %.2f & %.2f \\\\ \\hline\n,file,mediaGrasp,t_med_G,maior,menor,media,t_med);
*/
char* processaString(char *string);

int main(int argc,char *arg[]){
  if(argc > 2){

    FILE *in = fopen(arg[1],"r+");
    if(in == NULL){
      printf("Deu z1k4 no arquivo. \n");
      return 1;
    }

    FILE *out = fopen(arg[2],"a");

    char arquivo[200], nomeArquivo[200];
    int menor, maior, menorGe, maiorGe, ok = 0;
    double t_med_G, medG, medSA, t_med_SA;
    double somaTG = 0.0 , somaTSA = 0.0, somaSG = 0, somaSSA = 0;

    int i;

    while(!feof(in)){
      menorGe = 99999; maiorGe = 0; somaTG = 0.0; somaTSA = 0.0; somaSG = 0.0; somaSSA = 0.0;
      for(i = 0; i <= 9; i++){
        if(fscanf(in,"%s %lf %lf %d %d %lf %lf",arquivo,&medG,&t_med_G,&maior,&menor,&medSA, &t_med_SA) != EOF){
          if(menorGe > menor)
            menorGe = menor;

          if(maiorGe < maior)
            maiorGe = maior;

          somaTG += t_med_G;
          somaTSA += t_med_SA;

          somaSG += medG;
          somaSSA += medSA;

          strcpy(nomeArquivo,arquivo);
          if(i == 9)
            ok = 1;
        }else{
          ok = 0;
        }
      }
      if(ok){
        strcpy(nomeArquivo,processaString(nomeArquivo));
        nomeArquivo[0] = ' ';
        printf("File Family:%s \t GRASP: %.2f \t T_GRASP: %.2f \t Maior: %d \t Menor: %d \t SA_Sol: %.2f \t SA_Tem: %.2f \n", nomeArquivo, somaSG/10.0, somaTG/10.0, maior, menor, somaSSA/10.0,somaTSA/10.0);
        fprintf(out,"%s & %.2f & %.2f & %d & %d & %.2f & %.2f \\\\ \\hline\n", nomeArquivo, somaSG/10.0,somaTG/10.0,maior,menor,somaSSA/10.0,somaTSA/10.0);
      }
    }

    fclose(in);
    fclose(out);
  }
}

char* processaString(char *string){
  int b = 0, under = 0, i;

  for(i = 0; string[i] != '\0'; i++){
    if(string[i] == '/')
      b = i;

    if(string[i] == '_')
      under = i;
  }
  string[under] = '\0';
  return strrchr(string,'/');
}
