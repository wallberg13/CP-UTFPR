#include <msp430.h> 

#define clock 8000000.0
#define freq_sen 50
#define pont 64

float vet[64];
float amp = 0.5;
float aux;
unsigned char cont = 0;


void ini_TimerA1_Deb(void);
void ini_TimerA0_PWM(void);
void ini_vet(void);
void uCon(void);
void ini_P1_P2(void);

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uCon();
	ini_P1_P2();
	ini_vet();
	ini_TimerA0_PWM();
    ini_TimerA1_Deb();
	
    while(1){

    }
}

#pragma vector=PORT1_VECTOR
__interrupt void RTI_P1(){
    P1IFG = 0;
    P1IE &= ~(BIT0);
    TA1CTL |= MC0;
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_TimerA1_Deb(){
    TA1CTL &= ~(MC0);

    while(!(P1IN & BIT0));

    if(P1IN & BIT1){ //Horario
        if(amp < 0.5){
            amp += 0.05;
        }
    }else{ //Anti
        if(amp > 0)
            amp -= 0.05;
    }

    P1IE |= BIT0;
    P1IFG = 0;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void RTI_TimerA0_PWM(){
    aux = 0.5 + amp*vet[cont];
    aux = (float)TA0CCR0*aux;
    TA0CCR1 = (unsigned long)aux;
    cont++;
    if(cont == 62)
        cont = 0;
}

void ini_TimerA0_PWM(void){
    TA0CTL = TASSEL1 + MC0;
    TA0CCTL0 = CCIE;
    TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;
    aux = (1.0/(freq_sen*pont))*clock - 1.0;
    TA0CCR0 = (unsigned long)aux;
    aux = 0.5*(float)TA0CCR0;
    TA0CCR1 = (unsigned long)aux;
}


void ini_TimerA1_Deb(void){
    TA1CTL = TASSEL1; //MC0 para ativar o timer
    TA1CCTL0 = CCIE;
    TA1CCR0 = 400;
}

/*
 * Clock Principal: 8MHz
 * Clock Secundario: 2Mhz
 * Clock Auxiliar: Cristal
 */
void uCon(void){
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0;
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF);
    __enable_interrupt();
}


void ini_P1_P2(void){
    /**
     * P1.0 E P1.1: Entrada digital com resistores de Pull-Up
     * P1.2: Saida digital do PWM
     */
    P1DIR = ~(BIT0 + BIT1); //Bit 0 e 1 como entrada
    P1OUT = BIT0 + BIT1; //Pull-Up para o bit 0 e 1
    P1REN = BIT0 + BIT1; //Liga os Resistores
    P1IE = BIT0; //Habilita Interrupção
    P1IES = BIT0; // Borda de descida
    P1SEL |= BIT2; //Coloca o bit2 para ser a saida do modulo1 do timerA0
    P1IFG = 0;
    //Para a porta 2 -- Nada para ser usado
    P2DIR = 0xFF;
    P2OUT = 0;
}

void ini_vet(void){
    vet[0] = 0.000000;
    vet[1] = 0.098017;
    vet[2] = 0.195090;
    vet[3] = 0.290285;
    vet[4] = 0.382683;
    vet[5] = 0.471397;
    vet[6] = 0.555570;
    vet[7] = 0.634393;
    vet[8] = 0.707107;
    vet[9] = 0.773010;
    vet[10] = 0.831470;
    vet[11] = 0.881921;
    vet[12] = 0.923880;
    vet[13] = 0.956940;
    vet[14] = 0.980785;
    vet[15] = 0.995185;
    vet[16] = 1.000000;
    vet[17] = 0.995185;
    vet[18] = 0.980785;
    vet[19] = 0.956940;
    vet[20] = 0.923880;
    vet[21] = 0.881921;
    vet[22] = 0.831470;
    vet[23] = 0.773010;
    vet[24] = 0.707107;
    vet[25] = 0.634393;
    vet[26] = 0.555570;
    vet[27] = 0.471397;
    vet[28] = 0.382683;
    vet[29] = 0.290285;
    vet[30] = 0.195090;
    vet[31] = 0.098017;
    vet[32] = 0.000000;
    vet[33] = -0.098017;
    vet[34] = -0.195090;
    vet[35] = -0.290285;
    vet[36] = -0.382683;
    vet[37] = -0.471397;
    vet[38] = -0.555570;
    vet[39] = -0.634393;
    vet[40] = -0.707107;
    vet[41] = -0.773010;
    vet[42] = -0.831470;
    vet[43] = -0.881921;
    vet[44] = -0.923880;
    vet[45] = -0.956940;
    vet[46] = -0.980785;
    vet[47] = -0.995185;
    vet[48] = -1.000000;
    vet[49] = -0.995185;
    vet[50] = -0.980785;
    vet[51] = -0.956940;
    vet[52] = -0.923880;
    vet[53] = -0.881921;
    vet[54] = -0.831470;
    vet[55] = -0.773010;
    vet[56] = -0.707107;
    vet[57] = -0.634393;
    vet[58] = -0.555570;
    vet[59] = -0.471397;
    vet[60] = -0.382683;
    vet[61] = -0.290285;
    vet[62] = -0.195090;
    vet[63] = -0.098017;
}
