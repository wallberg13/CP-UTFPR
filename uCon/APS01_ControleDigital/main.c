#include <msp430.h> 

#define freq 3600
#define clock 1000000
#define N (clock/freq + 1) // Numero de contagens

int DutyCicle,

void ini_P1_P2();
void conf_TimerA0();
void ini_uCon();

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	

}

//------- CONF PORTAS ---------------------------------------------

void ini_uCon(){

}

void ini_P1_P2(){

    P1DIR = 0xFF;
    P1SEL |= BIT2;

    P2DIR = 0xFF;
    P2OUT = 0;
}

void conf_TimerA0(){

}
