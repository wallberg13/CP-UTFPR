#include "headers.h"
#define vazio "vazio"
/**
 NA PILHA SINTATICA, USANDO A MESMA ESTRUTURA DO TOKEN.
 TOKEN.NUM = 0; --> É VARIAVEL.
 TOKEN.NUM = 1; --> É TERMINAL.
*/
int analise_Sintatica(Token **token){
  Token *pilha;
  initialize(&pilha);
  add_ini(&pilha,"A",0);
  char *c;

  do{
//   printf("Pilha: ");
//   print_token_list(&pilha);
//   printf("Tokens: ");
//   print_token_list(token);
//   printf("\n\n\n");
    if((*token) == NULL)
      c = vazio;
    else
      c = (*token)->n_token;

    if(pilha->num){ //É terminal
      if(!strcmp(pilha->n_token,c)){
        rem_inic(token);
        rem_inic(&pilha);
      }else{
        return 0;
      }
    }else{
      if(!tab_Gram(&pilha,pilha->n_token,c))
        return 0;
    }
  }while(pilha != NULL && token != NULL);
  return 1;
}


/**
  Tabela Sintatica Top - Down da gramatica TINY.
*/
int tab_Gram(Token **pilha,char *topPil,char *topFil){

  if(!strcmp(topPil,"A") && ( !strcmp(topFil,"IF") ||
     !strcmp(topFil,"REPEAT") || !strcmp(topFil,"ID") ||
     !strcmp(topFil,"READ") || !strcmp(topFil,"WRITE") ) ){
    rem_inic(pilha);
    add_ini(pilha,"B",0);
    return 1;
  }

  if(!strcmp(topPil,"B") && ( !strcmp(topFil,"IF") ||
     !strcmp(topFil,"REPEAT") || !strcmp(topFil,"ID") ||
     !strcmp(topFil,"READ") || !strcmp(topFil,"WRITE") ) ){
    rem_inic(pilha);
    add_ini(pilha,"B'",0);
    add_ini(pilha,"C",0);
    return 1;
  }

  if(!strcmp(topPil,"B'") && !strcmp(topFil,"DOTCOMA")){
    rem_inic(pilha);
    add_ini(pilha,"B'",0);
    add_ini(pilha,"C",0);
    add_ini(pilha,"DOTCOMA",1);
    return 1;
  }

  if(!strcmp(topPil,"B'") && (!strcmp(topFil,"ELSE") ||
     !strcmp(topFil,"END") || !strcmp(topFil,"UNTIL") || !strcmp(topFil,vazio))){
    rem_inic(pilha);
    return 1;
  }

  if(!strcmp(topPil,"C") && !strcmp(topFil,"IF")){
    rem_inic(pilha);
    add_ini(pilha,"D",0);
    return 1;
  }

  if(!strcmp(topPil,"C") && !strcmp(topFil,"REPEAT")){
    rem_inic(pilha);
    add_ini(pilha,"E",0);
    return 1;
  }

  if(!strcmp(topPil,"C") && !strcmp(topFil,"ID")){
    rem_inic(pilha);
    add_ini(pilha,"F",0);
    return 1;
  }

  if(!strcmp(topPil,"C") && !strcmp(topFil,"READ")){
    rem_inic(pilha);
    add_ini(pilha,"G",0);
    return 1;
  }

  if(!strcmp(topPil,"C") && !strcmp(topFil,"WRITE")){
    rem_inic(pilha);
    add_ini(pilha,"H",0);
    return 1;
  }

  if(!strcmp(topPil,"D") && !strcmp(topFil,"IF")){
    rem_inic(pilha);
    add_ini(pilha,"D'",0);
    add_ini(pilha,"B",0);
    add_ini(pilha,"THEN",1);
    add_ini(pilha,"I",0);
    add_ini(pilha,"IF",1);
    return 1;
  }

  if(!strcmp(topPil,"D'") && !strcmp(topFil,"ELSE")){
    rem_inic(pilha);
    add_ini(pilha,"END",1);
    add_ini(pilha,"B",0);
    add_ini(pilha,"ELSE",1);
    return 1;
  }

  if(!strcmp(topPil,"D'") && (!strcmp(topFil,"DOTCOMA") ||
     !strcmp(topFil,"END") || !strcmp(topFil,"UNTIL") || !strcmp(topFil,vazio))){
    rem_inic(pilha);
    return 1;
  }

  if(!strcmp(topPil,"E") && !strcmp(topFil,"REPEAT")){
    rem_inic(pilha);
    add_ini(pilha,"I",0);
    add_ini(pilha,"UNTIL",1);
    add_ini(pilha,"B",0);
    add_ini(pilha,"REPEAT",1);
    return 1;
  }

  if(!strcmp(topPil,"F") && !strcmp(topFil,"ID")){
    rem_inic(pilha);
    add_ini(pilha,"I",0);
    add_ini(pilha,"ATRIB",1);
    add_ini(pilha,"ID",1);
    return 1;
  }

  if(!strcmp(topPil,"G") && !strcmp(topFil,"READ")){
    rem_inic(pilha);
    add_ini(pilha,"ID",1);
    add_ini(pilha,"READ",1);
    return 1;
  }

  if(!strcmp(topPil,"H") && !strcmp(topFil,"WRITE")){
    rem_inic(pilha);
    add_ini(pilha,"I",0);
    add_ini(pilha,"WRITE",1);
    return 1;
  }

  if(!strcmp(topPil,"I") && (!strcmp(topFil,"ID") ||
     !strcmp(topFil,"LBRACKET") || !strcmp(topFil,"NUM") )){
    rem_inic(pilha);
    add_ini(pilha,"I'",0);
    add_ini(pilha,"K",0);
    return 1;
  }

  if(!strcmp(topPil,"I'") && (!strcmp(topFil,"LESS") || !strcmp(topFil,"EQUAL"))){
    rem_inic(pilha);
    add_ini(pilha,"K",0);
    add_ini(pilha,"J",0);
    return 1;
  }

  if(!strcmp(topPil,"I'") && (!strcmp(topFil,"DOTCOMA") ||
     !strcmp(topFil,"THEN") || !strcmp(topFil,"ELSE") ||
     !strcmp(topFil,"END") || !strcmp(topFil,"UNTIL") ||
     !strcmp(topFil,vazio) || !strcmp(topFil,"RBRACKET") )){
    rem_inic(pilha);
    return 1;
  }

  if(!strcmp(topPil,"J") && !strcmp(topFil,"LESS")){
    rem_inic(pilha);
    add_ini(pilha,"LESS",1);
    return 1;
  }

  if(!strcmp(topPil,"J") && !strcmp(topFil,"EQUAL")){
    rem_inic(pilha);
    add_ini(pilha,"EQUAL",1);
    return 1;
  }

  if(!strcmp(topPil,"K") && (!strcmp(topFil,"ID") ||
     !strcmp(topFil,"LBRACKET") || !strcmp(topFil,"NUM"))){
    rem_inic(pilha);
    add_ini(pilha,"K'",0);
    add_ini(pilha,"M",0);
    return 1;
  }

  if(!strcmp(topPil,"K'") && (!strcmp(topFil,"PLUS") || !strcmp(topFil,"MINUS") )){
    rem_inic(pilha);
    add_ini(pilha,"K'",0);
    add_ini(pilha,"M",0);
    add_ini(pilha,"L",0);
    return 1;
  }

  if(!strcmp(topPil,"K'") && (!strcmp(topFil,"DOTCOMA") ||
     !strcmp(topFil,"THEN") || !strcmp(topFil,"ELSE") ||
     !strcmp(topFil,"END") || !strcmp(topFil,"UNTIL") ||
     !strcmp(topFil,vazio) || !strcmp(topFil,"RBRACKET") ||
     !strcmp(topFil,"LESS") || !strcmp(topFil,"EQUAL") )){
    rem_inic(pilha);
    return 1;
  }

  if(!strcmp(topPil,"L") && !strcmp(topFil,"PLUS")){
    rem_inic(pilha);
    add_ini(pilha,"PLUS",1);
    return 1;
  }

  if(!strcmp(topPil,"L") && !strcmp(topFil,"MINUS")){
    rem_inic(pilha);
    add_ini(pilha,"MINUS",1);
    return 1;
  }

  if(!strcmp(topPil,"M") && (!strcmp(topFil,"ID") ||
     !strcmp(topFil,"LBRACKET") || !strcmp(topFil,"NUM"))){
    rem_inic(pilha);
    add_ini(pilha,"M'",0);
    add_ini(pilha,"O",0);
    return 1;
  }

  if(!strcmp(topPil,"M'") && (!strcmp(topFil,"TIMES") || !strcmp(topFil,"DIV") )){
    rem_inic(pilha);
    add_ini(pilha,"M'",0);
    add_ini(pilha,"O",0);
    add_ini(pilha,"N",0);
    return 1;
  }

  if(!strcmp(topPil,"M'") && (!strcmp(topFil,"DOTCOMA") ||
     !strcmp(topFil,"THEN") || !strcmp(topFil,"ELSE") ||
     !strcmp(topFil,"END") || !strcmp(topFil,"UNTIL") ||
     !strcmp(topFil,vazio) || !strcmp(topFil,"RBRACKET") ||
     !strcmp(topFil,"LESS") || !strcmp(topFil,"EQUAL") ||
     !strcmp(topFil,"PLUS") || !strcmp(topFil,"MINUS") )){
    rem_inic(pilha);
    return 1;
  }

  if(!strcmp(topPil,"N") && !strcmp(topFil,"TIMES")){
    rem_inic(pilha);
    add_ini(pilha,"TIMES",1);
    return 1;
  }

  if(!strcmp(topPil,"N") && !strcmp(topFil,"DIV")){
    rem_inic(pilha);
    add_ini(pilha,"DIV",1);
    return 1;
  }

  if(!strcmp(topPil,"O") && !strcmp(topFil,"ID")){
    rem_inic(pilha);
    add_ini(pilha,"ID",1);
    return 1;
  }

  if(!strcmp(topPil,"O") && !strcmp(topFil,"LBRACKET")){
    rem_inic(pilha);
    add_ini(pilha,"RBRACKET",1);
    add_ini(pilha,"I",0);
    add_ini(pilha,"LBRACKET",1);
    return 1;
  }

  if(!strcmp(topPil,"O") && !strcmp(topFil,"NUM")){
    rem_inic(pilha);
    add_ini(pilha,"NUM",1);
    return 1;
  }

  return 0;
}
