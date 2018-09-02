/* Ler um número positivo e maior que zero (validar a entrada). Esse número indica a
quantidade de valores ímpares e não divisíveis por 5 e divisíveis por 7 que devem ser
mostrados. Apresentar 'n' valores por linha. 'n' é informado pelo usuário e deve ser maior
que zero. Validar a entrada.*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    char resp;
    int quantV, quantL, i,j,h;

    do{
        system("clear");
        printf("Algoritmo para Mostrar valores impares nao divisiveis por 5 e divisiveis por 7\n\n\n\n");

        do{
            printf("Digite a quantidade de numeros que você quer exibir: ");
            scanf("%d",&quantV);

            if (quantV<0)
                printf("Entrada invalida, digite só valores positivos!!");
        }while(quantV < 0);

        do{
            printf("Digite a quantidade de numeros que você quer exibir por linha: ");
            scanf("%d",&quantL);

            if(quantL<0)
                printf("Entrada invalida, digite só valores positivos!!");
        }while(quantL<0);

        for(i = 1, j = 0, h = 0;h < quantV; i++){
            if(i%2==1 && i%5 == 0 && i%7 !=0){
                printf("%d \t",i);
                h++;
                j++;
                if(quantL == j){
                    printf("\n");
                    j = 0;
                }
            }
        }

        do{
            printf("\nDeseja executar novamente o programa? \nS - Sim \nN - Não \nResposta: ");
            __fpurge(stdin);
            scanf("%c",&resp);
            if (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n'){
                printf("\nResposta Invalida!!! \n\n"); }
        }while(resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    }while(resp == 'S' || resp == 's');
}
