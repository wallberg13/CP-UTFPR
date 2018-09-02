/**Usando como base as funções de matriz esparsa 
 * baseada em vetores implementadas na semana passada:

- implemente a função double consulta_matriz(descr_matriz *matriz, int x, int y) //Concluido
- implemente a função void exclui_matriz(descr_matriz *matriz, int x, int y)

Faça um programa que crie duas matrizes esparsas 
colocando 100 valores double aleatórios em 100 posições 
aleatórias em cada uma, e em seguida produza uma terceira matriz com a soma das outras duas.

Cada posição da matriz C deve conter a soma a soma do conteúdo das matrizes A e B na mesma posição.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct NoTag{
	double info;
	int i,j; //i -> Linha e j ->Coluna =====>LOCALIZAÇÂO DO DADO NA MATRIZ E
	struct NoTag *abaixo, *direita;
}no;

typedef struct{
	no *inicio,*ult_col, *ult_lin;
	int m,n; //M -> Linha e N -> Coluna =====>ESQUELETO DA MATRIZ E
	int k;
}Me;

/** CABECALHOS DAS FUNCOES*/
void inicializa_matriz(Me *me, int m, int n); //Inicializa o cabeçalho da matriz
void inicializa_linha(Me *me); //Inicializa a Linha
void inicializa_coluna(Me *me); //Inicializa a Coluna
void no_principal(Me *me);
int adiciona_elemento(Me *me, int i, int j, double ele);
void mostrar_matriz(Me *me);
double consulta_matriz(Me *me, int i, int j);
void excluir_elemento_matriz(Me *me, int i, int j);
void sorteio_posicoes(Me *me);
void sorteio_posicoes_quick(Me *me);
int soma_matriz(Me *me1, Me *me2, Me *me3);

/** FUNCOES */
void inicializa_matriz(Me *me, int m, int n){
	me->k = 0;
	
	no_principal(me);
	
	me->m = m;
	me->n = n;
	
	for(int cont = 1; cont <= m; cont++)
		inicializa_linha(me);
	
	for(int cont = 1; cont <= n; cont++)
		inicializa_coluna(me);
	
	printf("Joinha \n\n");
	
}

void no_principal(Me *me){
	no *aux;
	aux = (no *)malloc(sizeof(no));
	
	aux->i = -1;
	aux->j = -1;
	
	aux->abaixo = aux;
	aux->direita = aux;
	
	me->inicio = aux;
	me->ult_col = aux;
	me->ult_lin = aux;
	
	me->k++;

}

void inicializa_linha(Me *me){
	no *aux;
	
	aux = (no *)malloc(sizeof(no));
	
	aux->i = -1;
	aux->j = 0;
	
	me->ult_lin->abaixo = aux;
	me->ult_lin = aux;
	
	aux->abaixo = me->inicio;
	aux->direita = aux;
	
	me->k++;
}

void inicializa_coluna(Me *me){
	no *aux;
	
	aux = (no *)malloc(sizeof(no));
	
	aux->i = 0;
	aux->j = -1;
	
	me->ult_col->direita = aux;
	me->ult_col = aux;
	
	aux->direita = me->inicio;
	aux->abaixo = aux;
	
	me->k++;
}

int adiciona_elemento(Me *me, int i, int j, double ele){
	no *aux, *lin, *col, *aux1, *aux2;
	aux = (no *)malloc(sizeof(no));
	
	if(i > me->m || j > me->n || i == 0 || j == 0)
		return -1;
	
	aux->i = i;
	aux->j = j;
	aux->info = ele;
	
	//ADICIONANDO NA COLUNA CERTA
	lin = me->inicio->abaixo;
	for(int cont = 1; cont <= i - 1;cont++)
		lin = lin->abaixo;
	
	if(lin->direita == lin){
		lin->direita = aux;
		aux->direita = lin;
	}else{
		aux1 = lin->direita; //VAI ATUALIZAR OS PONTEIROS DA DIREITA
		aux2 = NULL;
		while(j >= aux1->j){
			aux2 = aux1;
			aux1 = aux1->direita;
			if(aux1 == lin)
				break;
		}
		if(aux2 == NULL){ //ESTA LOGO DEPOIS DE LINHA E ANTES DO AUX
			lin->direita = aux;
			aux->direita = aux1;
		}else{
			if(aux1 == lin){ //NECESSIDADE DE ALTERAR O FIM DA COLUNA
				aux2->direita = aux;
				aux->direita = aux1;
			}else{//ADDICIONA ENTRE DOIS PONTEIROS
				aux2->direita = aux;
				aux->direita = aux1;
			}
		}
	}
	
	//ADICIONNDO LINHA CERTA
	col = me->inicio->direita;
	for(int cont = 1; cont <= j - 1; cont++)
		col = col->direita;
	
	if(col->abaixo = col){
		col->abaixo = aux;
		aux->abaixo = col;
	}else{
		aux1 = col->abaixo;
		aux2 = NULL;
		while(i >= aux1->i){
			aux2 = aux1;
			aux1 = aux1->abaixo;
			if(aux1 == col)
				break;
		}
		if(aux2 == NULL){
			lin->abaixo = aux1;
			aux->direita = aux1;
		}else{
			if(aux1 == col){
				aux2->abaixo = aux;
				aux->abaixo = aux1;
			}else{
				aux2->abaixo = aux;
				aux->abaixo = aux1;
			}
		}
	}
}

