#include <msp430.h> 

void ini_uCon();
void ini_P1_P2();
void ini_TimerA0(); //Meio segundo

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	return 0;
}

void ini_uCon(){

}
