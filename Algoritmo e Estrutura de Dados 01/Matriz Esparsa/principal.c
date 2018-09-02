#include <stdio.h>
#include "listaesparsa.h"
#include <time.h>
#include <stdlib.h>

double chute(){
	return rand()/100.0;
}

int main(){
	srand(time(NULL));
	descr_matriz matriz;
	inicializa_matriz(&matriz);
}
