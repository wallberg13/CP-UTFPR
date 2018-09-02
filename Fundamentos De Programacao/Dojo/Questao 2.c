#include<stdio.h>

int main(){
    int a, b, aux, mDivisor,qtDivisor, i, j;

    mDivisor = 0;

    do{
        printf("Digite um primeiro numero: ");
        scanf("%d",&a);
    }while(a<2 && a>100);

    do{
        printf("Digite um segundo numero: ");
        scanf("%d",&b);
    }while(a<2 && a>100);


    if(a>b){
        aux = a;
        a = b;
        b = aux;
    }

    for(i = a; i<b; i++){
        for (j = i; i > j; j++){
            if(j%i == 0){
                qtDivisor++;
            }
        }
    }

    printf("%d");
}
