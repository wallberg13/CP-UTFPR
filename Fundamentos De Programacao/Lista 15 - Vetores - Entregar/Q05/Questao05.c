#include<stdio.h>

int main(void){
    char matriz[5][30], letra;
    int i;

    for(i = 0; i <= 4; i++){
        printf("Digite o nome: ");
        gets(matriz[i]);
    }

    for(i = 0; i <= 4; i++){
        printf("%s \n", matriz[i]);
    }

    for(i = 0; i <= 4; i++){

    }
}
