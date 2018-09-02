/**2) Gerar um arquivo de cabeçalho com uma função para gerar um vetor com números
aleatórios, com determinado tamanho e em uma determinada faixa de valores e com outra
função para mostrar um vetor com tamanho não fixo.

Utilizar essas funções para gerar um vetor de valores randômicos com a quantidade de
elementos informada pelo usuário.
Validar a entrada para que seja informado um valor positivo para o tamanho do vetor.
Mostrar o vetor.
Encontrar o menor entre os elementos gerados e armazenados no vetor e
fazer a média dos pares que estão no vetor.
Validar para que não seja realizada divisão por zero no cálculo da média. */
#include<stdio.h>
#include "Funcoes.h"

int main(){
    int a,b,tam;

    do{
        printf("Digite o tamanho que você quer dar para o seu vetor: ");
        scanf("%d",&tam);

        if(tam<=0)
            printf("Valor Invalido!!!\n");

    }while(tam<=0);

    do{
        printf("Digite o primeiro numero do intervalo: ");
        scanf("%d",&a);
        if(a<0)
            printf("Valor Invalido!!!\n");
    }while(a<0);

    do{
        printf("Digite o segundo numero do intervalo: ");
        scanf("%d",&b);
        if(b<0)
            printf("Valor Invalido!!!\n");
    }while(b < 0);

    int v[tam];
    geraVetor(tam,a,b,v);

    escreverVetor(v,tam);

    printf("O menor valor do vetor é: %d \n", menorElemento(v,tam));
    printf("A media dos elementos pares do vetor é: %d \n",mediaPar(v,tam));
}
