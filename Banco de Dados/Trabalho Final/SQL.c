#include "headers.h"
#define tamquery 300

/*
  CONSULTAS QUE OBTEM APENAS CODIGOS. PARA EFEITO NA HORA DE ADICIONAR
  PALAVRAS DE UM TEXTO NO BANCO.

  RETORNO DO mysql_query ----> 0 SE DEU CERTO
                         ----> != 0 SE DEU ZIKA

  Funções para consultas:
  int mysql_num_field(MYSQL_RES *res):
    --> Recebe quantos campos existem na tabela que é recebida pela
        Query

  MYSQL_FIELD * mysql_fetch_fields(MYSQL_RES *res);
    --> Retorna uma estrutura do tipo MYSQL_FIELD e ela possui
        os nomes das colunas que saiu como resultado da query.

  MYSQL_ROW mysql_fetch_row(MYSQL_RES *result);
    --> Retorna os registros encontrados e como cada registro tem varias
        colunas, o valor char que é retornado é um vetor sendo que
        cada "posição" corresponde a uma coluna da tabela.

  void mysql_free_result(MYSQL_RES *result);
    --> serve para limpar a variavel que foi usada na saida da query.

  mysql_store_result(MYSQL *conexao);
    --> Retorna o resultado da minha consulta anterior numa estrutura do tipo MYSQL_RES
*/

int get_cod_idioma(MYSQL *conexao, char *idioma){
  char query[tamquery];
  sprintf(query,"select id.idIdioma from idioma id where upper(id.nome) = upper('%s');",idioma);
  return get_cod(conexao,query);
}

int get_cod_autor(MYSQL *conexao, char *nome){
  char query[tamquery];
  sprintf(query,"select a.idAut from autor a where upper(a.nome) = upper('%s');",nome);
  return get_cod(conexao,query);
}

/*
  Função que obtem o id da palavra que está sendo pesquisada apenas
  pelo o nome da palavra e o codIdioma, pois já que uma palavra não
  é unica pois a mesma existe em varios idiomas.
*/
int get_cod_palavra(MYSQL *conexao, char *palavra, int codIdioma){
  char query[tamquery];
  sprintf(query,"select p.idPal from palavra p where upper(p.nome) = upper('%s') and p.fk_idioma = %d;",palavra,codIdioma);
  return get_cod(conexao,query);
}

/**
  Pesquisa para obter codigo do texto em questão só pelo o titulo do mesmo
  para que possa ser usado na hora da inserção das palavras no banco de dados.
*/
int get_cod_text(MYSQL *conexao, char *nome){
  char query[tamquery];
  sprintf(query,"select t.idTex from texto t where upper(t.nome) = upper('%s');",nome);
  return get_cod(conexao,query);
}

int get_cod_pal_text(MYSQL *conexao, int idTex,int idPal){
  char query[tamquery];
  sprintf(query,"select pt.idPalTex from palavra_texto pt where pt.fk_pal = %d and pt.fk_text = %d;",idPal,idTex);
  return get_cod(conexao,query);
}

int get_cod_tipo_texto(MYSQL *conexao, char *nome){
  char query[tamquery];
  sprintf(query,"select tt.idTipText from tipo_texto tt where upper(tt.nome) = upper('%s');",nome);
  return get_cod(conexao,query);
}

int get_cod_pal_tex_prox(MYSQL *conexao, int fk_palTex, int fk_pal){
  char query[tamquery];
  sprintf(query,"select ptp.idPalTex from pal_tex_prox ptp where ptp.fk_palTex = %d and ptp.fk_pal = %d;",fk_palTex, fk_pal);
  return get_cod(conexao,query);
}

