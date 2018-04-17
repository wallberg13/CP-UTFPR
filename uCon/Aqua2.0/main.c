#include <msp430.h> 
#include "LCD.h"

#define tam_rx 16
#define tam_tx 32

void GPIO_config(void);
void BCS_config(void);
void TIMER0_config(void);
void TIMER1_config(void);
void UART_config(void);

void Configura_Debouncer(void);
void Configura_ModoCaptura(void);

void ini_display(void);
void to_string_f1(double d);
void to_string_f2(double d);
void to_string_int(char x);
void monta_String_TX();
void trata_RX();

char DD=0, HH=0, MM=0, SS=0;
unsigned int Stt_R = 0;
// 0 -> Primeira Leitura será realizada
        //reset em TA1
// 1 -> Leitura em curso:
        //1) Ler valor de TA1CCR0 (TA1R)
unsigned long num_pulsos = 0;
unsigned long contador_ciclos = 0;
double fluxo = 0, fluxo_med=0, fluxo_max=0, VOL_T=0;

static const int a=10257, b=-11741; //a e b são parâmetros da função:  fluxo = a*freq + b
static const unsigned int div_ab = 60000;

char TX_DATA[tam_tx], RX_DATA[tam_rx];
unsigned char tx_index = 0, rx_index=0;
char buffer[5];
unsigned long tempo_seg = 0;

int k = 0;
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    GPIO_config();
    BCS_config();
    TIMER0_config();
    TIMER1_config();
    UART_config();

    ini_LCD();
    ini_display();

    //OSC fault flag - Espera estabilizar
    do
    {
        IFG1 &= ~OFIFG; //OSC fault flag
        __delay_cycles(50); //50us
    } while (IFG1 & OFIFG); //OSCFault flag ainda setado?

    //__bis_SR_register(GIE); //__enable_interrupt();

    while(1)
    {
        //economia de energia
        /* Entering low power mode 3 */
        __bis_SR_register(LPM3_bits | GIE);
    }
    //return 0;
}

//**********************Funções de Inicialização
void GPIO_config(void)
{
    //P1 - P1.3 é entrada do debouncer (S2) <3
    P1DIR = ~BIT3; // bit 3 entrada do deboucer
    P1REN = BIT3;   //RESISTOR DE
    P1OUT = BIT3;       //PULL-UP
    P1IES = BIT3;
    P1IFG = 0;
    P1IE = BIT3;

    //P2 - Entrada no Bit 2
    P2OUT = 0;
    P2SEL = BIT2 | BIT6 | BIT7;
    P2DIR = BIT0 | BIT1 | BIT3 | BIT4 | BIT5;
    //bit 6 e 7 é xin e xout
    //bit 2 é entrada (TA1.CCI1B)
    P2REN = 0; //resistor enable
    P2IES = 0; //interrupt edge
    P2IFG = 0; //interrupt flag
    P2IE = 0; //interrupt enable
}

void BCS_config(void)
{//                                 ***DIVS_0 ou DIVS_1 ????
    BCSCTL2 = SELM_0 | DIVM_0 | DIVS_1; //DIVS_0 para /1       DIVS_1 para /2       em SMCLK (Secundario)
    //divs_1: divisão por 2 no clock secundário!!  ------> 8MHz
    if (CALBC1_16MHZ != 0xFF) {

        __delay_cycles(100000);
        /* Follow recommended flow. First, clear all DCOx and MODx bits. Then
         * apply new RSELx values. Finally, apply new DCOx and MODx bit values.
         */
        DCOCTL = 0x00;
        BCSCTL1 = CALBC1_16MHZ;     /* Set DCO to 16MHz */
        DCOCTL = CALDCO_16MHZ;
    }

    /*
    * Basic Clock System Control 1
    *
    * XT2OFF -- Disable XT2CLK
    * ~XTS -- Low Frequency
    * DIVA_0 -- Divide by 1
    *
    * Note: ~XTS indicates that XTS has value zero
    */
    BCSCTL1 |= XT2OFF | DIVA_0;

    /*
    * Basic Clock System Control 3
    *
    * XT2S_0 -- 0.4 - 1 MHz
    * LFXT1S_0 -- If XTS = 0, XT1 = 32768kHz Crystal ; If XTS = 1, XT1 = 0.4 - 1-MHz crystal or resonator
    * XCAP_1 -- ~6 pF
    */
    BCSCTL3 = XT2S_0 | LFXT1S_0 | XCAP_3;
    //                              ^12.5 pF
    /* USER CODE START (section: BCSplus_graceInit_epilogue) */
    /* User code */
    /* USER CODE END (section: BCSplus_graceInit_epilogue) */
}

