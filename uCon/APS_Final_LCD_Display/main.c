#include <msp430.h> 
#include "LCD.h"


void ini_P1_P2();
void ini_uCon();
void ini_TA0_Amostra();
void ini_TA0_Debounced();
void ini_display();
void ini_UART();
void monta_String_TX();
void trata_RX();


/**
 * Funcoes alternativas para o nao uso da
 * sprintf.
 * */
void to_string_f1(double d);
void to_string_f2(double d);
void to_string_int(char x);

/**
 * Foi setado uns valores de variaveis aqui, como o fluxo_m que � o fluxo Medio
 * o fluxo_M � o fluxo maximo, e o fluxo que � o fluxo instantaneo.
 *
 * Para mostrar j� funcionando em uma hora j� mais avan�ada, ent�o j� foi logo setado o valor.
 * */

char seg = 55;
char min = 58;
char hora = 23;
char dia = 8;
char buffer[5];
double vol_t = 2.2;
double fluxo_m = 0.5;
double fluxo_M = 0.6;
double fluxo = 0.4;

#define tam_rx 16
#define tam_tx 32

char TX_DATA[tam_tx], RX_DATA[tam_rx];
unsigned char tx_index = 0, rx_index;


unsigned char flag = 0;
unsigned char n_amostra = 0;

/*
 * main.c
 */
void main(void) {

    ini_P1_P2();
    ini_uCon();

    ini_LCD();
    ini_display();

    ini_UART();
    ini_TA0_Amostra();

    do{

    }while(1);
}



/**
 * Interrupcao classica do debounced, lembrando que como
 * est� sendo usado o mesmo timer, tanto para fazer debounced como
 * para fazer as amostras, quando a chave S2 � precionada
 * a configura��o do timer � mudada para o debounced, e uma flag � ativada
 * para que na RTI do timer possa ser indentificado quem gerou a interrupcao,
 * se foi a chave o as amostras.
 * */
#pragma vector=PORT1_VECTOR
__interrupt void RTI_P1(){
    P1IE &= ~BIT3;
    P1IFG &= ~BIT3;
    flag = 1;
    ini_TA0_Debounced();
}

/*
 * � um fato que est� RTI esteja muito carregada, com muito codigo,
 * mas como o timer nunca para quando entra aqui, mas pelo o fato tamb�m de serem interrup��es
 * de 1 em 1 segundo, a CPU tem tempo o sufiente para fazer o processamento
 * antes venha outra requisi��o de interrup��o desta mesma RTI.
 */
#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_Timer_A0(){
    if(!flag){
        /**
         *
         * Est� parte do codigo se diz respeito a amostra do sinal do sensor.
         *
         * O programa ira permitir ate um numero de 255 amostras, logo depois ele
         * ser� zerado, este numero � o fator de divis�o utilizado para calcular a m�dia
         * do sensor.
         * O volume total de �gua ir� se tornar zero tamb�m.
         *
         * */
        n_amostra++;
        if(n_amostra == 255){
            n_amostra = 0;
            vol_t = 0;
        }
        /**
         * Imprementa��o basica e classica do relogio do sistema.
         * Logo depois, ser� feito o tratamento do sensor, que ser�
         * implementado logo depois.
         * */
        seg++;
        if(seg == 60){
            seg = 0;
            min++;
            if(min == 60){
                min = 0;
                hora++;
                if(hora == 24){
                    hora = 0;
                    dia++;
                    if(dia == 9)
                        dia = 0;
                }
            }
        }
    }else{
        /**
         *  Est� parte do codigo se diz ao debounced do micro.
         *  Ele torna a flag como zero, para que caia no tratamento
         *  de amostras e n�o de debounced.
         *
         *  Aqui, o Fluxo Maximo, dado como FM, o Fluxo Medio, dado como Fm
         *  e o Volume total s�o zerados, como tambem o n_amostras, usado para
         *  calcular a m�dia de fluxo de agua.
         *
         *  O timer e parado no come�o da RTI, para que o tempo de debounced n�o
         *  fique valendo eternamente. E que tamb�m n�o venha ocorrer
         *  problemas na hora de imprimir o sensor, j� que ele precisa de mais
         *  tempo do que o timer do debounced.
         *
         * */
        if(flag){
            ini_TA0_Amostra();
            if((~P1IN) & BIT3){
                fluxo_M = 0.0;
                fluxo_m = 0.0;
                vol_t = 0.0;
                n_amostra = 0;
            }
            P1IFG &= ~BIT3;
            P1IE |= BIT3;
            flag = 0;
        }
    }

    /**
     * Atualiza��o do display, inicialmente n�o era a inten��o
     * que ele ficasse atualizando toda vez que entrasse na RTI,
     * mas quando estava sendo atualizado os valores dos Fluxo,
     * toda vez que apertava no bot�o, e os valores de tempo deveriam
     * ser atualizados, ent�o decidiu-se atualizar tudo de uma s� vez
     * pagando o preco de atualizar varios campos varias vezes.
     * */
    ini_display();

    monta_String_TX();

    IFG2 |= UCA0TXIFG;
}


