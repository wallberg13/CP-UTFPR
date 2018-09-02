#include <msp430.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Endereço da segunda linha na RAM do LCD
#define lcd_2nd_line 0x40

//Configurações display
#define lcd_cursor_on 2
#define lcd_cursor_off 0
#define lcd_cursor_blink 1
#define lcd_cursor_nblink 0
#define lcd_display_on 4
#define lcd_display_off 0
#define lcd_display_8x5 0
#define lcd_display_10x5 4
#define lcd_2_lines 8
#define lcd_1_line 0

//Protótitipo da função para ligar display.
void lcd_turnon_display(void);
//Protótipo da função de enviar nibble
void send_nibble(char data);
//Protótipo da função de enviar byte
void send_byte(char end, char data);
//Protótipo da função de inicialização do LCD.
void ini_lcd(char mode1,char mode2);
//Protótipo da função para escrever caracteres.
void lcd_write_c(unsigned char cin);
//Protótipo da função para posicionar o texto
void lcd_text_position(unsigned char X, unsigned char Y);
//Protótipo da função para escrever string.
void lcd_write_s(char* cin);
//Protótipo da função para extrair parte inteira e decimal.
void extract_intdec(float,int*,int*);

void send_nibble(char data){
        P2OUT = (P2OUT & 0xF0)|(data & 0x0F);
        // Pulsa Enable.
        P2OUT |= BIT4; //Set P2.4 = 1
        __delay_cycles(1600);
        P2OUT &= ~BIT4; //set p2.4 = 0
        __delay_cycles(80000);
}

void send_byte(char end, char data){

    P2OUT &= ~BIT5; //set p2.5 = 0
    //Seta RS dependendo do modo selecionado (modo de comando ou dados)
    P2OUT |= end << 5; //verificar bit a bit
    __delay_cycles(80000);
    //Primeira parte do byte é enviada
    send_nibble(data >> 4);
    __delay_cycles(80000);
    //Segunda parte do byte é enviada
    send_nibble(data);
    __delay_cycles(80000);
}

static char modelcd2;

void ini_lcd(char mode1,char mode2){

    char i = 0;

    __delay_cycles(1600000);

      //Configuração das portas.
      //P2DIR |= (BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5);
      //P2OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5);
    //Sequência de inicialização em modo 4 bits.

     //P2OUT = 0x03;

    //P2OUT &= ~BIT4; //ENABLE = 0 -> O display pode receber comandos.

    for(i = 1; i<=3;i++){
        send_nibble(3);
        __delay_cycles(80000);
    }
    send_nibble(2);

    /*Envia códigos de inicialização do display.
     *         MODO1
     * BIT       7 6 5 4  3 2 1 0
     * initial   0 0 1 DL N F - -
     * desej     0 0 1 0  X X 0 0
     *          ------------------> (0x20)|(modo1)
     * DL = 0 -> 4 bits mode. If DL=1 -> 8 bits.
     * N = 0/1 -> 1 ou 2 linhas.
     * F = 0/1 -> 5x7 dots ou 5x10 dots.
     *
     *      MODO2
     *      BIT 7 6 5 4 3 2 1 0
     *  initial 0 0 0 0 1 D C B
     *  desej   0 0 0 0 1 X X X
     *  ----------------------> (0x08)|(modo2)
     *  D -> Display ON/OFF
     *  C -> Cursor ON/OFF
     *  B -> Blink Characters ON/OFF
    */
    //send_byte(0, 0x28);
    send_byte(0, 0x20 | mode1); //configura modo1 (número de linhas e tamanho dos caracteres)
    //send_byte(0, 0x0D);
    send_byte(0, 0x08 | mode2); //configura modo2 (estado do cursor e do display)
    modelcd2 = 0x08 | mode2;
    send_byte(0, 1); //limpa display.
    send_byte(0, 6); //sets the cursor move direction (right) and cursor move.

}

void lcd_text_position(unsigned char X, unsigned char Y){

    char end;

    if(Y)
        end = 0x40;
    else
        end = 0;

    end += X - 1;

    send_byte(0, 0x80 | end);
}

void lcd_write_c(unsigned char cin){

    switch(cin){

    case '\f':
        send_byte(0, 1);
        //__delay_cycles(300);
        break;
    case '\r':
        lcd_text_position(1,2);
        break;
    default:
        send_byte(1, cin);
        break;

    }
}

void lcd_write_s(char *cin){

    while(*cin){
        lcd_write_c(*cin);
        cin++;
    }
}

void lcd_turnon_display(void){

    modelcd2 |= 4;
    send_byte(0, modelcd2);
    __delay_cycles(80000);
}

void extract_intdec(float data, int *intpart, int*decpart){
    //float shadow = 0;
    *intpart = floor(data);
    //shadow = data - *intpart;
    *decpart = (data - *intpart)*100;

    //*dezena = data/10;
    //*unidade = ((data/10)-*dezena)*10;
    //*decimo = data*10-((int)data)*10;
}

