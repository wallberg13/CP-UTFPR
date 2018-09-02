#include<stdio.h>
int contaCaracter(char nome[]){
    int i;

    for(i = 0; nome[i] != '\0'; i++);

    return i    ;
}

int pesquisaPrimeiroCaracter(char nome[], char letra){
    int i, achei = 0, j = -1;

    for(i = 0; (nome[i] != '\0') && (!achei); i++){
        if(nome[i] == letra){
            achei = 1;
            j = i;
        }
    }
    return j;
}

int pesquisaUltimoCaracter(char nome[], char letra){
    int i, achei = 0, j = -1;

    for(i = 0; nome[i] != '\0'; i++){
        if(nome[i] == letra){
            achei = 1;
            j = i;
        }
    }
    return j;
}
int main(){
    char nome[50];
    char letra;
    int tamanho;
    int gaveta, ultimo;

    printf("Qual é o nome? ");
    scanf("%[^\n]s",&nome);
    __fpurge(stdin);
    printf("Qual é o caractere para pesquisar? ");
    scanf("%c", &letra);
    __fpurge(stdin);

    tamanho = contaCaracter(nome);
    printf("Tamanho: %d \n", tamanho);

    gaveta = pesquisaPrimeiroCaracter(nome,letra);
    if (gaveta == -1)
        printf("Não achei!!\n");
    else
        printf("Achei na gaveta %d \n", gaveta);

    ultimo = pesquisaUltimoCaracter(nome,letra);
    if (ultimo == -1)
        printf("Não achei!!\n");
    else
        printf("Achei na gaveta %d \n", ultimo);

    return 1;
}
