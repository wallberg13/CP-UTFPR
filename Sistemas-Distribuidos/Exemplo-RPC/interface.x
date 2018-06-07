/* 
Esta interface deve ser compilada com o rpcgen

rpcgen interface.x

ou
rpcgen -a -C interface.x (gera esqueletos para cliente e servidor)

*/


/*0x20000000 - 0x3fffffff - numeros definidos pelo usuario 
Existem alguns numeros de programas ja' reservados. Deve-se usar
somente um numero nao reservado
*/
#define PROGRAM_NUMBER 0x20001234

#define VERSION_NUMBER 1

/*estutura que será passa pelo RPC*/
struct operandos{
  int a;
  int b;
};

/* interface com os procedimentos que serão oferecidos aos clientes */
program SOMASUB_PROG{
  version SOMASUB_VERSION{
     int SOMA (operandos) = 1;
     int SUB (operandos) = 2;
   } = VERSION_NUMBER;
} = PROGRAM_NUMBER;
