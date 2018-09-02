#include <msp430.h> 


#define SYNC BIT0

void ini_P1_P2(void);
void ini_uCon(void);
void ini_USCI_B0_SPI(void);

unsigned int valor_dac = 0;
unsigned char estado = 0;
/*
 * Uso do DAC121S101 via Serial.
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	ini_P1_P2();
	ini_uCon();

	do{

	}while(1);

}


#pragma vector=USCIAB0TX_VECTOR
__interrupt void RTI_USCI_BO_TX(void){

    IFG2 &= ~UCB0TXIFG;
    while(UCB0STAT & UCBUSY);

    switch(estado){
        case 0:

            UCB0TXBUF = (unsigned char)valor_dac;
            estado = 1;
            break;

        case 1:
            P1OUT |= SYNC;
            valor_dac++;
            P1OUT &= SYNC;
            UCB0TXBUF = (unsigned char)valor_dac>>8;
            estado = 0;
            break;
    }
}


void ini_uCon(void){
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = 0;
}

void ini_P1_P2(void){
    /*
     * Porta 1
     * P1.0 -- /SS /SYNC
     * P1.5 - UCB0CLK
     * P1.7 - UCB0MOSI
     * P1.X - NC
     */
    P1DIR = 0xFF;
    P1OUT = SYNC;

    P2DIR = 0xFF;
    P2OUT = 0;
}


void ini_USCI_B0_SPI(void){

    /*
     * Modo: SPI
     * Clock: SMCLK
     * 8 bits de dados
     */

    UCB0CTL1 |= UCSWRST; // Deixa a interface inativa ou em estado de RESET

    UCB0CTL0 = UCMSB + UCMST + UCSYNC;

    UCB0CTL1 |= UCSSEL1 + UCSWRST;

    UCB0BR1 = 0;
    UCB0BR0 = 1;

    P1SEL |= BIT5 + BIT7; // Configurando
    P1SEL2 |= BIT5 + BIT7; //

    IFG2 &= ~(UCB0TXIFG);
    IE2 |= UCB0TXIE;

    P1OUT &= ~SYNC;

    UCB0TXBUF = (unsigned char) valor_dac >> 8; //Desloca 8 bits, ficando somente os 8 menos significativos.

}
