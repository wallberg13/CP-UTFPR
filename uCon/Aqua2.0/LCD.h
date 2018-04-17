/*
 * lcd.h
 *
 *  Created on: 24 de jun de 2017
 *      Author: ParedeMan
 */

#ifndef LCD_H_
#define LCD_H_

#include <msp430.h>

/**
 * Condifuração das portas:
 *
 * DB4: Data bus 4 - BIT4 da P1
 * DB5: Data bus 5 - BIT5 da P1
 * DB6: Data bus 6 - BIT6 da P1
 * DB7: Data bus 7 - BIT7 da P1
 *
 * RS: Register Select Signal - BIT3 da P2
 * ES: Enable Signal - BIT4 da P2 --> Entrada pois o display irá dizer se esta pronto
 *                                --> ou não para fazer tal operacao
 *
 * RW: Leitura e escrita: BIT5 da P2
 *
 * Comandos: É preciso enviar comandos para o LCD para ver o que vai fazer.
 *           Estes comandos são enviados de 4 em 4 bits.
 *
 *          0x80 - Primeira Linha, Primeira Coluna
 *          0xC0 - Segunda Linha, Primeira Coluna
 *
 *          0x01 - Limpar Tudo
 *          0x0C - "Desliga o Cursor" --- Não está fazendo isso
 *          0x14 - Move o cursor para direita -- Datasheet
 *
 *
 * Algoritmo para enviar comandos para o
 * Display LCD 16x2.
 *
 * Primeiro, sempre verifica se o barramento está ocupado,
 * para isso é preciso criar sucessiveis bordas de descida em E
 * e verificar o DB7, porém, o DB7 deve está configurado como entrada
 * digital (E o RW como saida em nivel alto).
 * Fora isto, ele é saida.
 *
 * Logo depois, Prepara-se o display para que ele possa receber dados.
 * Para comandos, o RS deve ser 0
 * Para dados, o RS deve ser 1
 *
 *
 *
 * */
/** P1 */
#define DB4 BIT4 //Pino 11 do display
#define DB5 BIT5 //Pino 12 do display
#define DB6 BIT6 //Pino 13 do display
#define DB7 BIT7 //Pino 14 do display

/** P2 */
#define RS BIT3 // Pino 4 do display
#define ES BIT4 // Pino 6 do display
#define RW BIT5 // Pino 5 do display


#define RS_WRITE P2OUT |= RS // Escrever no display
#define RS_COM P2OUT &= ~RS // Mandar comandos para o Display

#define RW_WRITE P2OUT &= ~RW
#define RW_READ P2OUT |= RW

#define ENABLE_ON P2OUT |= ES
#define ENABLE_OFF P2OUT &= ~ES

#define BUS_WRITE P1DIR |= 0xF0 // Para escrever, todo mundo e saida - Só configura os 4 ultimos
// Bits para saída, assim não influenciando nos demais
#define BUS_READ P1DIR &= ~DB7 // Para ler, neste caso, so sera utilizado para configurar a escrita.


#define delay_cycles 2000
#define delay_clear 20000
void write_data();
void write_clear();
void wait(); //Função que irá esperar ficar esperando o barramento ficar desocupado.

void send_comand(unsigned char comd);
void write_string(char *str);
void ini_LCD();
void set_position(int y,int x); //Setando a posicao do cursor




#endif /* LCD_H_ */
