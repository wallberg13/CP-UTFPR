/*Escreva um programa fazendo o uso de struct. 
 * Voce devera criar uma struct chamada Ponto,
 * contendo apenas a posicao x e y (inteiros) do ponto. 
 * Declare 2 pontos, leia a posicao (coordenadas x e y) de 
 * cada um e calcule a distancia entre eles. 
 * Apresente no final a distancia entre os dois pontos.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
  int x, y;
}Ponto;

float distancia(Ponto *p1, Ponto *p2){
  return sqrt(pow(p1->x - p2->x,2) + pow(p1->y - p2->y,2));
}