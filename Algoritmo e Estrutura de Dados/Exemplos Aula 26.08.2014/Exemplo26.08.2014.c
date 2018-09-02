#include<stdio.h>
#include<stdlib.h>

int digita(char *mensagem){
	int valor;
	printf(mensagem);
	scanf("%d",&valor);
	return valor;
}

int calcula_diferenca(int idade1, int idade2){
	return idade1 - idade2;
}

int main(){
	printf("Sua mãe tinha %d anos quando voce nasceu !! \n",
	calcula_diferenca(digita("Idade de sua Mãe: "),digita("Sua idade: ")));
	return 0;
}

