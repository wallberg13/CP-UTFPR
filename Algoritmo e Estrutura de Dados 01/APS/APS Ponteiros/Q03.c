#include <stdio.h>

int main(){
    int um_numero = 1234567890;
    char *ptr;
    /*
        o tipo “char” é um número inteiro de 1 byte de comprimento
        o tipo “int” tem normalmente 4 bytes de comprimento (varia com a CPU e SO)
        use o ponteiro para imprimir os bytes da variável “um_numero”
        dica: você pode tanto usar o ponteiro como um vetor como incrementá-lo com ++
    */
    ptr = &um_numero;

    for(int i = 0; i < sizeof(int); i++){
        printf("%X \n\n",ptr[i]);
    }

    printf("%X \n", um_numero);
    return 0;
}
