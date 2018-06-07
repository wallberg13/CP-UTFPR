/* 
 **** Cliente RPC ****
Para compilar:

gcc cliente.c interface_clnt.c interface_xdr.c -o cliente -lnsl

*/

#include <stdio.h>
#include "interface.h"

/* função que chama a RPC soma_1 */
int soma (CLIENT *clnt, int a, int b)
{
   operandos ops;
   int *resultado;

   /* junta os parâmetros em um struct */
   ops.a = a;
   ops.b = b;

   /* chama a função remota */
   resultado = soma_1 (&ops,clnt);
   if (resultado == NULL)
   {
     printf ("Problemas ao chamar a função remota\n");
     exit (1);
   }

   return (*resultado);
}

/* função que chama a RPC sub_1 */
int sub (CLIENT *clnt, int x, int y)
{
   operandos ops;
   int *resultado;

   /* junta os parâmetros em um struct */
   ops.a = x;
   ops.b = y;

   /* chama a função remota */
   resultado = sub_1 (&ops,clnt);
   if (resultado == NULL)
   {
      printf ("Problemas ao chamar a função remota\n");
      exit (1);
   }
   return (*resultado);
}

int main( int argc, char *argv[])
{
   CLIENT *clnt;
   int x,y;

   /* verifica se o cliente foi chamado corretamente */
   if (argc!=4)
   {
      fprintf (stderr,"Sintaxe: %s hostname operando1 operando2\n",argv[0]);
      exit (1);
   }

   /* cria uma struct CLIENT que referencia uma interface RPC */
   clnt = clnt_create (argv[1], SOMASUB_PROG, SOMASUB_VERSION, "udp");

   /* verifica se a referência foi criada */
   if (clnt == (CLIENT *) NULL)
   {
      clnt_pcreateerror (argv[1]);
      exit(1);
   }

   /* obtém os dois inteiros que serão passados via RPC */
   x = atoi (argv[2]);
   y = atoi (argv[3]);

   /* executa os procedimentos remotos */
   printf ("%d + %d = %d\n", x, y, soma (clnt,x,y));
   printf ("%d - %d = %d\n", x, y, sub (clnt,x,y));

   return (0);
}
