#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>

#define HOST "localhost"
#define USER "guest"
#define PASS "guest"
#define DB "words"

/**sudo
  OBS: SEMPRE COMPILAR ESTE PROGRAMA COM A FLAG>>>> -lmysqlclient
**/


/** Estruturas e Funções do arquivo AUX.c
  Funções para facilitar a inserção na tabela pal_tex_prox.
  */
typedef struct noTag{
  struct noTag *prox;
  int idPalTex;
  int idPal;
}AUX;

void initialize(AUX **aux);
int addFinal(AUX **aux,int idPalTex, int idPal);
int limpa(AUX **aux);
int pal_tex_prox_povo(MYSQL *conexao, AUX **aux);

/* Funçoes do arquivos.c */
int import(char *file, MYSQL *conexao);
char* get_first(char *text);
char* get_nome(char *text);
void destrincha(MYSQL *conexao, char *text, int codIdi, int codText);

/* Funções do SQL.c */
/* Funções que tem por função (ba dum tss)
   retorna valores de codigos para que possam
   serem usados na inserção de tabelas que
   precisam
*/
int get_cod_idioma(MYSQL *conexao, char *idioma);
int get_cod_autor(MYSQL *conexao, char *nome);
int get_cod_palavra(MYSQL *conexao, char *palavra, int codIdioma);
int get_cod_text(MYSQL *conexao, char *nome);
int get_cod_pal_text(MYSQL *conexao, int idTex,int idPal);
int get_cod_tipo_texto(MYSQL *conexao, char *nome);
int get_cod_pal_tex_prox(MYSQL *conexao, int fk_palTex, int fk_pal);
int get_cod(MYSQL *conexao, char *query);

/**
  Funções que fazem inserção em banco.
*/
int insert(MYSQL *conexao, char *query);
int insert_idioma(MYSQL *conexao, char *nome);
int insert_texto(MYSQL *conexao,char *nome,int fk_autor, int fk_idioma, int fk_tipTex);
int insert_palavra_texto(MYSQL *conexao,int fk_text,int fk_pal);
int insert_pal_tex_prox(MYSQL *conexao, int fk_palTex, int fk_pal);
int insert_palavra(MYSQL *conexao, char *nome, int fk_idioma);
int insert_tipo_texto(MYSQL *conexao, char *nome);
int insert_autor(MYSQL *conexao,char *nome);

int update_ocor_pal_tex(MYSQL *conexao, int idPalTex);
int update_ocor_pal_tex_prox(MYSQL *conexao, int idPalTexProx);

void commit(MYSQL *conexao);

#endif //HEADERS_H_INCLUDED
