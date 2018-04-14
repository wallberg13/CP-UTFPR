#include "headers.h"

Coluna* cata_Colu(char *text, int y){
  Coluna *aux2;
  ini_Coluna(&aux2);
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
    add_Coluna_Fim(&aux2,y,x,atoi(aux));
    free(aux);
    x++;
    text++;
  }
  return aux2;
}

/**
  O vetor de dimensão é alterado para que a saida saia de
  acordo com o esperado.
*/
int** loadInt(char *arq,int *dim){
  FILE *file = fopen(arq,"r+");
  if(file == NULL){
    printf("Deu zika no arquivo\n");
    return NULL;
  }
  int x,y;
  char aux[200];
  char *text;
  Linha *lin;
  ini_Linha(&lin);
  y = 0;
  while(!feof(file)){
    text = fgets(aux,200,file);
    if(text != NULL){
      add_Linha_Fim(&lin,y,cata_Colu(text,y));
      y++;
    }
  }
  dim[0] = y;
  dim[1] = cont_Coluna(&lin);
  int **mtz;
  mtz = converte_Matriz(&lin,dim);

  fclose(file);
  return mtz;
}
