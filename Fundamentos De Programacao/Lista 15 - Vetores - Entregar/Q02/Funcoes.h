#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void geraVetor(int tam, int a, int b, int v[]){
    int i;

    if (a > b){
        i = a;
        a = b;
        b = i;
    }

    srand(time(NULL));
    for (i=0;i<tam;i++){
        v[i] = a + rand()%(b-a);
    }
}

int escreverVetor(int v[],int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int menorElemento(int v[], int tam){
    int men = 0,i;

    for(i = 0; i < tam; i++){
        if(v[i]<men || men == 0)
            men = v[i];
    }

    return men;
}

float mediaPar(int v[], int tam){
    int soma, quant, i;

    for(i = 0, soma = 0, quant = 0; i < tam; i++){
        if(v[i]%2 == 0){
            soma += v[i];
            quant++;
        }
    }

    if(soma != 0)
        return ((float)soma)/quant;
    else
        return 0.0;
}
