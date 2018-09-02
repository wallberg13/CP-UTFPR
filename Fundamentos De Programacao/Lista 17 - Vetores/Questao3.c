/**3) Gerar aleatoriamente 7 elementos para um vetor A. Construir um vetor B de mesmo
tipo, sendo que cada elemento de B deverá ser o elemento de A correspondente
multiplicado por sua posição (ou índice), ou seja, B[i] = A[i] * i. Represente a solução.*/

#include<Wall.h>
#include<stdio.h>

int main(){

    int a[6], b[6],i;
    geraVetor(7,1,100,a);

    for(i = 0; i<7; i++){
        b[i] = a[i]*i;
    }

    printf("Vetor A!!\n");
    escreverVetor(a,7);
    printf("Vetor B!!\n");
    escreverVetor(b,7);

}
