#include<stdio.h>
#include<string.h>

void piramide(char *texto);

int main(){
    char texto[50];
    printf("Digite um texto: ");
    gets(texto);
    piramide(texto);

}

void piramide(char *texto){

    if(texto[0]){
        piramide(++texto);
        --texto;
        printf("%s \n",texto);
    }
}
