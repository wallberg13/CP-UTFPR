#include <msp430.h> 

void ini_P1_P2(void);
void ini_uCon(void);

/*
 * main.c
 */
int main(void) {

    long i = 0;
    ini_uCon();
    ini_P1_P2();

    /* CONFIG. DO WDT
     * Clock: ACLK ~ 6kHz
     * Modo: watchdog
     * Saida: Q15 -> 32768
     * Int.: desabilitada
     */

    WDTCTL = WDTPW + WDTSSEL;

    do{
        if(i >= 100000){
            i = 0;
            P1OUT ^= BIT0; //Alternando o estado do LED VM
            WDTCTL = WDTPW + WDTSSEL + WDTCNTCL;
        }else{
            i++;
        }
    /**
     * P1.3 -> S2
     *      S2 aberta   - 1
     *      S2 fechada  - 0
     *
     * bit      7 6 5 4 3  2 1 0
     * P1IN     X X X X S  X X X
     * ~P1IN    X X X X /S X X X
     * BIT 3
     */
        if((~P1IN)&BIT3){
            do{
                //Trap: Armadinha
            }while(1);
        }
    }while(1);
}
//-----------------------------------------------------------------------------------------------

void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    /* CONFIG. O BCS
     *
     * MCLK = DCOCLK ~ 16MHz
     * SMCLK = DCOCLK/8 ~ 2MHz
     * ACLK = VLOCLK/2 ~ 6kHz
     * BCSCTL1 = CALBC1_16MHZ + DIVA0 + DIVA1; //DIVA0 E DIVA1 --> DIVIDIR O CLOCK
    */

    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ + DIVA0;
    BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = LFXT1S1 + XCAP0 + XCAP1;

    /*
     * Verificar se o sinal de clock se estabilizou ou nao
     * while(BCSCTL3 & LFXT1OF);
     */

}

void ini_P1_P2(void){
    /*
     * CONFIG. DA PORTA 1
     * P1.3 - Entrada com resistor de pull-up
     * P1.0 - LED VM - saida em nivel baixo
     * P1.X - Demais nao conectados - Saida em nivel baixo
     *
     * BIT3     0 0 0 0 0 1 0 0
     * ~BIT3    1 1 1 1 1 0 1 1
     */
    P1DIR = ~BIT3;
    P1REN = BIT3;
    P1OUT = BIT3;

    /* CONFIG. DA PORTA 2
     * P2.X - N.C -> todos como saida em nivel baixo
     *
     * Pinos 18 e 19 -> Conectados no LFXT1
     */
    P2DIR = 0xFF;
    P2OUT = 0;
}
