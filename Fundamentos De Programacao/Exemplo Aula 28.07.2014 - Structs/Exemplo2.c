#include<stdio.h>
struct rgAluno{
    char nome[35];
    float nota[3];
    float media;
};

struct rgAluno aluno[3];

int main(void){
    float soma = 0;
    int i, j;

    for(i = 0; i < 3; i++){
        printf("Digite o %d° nome do aluno: ",i+1);
        __fpurge(stdin);
        scanf("%[^\n]s", &aluno[i].nome);
        for(j = 0; j < 3; j++){
            printf("Digite a %d° nota do aluno: ",j+1);
            scanf("%f",&aluno[i].nota[j]);
            soma += aluno[i].nota[j];
        }
        aluno[i].media = soma/3;
        soma = 0;
    }

    for(i = 0; i < 3; i++){
        printf("\nAluno: %s \n",aluno[i].nome);
        for(j = 0; j < 3; j++){
            printf("%d° nota do aluno: %.2f \n",j+1,aluno[i].nota[j]);
        }
        printf("Media do aluno: %.2f\n",aluno[i].media);
        printf("\n");
    }
}

