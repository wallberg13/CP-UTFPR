#include <stdio.h>
int main(){
    int um_numero = 1234;
    int outro_numero = 5678;
    int auxiliar;
    int *ptr;

    ptr = &auxiliar;
    *ptr = um_numero;
    um_numero = outro_numero;
    outro_numero = *ptr;

    // use o ponteiro “ptr” para trocar os valores das variáveis
    // “um_numero” e “outro_numero” um pelo outro
    // o printf abaixo deve produzir o resultado "um: 5678, outro: 1234"

    printf("um: %d, outro: %d", um_numero, outro_numero);
    return 0;
}
