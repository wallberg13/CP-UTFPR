#include <msp430.h> 

/** Debounced Teclado*/

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
#define TRES (a + b + c + d + g)
#define QUATRO (f + g + b + c)
#define CINCO (a + f + g + c + d)
#define SEIS (a + f + g + e + d + c)
#define SETE (a + b + c)
#define OITO (a + b + c + d + e + f + g)
#define NOVE (a + b + c + d + f + g)
#define A (a + b + c + e + f + g)
#define B (c + d + e + f + g)
#define Ce (a + f + e + d)
#define D (b + c + d + e + g)


/**
 * Funções:
 * */
void ini_uCon(void);
void ini_P1_P2(void);
void ini_TA0(void);
void ini_TA1(void);
void tecla(void);


/**
 * Variavel que controla qual numero foi precionado.
 */
unsigned char i = 15; //Tecla precionada
unsigned char est = 0; //Sem piscar
unsigned char ligDes = 0; //Desligado

void main(void) {
	
    ini_P1_P2();
    ini_uCon();
    ini_TA0();
    ini_TA1();

    do{

    }while(1);
}


//---------------------------------------------------------------------------------
//----------------------------Interrucoes do Micro---------------------------------
//---------------------------------------------------------------------------------
/*
 * Apenas ativa o contador no modo UP que vai fazer o debounced
 * e so e permitido uma tecla por vez, logo, quando uma
 * tecla for precionada, ninguem faz mais interrupcao e assume
 * limpa o vetor de interrupcao
 */
