#include<stdio.h>
#include "Funcoes.h"

void questao1();
void questao2();

int main(){
    char resp;

    printf("-->Menu<---\n");
    printf("1 - Questao 01\n");
    printf("2 - Questao 02\n");
    printf("3 - Questao 03\n");
    printf("Resp: ");
    scanf("%d",&resp);

    switch(resp){
        case '1':
            questao1();
            break;
        case '2':
            questao2();
            break;
    }



}