void mostrar_matriz(Me *pmat){
	int i, j;
	no *temp;
	
	temp = pmat->inicio->abaixo;
	
	for(i = 1; i<= pmat->m; i++){
		for(j = 1; j <= pmat->n; j++){
			if(i == temp->direita->i && j == temp->direita->j){
				printf("%.2f \t",temp->direita->info);
				temp = temp->direita;
			}else
				printf("0.0 \t");
		}
		printf("\n");
		temp = temp->direita->abaixo;
	}
}

/**
 * Retorna 0 para não encontrar ou NaN, e o valor caso encontrar
 */
double consulta_matriz(Me *me, int i, int j){
	no *aux, *lin;
	
	if(i > me->m || j > me->n)
		return 0;
		
	lin = me->inicio->abaixo;
	for(int cont = 1; cont < i; cont++)
		lin = lin->abaixo;
	
	aux = lin->direita;
	while(aux != lin){
		if(aux->i == i && aux->j == j)
			break;
		else
			aux = aux->direita;
	}
	if(aux == lin)
		return 0;
	else
		return aux->info;	
}

/**
 * Excluir os elementos da matriz, só se ele elemento existir na matriz, se ele não existir,
 * a função não faz nada.
 */
void excluir_elemento_matriz(Me *me, int i, int j){
	no *col, *lin, *aux1, *aux2, *aux;
	
	if(consulta_matriz(me,i,j)){
		
		lin = me->inicio->abaixo;
		for(int cont = 1; cont < i; cont++)
			lin = lin->abaixo;
		
		if(lin->direita->direita == col && lin->direita->i == i && lin->direita->j == j){
			aux = lin->direita;
			lin->direita = lin;
		}else{
			aux1 = lin->direita;
			aux2 = lin;
			
			while(aux1 != lin){
				if((aux1->j == j)&&(aux1->i == i)){
					aux = aux1; //ONDE ESTA O QUE EU QUERO EXCLUIR, SÓ PRECISA SER SELECIONADO UMA VEZ
					aux1 = aux->direita; //AQUI ELE VAI FOI ENCONTRADO, LÁ NA FRENTE NÃO SERA PRECISO;
					break;
				}else{
					aux2 = aux1;
					aux1 = aux1->direita;
				}
			}
			if(aux2 == lin)
				lin->direita = aux1;
			else
				aux2->direita = aux1;
		}
		
		col = me->inicio->direita;
		for(int cont = 1; cont < j; cont++)
			col = lin->direita;
		
		if(col->abaixo->abaixo == col && col->abaixo->i == i && col->abaixo->j == j){
			col->abaixo = col;
		}else{
			aux1 = col->abaixo;
			aux2 = col;
			while(aux1 != col){
				if((aux1->j == j)&&(aux1->i == i)){
					aux1 = aux->abaixo;
					break;
				}else{
					aux2 = aux1;
					aux1 = aux1->abaixo;
				}
			}
			if(aux2 == col)
				col->abaixo = aux1;
			else
				aux2->abaixo = aux1;
		}
		free(aux);
	}	
}

int foi = 0;

void sorteio_posicoes(Me *me){ 
	int i, j, cont = 0; //Posições a ser sorteada;
	double ele;
	
	if(!foi){
		srand(time(NULL));
		foi = 1;
	}
	if((me->m)*(me->n) >= 100){
		while(cont < 100){
			i = 1 + rand()%(me->m);
			j = 1 + rand()%(me->n);
			if(!consulta_matriz(me,i,j)){
				ele = 1 + rand()%100/100.0;
				//printf("%.2f %d \n", ele, cont);
				cont++;
				adiciona_elemento(me,i,j,ele);
			}
		}
	}
}

/**
 * Soma duas matriz em uma 3° com os elementos de soma; 
 * pode ser feito isso de forma automatica;
 * */
int soma_matriz(Me *me1, Me *me2, Me *me3){
	int i, j;
	
	if(me1->m == me2->m && me2->m == me3->m && me1->n == me2->n && me2->n == me3->n){
		for(i = 1; i <= me1->m; i++){
			for(j = 1; j <= me1->n; j++){
				double k = consulta_matriz(me1,i,j)+consulta_matriz(me2,i,j);
				if(k != 0.0)
					adiciona_elemento(me3,i,j,k);
			}
		}
	}else{
		return -1;
	}
	
}

#endif //FUNCOES_H