void TIMER0_config(void)
{
    TA0CCTL0 = CM_2 | CCIS_0 | OUTMOD_0 | CCIE;
    TA0CCTL1 = CM_0 | CCIS_2 | OUTMOD_0;
    TA0CCTL2 = CM_0 | CCIS_2 | OUTMOD_0;
    TA0CCR0 = 32767; //Interrupções de 1 em 1 segundo
    TA0CTL = TASSEL_1 | ID_0 | MC_1;
}//                             ^ Modo up (até TACCR0)

void TIMER1_config(void)
{
    //TA1 no modo Contínuo
    //TA1CCTL1 no modo comparação
    TA1CTL = TASSEL_1 | ID_0 | MC_2; //inicia contagem modo contínuo

    /* CONFIGURAÇÃO PARA MODO CAPTURA EM TACCR1*/
    TA1CCTL1 = CM_2 | CCIS_1 | SCS | CAP | OUTMOD_0;
                                            //      ^ não habilito CCIE ainda
    //isso será feito na RTI do Timer A0

    /* CONFIGURAÇÃO PARA DEBOUNCER: TACCR2 GERA INTERRUPÇÃO*/
    TA1CCTL2 = CM_0 | CCIS_0 | OUTMOD_0;
    //                                      ^não habilito CCIE ainda
    // isso será feito na RTI da porta P1.3
    TA1CCR2 = 3276; // alguns ciclos de clock, usando clock auxiliar (32768 Hz)
}

void Configura_Debouncer(void)
{
    //Desabilitar interrupção em TACCTL1
    TA1CCTL1 &= ~CCIE;

    //Descartar amostragem atual
            // -> Como?
            // -> Zerar Stt_R, num_pulsos, contador_ciclos

    Stt_R = 0;
    num_pulsos = 0;
    contador_ciclos = 0;

    //Zerar Contador
    TA1CTL &= ~(MC1 + MC0);
    TA1R = 0; //zera contador
    TA1CTL |= MC_2; //inicia contagem modo contínuo

    //Habilitar interrupção em TACCTL2
    TA1CCTL2 |= CCIE;

    //Garantir que Interrupção da porta 1 está habilitada!!!!
    P1IE |= BIT3;
}

void Configura_ModoCaptura(void)
{
    //Desabilitar interrupção em TACCTL2
    TA1CCTL2 &= ~CCIE;

    //Habilitar interrupção em TACCTL1
    TA1CCTL1 |= CCIE;
}

/**
 * Configuracao da UART
 * */
void UART_config(void){

    /**
     * CONFIGURAÇÃO COM BASE COM O QUE FOI VISTO EM AULA
     *
     * O USCWRST no registrador de controle 1 deve
     * está setado para que seja possivel fazer as demais
     * configuracoes da UART
     *
     * UCSSEL1 - Selecao da fonte de Clock para 8MHz e um
     * fator de divisao de 833 ==> 0x0341;
     *
     * Separando isso nos UCBR0 e 1 (Cada registrador de 8 bits)
     * ficaria: UCBR0 = 0x41 e UCBR1 = 0x03;
     *
     * Não tem sobreamostragem
     *
     * UCA0MCTL = UCBRS1; //
     *
     * UCA0CTL0 - Igual a zero. (Não sei pq)
     *
     **/
    UCA0CTL1 = UCSSEL1 + UCSWRST;

    UCA0CTL0 = 0;

    UCA0BR0 = 0x41;
    UCA0BR1 = 0x03;

    UCA0MCTL = UCBRS1;

    // Configuracao da Porta P1.1 e P1.2 para saída e entrada da UART
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;

    //Com todas as configurações feita, nao é mais preciso o bit de reset em CTL1
    UCA0CTL1 &= ~UCSWRST;

    /*
     * Interrupcao por transmissao e recepcao habilitados.
     * */
    //IFG2.UCA0TXIFG == 0 ?? isso ta correto?
    IFG2 &= ~UCA0TXIFG; //sim.. transmissão ocorre na RTI do TA0

    IE2 |= UCA0TXIE + UCA0RXIE; //Só pra testar a transmissao
}


