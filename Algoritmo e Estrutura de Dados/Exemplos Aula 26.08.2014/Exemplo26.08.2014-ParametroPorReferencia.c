#include<stdio.h>

void troca(int *um, int *outro){
    int aux;
    aux = *um;
    *um = *outro;
    *outro = aux;
}

int main(){
    //asdas
    int a = 3;
    int b = 17;

    printf("A = %d ,B = %d \n",a,b);
	troca(&a,&b);
	printf("A = %d ,B = %d \n",a,b);
	return 0;
}
