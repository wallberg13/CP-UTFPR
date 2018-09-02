#include<stdio.h>

int main(void){

    int matriz[5][2];
    int linha, coluna, lmenor, cmenor, menor, maior, cmaior, lmaior;

    for(linha = 0; linha <= 4; linha++){
        for (coluna = 0; coluna <= 1; coluna++){
            printf("Qual a nota[%d] do aluno[%d]? ", coluna+1, linha+1);
            scanf("%d",&matriz[linha][coluna]);
        }
    }
    menor = matriz[0][0]; maior = matriz[0][0];
    lmenor = 0; lmaior = 0;
    cmenor = 0; cmaior = 0;

    for(linha = 0; linha<=4; linha++){
        for(coluna = 0; coluna <= 1; coluna++){
            if(matriz[linha][coluna] < menor){
                menor = matriz[linha][coluna];
                lmenor = linha;
                cmenor = coluna;
            }

            if(matriz[linha][coluna] > maior){
                maior = matriz[linha][coluna];
                lmaior = linha;
                cmaior = coluna;
            }
        }
    }

    printf("\nMenor Nota = %d\n na linha %d e coluna %d\n", menor, lmenor, cmenor);
    printf("\nMaior Nota = %d\n na linha %d e coluna %d\n", maior, lmaior, cmaior);
    return 1;
}
