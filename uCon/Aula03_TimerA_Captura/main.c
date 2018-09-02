#include <msp430.h> 


void ini_P1_P2(void);
void ini_uCon(void);
void ini_TA0_CAP_Mode(void);

unsigned int val_atual = 0, val_anterior = 0, contagens = 0;
long freq_dco;
char captura = 0;

void main(void) {
    ini_P1_P2();
    ini_uCon();
    ini_TA0_CAP_Mode();

    do{

    }while(1);
}


#pragma vector=TIMER0_AO_VECTOR
__interrupt void RTI_TIMER0_M0(void){
    val_atual = TA0CCR0;

    if(captura >= 1){
        if(val_atual >= val_anterior){
            contagens = val_atual - val_anterior;
        }else{
            contagens = 65536 - val_atual + val_anterior;
        }

        /*
         * << ==> Deslocamento de Bit
         * Numero << X
         * Deslocou X vezes o bit do numero
         */
        freq_dco = contagens;
        freq_dco = freq_dco<<12;
        //ou: freq_dco <<= 12;
    }

    captura = 1;
    val_anterior = val_atual;
}


void ini_TA0_CAP_Mode(void){
    TA0CTL = TASSEL1 + MC1;
    TA0CCTL0 = CM0 + CAP + CCIE;
}

void ini_uCon(void){
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ + DIVA0 + DIVA1;
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF);
    _enable_interrupt();

}

void ini_P1_P2(void){
    /*
     * P1.0 - Saida de sinal ACLK -> PINO 2
     * P1.1 - Entrada para TA0.CCIOA -> PINO 3
     * P1.X - Saida nivel baixo.
     */
    P1DIR = ~BIT1;
    P1SEL |= BIT0 + BIT1;
    P1OUT = 0;

    P2DIR = 0xFF;
    P2OUT = 0;
}
