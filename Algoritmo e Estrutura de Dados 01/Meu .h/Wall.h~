#ifndef Wall ._H_INCLUDED
#define Wall ._H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#define JOINHA 1

#define ErrorFull -1
#define ErrorEmpty -2
#define MAX 100

typedef struct{
  int top;
  int vetor[MAX];
}Lista;

typedef struct{
  int top;
  int vetor[MAX];
}Stack;

typedef struct{
  int ini,top,cont;
  int vetor[MAX];
}Fila;

typedef struct{
  int top1,top2;
  int vetor[MAX];
}Stack2;

/**Funções de Pilha */
int stackFull(Stack *pStack);
int stackEmpty(Stack *pStack);
int push(Stack *pStack, int element);
int pop(Stack *pStack);
int initializeStack(Stack *pStack);
int printStack(Stack *pStack);

/**Funções de duas pilhas em uma */
int inicializar(Stack2 *pStack);
int pushStack1(Stack2 *pStack,int elemento);
int popStack1(Stack2 *pStack);
int pushStack2(Stack2 *pStack,int elemento);
int popStack2(Stack2 *pStack);
int printStack1(Stack2 *pStack1);
int printStack2(Stack2 *pStack2);

/**Funcoes de Fila */
int iniFila(Fila *pFila);
int pushFila(Fila *pFila, int element);
int popFila(Fila *pFila);
int FilaFull(Fila *pfila);
int FilaEmpty(Fila *pFila);

/** Funções de Lista */
int inserirOrdenado(Lista *pLista, int valor);
int pos_inser(int vetor[],int valor, int tamanho);
int inicializaLista(Lista *pLista);
void imprimeLista(Lista *pLista);
int inserirDesordenado(Lista *pLista,int elemento);
int PLBi(Lista *pLista, int elemento,int ini,int fim);

/** Funcoes de Pilha */
int push(Stack *pStack, int element){
  if(stackFull(pStack))
    return(ErrorFull);
  else{
    pStack->vetor[pStack->top] = element;
    pStack->top++;
    return(pStack->top);
  }
}
  
int pop(Stack *pStack){
  if(stackEmpty(pStack))
    return(ErrorEmpty);
  else
    return(pStack->top--);  
}
  
int stackFull(Stack *pStack){
  if(pStack->top == MAX)
    return(1);
  else
    return(0);  
}

int stackEmpty(Stack *pStack){
  if(pStack->top == 0)
    return(1);
  else
    return(0);
}

int initializeStack(Stack *pStack){
  pStack->top = 0;
}

int printStack(Stack *pStack){
  Stack aux; initializeStack(&aux);
  if(stackEmpty(pStack)){
    printf("Pilha Vazia!!");
  }else{
     while(!stackEmpty(pStack)){ //Desempilhando a principal e jogando na auxiliar;
       printf("%d \n",pStack->vetor[pStack->top-1]);
       push(&aux,pStack->vetor[pStack->top-1]);
       pop(pStack);
     }
     while(!stackEmpty(&aux)){
       push(pStack,aux.vetor[aux.top-1]);
       pop(&aux);
     }
  }
}

/** Funcoes de Fila */
int iniFila(Fila *pFila){
  pFila->ini = 0;
  pFila->top = 0;
  pFila->cont = 0;
  return (JOINHA);
}

int pushFila(Fila *pFila, int element){
  if(FilaFull(pFila))
    return ErrorFull;
  else{
    pFila->vetor[pFila->top] = element;
    if(pFila->top == MAX - 1)
      pFila->top = 0;
    else
      pFila->top++;
    pFila->cont++;
  }
  return(pFila->top);
}

int popFila(Fila *pFila){
  if(FilaEmpty)
    return ErrorEmpty;
  else{
    if(pFila->ini == MAX - 1)
      pFila->ini = 0;
    else
      pFila->ini++;
    pFila->cont--;
  }
  return (pFila->ini);
}

int FilaFull(Fila *pFila){
  if(pFila->cont == MAX - 1)
    return (1);
  else
    return(0);  
}

