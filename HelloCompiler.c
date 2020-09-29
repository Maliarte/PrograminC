/* Isto eh um comentario a proxima linha contem uma diretiva de para o pre-processador */

#include<stdio.h>
/* main eh o ponto de entrada do programa =m como _start em assembly, na vdd a funcao oculta _start chama 'main'

main devolve o 'codigo de retorno', que, por sua vez, e atribuido a chamada de sistema 'exit'

a palavra reservada void no lugar da lista de  argumentos indica que a funcao  nao aceita nenhum argumento*/

int main (void) 
{ /* uma variavel local de main sera destruida assim que main terminar */
int x = 42;
int y;
y = x - 1; /* c nao se importa com espacamentos desde que o parser seja capaz de separar os lexamos uns dos outros
/*chamando uma funcao printf padrao com tres argumentos */
printf("Ola Mundo!!! y=%d x=%d\n", y, x);

return 0;
}