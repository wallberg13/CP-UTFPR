/** Gerar aleatoriamente 10 elementos para um vetor A e construir um vetor B de mesma
dimensão com os mesmos elementos de A, mas em ordem invertida, ou seja, o primeiro
elemento de A será o último de B, o segundo elemento de A será o penúltimo de B e
assim sucessivamente. Represente a solução. */

#include<stdio.h>
#include<Wall.h>            //Biblioteca particular, usei para informar o tamanho de um vetor e imprimir ele!!

int main(){
    int i, a[9], b[9];

    for(i = 0; i<10; i++){
        printf("Digite o %d° numero do vetor: ",i+1);
        scanf("%d",&a[i]);
        b[9-i] = a[i];
    }

    printf("\nO vetor normal!!! \n");
    escreverVetor(a,10);
    printf("O vetor invertido!!!\n");
    escreverVetor(b,10);
}
