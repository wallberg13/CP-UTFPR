#include<stdio.h>

#define max 100

typedef struct{
  char text[max];
  int top;  
}pilha;

void inicializa(pilha *p){
  p->top = -1;
}

char add_pilha(pilha *p, char c){
  
  if(p->top == max - 1)
    return '0';
  p->top++;
  p->text[p->top] = c;
  return c;
  
}

int vazia(pilha *p){
  if(p->top == -1)
    return 1;
  else
    return 0;
}

char rem_pilha(pilha *p){
  char c = p->text[p->top];
  if(vazia(p))
    return '0';
  
  p->top--;
  return c;
}

int trata_palavras(char *texto){
  pilha p;
  int i = 0;
  inicializa(&p);
  
  while((texto[i] != '.')&&(texto[i] != '\0')){
    if(texto[i] != ' '){
      add_pilha(&p,texto[i]);
    }else{
      while(!vazia(&p))
	printf("%c",rem_pilha(&p));
      printf(" ");
    }
    i++;
  }
  while(!vazia(&p))
	printf("%c",rem_pilha(&p));
  printf(".");
  printf("\n");
  
}