//----------------------------------------------------------------------------------------
//------------------------------FUNCOES NECESSARIAS---------------------------------------
//----------------------------------------------------------------------------------------
/**
 * Função de escrita no display,
 * qualquer atualização que seja feito nas variaveis, essa
 * função é chamada.
 * */
void ini_display(void){
    set_position(0,1);
    write_string("D");
    to_string_int(DD);
    write_string(buffer);

    set_position(0,5);
    write_string("h");
    to_string_int(HH);
    write_string(buffer);

    set_position(0,9);
    write_string("m");
    to_string_int(MM);
    write_string(buffer);

    set_position(0,13);
    write_string("s");
    to_string_int(SS);
    write_string(buffer);

    set_position(1,1);
    write_string("V");
    to_string_f2(VOL_T);
    write_string(buffer);

    set_position(1,6);
    write_string("Fm");
    to_string_f1(fluxo_med);
    write_string(buffer);

    set_position(1,12);
    write_string("FM");
    to_string_f1(fluxo_max);
    write_string(buffer);
}



/*
 * Como sao floats de precisao 1, multiplica por 10 para pegar
 * as partes importantes, e joga esse valor no buffer
 *
 * Lembrando que so esta sendo pego um casa depois da virgula de precisao do float,
 * ele e multiplicado por 10, e retirado somente a parte inteira do numero (este
 * numero tem precisao de 1.1), fazendo calculo de retirada da parte de dezena e unidade.
 *
 * Em seguida, este numero retirado é somado com o caractere '0' que na tabela ASCII representa
 * o numero 48, como cada numero e pego em uma faixa de 0 a 9, entao nao tem perigo de
 * sair um caractere errado.
 * */
void to_string_f1(double d){

    unsigned char i;
/*
    if(d<10)
    {
*/
        i = (unsigned char)(d*10);
        buffer[0] = (unsigned char)((i/10)%10);
        buffer[2] = i%10;
        buffer[3] = '\0';

        buffer[0] += '0';
        buffer[1] = '.';
        buffer[2] += '0';
/*
    }
    else
    {
        buffer[0] += '-';
        buffer[1] = '.';
        buffer[2] += '-';
    }
*/
}


/**
 * O mesmo da anterior, porem esta funcao captura
 * 1 caractere a mais a esquerda para o volume total de agua.
 * */
void to_string_f2(double d){

    unsigned char i;
    i = (unsigned char)(d*10);
    buffer[0] = (unsigned char)(i/100);
    buffer[1] = (unsigned char)((i - 100*buffer[0])/10);
    buffer[2] = '.';
    buffer[3] = i - buffer[0]*100 - buffer[1]*10;

    buffer[4] = '\0';

    buffer[0] += '0';
    buffer[1] += '0';
    buffer[3] += '0';
}

/**
 * A mesma das anteriores, com a diferenca que e um numero inteiro agr.
 *  */
void to_string_int(char x){
    buffer[0] = (unsigned char)(x/10);
    buffer[1] = x%10;
    buffer[2] = '\0';

    buffer[0] += '0';
    buffer[1] += '0';
}

/**
 * Montagem da String para transmissão, formatada meio que na
 * gambiarra.
 * */
void monta_String_TX(){
    TX_DATA[0] = 'V';
    TX_DATA[1] = 'o';
    TX_DATA[2] = 'l';
    TX_DATA[3] = ' ';
    TX_DATA[4] = 'T';
    TX_DATA[5] = 'o';
    TX_DATA[6] = 't';
    TX_DATA[7] = 'a';
    TX_DATA[8] = 'l';
    TX_DATA[9] = ':';
    to_string_f2(VOL_T);
    TX_DATA[10] = ' ';
    TX_DATA[11] = buffer[0];
    TX_DATA[12] = buffer[1];
    TX_DATA[13] = buffer[2];
    TX_DATA[14] = buffer[3];
    TX_DATA[15] = ' ';
    TX_DATA[16] = 'F';
    TX_DATA[17] = 'l';
    TX_DATA[18] = 'u';
    TX_DATA[19] = 'x';
    TX_DATA[20] = 'o';
    TX_DATA[21] = ' ';
    TX_DATA[22] = 'I';
    TX_DATA[23] = 'n';
    TX_DATA[24] = 's';
    TX_DATA[25] = 't';
    TX_DATA[26] = ':';
    TX_DATA[27] = ' ';
    to_string_f1(fluxo);
    TX_DATA[28] = buffer[0];
    TX_DATA[29] = buffer[1];
    TX_DATA[30] = buffer[2];
    TX_DATA[31] = '\n';
}

