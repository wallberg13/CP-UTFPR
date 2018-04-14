struct rgAluno{
    char nome[35];
    float nota1;
    float nota2;
    float trabalho;
};

struct rgAluno aluno;

int main(void){
    float media;
    printf("Nome do Aluno: ");
    scanf("%[^\n]s",aluno.nome);
    printf("Nota 1o. Bimestre: ");
    scanf("%f", &aluno.nota1);
    printf("Nota 2o. Bimestre: ");
    scanf("%f", &aluno.nota2);
    printf("Nota do trabalho de struct: ");
    scanf("%f", &aluno.trabalho);

    printf("A media é %.2f",aluno.nota1*0.35 + aluno.nota2*0.55 + aluno.trabalho*0.1);

}
