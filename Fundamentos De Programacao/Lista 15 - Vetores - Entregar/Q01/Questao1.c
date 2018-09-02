#include<stdio.h>
#include<stdlib.h>

void letraa(int v[]);
void letrab(int v[]);
void letrac(int v[]);
void letrad(int v[]);
void letrae(int v[]);

int main(){
    int v[9],i;
    char resp;

    do{
        system("clear");
        for (i = 0; i<= 9; i++){
            do{
                printf("Digite o %d° numero: ",i+1);
                scanf("%d",&v[i]);
                if (v[i]<=0)
                    printf("Digite novamente!!!\n");
            }while(v[i]<=0);
        }

        printf("\n\nLetra A: \n");
        letraa(v);
        printf("\nLetra B: \n");
        letrab(v);
        printf("\nLetra C: \n");
        letrac(v);
        printf("\nLetra D: \n");
        letrad(v);
        printf("\nLetra E: \n");
        letrae(v);

        do{
            printf("\nDeseja executar o programa novamente? \nS - Sim \nN - Não \nResposta: ");
            __fpurge(stdin);
            scanf("%c",&resp);

            if(resp != 'S' && resp != 's' && resp != 'N' && resp != 'n')
                printf("Resposta invalida!!\n");

        }while(resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    }while(resp == 'S' || resp == 's');
}

void letraa(int v[]){
    int i;
    for (i = 0; i<=9; i++){
        if(v[i]%2 == 0)
            printf("%d é um numero par e esta na posição: %d\n",v[i],i);
    }
}

void letrab(int v[]){
    int quant, i;

    for(i = 0, quant = 0; i<= 9; i++){
        if(v[i]%3 == 0 && v[i]%5 == 0){
            printf("%d é divisivel por 3 e por 5!!\n",v[i]);
            quant++;
        }
    }
    printf("A quantidade de numeros divisiveis por 3 e 5 é: %d !!\n",quant);
}

void letrac(int v[]){
    int i;
    for (i = 0; i<=9; i++){
        if(v[i]<10)
            printf("%d é um numero menor do que 10!! \n",v[i]);
        if(v[i]>100)
            printf("%d é um numero maior do que 100!! \n",v[i]);
    }
}

void letrad(int v[]){
    int i;
    for (i = 0; i<=9; i++){
        if(v[i]>10 && v[i]<100)
            printf("%d é um numero maior do que 10 e menor que 100!!\n",v[i]);
    }
}

void letrae(int v[]){
    int i, quant;
    for (i = 0, quant = 0; i<=9; i++){
        if(v[i]%2 != 0){
            printf("%d é um numero impar!! \n",v[i]);
            quant++;
        }
    }

    printf("\nA quantidade de numeros impares é: %d !!\n",quant);
    printf("A porcentagem de numeros impares em relação ao todo conjunto é: %.2f %c",((float)quant/10)*100,37);
}
