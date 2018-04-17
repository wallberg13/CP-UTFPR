#include <msp430.h> 

#define LED_VM BIT0

void ini_P1_P2(void);
void ini_uCon(void);

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


//RTI da P1
#pragma vector= PORT1_VECTOR
__interrupt void P1_RTI(void){

    /*
     * 1 - Precisa limpar flag de int.?
     * R.: Sim, pois o hardware nao limpa
     * automaticamente.
     *
     *      COMO LIMPAR:
     *          P1IFG &= ~BIT3; //Limpa flag BIT3
     *
     */
    P1IFG &= ~BIT3; // Limpando a flag de int de P1.3

    P1IE &= ~BIT3; //Desabilitando a int. de P1.3

    //(void) P1IFG; //Este registrador quando é lido, é limpo
    /*
     * CLOCK
     *
     * SAIDA WDT            Q6      Q9      Q13     Q15
     *                      64     512     8192   32768
     *
     * ACLK 32768 Hz       1,9ms  15,6ms   250ms    1s
     *
     * SMCLK 125kHz        512us   >4,1ms<   65,5ms  262ms
     *
     * Clock: SMCLK
     * Modo: Temporizador
     * Saida: Q9 -> 512 contagens
     * Int.: Habilitada
     * Tempo de int.: 4,1 ms
     *
     */

    WDTCTL = WDTPW + WDTTMSEL + WDTCNTCL + WDTIS0;
    IE1 |= WDTIE; //Habilita Interrupcao: Habilita somente o bit que quero (que no caso é o bit 0)

}
//RTI do WDT
#pragma vector = WDT_VECTOR
__interrupt void WDT_RTI(void){

    /*
     * 1 - Parar o temporizador
     *
     * 2 - Validar Tecla -> Realiza a acao da tecla
     *      -> Alternar o estado do LED VM
     *
     * 3 - Limpar flag de int. de P1.3
     *
     * 4 - Habilitar a geracao de int. de P1.3;
     */

    WDTCTL = WDTPW + WDTHOLD;

    /*
     * Verifica se a porta está fechada (então no bit3) do
     * P1IN
     */
    if((~P1IN) & BIT3){
        P1OUT ^= BIT0;
    }

    //Habilitando novamente a flag
    P1IFG &= ~BIT3;
    P1IE |= BIT3;
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
    P1DIR = ~BIT3;
    P1REN = BIT3;
    P1OUT = BIT3;
    P1IES = BIT3;
    P1IFG = 0;
    P1IE = BIT3;

    P2DIR = 0xFF;
    P2OUT = 0;
}
