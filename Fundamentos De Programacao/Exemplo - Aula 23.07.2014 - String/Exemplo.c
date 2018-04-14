#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[35];
    printf("Digite o seu nome:\n");
    scanf("%[^\n]s",&nome);
    printf("\nNome informado: %s.", nome);
}
