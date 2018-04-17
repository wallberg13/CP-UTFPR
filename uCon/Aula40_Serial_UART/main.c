#include <msp430.h> 

void ini_uCon();
void ini_P1_P2();
void ini_TA1_Deboucer(void);


/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	ini_P1_P2();
	ini_uCon();

	do{

	}while(1);
}

#pragma vector=

#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_TA1_M0(){

}



void ini_uCon(){
   DCOCTL = CALDCO_16MHZ;
   BCSCTL1 = CALBC1_16MHZ;
   BCSCTL2 = DIVS0;
   BCSCTL3 = XCAP1 + XCAP2;
}


void ini_P1_P2(){
    P1DIR = ~BIT3;
    P1REN = BIT3;
    P1OUT =

}

void ini_TA0(){
    TA0CTL = TASSEL1 + MC0;
    TA0CCTL = CCIE;

}

void ini_TA1_Deboucer(){
    TA1CTL = TASSEL1;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 31999;
}

// --- Inicialização de UART

void ini_USCI_A0_UART(void){
    UCA0CTL1 = UCSSEL1 + UCSWRST;

    UCA0CTL0 = 0;

    UCA0BR0 = 0x41; //Via TAb. 15-4 para 9600bps e 8MHz de clock
    UCA0BR1 = 0x3;

    UCA0MCTL = UCBRS1;

    // PORTA 1
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;

    IFG2 &= ~UCA0TXIFG;
    IE2 |=
}
