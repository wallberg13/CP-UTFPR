#include<stdio.h>

int potencia(int x, int n);

int main(){
    int x,n;
    printf("Digite um numero: ");
    scanf("%d",&x);
    printf("Digite a potencia: ");
    scanf("%d",&n);



    printf("Pontecia: %d", potencia(x,n));

    return 0;
}

int potencia(int x, int n){
    if(n==1)
        return x;
    else
        return x*potencia(x,--n);
}
