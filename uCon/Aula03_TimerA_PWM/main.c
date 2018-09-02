#include <msp430.h> 


void ini_P1_P2(void);
void ini_uCon(void);
void ini_TA0_PWM(void);
void ini_TA1_Deboucer(void);

void main(void) {
    ini_P1_P2();
    ini_uCon();
    ini_TA0_PWM();
    ini_TA1_Deboucer();

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

void ini_TA1_Deboucer(void){
    /*
     * TIMER 1
     * Modo contador: UP
     * Clock: SMCLK ~ 125kHz
     * Fdiv:
     *
     * Modulo 0:
     * Funcao: Comparacao
     * Int.: Habilitada
     * Tempo: 5.25 ms
     * TA0CCR0 = 655
     */

    TA1CTL = TASSEL1; //Inicialmente parado;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 655;
}

void ini_TA0_PWM(void){
    /**
     * Modo> UP
     * Clock ?
     * FDIV 1
     *
     *                              10ms          x ms
     *                             TA0CCR0       TA0CCR1
     * SMCLK ~ 125 kHz            >> 1249 <<     0 - 1249*
     * ACLK = 32768 Hz               327         0 - 327
     *
     *
     *      TA0CCR0 = ((tempo*CLOCK)/(FDIV)) - 1
     * Modulo 0
     * Funcao> COMPARACAO
     * PWM> 10ms
     * Int> Desabilitada
     *
     * Modulo 1
     * Funcao> Comparacao
     * PWM> Razao ciclica variavel
     * Int> Desabilitada

       Modulo 0 nao precisa ser considerado

     */

    TA0CTL = TASSEL1 + MC0;
    TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;
    TA0CCR0 = 1249;
    TA0CCR1 = 0;
}

void ini_uCon(void){
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    /*
     * DCO ~ 1M
     *
     */

    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    BCSCTL2 = DIVS0 + DIVS1;
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
}