/**
    Como uma parte de todas as funções que querem apenas obter um codigo é
    padrão, nada melhor do que fazer uma função que tenha como parametro
    de entrada apenas a conexao e a query(a "pergunta" para o sgbd)
*/
int get_cod(MYSQL *conexao, char *query){
  MYSQL_RES *resp; //Estruta que recebe a resposta
  MYSQL_ROW linha; //Estrutura que recebe uma linha da resposta (neste caso é só uma linha)
  int ret = 0;
  if(!mysql_query(conexao,query)){ //Se a query está ok
    resp = mysql_store_result(conexao);
    if(resp){ //Se obteve resposta, as vezes a query está mal escrita.
      linha = mysql_fetch_row(resp); //Obter a linha de resposta da query.
      if(linha != NULL){ //Se tem pelo menos uma linha, é pq tem resposta e que foi encotnrado algo.
        ret = atoi(linha[0]); //em linhas, ele possui um char*, como pesquisei por um cod,
        // sempre será retornado um numero, assim não tendo o perigo de retornar algo diferente.
        mysql_free_result(resp); //Limpa o buffer do mysql da consulta que foi feita
        return ret;
      }else
        return ret;
    }else
      return ret;
  }else
    return ret;
}

/** FUNÇÕES DESTINADAS AS FUNÇÕES DE INSERTS
  Muito simples. Cada função ira retornar o codigo que foi inserido.
*/
void commit(MYSQL *conexao){
  mysql_query(conexao,"commit;");
}

int insert(MYSQL *conexao, char *query){
  int res = mysql_query(conexao,query);
  if(res){
    printf("Erro na inserção: %d: %s\n",mysql_errno(conexao),mysql_error(conexao));
  }
  return res;
}

int insert_idioma(MYSQL *conexao, char *nome){
  char query[tamquery];
  sprintf(query,"insert into idioma (nome) values (upper('%s'));",nome);
  if(!insert(conexao,query))
    return get_cod_idioma(conexao,nome);
  else
    return 0;
}

int insert_texto(MYSQL *conexao,char *nome,int fk_autor, int fk_idioma, int fk_tipTex){
  char query[tamquery];
  sprintf(query,"insert into texto (nome, fk_tiptex, fk_autor, fk_idioma) values (upper('%s'),%d,%d,%d);",nome,fk_tipTex,fk_autor,fk_idioma);
  if(!insert(conexao,query))
    return get_cod_text(conexao,nome);
  else
    return 0;
}

int insert_palavra_texto(MYSQL *conexao,int fk_text,int fk_pal){
  char query[tamquery];
  sprintf(query,"insert into palavra_texto (fk_text, fk_pal) values (%d,%d);",fk_text, fk_pal);
  if(!insert(conexao,query))
    return get_cod_pal_text(conexao,fk_text,fk_pal);
  else
    return 0;
}

int insert_pal_tex_prox(MYSQL *conexao, int fk_palTex, int fk_pal){
  char query[tamquery];
  sprintf(query,"insert into pal_tex_prox (fk_palTex, fk_pal) values (%d,%d);",fk_palTex,fk_pal);
  return insert(conexao,query);
}

int insert_palavra(MYSQL *conexao, char *nome, int fk_idioma){
  char query[tamquery];
  sprintf(query,"insert into palavra (nome, fk_idioma) values (upper('%s'),%d);",nome,fk_idioma);
  if(!insert(conexao,query))
    return get_cod_palavra(conexao,nome,fk_idioma);
  else
    return 0;
}

int insert_tipo_texto(MYSQL *conexao, char *nome){
  char query[tamquery];
  sprintf(query,"insert into tipo_texto (nome) values (upper('%s'));",nome);
  if(!insert(conexao,query))
    return get_cod_tipo_texto(conexao,nome);
  else
    return 0;
}

int insert_autor(MYSQL *conexao,char *nome){
  char query[tamquery];
  sprintf(query,"insert into autor (nome) values (upper('%s'));",nome);
  if(!insert(conexao,query))
    return get_cod_autor(conexao,nome);
  else
    return 0;
}

/** UPDATES VALUES
  Funções para update.
*/
int update(MYSQL *conexao, char *query){
  return mysql_query(conexao,query);
}

int update_ocor_pal_tex(MYSQL *conexao, int idPalTex){
  char query[tamquery];
  sprintf(query,"update palavra_texto set ocorrencia = ocorrencia+1 where idPalTex = %d;",idPalTex);
  if(!update(conexao,query))
    return 1;
  return 0;
}

int update_ocor_pal_tex_prox(MYSQL *conexao, int idPalTexProx){
  char query[tamquery];
  sprintf(query,"update pal_tex_prox set ocorrencia = ocorrencia+1 where idPalTexProx = %d;",idPalTexProx);
  if(!update(conexao,query))
    return 1;
  return 0;
}
