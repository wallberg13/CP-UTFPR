/**Gerar um vetor de inteiros com 15 elementos. Gerar outros dois vetores um contendo
os valores pares e outro os ímpares. Fazer incialmente a representação gráfica do
conteúdo dos vetores:
*/

#include<stdio.h>

int main(){
    int impar, par, v[14], i;

    for(i = 0, impar = 0, par = 0; i<15; i++){
        printf("Digite o %d° numero do vetor: ",i+1);
        scanf("%d",&v[i]);

        if(v[i]%2==0)
            par++;
        else
            impar++;

    }

    int imp[impar];
    int p[par];
    int j = 0, k = 0;;

    for(i = 0; i < 15; i++){
        if(v[i]%2==0){
            p[j] = v[i];
            j++;
        }
        if(v[i]%2 != 0){
            imp[k] = v[i];
            k++;
        }
    }

    printf("Vetor Normal!!!\n");
    for(i = 0; i < 15; i++){
        printf("%d ",v[i]);
    }
    printf("\nVetor com os numeros Pares!!\n");
    for(i = 0; i < par; i++){
        printf("%d ",p[i]);
    }
    printf("\nVetor com os numeros Impares!!\n");
    for(i = 0; i < impar; i++){
        printf("%d ",imp[i]);
    }

}

