#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct noTag{
  struct noTag *prox;
  char *n_token;
  int num;
}Token;

/**
 * Função que diz se o char é um digito,
 * uma letra ou um caractere invalido, ou especial.
 */
char class_digito(int dig);
char* tokens_plv_res(char *palavra);
int verifica_num(char *palavra);
int analise_lexica(Token **token,char *text, Token **tab_token);
int verifica_com(char* text);
int verifica_id(char *palavra);

//Arquivos
int read_file(char *arq);

//Funcoes do Token
void initialize(Token **token);
int add_token(Token **token,char *tkn, int num);
void print_token_list(Token **token);
int search(Token **token,char *tkn);
int rem_inic(Token **token);
int add_ini(Token **token, char *tkn, int num);

char* tirar_com(char *text);

#endif //HEADERS_H_INCLUDED
