#include "headers.h"

#define tamtext 200

int import(char *arq, MYSQL *conexao){
  FILE *file = fopen(arq,"rt");
  char *text;
  char aux[tamtext];
  int codAut = 0, codIdi = 0, codTex = 0, codTipTex = 0;
  char *aux2;

  if(file == NULL){
    printf("Deu zika no arquivo\n");
  }

  while(!feof(file)){
    text = fgets(aux,tamtext,file);
    if(text != NULL){
      printf("%s",text);

      /** Primeiro só é lido o cabeçalho que foi posto para padronizar,
          Depois é que finalmente poderá ser as palavras, e para isso é bom que
          tenha uma função separada para que possa ser feito isso.*/
      if(!codAut || !codIdi || !codTipTex || !codTex)
        aux2 = get_first(text);
      else{
        destrincha(conexao,text,codIdi,codTex);
      }

      if(!strcmp(aux2,"AUTOR")){
        aux2 = get_nome(text);
        codAut = get_cod_autor(conexao,aux2);
        if(!codAut)
          codAut = insert_autor(conexao,aux2);
      }

      if(!strcmp(aux2,"IDIOMA")){
        aux2 = get_nome(text);
        codIdi = get_cod_idioma(conexao,aux2);
        if(!codIdi)
          codIdi = insert_idioma(conexao,aux2);
      }

      if(!strcmp(aux2,"TIPO_TEXTO")){
        aux2 = get_nome(text);
        codTipTex = get_cod_tipo_texto(conexao,aux2);
        if(!codTipTex)
          codTipTex = insert_tipo_texto(conexao,aux2);
      }

      if(!strcmp(aux2,"TEXTO")){
        aux2 = get_nome(text);
        codTex = get_cod_text(conexao,aux2);
        if(!codTex){
          codTex = insert_texto(conexao,aux2,codAut,codIdi,codTipTex);
        }else{
          printf("Texto já existe, Portanto, a operação será cancelada\n");
          mysql_query(conexao,"rollback");
          return 0;
        }
      }
    }
  }
  fclose(file);
}

char* get_first(char *text){
  int i;
  char *aux;

  for(i = 0;text[i] != '\0' && text[i] != '\n' && text[i] != ':'; i++);
  aux = (char *)malloc(i*sizeof(char));

  for(i = 0;text[0] != '\0' && text[0] != '\n' && text[0] != ':'; i++,text++){
    aux[i] = text[0];
  }
  aux[i] = '\0';
  return aux;
}

char* get_nome(char *text){
  int i;
  char *aux;

  /** Não preciso capturar a primeira parte da palavra pois não é necessario. */
  for(;text[0] != ' ' && text[0] != '\0' && text[0] != '\n' && text[0] != ':'; text++);

  /** PEGA O RESTO DA STRING*/
  text++;
  text++;
  for(i = 0; text[i] != '\n' && text[i] != '\0'; i++);
  aux = (char *)malloc(i*sizeof(char));

  for(i = 0;text[0] != '\n' && text[0] != '\0';text++,i++){
    aux[i] = text[0];
  }
  aux[i] = '\0';
  return aux;
}

/** Como deve ser ignorado caracteres especiais, como: { ' ; , .  */
/** Detalhe sobre o ponto(.), ao ser encontrado, a proxima palavra que ele achar não entra do
    pal_tex_prox da palavra anterior.
*/
void destrincha(MYSQL *conexao, char *text, int codIdi, int codText){
  char *aux;
  int i, x = 0;
  int codPal = 0, codPalTex = 0, codPalTexProx = 0;
  AUX *a;
  initialize(&a);
  while(text[0] != '\0'){

    while(text[0] == ' ' || text[0] == '\t' || text[0] == '`')
      text++;

    for(i = 0;text[i] != '\t' && text[i] != ':' && text[i] != ';' && text[i] != '`' && text[i] != ' ' && text[i] != '\'' && text[i] != ',' && text[i] != '.' && text[i] != '\n' && text[i] != '\0';i++);
    aux = (char *)malloc(i*sizeof(char));

    for(i = 0; text[0] != '\t' && text[0] != ':' && text[0] != ';' && text[0] != '`' && text[0] != ' ' && text[0] != '\'' && text[0] != ',' && text[0] != '.' && text[0] != '\n' && text[0] != '\0';text++,i++){
      aux[i] = text[0];
    }

    aux[i] = '\0';
    printf("%s\n",aux);

    /** Inserção da palavra no banco -- SOMENTE A PALAVRA */
    codPal = get_cod_palavra(conexao,aux,codIdi);
    if(!codPal){
      codPal = insert_palavra(conexao,aux,codIdi);
      commit(conexao);
    }

    codPalTex = get_cod_pal_text(conexao,codText,codPal);
    if(!codPalTex){
      codPalTex = insert_palavra_texto(conexao,codText,codPal);
      commit(conexao);
    }else{
      update_ocor_pal_tex(conexao,codPalTex);
      commit(conexao);
    }

    addFinal(&a,codPalTex,codPal);

    text++;
    if(text[0] == ' ' || text[0] == '\t' || text[0] == '`'){
      text++;
    }
    free(aux);
  }

  /** */
  pal_tex_prox_povo(conexao,&a);
  limpa(&a);

}
