#include <stdio.h>

typedef struct{
    int codigo;
    float saldo;
    char nome[12];
}reg_cliente;

void imprime_bytes(void *bytes, int tamanho){
    unsigned char *dados = bytes;

    for(int i=0; i<tamanho; i++){
        printf("%3d ", dados[i]);
    }

    printf("\n");

    for(int i=0; i<tamanho; i++){
        printf("%3X ", dados[i]);
    }

    printf("\n\n");
}

void main(void){
    printf("%d \n", 'A'*10);
    printf("Tamanho de um int: %d \n",sizeof(int));
    printf("Tamanho de um float: %d \n",sizeof(float));
    printf("Tamanho de um double: %d \n",sizeof(double));
    printf("Tamanho de um long: %d \n",sizeof(long));
    printf("Tamanho de um short: %d \n",sizeof(short));
    printf("Tamanho de um Cliente: %d \n",sizeof(reg_cliente));
    puts("");

    char dados[16] = "ABCDEFGHIJKLMNO";
    int numInteiro = 0xAABBCCD;
    float numFloat = 1.0f;
    double numDouble = 1.0;

    imprime_bytes(dados, 16);
    imprime_bytes(&numInteiro, sizeof(int));
    imprime_bytes(&numFloat, sizeof(float));
    imprime_bytes(&numDouble, sizeof(double));

    int *p_Int = dados;
    printf("%X \n", *p_Int);
    printf("%d \n", *p_Int);

    float *p_Float = dados;
    printf("%f \n", *p_Float);

    double *p_double = dados;
    printf("%f \n", *p_double);

    reg_cliente *p_cliente = dados;
    printf("cod cliente: %X \n", (*p_cliente).codigo);
    printf("Nome cliente: %s \n", (*p_cliente).nome);
    printf("Saldo cliente: %f \n", (*p_cliente).saldo);

}
