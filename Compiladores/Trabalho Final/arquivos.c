#ifndef ARQUIVOS_C_INCLUDED
#define ARQUIVOS_C_INCLUDED

#include "headers.h"

#define ERRO_PALAVRA -1
#define ERRO_NUM -2

int x = 0,y = 0, n_t;

char class_digito(int dig){
  if(dig>=48 && dig<=57)
    return 'd'; // Classifica o char como um Digito.

  if((dig>=65 && dig<=90) || (dig>=97 && dig<=122))
    return 'l'; // Classifica o char como uma Letra.

  return '0'; // Retorna 0 quer dizer que deve ser um caractere especial
}

/**
 * Função para verificar numeros, enquanto o char for classificado como
 * um numero, ele continuara executando o codigo.
 */
int verifica_num(char *palavra){
  if(class_digito(palavra[0]) == 'd'){
    while(palavra[0] != '\n' && palavra[0] != '\0'){
      if(class_digito(palavra[0]) != 'd')
        return ERRO_NUM;
      palavra++;
    }
    return 1;
  }
  return 0;
}

/**
 * Função para verificar numeros, enquanto o char for classificado como
 * uma letra ou numero,continuara a execução do
 * mesmo para saber se é um identificador.
 */
int verifica_id(char *palavra){
  if(class_digito(palavra[0]) == 'l'){
    while(palavra[0] != '\n' && palavra[0] != '\0'){
      if(class_digito(palavra[0]) == '0')
        return ERRO_PALAVRA;
      palavra++;
    }
    return 1;
  }
  return 0;
}

/**
 * Função para classificar o que cada palavra pode ser.
 */
char* tokens_plv_res(char *palavra){

    if (!strcmp(palavra,"if"))
      return "IF";
    if (!strcmp(palavra,"then"))
      return "THEN";
    if (!strcmp(palavra,"else"))
      return "ELSE";
    if (!strcmp(palavra,"end"))
      return "END";
    if (!strcmp(palavra,"repeat"))
      return "REPEAT";
    if (!strcmp(palavra,"until"))
      return "UNTIL";
    if (!strcmp(palavra,"read"))
      return "READ";
    if (!strcmp(palavra,"write"))
      return "WRITE";
    if (!strcmp(palavra,"+"))
      return "PLUS";
    if (!strcmp(palavra,"-"))
      return "MINUS";
    if (!strcmp(palavra,"*"))
      return "TIMES";
    if (!strcmp(palavra,"/"))
      return "DIV";
    if (!strcmp(palavra,"="))
      return "EQUAL";
    if (!strcmp(palavra,"<"))
      return "LESS";
    if (!strcmp(palavra,"("))
      return "LBRACKET";
    if (!strcmp(palavra,")"))
      return "RBRACKET";
    if (!strcmp(palavra,";"))
      return "DOTCOMA";
    if (!strcmp(palavra,":="))
      return "ATRIB";

    int i = verifica_id(palavra);
    if (i && i != ERRO_PALAVRA)
      return "ID";

    i = verifica_num(palavra);
    if (i && i != ERRO_NUM)
      return "NUM";

    return "ERRO";
}

int verifica_com(char *text){
  while(text[0] != '\n'){
    if(text[0] == '{'){
      while(text[0] != '\n'){
        if(text[0] == '}' && (text[1] == '\n' || text[1] == '\0'))
          return 1;
        text++;
      }
    }
    text++;
  }
  return 0;
}


char* tirar_com(char *text){
  int i;
  for(i = 0; text[i] != '{'; i++);
  text[i] = '\0';
  return text;
}

/**
  Analise Lexica que uma frase somente.
*/
int analise_lexica(Token **token, char *text, Token **tab_token){
  char *aux,*aux2,*aux3;
  int i,j=0,erro = 0;
  x = 0;
  y++;

  //Consome identações
  while(text[0] == '\t')
    text++;

  if(verifica_com(text)) //Fazer uma alteração para eliminar os comentarios
    text = tirar_com(text);

  for(;text[0] != '\n' && text[0] != '\0';text++){
    //Consome espaços em branco
    while(text[0] == ' ')
      text++;

    for(i=1;text[i-1] != ' ' && text[i-1] != '\n' && text[i-1] != '\0';i++);

    aux = (char *)malloc(i*sizeof(char));
    aux3 = (char *)malloc(i*sizeof(char));

    for(i = 0; text[0] != ' ' && text[0] != '\n' && text[0] != '\0';i++,text++){
      aux[i] = text[0];
      aux3[i] = text[0];
    }
    x++;


    aux2 = tokens_plv_res(aux);

    if(!strcmp(aux2,"ERRO")){
      erro++;
      if(verifica_id(aux) == ERRO_PALAVRA)
        printf("Erro lexico da palavra %s na lin: %d, col: %d \n",aux,y,x);
      else{
        if(verifica_num(aux) == ERRO_NUM)
          printf("Erro lexico do numero %s na lin: %d, col: %d \n",aux,y,x);
      }
    }else{
      if(!strcmp(aux2,"ID") || !strcmp(aux2,"NUM")){
        i = search(tab_token,aux3);
        if(!i){
          n_t++;
          add_token(tab_token,aux3,n_t);
          add_token(token,aux2,n_t);
        }else
          add_token(token,aux2,i);
      }else{
        add_token(token,aux2,0);
      }
    }
    free(aux);
  }
  return erro;
}

int read_file(char *arq){
  y = 0;
  n_t = 0;
  FILE *file = fopen(arq,"rt");
  char *text;
  char aux[200];
  int e_t_l = 0;

  Token *token, *tab_token;
  initialize(&token);
  initialize(&tab_token);

  if(file == NULL){
    printf("Deu zika no arquivo");
    return 0;
  }

  while(!feof(file)){
    text = fgets(aux,200,file);
    if(text != NULL){
      e_t_l = analise_lexica(&token,text,&tab_token) + e_t_l;
    }
  }
  fclose(file);

  if(!e_t_l){
    printf("Arquivo não possui nenhum erro lexico, portanto ira para proxima fase de compilação. \n\n");
    printf("Lista de Tokens:\n");
    print_token_list(&token);

    printf("\n");
    printf("Lista de IDs e NUMs:\n");
    print_token_list(&tab_token);
  }else{
    printf("Programa possui %d erro(s), portanto, não passara para a prox. fase de compilação\n",e_t_l);
    return 0;
  }

  if(analise_Sintatica(&token))
    printf("O Programa está sintaticamente correto!!\n");
  else
    printf("O Programa possui erro sintatico.\n");

  return 1;
}

#endif //ARQUIVOS_C_INCLUDED
