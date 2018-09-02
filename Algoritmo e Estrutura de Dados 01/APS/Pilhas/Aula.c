#include<stdio.h>
#include<stdlib.h>

#define ErrorFull -1
#define ErrorEmpty -2
#define MAX_STACK 100

typedef struct{
  int top;
  int vetor[MAX_STACK];
}Stack;

int stackFull(Stack *pStack);
int stackEmpty(Stack *pStack);
int push(Stack *pStack, int element);
int pop(Stack *pStack);
int initializeStack(Stack *pStack);
int printStack(Stack *pStack, int top);


int main(){
  Stack stack;
  initializeStack(&stack);
  
  push(&stack, 1);
  push(&stack, 5);
  push(&stack, 4);
  push(&stack, 2);
  push(&stack, 15);
  push(&stack, 13);
  printStack(&stack,stack.top);
  return 0;
}

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
  if(pStack->top == MAX_STACK)
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

int printStack(Stack *pStack, int top){
  pop(pStack);
  printf("%d \n", );
  printStack()
}