/**
 * Parte que ira tratar os dados vindo da serial.
 *
 * O texto deve já entrar aqui no formato que será descrito a
 * seguir, caso não vier nesse formato, o codigo pode apresentar problemas
 * que não foram tratados.
 *
 * O objetivo é de receber um texto formatado e alterar os valores das variaveis.
 *
 * Não é possivel mudar um de cada vez, é preciso alterar tudo no modo
 * que está descrito.
 *
 * Para Mudar o Dia, Hora, Minuto e Segundo, o texto
 * que tem que vim pela serial é o seguinda:
 *
 * Dois algorismos para Dia, dois para hora,
 * dois para minutos e dois para segundos e no final,
 * para fazer a validação da recepção, um '.' no final.
 * DD/HH/MM/SS.
 *
 * Sera tratado meio que na gambiarra, assim, limitando o algoritmo
 * */
void trata_RX(){
    unsigned char i = 0, j = 0, k = 0;

    /*
     * É sempre pego a primeira posição do vetor de RX_DATA para
     * ser trabalhado, pq assim, ao ler aquele char, ele já é limpo
     * ao colocar '\0' naquele local.
     *
     * Segue o esquema para saber qual variavel deve ser alterada.
     * i = 0 >>> Muda o Dia
     * i = 1 >>> Muda a hora
     * i = 2 >>> Muda os minutos
     * i = 3 >>> Muda os Segundos
     *
     *
     * */
    for(j = 0, i = 0, k = 0; RX_DATA[k] != '.'; k++){
        /*
         * Quando o RX_DATA[k] for igual a \, então j volta a ser zero e o i é incrementado,
         * isso quer dizer que uma variavel acabou de ser lida e que está pronto para ler a
         * proxima.
         * */
        if(RX_DATA[k] == 47){
            j = 0;
            i++;
        }else{
            /*
             * Switch case para saber qual variavel foi utilizada.
             * Quando J é 0, significa que ele capturou a parte mais significativa do numero.
             * É ideal que o char que está vindo seja realmente numero, e não letras, para
             * que não dê um bug no algoritmo.
             *
             * Com o j = 0, ele pega a dezena do numero, então o valor do char
             * é subtraido de '0' que representa 48 em decimal pois assim a variavel fica com o
             * numero da parte inteira. Essa logica é baseada na tabela ASCII.
             * */
            switch(i){
                case 0:
                    if(!j) //Dezena
                        DD = 10*(RX_DATA[k] - '0');
                    else
                        DD += RX_DATA[k] - '0';
                    break;
                case 1:
                    if(!j) //Dezena
                        HH = 10*(RX_DATA[k] - '0');
                    else
                        HH += RX_DATA[k] - '0';
                    break;
                case 2:
                    if(!j) //Dezena
                        MM = 10*(RX_DATA[k] - '0');
                    else
                        MM += RX_DATA[k] - '0';
                    break;
                case 3:
                    if(!j) //Dezena
                        SS = 10*(RX_DATA[k] - '0');
                    else
                        SS += RX_DATA[k] - '0';
                    break;
            }
            j++;
        }
        RX_DATA[k] = '\0';
    }
    ini_display(); // Isso é para que apareça os valores alterados instantaneamente.
    /**
     * As escritas em display estão sendo feitas dentro das interrupções pois
     * a CPU vai ficar funcionando quando for detectado uma interrupção.
     * */
}











