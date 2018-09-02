#include "headers.h"

/*
  Funções para carregar uma lista de Strings.
  Essa lista será usada no algoritmo Apriori, só a fim de exibição

  Ele irá gerar uma "matriz" que na vdd é um vetor de strings.
*/
int cata_Colu_char(char *text, CharZao **cz){
  int i, x = 0;
  char *aux;

  while(text[0] != '\0'){
    while(text[0] == ' ' || text[0] == '\t')
      text++;

    for(i = 0; text[i] != ' ' && text[i] != '\t' && text[i] != '\n' && text[i] != '\0';i++);
    aux = (char *)malloc(i*sizeof(char));
    for(i = 0; text[0] != ' ' && text[0] != '\t' && text[0] != '\n' && text[0] != '\0'; i++, text++){
      aux[i] = text[0];
    }
    aux[i] = '\0';
    add_CharZao_Fim(cz,aux);
    text++;
    x++;
  }
  return x;
}

CharZao* loadStr(char *arq,int *x){
  FILE *file = fopen(arq,"r+");

  if(file == NULL){
    printf("Deu zika no arquivo\n");
    return NULL;
  }

  CharZao *cz;
  ini_CharZao(&cz);
  char aux[1000];
  char *text;
  int y = 0;
  while(!feof(file)){
    text = fgets(aux,200,file);
    if(text != NULL){
      y += cata_Colu_char(text,&cz);
    }
  }
  fclose(file);
  *x = y;
  return cz;
}
