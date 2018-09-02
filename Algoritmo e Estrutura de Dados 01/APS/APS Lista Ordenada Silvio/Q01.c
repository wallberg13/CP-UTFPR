/**Inicializa a lista;
Inserir um elemento na lista;
Remover um elemento da lista (passado por parâmetro o elemento);
Remover um elemento da lista (passado por parâmetro a posição);
Exibir os elementos da lista;
Pesquisar por um elemento especificado pelo usuário.
Para isso você deve utilizar a seguinte estrutura:
*/
#include<stdio.h>
#define max 100

typedef struct{
    int ultimo;
    int vetor[max];
}tipo1;

void inicializa(tipo1 *p_tipo);
int inserir(tipo1 *p_tipo, int valor);
int pos_inser(int vetor[],int valor, int tamanho);
void imprimeTipo1(tipo1 *p_tipo1);
int RemoverPorElemento(tipo1 *p_tipo, int valor);
int PBRecursiva(int vetor[], int valor, int ultimo, int ini);



int main(void){
    tipo1 Tipo1;
    int i;
    inicializa(&Tipo1);

    for(int j = 0; j<10; j++){
        printf("Digite um valor: ");
        scanf("%d",&i);
        inserir(&Tipo1, i);
    }
    
    imprimeTipo1(&Tipo1);
    int p;
    printf("Faça uma pesquisa: ");
    scanf("%d",&p);
    printf("Posição: %d \n",PBRecursiva(Tipo1.vetor, p, Tipo1.ultimo, 0));
}

void inicializa(tipo1 *p_tipo){
    (*p_tipo).ultimo = 0;
}

int pos_inser(int vetor[],int valor, int ultimo){
    int i;
    for(i = 0; (valor>vetor[i])&&(i<ultimo); i++);
    return i;
}

int inserir(tipo1 *p_tipo, int valor){
    int i = (*p_tipo).ultimo;
    int j;

    if(i != max){
        if(i == 0){
            p_tipo->vetor[i] = valor;
        }else{
            for(j = i; j>pos_inser((*p_tipo).vetor,valor,i); j--){
                    p_tipo->vetor[j] = (*p_tipo).vetor[j-1];
            }
            (*p_tipo).vetor[pos_inser((*p_tipo).vetor,valor,i)] = valor;
        }
    }else{
        return -1;
    }
    (*p_tipo).ultimo++;
    return (*p_tipo).ultimo;
}

void imprimeTipo1(tipo1 *p_tipo){
    int i;
    for(i = 0; i<p_tipo->ultimo; i++){
        printf("%d \n", (*p_tipo).vetor[i]);
    }
    printf("\n\n");
}

int RemoverPorElemento(tipo1 *p_tipo, int valor){
    int i = PBRecursiva(p_tipo->vetor, valor, p_tipo->ultimo, 0);
    return i;
}

int PBRecursiva(int vetor[], int valor, int ultimo, int ini){
  int i = ini,f = ultimo, m = (i + f)/2;
  
  if(i > f)
    return -1;
  
  if(vetor[m]==valor){
    return m;
  }
  if(valor>vetor[m]){
    return PBRecursiva(vetor,valor,ultimo,m+1);
  }
  if(valor<vetor[m]){
    return PBRecursiva(vetor,valor,m-1,i);
  } 
}








