#include <stdio.h>
#include <stdlib.h>
#include "Engine/headers.h"


void import(char *fileM, char *fileList);
void Apriori(int **mtz, int *dim, CharZao *cz);
void ini_Elementos(int *ele, int *dim);
void print_Elementos_Live(int *ele, CharZao *cz, int *dim);
int cont_Elementos_Live(int *ele, int *dim);
void vet_zeros(int *vet, int n);
void print_vet(int *ele, int n);
