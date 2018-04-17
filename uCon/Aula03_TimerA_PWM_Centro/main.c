#include <msp430.h> 

/**
 * TimerR0 - Alinhado a borda
 *
 */

void ini_P1_P2(void);
void ini_uCon(void);
void ini_TA0_PWM_borda(void);
void ini_TA1_PWM_centro(void);

void main(void) {
    ini_P1_P2();
    ini_uCon();
    ini_TA0_PWM_borda();
    ini_TA1_PWM_centro();

    do{

    }while(1);
}

//------------------------------------------------------

/*
 * RTI da Porta 01
 */
#pragma vector=PORT1_VECTOR
__interrupt void RTI_Porta_1(void){
    P1IFG &= ~BIT3;
    P1IE &= ~BIT3;
    TA1CTL |= MC0;
}

/*
 * RT1 do TIMER 1 - Modulo 0
 */
#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_TA1_M0(void){
    TA1CTL &= ~MC0;

    if((~P1IN) & BIT3){
       if(TA0CCR1 >= 1250){
           TA0CCR1 = 0;
       }else{
           TA0CCR1 = TA0CCR1 + 313;
       }
    }
    P1IFG = 0;
    P1IE |= BIT3;
}

void ini_TA1_PWM_borda(void){
    /*
     * TIMER 1
     * Modo contador: UP
     * Clock: SMCLK ~ 125kH
     */

    TA1CTL = TASSEL1 + MC0;
    TA1CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;
    TA1CCR0 = 1599;
    TA1CCR1 = 0;
}

void ini_TA0_PWM_borda(void){
    /**
     * Config. Timer 0 - Fpwm = 10kHz
     * Modo> UP
     * Clock ?
     * FDIV 1
     *                              100 us
     *                             TA0CCR0
     * SMCLK 16 MHz               >> 1599 <<
     *
     *      TA0CCR0 = ((tempo*CLOCK)/(FDIV)) - 1
     * Modulo 0
     * Funcao> COMPARACAO
     * PWM> 10ms
     * Int> Desabilitada
     */

    TA1CTL = TASSEL1 + MC0;
    TA1CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;
    TA1CCR0 = 1599;

}

void ini_uCon(void){
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    /*
     * DCO ~ 16 Mhz
     * LFXT1CLK = 32768 Hz
     */

    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC16_1MHZ;
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF);

    _enable_interrupt();
}

void ini_P1_P2(void){
    /*
     * P1.3 - S2 - Entrada com Resistor de pull-up e
     *             int de borda de descida.
     * P1.6 - Saidade PWM do Mod. 1 do Timer 0
     * P1.X - Saida nivel baixo.
     */
    P1DIR = ~BIT3;
    P1REN = BIT3;
    P1OUT = BIT3;
    P1SEL |= BIT6;
    P1IES = BIT3;
    P1IFG = 0;
    P1IE = BIT3;

    P2DIR = 0xFF;
    P2OUT = 0;
    P2SEL |= BIT1 + BIT2 + BIT4 + BIT5;
}
