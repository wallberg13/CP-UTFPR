/**
  Funções static para a máquina de estados
*/
#include "sm.h"

/**
  Funções dos estados
**/

static void fn_stx(sm_t *sm, unsigned char data){
  /**
    No inicio da maquina de estados, todo mundo esta zerado, tanto o
    endereco recebido, como tambem o checksum, pois ele ainda nao comecou
    a ser verificado, como tambem a qtd_rec de dados.
  */
  if(data == STX){
    printf("Inicio de mensagem reconhecido \n");
    sm->chk_rec = 0;
    sm->addr_rec = 0;
    sm->qtd_rec = 0;
    memset(sm->buffer, 0, 128);
    sm->state = ST_ADDR;
  }
}

static void fn_addr(sm_t *sm, unsigned char data){

  // Parte menos significativa
  if(sm->addr_rec == 0){
    sm->addr_rec = data;
  }else{
    sm->addr_rec |= (((unsigned short) data)<<8);
    printf("Endereco recebido: %x \n", sm->addr_rec);
    if(sm->addr_rec == sm->addr){
      sm->state = ST_QTD;
    }else{
      sm->state = ST_STX;
      if(sm->callback != NULL){
        sm->callback("Endereco invalido");
      }
    }
  }
  sm->chk_rec += data;
}

static void fn_qtd(sm_t *sm, unsigned char data){
  sm->qtd_dados = data;
  sm->chk_rec += data;
  printf("Quantidade de bytes: %d \n", data);
  sm->state = ST_DADOS;
}

static void fn_dados(sm_t *sm, unsigned char data){

  if(sm->qtd_rec < sm->qtd_dados){
    sm->buffer[sm->qtd_rec] = data;
    sm->qtd_rec++;
    if(sm->qtd_rec == sm->qtd_dados){
      sm->state = ST_CHK;
      sm->buffer[sm->qtd_rec] = '\0';
      printf("Dado recebido: %s\n", sm->buffer);
    }
  }
  sm->chk_rec += data;
}

static void fn_chk(sm_t *sm, unsigned char data){
  sm->chk = data;
  printf("sm->chk_rec: %x sm->chk: %x\n", sm->chk_rec, sm->chk);
  if(sm->chk_rec == sm->chk){
    sm->callback("Mensagem processadada com sucesso!! ");
  }else{
    sm->callback("Error no checksum");
  }
  sm->state = ST_STX;
}

static void fn_etx(sm_t *sm, unsigned char data){
  if(data == ETX){
    sm->callback(sm->buffer);
  }
  sm->state = ST_ETX;
}

/**
  Callback ==> Ponteiro de Função para quando a merda acontecer
*/
void initSM(sm_t *sm, unsigned short addr, Callback_t callback){
  sm->state    = ST_STX;
  sm->callback = callback;

  sm->action[ST_STX]   = (Action_t) fn_stx;
  sm->action[ST_ADDR]  = (Action_t) fn_addr;
  sm->action[ST_QTD]   = (Action_t) fn_qtd;
  sm->action[ST_DADOS] = (Action_t) fn_dados;
  sm->action[ST_CHK]   = (Action_t) fn_chk;
  sm->action[ST_ETX]   = (Action_t) fn_etx;

  sm->addr     = addr;
  sm->addr_rec = 0;
  sm->chk      = 0;
  sm->chk_rec  = 0;

  sm->qtd_dados = 0;
  sm->qtd_rec   = 0;

  memset(sm->buffer, 0, 128);
}

/**
  Colocar em alguma interrupção de máquina, ou da serial
*/
void execSM(sm_t *sm, unsigned char data){
  sm->action[sm->state](sm, data);
}

void ExecSM(sm_t *sm, unsigned char *data, unsigned short size){
  int i = 0;

  for(i = 0; i < size; i++){
    execSM(sm,data[i]);
  }

}