#pragma vector = PORT2_VECTOR
__interrupt void RTI_Porta_02(void){
    TA0CTL |= MC0; //Debounced
    P2IFG &= ~(BIT0 + BIT1 + BIT2 + BIT3);
    P2IE &= ~(BIT0 + BIT1 + BIT2 + BIT3);
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void RTI_TA1_M0(void){
    if(est == 1){
        tecla();
        est = 2;
    }else{
        P1OUT = 0xFF;
        est = 1;
    }
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void RTI_TA0_M0(void){
    TA0CTL &= ~MC0;

    if(P2IN & BIT0){ //1 2 3 A
        P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
        P2OUT |= BIT4;
        if(P2IN & BIT0){
            i = 1;
        }

        P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
        P2OUT |= BIT5;
        if(P2IN & BIT0){
            i = 2;
        }

        P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
        P2OUT |= BIT6;
        if(P2IN & BIT0){
            i = 3;
        }

        P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
        P2OUT |= BIT7;
        if(P2IN & BIT0){
            i = 10;
        }
    }else{
        if(P2IN & BIT1){ //4 5 6 B
            P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
            P2OUT |= BIT4;
            if(P2IN & BIT1){
                i = 4;
            }

            P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
            P2OUT |= BIT5;
            if(P2IN & BIT1){
                i = 5;
            }

            P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
            P2OUT |= BIT6;
            if(P2IN & BIT1){
                i = 6;
            }

            P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
            P2OUT |= BIT7;
            if(P2IN & BIT1){
                i = 11;
            }
        }else{
            if(P2IN & BIT2){ //7 8 9 C
                P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                P2OUT |= BIT4;
                if(P2IN & BIT2){
                    i = 7;
                }
                P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                P2OUT |= BIT5;
                if(P2IN & BIT2){
                    i = 8;
                }

                P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                P2OUT |= BIT6;
                if(P2IN & BIT2){
                    i = 9;
                }

                P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                P2OUT |= BIT7;
                if(P2IN & BIT2){
                    i = 12;
                }
            }else{
                if(P2IN & BIT3){ // * 0 # D
                    P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                    P2OUT |= BIT4;
                    if(P2IN & BIT3){
                        if(!ligDes){
                            ligDes = 1;
                            i = 0;
                        }else{
                            ligDes = 0;
                            i = 15;
                            tecla();
                            TA1CTL &= ~MC0;
                        }
                    }

                    P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                    P2OUT |= BIT5;
                    if(P2IN & BIT3){
                        i = 0;
                    }

                    P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                    P2OUT |= BIT6;
                    if(P2IN & BIT3){ //Blink
                        if(ligDes){
                            if(!est){
                                est = 1;
                                TA1CTL |= MC0;
                            }else{
                                est = 0;
                                TA1CTL &= ~MC0;
                            }
                        }
                    }
                    P2OUT &= ~(BIT4 + BIT5 + BIT6 + BIT7);
                    P2OUT |= BIT7;
                    if(P2IN & BIT3){
                        i = 13;
                    }
                }
            }
        }
    }

    if(ligDes)
        tecla();

    P2OUT |= BIT4 + BIT5 + BIT6 + BIT7;
    P2IFG = 0;
    P2IE = BIT0 + BIT1 + BIT2 + BIT3;
}


void tecla(void){
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
        case 10:
            P1OUT = ~A;
            break;
        case 11:
            P1OUT = ~B;
            break;
        case 12:
            P1OUT = ~Ce;
            break;
        case 13:
            P1OUT = ~D;
            break;
        default:
            P1OUT = 0xFF;
    }
}

//---------------------------------------------------------------------------------
//---------------------------Configuracoes do Micro--------------------------------
//---------------------------------------------------------------------------------
/**
 * Configuracoes de Clock
 *
 * Como as portas do cristal estao ocupadas, eh o jeito
 * usar o watdogtimer como temporizador para fazer o debounced.
 * */
void ini_P1_P2(void){
    /*
     * P1.0 -- P1.6 ==> Saidas Digitais
     * P2.0 -- P2.3 ==> Entradas Digitais
     *                  Ligar Registores de Pull-Down
     * P2.4 -- P2.7 ==> Saidas Digitais
     *                  Todas em nivel logico alto
     *                  Pino 2.6 e 2.7 -- Sao os pinos do cristal, configurar devidamente
     */
    P1DIR = 0xFF;
    tecla();

    P2DIR = ~(BIT0 + BIT1 + BIT2 + BIT3); //Entradas
    P2REN = BIT0 + BIT1 + BIT2 + BIT3; //Habilita os resistores de pull
    P2OUT = BIT4 + BIT5 + BIT6 + BIT7; //Pull-Down -- Saidas Digitais em 1 -- Configurado ja
    P2SEL &= ~(BIT6 + BIT7); //Funcao de P2.6 e P2.7
    P2IES = 0;
    P2IE = BIT0 + BIT1 + BIT2 + BIT3;
    P2IFG = 0;

    __enable_interrupt();
}

/**
 * Configurações de clock
 *
 * Principal: DCO --> 1MHz
 * Secundario: DC0/8 --> 125kHz
 * AUX: Secundario
 *
 * */
void ini_uCon(void){
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    /*
     * Clocks:
     * Principal: 1MHz
     * Secundario: 125kHz
     * Auxiliar de baixa frequencia: Nenhum
     */
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    BCSCTL2 = DIVS1 + DIVS0;
    BCSCTL3 = 0; //Nao uso clock auxiliar
}

/*
 * TimerA 0 para fazer o Debounced
 * Modo comparacao
 * Tempo de Debounced:
 *      tempo = 1ms
 *      VC = tempo*Freq_Clock - 1
 *      Valor de Contagem: 124
 * Fonte do Clock: Secundario
 * Inicialmente fica parado.
 *
 */
void ini_TA0(void){
    TA0CTL = TASSEL1; //Inicialmente Parado Sem o MC0.
    TA0CCTL0 = CCIE; //Modulo 0 -- Configura Pra poder gerar interrupcao
    TA0CCR0 = 12; //Numero de contagens
}

/*
 * TimerA 1 para fazer o blink do display
 * Modo comparacao
 * Fica piscando a cada 0.5s
 *      tempo = 0.5s
 *      VC = tempo*Freq_Clock - 1
 *      Valor de Contagem = 62500
 * Fonte do Clock: Secundario
 * Inicialmente fica parado.
 */
void ini_TA1(void){
    TA1CTL = TASSEL1;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 62500;
}
