#include <msp430g2553.h>
#include "LCD.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

void conf_ini(void);
void p1_p2_ini(void);
void timer0_cronometro(void);
void timer1_debouncer(void);
//variaveis de tempo
unsigned int minutos=0, segundos=0, dec_segundos=0, cent_segundos=0, modo=0;
char string1[10], string2[10];


void main(void){

    WDTCTL = WDTPW + WDTHOLD;// Stop Watchdog
    conf_ini();
    p1_p2_ini();


    ini_lcd(lcd_display_8x5 | lcd_2_lines, lcd_display_on | lcd_cursor_on | lcd_cursor_blink);
    lcd_write_c('\f');



    do{
        lcd_text_position(1,0);
        sprintf(string1, "Modo: %d",modo);
        lcd_write_s(string1);
        lcd_text_position(1,1);
        sprintf(string2, "%d:%d.%d%d", minutos, segundos,dec_segundos,cent_segundos);
        lcd_write_s(string2);

    }
    while(1);
}
void conf_ini(void){
// Seta os Clocks
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = XCAP0 + XCAP1;
    while(BCSCTL3 & LFXT1OF);

    __enable_interrupt();
}

void p1_p2_ini(void){
    P1DIR = ~(BIT3);
    P1REN = BIT3;
    P1OUT = BIT3;
    P1IES = BIT3;
    P1IFG = 0;
    P1IE = BIT3;


    P2DIR = 0xFF;
    P2OUT = BIT6 + BIT7; //com nivel 0
}

void timer0_cronometro(void){
/*inicia o timer A0
 * modulo0 -> Gera uma interrupção a cada 10ms e altera a entrada da captura
 * modulo1 -> Cronometro propriamente dito, incrementa a variavel cent_segundos
 */
    TA0R = 0;
    TA0CTL = TASSEL0 + MC0; //ACLK + Modo UP
    TA0CCTL0 = CCIE; //habilita interrupção por comparação
    TA0CCR0 = 327;//tempo=327/32768 = 10ms

    TA0CCTL1 = CM0 +CM1 + CCIS1 + CAP + CCIE; //captura por ambas as bordas + catura + interrupção por captura

}
void timer1_debouncer(void){
    //debouncer marotão
    TA1R = 0;
    TA1CTL = TASSEL0 + MC0; //AUXILIAR + UP
    TA1CCTL0 = CCIE; //INTERRUPÇÃO POR COMPARAÇÃO
    TA1CCR0 = 130; //tempo de debouncer de 4ms => TA0CCTR0 = 4e-3+32768-1
}

#pragma vector=PORT1_VECTOR
__interrupt void P1_RTI(void){
    //DESATIVA INTERRUPÇÃO, LIMPA FLAG, DISPARA DEBOUNCER
    P1IE &= ~BIT3;
    P1IFG = 0;
    timer1_debouncer();

}

#pragma vector=TIMER0_A0_VECTOR//comparação modulo 0
__interrupt void Contador_10ms_RTI(void){
    TA0CCTL1 ^= CCIS0; //muda a borda do modulo 1
}


#pragma vector=TIMER0_A1_VECTOR //modo captura do modulo 1
__interrupt void Cronometro_RTI(void){
    TA0CCTL1 &= ~(CCIFG); //limpa a flag
    cent_segundos++;
    if(cent_segundos>9){
        cent_segundos=0;
        dec_segundos++;
        if(dec_segundos>9){
            dec_segundos=0;
            segundos++;
            if(segundos>59){
                segundos=0;
                minutos++;
            }
            else if(minutos>59){
                minutos=0;
            }
        }
    }
}

#pragma vector=TIMER1_A0_VECTOR  //debouncer
__interrupt void Debouncer_RTI(void){
    //desliga o contador
    // altera o modo que vai funcionar o timer,
    //modo = 0; inicia
    //modo = 1; para e mostra o valor
    //modo = 2; reseta

    TA1CTL = TACLR;//limpa TAE
    TA1CCR0 = 0; //para o contador
    if(~(P1IN)& BIT3){//comprara se o pino está em nivel baixo
        if(modo==0){
            //começa contar
            timer0_cronometro();
            modo ++;


        }
        else if(modo==1){
            //pausa e exibe o valor
            TA0CTL &= ~MC0; //para o TAE
            TA0R=0;
            TA0CCTL1 &= ~CCIS0; //muda a borda
            modo ++;

        }
        else if(modo==2){
            //limpa as variaveis do tempo
            minutos = 0;
            segundos = 0;
            dec_segundos = 0;
            cent_segundos = 0;

            modo = 0;


        }
    }
    //REATIVA INTERRUPÇÃO DA PORTA 1

    P1IE |= BIT3;
    P1IFG = 0;

}


