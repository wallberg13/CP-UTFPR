#include "LCD.h"

/*
 * Função que irá habilitar o barramento para escrita, esperar um pouco
 * para efetivar a operacao
 * */
void write_data(){
    ENABLE_ON;
    __delay_cycles(delay_cycles);
    ENABLE_OFF;
}


void write_clear(){
    ENABLE_ON;
    __delay_cycles(delay_clear);
    ENABLE_OFF;
}

/**
 * Função que fica verificando se o barramento está ocupado.
 * Para isso, dentro de um loop aparentemente infinito, ele
 * ira ficando dando bordas sucessivas de descida em ES e
 * irá ler o valor de DB7, enquanto ter seu valor logico
 * nivel alto, não irá sair do loop.
 * De começo, a porta utilizada do DB7 é utilizada como entrada,
 * e logo no final como saida.
 *
 *
 * */
void wait(){
    BUS_READ;
    RW_READ;
    RS_COM;

    ENABLE_ON;
    __delay_cycles(delay_cycles);
    ENABLE_OFF;

    while(P2IN & DB7){
        ENABLE_ON;
        __delay_cycles(delay_cycles);
        ENABLE_OFF;
    }

    BUS_WRITE;
    RW_WRITE;
    RS_WRITE;
}


/**
 * Cada comando deve ser enviado de 4 em 4 bits
 *
 * O objetivo é mandar primeiro os bits mais significativos e
 * depois os menos significativos.
 *
 * Para esse projeto, as portas do micro está configurado para
 * serem as 4 ultimas do P1, que estende da P1.4 - P1.7.
 *
 */
void send_comand(unsigned char comd){
    wait();
    RS_COM;

    /* Como Está sendo usado os 4 primeiros bits de
     * P1OUT, e é preciso enviar a parte mais significativa
     * do comando, então:
     */
    P1OUT &= 0x0F; // Limpa os 4 ultimos bits que se diz respeito ao display
    P1OUT |= (comd & 0xF0); //Filtra os bits mais significativos.
    if(comd == 0x01) // Dependendo do comando, como o clear do display, ele precisa de mais tempo para ser processado.
        write_clear();
    else
        write_data();

    P1OUT &= 0x0F;
    P1OUT |= (comd & 0x0F) << 4; //Manda os 4 bits menos significativos, fazendo um shift a esquerda pois
    // a saída da porta é nos 4 ultimos bits.
    if(comd == 0x01)
        write_clear();
    else
        write_data();

}


void send_data(unsigned char data){
    wait(); //Já garante que vem preparado pra escrever

    RS_WRITE;

    /*
     * O esquema para colocar os dados no barramento é o mesmo que o da
     * função acima.
     * */
    P1OUT &= 0x0F;
    P1OUT |= (data & 0xF0);
    write_data();

    P1OUT &= 0x0F;
    P1OUT |= (data & 0x0F) << 4;
    write_data();
    send_comand(0x0C); // Não deixa o cursor piscando.
}


/**
 * Função que irá escrever diretamente no display
 * Por que não precisa ficar descolando o cursor que será escrito:
 * O display já faz isso automaticamente.
 * */
void write_string(char *str){
    while(*str != '\0'){
        send_data(*str);
        str++;
    }
}

void ini_LCD(){
    send_comand(0x33);
    send_comand(0x32); // Em boa parte dos codigos na internet estavam mandando esses primeiros dois comandos.
    send_comand(0x28); // Modo de 4bit ---> Datasheet
    send_comand(0x01); // Limpa Cursor ---> DataSheet
    send_comand(0x0C); // Não deixa o cursor piscando.
    send_comand(0x80); // Deixa o cursor na primeira linha e coluna
}

/**
 * Função para configurar a posição do cursor, forçando ele ficar em determinado local.
 * Linha e coluna
 *
 * Conforme o Datasheet do Display, o comando para
 * deslocar o cursor é o 0x14.
 *
 * Ele desloca o cursor para a direita sem dá shift.
 * */
void set_position(int y, int x){
    int i;
    x--;
    if(!y){ //Primeira Linha
        send_comand(0x80);
        for(i = 0; i < x; i++){
            send_comand(0x14);
        }
    }else{
        if(y){ //Segunda Linha
            send_comand(0xC0);
            for(i = 0; i < x; i++){
                send_comand(0x14);
            }
        }
    }
}
