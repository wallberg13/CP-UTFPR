#include <msp430.h> 

#define LED_VM BIT0

void ini_P1_P2(void);
void ini_uCon(void);
void ini_TA0(void);

/*
 * main.c
 */
int main(void) {

    //long i = 0;
    ini_uCon();
    ini_P1_P2();


    do{

    }while(1);
}
//-----------------------------------------------------------------------------------------------


#pragma vector=TIMER0_A0_VECTOR
__interrupt void RTI_TIMER0_M0(void){
    //Não precisa limpar a flag de int.
    P1OUT ^= BIT0;
}


void ini_TA0(void){
    TA0CTL = TASSEL0 + MC0;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 32767;
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

    P1OUT = BIT3;
    P1IES = BIT3;
    P1IFG = 0;
    P1IE = BIT3;

    P2DIR = 0xFF;
    P2OUT = 0;
}

