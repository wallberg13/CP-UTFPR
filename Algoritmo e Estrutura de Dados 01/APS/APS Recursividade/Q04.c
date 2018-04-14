#include<stdio.h>

int fibo(int n);

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("%d",fibo(n));

}


int fibo(int n){
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}
