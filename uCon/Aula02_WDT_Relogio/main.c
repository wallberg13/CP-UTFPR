#include <msp430.h> 

#define LED_VM BIT0

void ini_P1_P2(void);
void ini_uCon(void);

unsigned char SEGUNDO = 0, MINUTO = 0, HORA = 0;
/*
 * main.c
 */
int main(void) {

    //long i = 0;
    ini_uCon();
    ini_P1_P2();

    /* CONFIG. DO WDT
     * Clock: ACLK = 32768 Hz
     * Modo: Temporizador
     * Saida: 15 -> 32768 contagens
     * Int.: Habilitada
     * Tempo de int.: 1 segundo
     *
     */

    WDTCTL = WDTPW + WDTTMSEL + WDTCNTCL + WDTSSEL;
    IE1 |= WDTIE; //Habilita Interrupcao: Habilita somente o bit que quero (que no caso é o bit 0)

    do{

    }while(1);
}
//-----------------------------------------------------------------------------------------------

//RTI do WDT
#pragma vector = WDT_VECTOR
__interrupt void WDT_RTI(void){
    /*
     * A CPU entra nesta RTI a cada 1s
     *
     * E necessario limpar a flag de int?
     * R.: Nao, pois e limpa automaticamente pelo
     * hardware.
     */
    P1OUT ^= LED_VM;

    if(SEGUNDO >= 59){
        SEGUNDO = 0;
        if(MINUTO >= 59){
            MINUTO = 0;
            if(HORA >= 23){
                HORA = 0;
            }else{
                HORA++;
            }
        }else{
            MINUTO++;
        }
    }else{
        SEGUNDO++;
    }
}

void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    /* CONFIG. O BCS
     *
     * MCLK = DCOCLK ~ 1MHz
     * SMCLK = DCOCLK/8 ~ 125 kHz
     * ACLK = LFXT1CLK = 32768 Hz
     * BCSCTL1 = CALBC1_16MHZ + DIVA0 + DIVA1; //DIVA0 E DIVA1 --> DIVIDIR O CLOCK
    */

    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = XCAP0 + XCAP1; //Fonte do Clock do Cristal

    /*
     * BCSCTL3
     *                                |----> LFXT1OF
     *                                |
     * bits             7 6 5 4 3 2 1 0
     * BCSCTL3          X X X X X X X Y
     * BIT0<-->LFXT1OF  0 0 0 0 0 0 0 1
     *  AND B-A-B       ---------------
     *                  0 0 0 0 0 0 0 Y
     *
     * Se Y == 1, entao LFXT1 nao esta sintonizado ainda
     * com o cristal
     *
     * Se Y == 0, entao LFXT1 tem a freq. nominal do cristal,
     * ou seja, ja pode ser utilizado.
     *
     * O programa so pode funcionar com o sinal de LFXT1
     * sintonizado na freq. do cristal, caso contrario, o
     * relogio nao vai funcionar corretamente.
     */
    while(BCSCTL3 & LFXT1OF);

    /* Seta bit GIE de R2, ou seja, habilita a
     * CPU a aceitar Requisicoes de Int. (IRQs).
     */
    __enable_interrupt();

}

void ini_P1_P2(void){
    /*
     * CONFIG. DA PORTA 1
     * P1.0 - LED VM - Saida a cada 1 seg
     * P1.X - Demais nao conectados - Saida em nivel baixo
     *
     * BIT3     0 0 0 0 0 1 0 0
     * ~BIT3    1 1 1 1 1 0 1 1
     */
    P1DIR = 0xFF; //Todo mundo sendo pino de saída
    P1OUT = 0; //Tudo desligado

    /* CONFIG. DA PORTA 2
     * P2.X - N.C -> todos como saida em nivel baixo
     *
     * Pinos 18 e 19 -> Conectados no LFXT1
     */
    P2DIR = 0xFF;
    P2OUT = 0;

}
