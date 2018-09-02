#include<stdio.h>

int main(){

    int Int = 1, *p_Int;
    double Dou = 2.0, *p_Dou;
    char Char = 'A', *p_Char;

    //Para apontar aonde esta cada um
    p_Int = &Int;
    p_Dou = &Dou;
    p_Char = &Char;

    //Para receber o que cada um possui na variavel;
    *p_Int = Int;
    *p_Dou = Dou;
    *p_Char = Char;

    puts("Imprime o Local de cada variavel!!");
    printf("%X \n", &Int);
    printf("%X \n", &Dou);
    printf("%X \n", &Char);
    printf("%X \n", &p_Int);
    printf("%X \n", &p_Dou);
    printf("%X \n", &p_Char);

    puts("\n\nImprime Valores\n");
    printf("%d \n", *p_Int);
    printf("%f \n", *p_Dou);
    printf("%c \n", *p_Char);

    //Alterando o valor das variaveis usando ponteiros
    *p_Int = 2;
    *p_Dou = 2.0;
    *p_Char = 'K';

    puts("\n\nImprime valores depois de alterados via ponteiro! \n");
    printf("%d \n", *p_Int);
    printf("%f \n", *p_Dou);
    printf("%c \n", *p_Char);

    p_Int = &Char;
    p_Char = &Int;

    printf("%X \n", p_Int);
    printf("%X \n", p_Dou);
    printf("%X \n", p_Char);

    /**Ele aponta normal, só que os bytes que vai para o ponteiro, só vai os primeiro bits que ponteiro representa;
       Ex: um Int tem 4 bits, se eu pego um ponteiro de char para apontar para o do Int, ele só vai pegar o
       primeiro bit, pois um ponteiro de bits so tem espaço para 1 bits, que no caso seria o primeiro bit do
       Int;
    */

    return 0;
}
