#include <msp430.h> 


void uCon(void);
void ini_P1_P2(void);
void ini_TimerA1(void);
void ini_TimerA0_PWM(void);

#define resol_freq 50
#define resol_duty_cicle 0.05
#define clock 1000000.0
/*
 * Variaveis Globais
 *
 * Est: Variavel estado, onde para 0 o encoder regula a frequencia do PWM
 *      e para 1 regula do Duty Cicle
 * freq: Frequencia Atual
 * degrau: Quanto deve aumentar no TA0CCR1 para aumentar 5% do duty_cicle;
 */
unsigned char est = 0;
unsigned int freq = 3200, degrau; //Deve-se pegar o calculo da frequencia minima. -- 100Hz, Degrau de quanto deve ser aumentado
float duty_cicle = 0.5, aux;

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    uCon();
    ini_P1_P2();
    ini_TimerA1();
    ini_TimerA0_PWM();

    do{

    }while(1);

}

/*
 * Aqui só ativa o timer, limpa as flags e desativa interrupções
 */
#pragma vector=PORT1_VECTOR;
__interrupt void RTI_P1(void){
    P1IFG = 0;
    P1IE &= ~(BIT0 + BIT3);
    TA1CTL |= MC0;
}

#pragma vector=TIMER1_A0_VECTOR;
__interrupt void RTI_Timer01_Mod0(void){

    TA1CTL &= ~MC0;

    if((~P1IN) & BIT0){ //Encoder

        while(!(P1IN & BIT0));

        if(P1IN & BIT1){ //Sentido Horario
            if(est){
                if(duty_cicle + resol_duty_cicle <= 0.99){
                    duty_cicle += resol_duty_cicle;
                    TA0CCR1 += degrau;
                }
            }else{
                if(freq + resol_freq <= 1000){
                    freq += resol_freq;
                    aux = (1.0/(float)freq)*clock;
                    TA0CCR0 = (unsigned long)aux;
                    aux = duty_cicle*(float)TA0CCR0;
                    TA0CCR1 = (unsigned long)aux;
                    degrau = (unsigned int)(resol_duty_cicle*(float)TA0CCR0);
                }
            }
        }else{ //Sentido antihorario
            if(est){
                if(duty_cicle - 0.05 >= 0){
                    duty_cicle -= resol_duty_cicle;
                    TA0CCR1 -= degrau;
                }
            }else{
                if(freq - resol_freq >= 100){
                    freq -= resol_freq;
                    aux = (1.0/(float)freq)*clock;
                    TA0CCR0 = (unsigned long)aux;
                    aux = duty_cicle*(float)TA0CCR0;
                    TA0CCR1 = (unsigned long)aux;
                    degrau = (unsigned int)(resol_duty_cicle*(float)TA0CCR0);
                }
            }
        }
    }else{
        if((~P1IN) & BIT3){ //Chave S02
            if(!est)
                est = 1;
            else
                est = 0;
        }
    }

    P1IFG = 0;
    P1IE = BIT0 + BIT3;
}

/*
 *  Clock Principal: ~8MHz
 *  Clock Secundario: ~1MHz
 *  Clock Auxiliar: Cristal 32...
 */
void uCon(void){
    DCOCTL = CALDCO_8MHZ;
    BCSCTL1 = CALBC1_8MHZ;
    BCSCTL2 = DIVS1 + DIVS0;
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF);
}

/*
 * Chave S02 para fazer o debounced: P1.3 : Entrada digital - pull-up
 * P1.0 e P1.1 - entrada digital com resistor de pull-up
 * P1.2 - Saida PWM, saida timer
 * Timer A1 - Debounced do Botão e Encoder
 * Timer A2 - PWM
 */
void ini_P1_P2(void){
    P1DIR = ~(BIT0 + BIT1 + BIT3);
    P1OUT = BIT0 + BIT1 + BIT3; //Resistores de Pull-Up
    P1REN = BIT0 + BIT1 + BIT3;
    P1IES = BIT0 + BIT3; //Borda de descida nos pinos P1.3 e P1.0;
    P1IE = BIT0 + BIT3;
    P1SEL |= BIT2;

    P2DIR = 0xFF;
    P2OUT = 0;
    __enable_interrupt();
}

/*
 * Timer 1 que irá fazer o debounced
 */
void ini_TimerA1(void){
    TA1CTL = TASSEL1; //Para iniciar a contagem para cima ==> MC0;
    TA1CCTL0 = CCIE; //Habilita interrupção
    TA1CCR0 = 300;
}


/**
 * Frequencia inicial do timer é de 100Hz, e dutycicle de 50%
 * */
void ini_TimerA0_PWM(void){
    TA0CTL = TASSEL1 + MC0;
    TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;

    aux = (1.0/freq)*clock - 1.0;
    TA0CCR0 = (unsigned long)aux;
    aux = duty_cicle*(float)TA0CCR0;
    TA0CCR1 = (unsigned long)aux;
    aux = resol_duty_cicle*TA0CCR0;
    degrau = (unsigned int)aux;
}