/**
 * RTI padrao de Transmissao.
 *
 * Trasmite o que tiver dentro do vetor TX_DATA,
 * enquanto ele nao for totalmente transmitido,
 * vai continuar tendo interrupcao de trasmissao,
 * e essa flag s� � limpa depois que ele acha o
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
 *  Enquanto n�o for encontrado o '.' na string, ele n�o para de
 *  receber caractere.
 *  Aqui est� a limita��o do codigo, pois n�o faz valida��o devido as posi��es.
 *  E ele s� faz alguma coisa caso tiver o ponto final.
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

/**
 * Parte que ira tratar os dados vindo da serial.
 *
 * O texto deve j� entrar aqui no formato que ser� descrito a
 * seguir, caso n�o vier nesse formato, o codigo pode apresentar problemas
 * que n�o foram tratados.
 *
 * O objetivo � de receber um texto formatado e alterar os valores das variaveis.
 *
 * N�o � possivel mudar um de cada vez, � preciso alterar tudo no modo
 * que est� descrito.
 *
 * Para Mudar o Dia, Hora, Minuto e Segundo, o texto
 * que tem que vim pela serial � o seguinda:
 *
 * Dois algorismos para Dia, dois para hora,
 * dois para minutos e dois para segundos e no final,
 * para fazer a valida��o da recep��o, um '.' no final.
 * DD/HH/MM/SS.
 *
 * Sera tratado meio que na gambiarra, assim, limitando o algoritmo
 * */
void trata_RX(){
    unsigned char i = 0, j = 0, k = 0;

    /*
     * � sempre pego a primeira posi��o do vetor de RX_DATA para
     * ser trabalhado, pq assim, ao ler aquele char, ele j� � limpo
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
         * Quando o RX_DATA[k] for igual a \, ent�o j volta a ser zero e o i � incrementado,
         * isso quer dizer que uma variavel acabou de ser lida e que est� pronto para ler a
         * proxima.
         * */
        if(RX_DATA[k] == 47){
            j = 0;
            i++;
        }else{
            /*
             * Switch case para saber qual variavel foi utilizada.
             * Quando J � 0, significa que ele capturou a parte mais significativa do numero.
             * � ideal que o char que est� vindo seja realmente numero, e n�o letras, para
             * que n�o d� um bug no algoritmo.
             *
             * Com o j = 0, ele pega a dezena do numero, ent�o o valor do char
             * � subtraido de '0' que representa 48 em decimal pois assim a variavel fica com o
             * numero da parte inteira. Essa logica � baseada na tabela ASCII.
             * */
            switch(i){
                case 0:
                    if(!j) //Dezena
                        dia = 10*(RX_DATA[k] - '0');
                    else
                        dia += RX_DATA[k] - '0';
                    break;
                case 1:
                    if(!j) //Dezena
                        hora = 10*(RX_DATA[k] - '0');
                    else
                        hora += RX_DATA[k] - '0';
                    break;
                case 2:
                    if(!j) //Dezena
                        min = 10*(RX_DATA[k] - '0');
                    else
                        min += RX_DATA[k] - '0';
                    break;
                case 3:
                    if(!j) //Dezena
                        seg = 10*(RX_DATA[k] - '0');
                    else
                        seg += RX_DATA[k] - '0';
                    break;
            }
            j++;
        }
        RX_DATA[k] = '\0';
    }
    ini_display(); // Isso � para que apare�a os valores alterados instantaneamente.
    /**
     * As escritas em display est�o sendo feitas dentro das interrup��es pois
     * a CPU vai ficar funcionando quando for detectado uma interrup��o.
     * */
}



