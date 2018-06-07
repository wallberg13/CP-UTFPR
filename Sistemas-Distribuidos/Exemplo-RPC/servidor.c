/* 
 **** Servidor RPC ****

Para compilar: 
gcc servidor.c interface_svc.c  interface_xdr.c -o servidor -lnsl

*/

#include <stdio.h>
#include "interface.h"

/* implementação da função soma */
int * soma_1_svc (operandos *argp, struct svc_req *rqstp){
   static int result;

   printf ("Recebi chamado: soma %d %d\n", argp->a, argp->b);
   result = argp->a + argp->b;
   return (&result);
}

/* implementação da função sub */
int * sub_1_svc (operandos *argp, struct svc_req *rqstp){
   static int result;

   printf ("Recebi chamado: sub %d %d\n", argp->a, argp->b);
   result = argp->a - argp->b;
   return (&result);
}