//*****************************************************************
//**                       Interrupções                          **
//*****************************************************************
/**
 * Interrupcao classica do debounced, lembrando que como
 * está sendo usado o mesmo timer, tanto para fazer debounced como
 * para fazer as amostras, quando a chave S2 é precionada
 * a configuração do timer é mudada para o debounced, e uma flag é ativada
 * para que na RTI do timer possa ser indentificado quem gerou a interrupcao,
 * se foi a chave o as amostras.
 * */
#pragma vector=PORT1_VECTOR
__interrupt void RTI_P1(){
    P1IE &= ~BIT3;
    P1IFG &= ~BIT3;
    //flag = 1; não precisamos mais disso
    Configura_Debouncer();
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR_HOOK(void)
{
    /*
     *  -> Desabilitar CCIE em TA1CCTL1
     *
     *      Se(contador_ciclos !=0)
     *          -> Calcular Fluxo:
     *          -> Zerar Stt_R e contador_ciclos
     *          Como?
     *          -> Calcular com base na variável num_pulsos e
     *          -> valor de contador_ciclos
     *      Senao:
     *          ->Fluxo é 0;
     *
     *  -> Habilitar CCIE em TA1CCTL1
     */

    TA1CCTL1 &= ~CCIE; //Desabilita interrupção em TA1CCTL1
    if(contador_ciclos != 0)
    {//Calculos:
        fluxo = (a*(num_pulsos*32768/contador_ciclos) + b)/div_ab;
        //          |------------^Esse termo é a frequência do sinal
        //      ^ 'a' e 'b' são parâmetros da equação:  fluxo = a*freq + b
        //Obtidos por meio de regressão por mínimos quadrados, usando dados
        //do datasheet.

        //LITRO POR SEGUNDO: div_ab: 60000 *****************************TA ASSIM!!!
        //LITRO POR MINUTO: div_ab: 10000

        VOL_T += (fluxo*tempo_seg);

        //VOL_T = VOL_T_X60/60;
        //              |_______________|^tempo em minutos

        if(fluxo > fluxo_max)
        {
            fluxo_max = fluxo;
        }
    }
    else //==0
    {
        fluxo = 0;
    }

    //fluxo_med
    fluxo_med = VOL_T/(tempo_seg+1); //+1 por que essa variável só é incrementada no final da rti!!!

    //Retorna ao estado 0: (Aguardar primeiro pulso)
    Stt_R = 0;
    contador_ciclos = 0;

    /*
     * Contar Tempo:
     * SS -> Segundos
     * MM -> Minutos
     * HH -> Hora
     */
    SS++;
    if(SS == 60)
    {
        SS=0;
        MM++;

        if(MM == 60)
        {
            MM=0;
            HH++;
            if(HH == 24)
            {
                HH = 0;
                DD++;
                if(DD == 9)
                {
                    DD = 0;
                }
            }
        }
    }
    tempo_seg++; //variável que guarda o tempo em segundo (x60 pois queremos valor em minuto - devemos dividir a posteriori)

    //escreve display
    ini_display();

    //transmissão
    monta_String_TX();
    IFG2 |= UCA0TXIFG;

    //Habilita captura (interrupção em TA1CCTL1):
    Configura_ModoCaptura();
}

#pragma vector=TIMER1_A1_VECTOR
__interrupt void TIMER1_A1_ISR_HOOK(void)
{
    /*
     * Ideia: a cada 1 segundo, teremos n pulsos
     * Aqui, contaremos esses pulsos
     *
     * Na primeira interrupção após interrupção do TA0:
     *      -> Iniciamos ou resetamos o TA1
     *      Isso garante que TA1R inicie em 0 no início de
     *      uma leitura.
     *      -> zerar num_pulsos
     *
     * Em todas as próximas interrupções:
     *      -> Ler valor de TA1R (TA1CCR0 - modo captura)
     *      -> incrementar num_pulsos
     */

    switch(__even_in_range(TA1IV, 10))
    {
        case TA1IV_TACCR1: // É aqui a interrupção.. partiu
            if(Stt_R == 1) // Leitura em curso
            {
                //contador_ciclos = TA1CCR0;
                contador_ciclos = TA1R;
                num_pulsos++;
            }
            else //Primeira Leitura ocorrendo
            {
                // Reset TA1
                TA1CTL &= ~(MC1 + MC0);
                TA1R = 0; //zera contador
                TA1CTL |= MC_2; //inicia contagem modo contínuo

                num_pulsos = 0;

                Stt_R = 1;
            }
            break;
        case TA1IV_TACCR2: // Interrupção do Debouncer não é aqui
            //Desabilitar interrupção em TA1CCTL2
            // Atenção: Habilitar interrupção em TA1CCTL1 somente na RTI do Timer A0!!!!!!!
            TA1CCTL2 &= ~CCIE;
            //                                    ____          ________          _______
            if((~P1IN) & BIT3){ //se zerado  deboucer |________|        |________|       |
                fluxo_max = 0.0;  //                                    ^db ^>verifica em nível baixo
                fluxo_med = 0.0;
                VOL_T = 0;
                tempo_seg = 0;
            }
            break;
        case TA1IV_TAIFG: //Overflow (nunca vai dar)
            //no_operation();
            break;
    }
}

/**
 * RTI padrao de Transmissao.
 *
 * Trasmite o que tiver dentro do vetor TX_DATA,
 * enquanto ele nao for totalmente transmitido,
 * vai continuar tendo interrupcao de trasmissao,
 * e essa flag só é limpa depois que ele acha o
 * final da string.
 *
 * QUANDO ELE TERMINAR DE TRANSMITIR OS DADOS, COLOCAR A CPU PRA DORMIR E
 * ACORDAR SOMENTE COM INTERRUPCAO
 * */
#pragma vector=USCIAB0TX_VECTOR
__interrupt void RTI_UART_TX(){

    if(TX_DATA[tx_index] == '\0'){
        tx_index = 0;
        IFG2 &= ~UCA0TXIFG;
    }else{
        UCA0TXBUF = TX_DATA[tx_index];
        tx_index++;
    }
}

/**
 *  Enquanto não for encontrado o '.' na string, ele não para de
 *  receber caractere.
 *  Aqui está a limitação do codigo, pois não faz validação devido as posições.
 *  E ele só faz alguma coisa caso tiver o ponto final.
 * */
#pragma vector=USCIAB0RX_VECTOR
__interrupt void RTI_UART_RX(){
    RX_DATA[rx_index] = UCA0RXBUF;

    if(RX_DATA[rx_index] == '.'){
        trata_RX();
        rx_index = 0;
    }else{
        rx_index++;
    }
}

/*
#pragma vector=TIMER0_A1_VECTOR
__interrupt void teste1(void)
{
    //Desabilitar interrupção em TACCTL2
    if(TA0IV)
    {
        k=10;
    }
    if(TA1IV)
    {
        k=11;
    }
    TA1CCTL2 &= ~CCIE;
    //Habilita interrupção somente na RTI do Timer A0
}
#pragma vector=TIMER1_A0_VECTOR
__interrupt void teste2(void)
{
    //Desabilitar interrupção em TACCTL2
    TA1CCTL2 &= ~CCIE;
    //Habilita interrupção somente na RTI do Timer A0
}

//Trap: ISR
#pragma vector = PORT2_VECTOR, ADC10_VECTOR, NMI_VECTOR, \
COMPARATORA_VECTOR, WDT_VECTOR
__interrupt void TrapIsr(void)
{
    k = 1;

    if(ADC10CTL0 & ADC10IFG)
    {
        k=2;
    }
    if(CACTL1 & CAIFG)
    {
        k=3;
    }
    if(TA1CTL & TAIFG)
    {
        k=5;
    }
    if(TA1CCTL0 & CCIFG)
    {
        k=6;
    }
    if(TA1CCTL1 & CCIFG)
    {
        k=7;
    }
    if(TA1CCTL2 & CCIFG)
    {
        k=8;
    }
    if(TA0CTL & TAIFG)
    {
        k=9;
    }
    if(TA0CCTL0 & CCIFG)
    {
        k=10;
    }
    if(TA0CCTL1 & CCIFG)
    {
        k=11;
    }
    if(TA0CCTL2 & CCIFG)
    {
        k=12;
    }
    if(IFG1 & NMIIFG)
    {
        k=13;
    }
    if(IFG1 & WDTIFG)
    {
        k=14;
    }
    else
    {
        //k=15;
    }
// this is a trap ISR - check for the interrupt cause here by
// checking the interrupt flags, if necessary also clear the interrupt
// flag
}
*/
