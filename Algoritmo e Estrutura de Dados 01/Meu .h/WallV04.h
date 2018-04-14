#include<stdlib.h>
#include<stdio.h>

typedef struct NoTag{
	int linha, coluna;
	int valor;
	struct NoTag *direita, *abaixo;
}no;

typedef struct MatrizE{
	int m,n; //Dimensão da Matriz (M para Linha, N para coluna)
	struct NoTag *inicio, *fimLinha, *fimColuna;
}MatrizE;

//Cabeçalhos.
void Mostra(MatrizE *pmat);
void LeMatriz(MatrizE *pmat);
void CriaMatriz(MatrizE *Maux, int quantLinha, int quantColuna);
void CriaNoPrincial(MatrizE *pmat);
void InicializaLinha(MatrizE *pmat);
void InicializaColuna(MatrizE *pmat);
void ObtemDados(int *i, int *j, int *valor);
void Insere(MatrizE *pmat, int i, int j, int elem);



void LeMatriz(MatrizE *pmat){
	int quantLinha, quantColuna; //Dimensão da linha e coluna
	int opcao, i, j, valor;
	
	printf("Insira a quantidade de linhas da Matriz: ");
	scanf("%d",&quantLinha);
	
	printf("Insira a quantidade de colunas da Matriz: ");
	scanf("%d",&quantColuna);
	
	CriaMatriz(pmat, quantLinha, quantColuna);

	do{
		printf("\n1 - Insere elemento na Matriz ");
		printf("\n2 - Mostra Matriz ");
		printf("\n3 - Encerrar Programa ");
		printf("\nInsira a sua opcao: ");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				ObtemDados(&i,&j,&valor);
				Insere(pmat, i, j, valor);
				break;
			case 2: 
				Mostra(pmat);
				break;
			case 3:
				break;
			default:
				printf("Digito não valido ");
				break;
		}
	}while(opcao != 3);
}

void CriaMatriz(MatrizE *Maux, int quantLinha, int quantColuna){
	int cont;
	CriaNoPrincial(Maux);
	
	Maux->m = quantLinha;
	Maux->n = quantColuna;
	
	//Cria o esqueleto da Matriz
	for(cont = 1; cont <= quantLinha; cont++)
		InicializaLinha(Maux);
	
	for(cont = 1; cont <= quantColuna; cont++)
		InicializaColuna(Maux);
	
}

void CriaNoPrincial(MatrizE *pmat){
	no *temp;
	temp = (no *)malloc(sizeof(no));
	
	temp->linha = -1;
	temp->coluna = -1;
	
	temp->direita = temp; //Fecha o ciclo
	temp->abaixo = temp;
	
	pmat->inicio = temp;
	pmat->fimLinha = temp;
	pmat->fimColuna = pmat->fimLinha;
	
}

void InicializaLinha(MatrizE *pmat){
	no *temp;
	
	temp = (no *)malloc(sizeof(no));
	
	temp->linha = -1;
	temp->coluna = 0;
	
	pmat->fimLinha->abaixo = temp;
	pmat->fimLinha = temp;
	
	temp->abaixo = pmat->inicio; //Fecha o circulo
	temp->direita = temp;
}

void InicializaColuna(MatrizE *pmat){
	no *temp;
	
	temp = (no *)malloc(sizeof(no));
	
	temp->linha = 0;
	temp->coluna = -1;
	
	pmat->fimColuna->direita = temp;
	pmat->fimColuna = temp;
	
	temp->direita = pmat->inicio; //Fecha o circulo
	temp->abaixo = temp;
}

void ObtemDados(int *i, int *j, int *valor){
	int linha, coluna, item;
	
	printf("Digite a linha para inserir o elemento na matriz: ");
	scanf("%d",&linha);
	
	printf("Digite a coluna para inserir o elemento na matriz: ");
	scanf("%d",&coluna);
	
	printf("Digite o valor para ser inserido na matriz: ");
	scanf("%d",&item);
	
	*i = linha;
	*j = coluna;
	*valor = item;
}

void Insere(MatrizE *pmat, int i, int j, int elem){
	no *auxL; //Auxilia a percorrer as linhas
	no *auxC; //Auxilia a percorrer as colunas
	no *temp; //Ponteiro de prova
	int cont;
	//Cria um novo no
	temp = (no *)malloc(sizeof(no));
	
	temp->linha = i;
	temp->coluna = j;
	temp->valor = elem;
	
	//Percorre as linhas com auxiliar
	
	auxL = pmat->inicio->abaixo;
	
	// i - 1 pois já descolocou uma vez
	// percorre ate encontrar a linha desejada
	
	for(cont = 1; cont <= i - 1; cont++)
		auxL = auxL->abaixo;
	
	for(cont = 1; cont <= j; cont++){
		if(temp->coluna < auxL->direita->direita->coluna){
			temp->direita = auxL->direita->direita;
			auxL->direita->direita = temp;
			break;
		}else{
			if(auxL->direita->linha == -1){
				temp->direita = auxL->direita;
				auxL->direita = temp;
				break;
			}else
				auxL = auxL->direita;
		}
	}
	
	//Percorrer Coluna com um auxiliar.
	
	for(cont = 1; cont <= j - 1; cont++)
		auxC = auxC->direita;
	
	for(cont = 1; cont <= i; cont++){
		if(temp->linha < auxL->abaixo->abaixo->linha){
			temp->abaixo = auxL->abaixo->abaixo;
			auxC->abaixo->abaixo = temp;
			break;
		}else{
			if(auxC->abaixo->coluna == -1){
				temp->abaixo = auxC->abaixo;
				auxC->abaixo = temp;
				break;
			}else
				auxC = auxC->abaixo;
		}
	}
}

void Mostra(MatrizE *pmat){
	int i, j;
	no *temp;
	
	temp = pmat->inicio->abaixo;
	
	for(i = 1; i<= pmat->m; i++){
		for(j = 1; j <= pmat->n; j++){
			if(i == temp->direita->linha && j == temp->direita->coluna){
				printf("(%d,%d) Elemento: %d ",i,j,temp->direita->valor);
				temp = temp->direita;
			}else
				printf("%d ", 0);
		}
		printf("\n");
		temp = temp->direita->abaixo;
	}
}