/**
 * Inicializa��o das Portas (N�o levando conta o display)
 * Na verdade, na propria escrita do display ele j� faz a configura��o nas
 * portas de escrita para que possa ser feito tudo.
 *
 * PRECISA CONFIGURAR A PORTA AQUI DO SENSOR
 **/
void ini_P1_P2(){
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR = ~BIT3;
    P1REN = BIT3;
    P1OUT = BIT3;
    P1IES = BIT3;
    P1IFG = 0;
    P1IE = BIT3;


    P2DIR = 0xFF;
    P2OUT = 0;
}

/**
 * Inicializa��o de Clock,
 * Principal: 16MHz
 * Secundario: 8MHz --> Usado para calibrar a UART
 * Auxiliar: Cristal
 * */
void ini_uCon(){
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0; // Secundario para 8MHz para poder usar a UART
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF);
    __enable_interrupt();
}


/**
 * Configura��es dos Timers, uma configura��o para DEBOUNCED e
 * outra para aquisi��o de amostra.
 * Poderia-se utilizar s� mudar o TA0CCR0 de cada um;
 * */
void ini_TA0_Debounced(){
    TA1CTL = TASSEL0 + MC0;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 6;
}

void ini_TA0_Amostra(){
    TA1CTL = TASSEL0 + MC0;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 32767;
}

/**
 * Configuracao da UART
 * */
void ini_UART(){

    /**
     * CONFIGURA��O COM BASE COM O QUE FOI VISTO EM AULA
     *
     * O USCWRST no registrador de controle 1 deve
     * est� setado para que seja possivel fazer as demais
     * configuracoes da UART
     *
     * UCSSEL1 - Selecao da fonte de Clock para 8MHz e um
     * fator de divisao de 833 ==> 0x0341;
     *
     * Separando isso nos UCBR0 e 1 (Cada registrador de 8 bits)
     * ficaria: UCBR0 = 0x41 e UCBR1 = 0x03;
     *
     * N�o tem sobreamostragem
     *
     * UCA0MCTL = UCBRS1; //
     *
     * UCA0CTL0 - Igual a zero. (N�o sei pq)
     *
     **/
    UCA0CTL1 = UCSSEL1 + UCSWRST;

    UCA0CTL0 = 0;

    UCA0BR0 = 0x41;
    UCA0BR1 = 0x03;

    UCA0MCTL = UCBRS1;

    // Configuracao da Porta P1.1 e P1.2 para sa�da e entrada da UART
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;

    //Com todas as configura��es feita, nao � mais preciso o bit de reset em CTL1
    UCA0CTL1 &= ~UCSWRST;

    /*
     * Interrupcao por transmissao e recepcao habilitados.
     * */
    IFG2 &= ~UCA0TXIFG;
    IE2 |= UCA0TXIE + UCA0RXIE; //S� pra testar a transmissao
}


//----------------------------------------------------------------------------------------
//------------------------------FUNCOES NECESSARIAS---------------------------------------
//----------------------------------------------------------------------------------------

/**
 * Fun��o de escrita no display,
 * qualquer atualiza��o que seja feito nas variaveis, essa
 * fun��o � chamada.
 * */
void ini_display(){
    set_position(0,1);
    write_string("D");
    to_string_int(dia);
    write_string(buffer);

    set_position(0,5);
    write_string("h");
    to_string_int(hora);
    write_string(buffer);

    set_position(0,9);
    write_string("m");
    to_string_int(min);
    write_string(buffer);

    set_position(0,13);
    write_string("s");
    to_string_int(seg);
    write_string(buffer);

    set_position(1,1);
    write_string("V");
    to_string_f2(vol_t);
    write_string(buffer);

    set_position(1,6);
    write_string("Fm");
    to_string_f1(fluxo_m);
    write_string(buffer);

    set_position(1,12);
    write_string("FM");
    to_string_f1(fluxo_M);
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
 * Em seguida, este numero retirado � somado com o caractere '0' que na tabela ASCII representa
 * o numero 48, como cada numero e pego em uma faixa de 0 a 9, entao nao tem perigo de
 * sair um caractere errado.
 * */
void to_string_f1(double d){

    unsigned char i;
    i = (unsigned char)(d*10);
    buffer[0] = (unsigned char)(i/10);
    buffer[2] = i%10;
    buffer[3] = '\0';

    buffer[0] += '0';
    buffer[1] = '.';
    buffer[2] += '0';
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
 * Montagem da String para transmiss�o, formatada meio que na
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
    to_string_f2(vol_t);
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
