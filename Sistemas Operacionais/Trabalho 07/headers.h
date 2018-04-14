#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

#define READ 0
#define WRITE 1
#define max_tam 20
#define n_consumidores 2
#define n_produtores 2
