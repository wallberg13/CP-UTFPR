#include <msp430.h> 

/** Debounced Encoder*/

#define a BIT0
#define b BIT1
#define c BIT2
#define d BIT3
#define e BIT4
#define f BIT5
#define g BIT6

/** Na hora que o pino for setado, deve-se negar ele*/
#define ZERO (a + b + c + d + e + f)
#define UM (b + c)
#define DOIS (a + b + g + e + d)
#define TRES (a + b + g + c + d)
#define QUATRO (f + g + b + c)
#define CINCO (a + f + g + c + d)
#define SEIS (a + f + g + e + d + c)
#define SETE (a + b + c)
#define OITO (a + b + c + d + e + f + g)
#define NOVE (a + b + c + d + f + g)


void ini_P1_P2();
void ini_uCon();


unsigned char i = 0; //Contador


void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    ini_P1_P2();
    ini_uCon();

    do{

    }while(1);

}

/**
 *  Função para inicialização das portas do Micro.
 */
void ini_P1_P2(){
    /*
     * Configurando P1:
     *
     * P1.0 - P1.6 --> Saidas --> 1.0 -> a ... 1.6 -> g
     * P2.0 e P2.1 --> Entradas do encoder (Entrada digital);
     *      P2.0 -> CLK
     *      P2.1 -> DT
     * */

     P1DIR = 0xFF; // Todo mundo saida
     P1OUT = ~ZERO;

     P2DIR = ~(BIT0 + BIT1);
     P2OUT = BIT0 + BIT1; //Resistor 1 e 2 de Pull Up
     P2REN = BIT0 + BIT1; //Ligando os Resistores de Pull-Up
     P2IES = BIT0; //Habilita interrupcao por borda de descida
     P2IE = BIT0; //Habilita a geracao de interrupcao

     _enable_interrupt();

}

/**
 * Funcao para inicializacao de clock no micro.
 */
void ini_uCon(void){
    /**
     * Clock Principal: 1MHz
     * Secundario: CP/8 ~ 125kHz
     * Auxiliar: LFXT1CLK --> Cristal --> 32768Hz
     */
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    BCSCTL2 = DIVS0 + DIVS1; //Dividindo por 8
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF); //Enquanto o cristal nao estiver sincronizado
}


#pragma vector = PORT2_VECTOR
__interrupt void RTI_P20(void){
    /**
     * Deve-se limpar a flag de interrupcao e desabilitar a interrupcao da porta
     *
     * BITS     7 6 5 4 3 2 1 0
     * P2IE     X X X X X X X Y
     * ~BIT0    1 1 1 1 1 1 1 0
     *          ---------------
     * P2IE     X X X X X X X 0 --> LIMPOU O BIT QUE QUERIA DESATIVAR
     */
    P2IFG &= ~BIT0; //Desabilita a flag de interrupcao
    P2IE &= ~BIT0; //Proibe da porta nao gerar interrupcao

    /*
     * Quando a interrupcao da porta 2 for acionada, entao o timer dara um
     * tempo para validar a borda.
     */
    TA0CTL = TASSEL0 + MC0; //Diz a fonte de clock e o modo de operacao, que eh o UP
    TA0CCTL0 = CCIE; //Faz interrupcao quando der a comparacao certa
    TA0CCR0 = 8; //Numero de contagens que deve fazer
}

/**
 * Interrupcao do debounced do micro.
 */
#pragma vector = TIMER0_A0_VECTOR
__interrupt void RTI_TIMER0_M0(void){

    while(!(P2IN & BIT0));

    if(P2IN & BIT1){
        if(i < 9)
            i++;
    }else{
        if(i > 0)
            i--;
    }

    /*Tratamento de interrupções, dizer que a cada tempo X o display vai mudar de valor. */
    switch(i){
        case 0:
            P1OUT = ~ZERO;
            break;
        case 1:
            P1OUT = ~UM;
            break;
        case 2:
            P1OUT = ~DOIS;
            break;
        case 3:
            P1OUT = ~TRES;
            break;
        case 4:
            P1OUT = ~QUATRO;
            break;
        case 5:
            P1OUT = ~CINCO;
            break;
        case 6:
            P1OUT = ~SEIS;
            break;
        case 7:
            P1OUT = ~SETE;
            break;
        case 8:
            P1OUT = ~OITO;
            break;
        case 9:
            P1OUT = ~NOVE;
            break;
    }

    //Habilita interrupcao da porta 2
    P2IFG &= ~BIT0;
    P2IE |= BIT0;
    TA0CCTL0 = 0;
}


