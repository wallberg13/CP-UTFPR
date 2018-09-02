#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int i[90000], j;

    srand(time(NULL));
    for (j=0;j<=90000;j++){
        i[j] = 1 + rand()%1000;
        printf("%d \n",i[j]);
    }


}
