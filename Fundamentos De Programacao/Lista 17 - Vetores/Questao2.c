/** Gerar aleatoriamente 8 elementos para um vetor A. Construir um vetor B de mesma
dimensão com os elementos de A multiplicados por 2. Represente a solução. */

#include<stdio.h>
#include<Wall.h>  //Biblioteca Pessoal

int main(){
    int v[7],v2[7];
    int i;

    for(i = 0; i<8; i++){
        printf("Digite o %d° numero do vetor: ",i+1);
        scanf("%d",&v[i]);
        v2[i] = v[i]*2;
    }

    printf("O vetor original!!!\n");
    escreverVetor(v,8);
    printf("O vetor doblado!!!\n");
    escreverVetor(v2,8);
}
