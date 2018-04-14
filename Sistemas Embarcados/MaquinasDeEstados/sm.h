/**
  Definindo os tipos de funções que irá receber os estados.
*/

#define STX 0x02
#define ETX 0x03

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef void (*Action_t)(void *, unsigned char);
typedef void (*Callback_t)(unsigned char *);

typedef enum{
  ST_STX,
  ST_ADDR,
  ST_QTD,
  ST_DADOS,
  ST_CHK,
  ST_ETX,
  ST_END
}state_t;

/**
  Union ---> Variaveis que possuem mesmo espaco de memoria
  Variaveis com diferentes representacoes mas com o mesmo espaco de memoria
  union{
    short addr16[2];
    int addr;
    uchar addr8[4];
  }addr_u
*/

/**
  Tipos de dados armazenados:
  STX: 1 byte (Inicio de transmissao) (0x02)
  ADDR: 2 bytes em formato little endian (menos significativo primeiro) -> Para endereco
  QTD_DADOS: 1 byte -> Quantidade de dados transmitidos
  DADOS: N Bytes -> Dados ate 128 bytes, como determina a QTD_DADOS
  CHK: 1 Byte --> Checksum da transmissao -> Soma a partir do enderco ate os dados deve ser igual ao checksum.
  ETX: 1 Byte --> Fim da tranmissao (0x03).
*/
typedef struct StateMachine{
  state_t state;
  Action_t action[ST_END];

  //Endereco
  unsigned short     addr;
  unsigned short addr_rec;

  //Checksum
  unsigned char     chk;
  unsigned char chk_rec;

  //Dados
  unsigned char buffer[128];
  unsigned char   qtd_dados;
  unsigned char     qtd_rec;

  Callback_t callback;
}sm_t;

/**
  Cabecalhos de Funcoes
*/

void initSM(sm_t *sm, unsigned short addr, Callback_t callback);
void execSM(sm_t *sm, unsigned char data);
void ExecSM(sm_t *sm, unsigned char *data, unsigned short size);

