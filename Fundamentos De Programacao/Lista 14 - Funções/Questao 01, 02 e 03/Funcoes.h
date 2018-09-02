long fatorial(int num){
    int fat, i;

    fat = 1;
    for (i = 0;i<=num;i++){
        if (i != 0)
            fat *= i;
    }
    return fat;
}

int combinacaoSimples(int n,int p){ //Questão 01
    if((n - p)>=0)
        return fatorial(n)/(fatorial(p)*fatorial(n-p));
    else
        return 0;
}