int FilaEmpty(Fila *pFila){
  if(pFila->cont == 0)
    return (1);
  else
    return (0); 
}

/**Funcoes de Lista Ordenada */
int pos_inser(int vetor[],int valor, int top){
    int i;
    for(i = 0; (valor>vetor[i])&&(i<top); i++);
    return i;
}

int inserirOrdenado(Lista *pLista, int valor){
    int i = pLista->top;
    int j;

    if(i != MAX){
        if(i == 0){
            pLista->vetor[i] = valor;
        }else{
            for(j = i; j>pos_inser(pLista->vetor,valor,i); j--){
                    pLista->vetor[j] = pLista->vetor[j-1];
            }
            pLista->vetor[pos_inser(pLista->vetor,valor,i)] = valor;
        }
    }else{
        return -1;
    }
    pLista->top++;
    return pLista->top;
}

int inicializaLista(Lista *pLista){
  pLista->top = 0;
}

void imprimeLista(Lista *pLista){
    int i;
    for(i = 0; i<pLista->top; i++){
        printf("%d \n", pLista->vetor[i]);
    }
    printf("\n\n");
}

int inserirDesordenado(Lista *pLista,int elemento){
   pLista->vetor[pLista->top] = elemento;
   pLista->top++;
}

int PLBi(Lista *pLista, int elemento,int ini, int fim){
  int meio = (ini+fim)/2;
  if(ini == fim)
    return (-1);
  if(pLista->vetor[meio]==elemento)
     return(meio);
  if(elemento>pLista->vetor[meio])
     return(PLBi(pLista,elemento,meio+1,fim));
  if(elemento< pLista->vetor[meio])
     return(PLBi(pLista,elemento,ini,meio-1));
}

/**Funções de Pilha Dupla em uma unica */
int inicializar(Stack2 *pStack){
  pStack->top1 = 0;
  pStack->top2 = MAX-1;
}

int pushStack1(Stack2 *pStack,int elemento){
  if(pStack->top1>pStack->top2)
    return(-1);
  else{
    pStack->vetor[pStack->top1] = elemento;
    pStack->top1++;
    return(pStack->top1);
  }
}

int popStack1(Stack2 *pStack){
  if(pStack->top1 == 0)
    return(-1);
  else{
    pStack->top1--;
    return(pStack->top1);
  }
}

int pushStack2(Stack2 *pStack,int elemento){
  if(pStack->top2 < pStack->top1)
    return(-1);
  else{
    pStack->vetor[pStack->top2] = elemento;
    pStack->top2--;
    return(pStack->top2);
  }
}

int popStack2(Stack2 *pStack){
  if(pStack->top2 == MAX-1)
    return(-1);
  else{
    pStack->top2++;
    return(pStack->top2);
  }
}


int printStack1(Stack2 *pStack1){
  Stack aux; initializeStack(&aux);
  if(pStack1->top1 == 0)
    printf("Pilha Vazia!!!");
  else{
    while(pStack1->top1 != 0){
      printf("%d \n",pStack1->vetor[pStack1->top1 - 1]);
      push(&aux,pStack1->vetor[pStack1->top1 - 1]);
      popStack1(pStack1);
    }
    while(aux.top != 0){
      pushStack1(pStack1,aux.vetor[aux.top - 1]);
      pop(&aux);
    }
  }
}

int printStack2(Stack2 *pStack2){
  Stack aux; initializeStack(&aux);
  if(pStack2->top2 == MAX - 1)
    printf("Pilha Vazia!!!");
  else{
    while(pStack2->top2 != MAX - 1){
      printf("%d \n",pStack2->vetor[pStack2->top2 + 1]);
      push(&aux,pStack2->vetor[pStack2->top2 + 1]);
      popStack2(pStack2);
    }
    while(aux.top != 0){
      pushStack2(pStack2,aux.vetor[aux.top - 1]);
      pop(&aux);
    }
  }
}

#endif
