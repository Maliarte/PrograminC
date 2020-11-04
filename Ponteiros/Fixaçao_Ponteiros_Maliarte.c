/* Estudo detalhado utilizando ponteiros na linguagem C desenvolvido por Marília Silva  em quatro de Novembro de 2020.

Todos os direitos compartilhados no repositório externo da mesma em: github/@maliarte

https://maliarte.com.br
 */
 
#include <stdio.h>
void endereco_como_parametro(int* pa, int* pb, int* pacesso) {
(*pa)++;
(*pb)++;
(*pacesso)++;
return;
}
int main(void) {
  int a=2, b=3, acesso=3;
  char c = '@';
  char *p2;
  int*p1= &a; int* p3 = &a; //um endereço que um ptr armazena eh sempre de um tipo específico.
  (*p1)=30; /*ponteiro entre parenteses quer ser modificado, atribuimos o valor 30, logo no lugar de a=2 teremos 30 
  
  E se quisermos ter acesso à região de memória apontada pelo ponteiro?*/
  (*p3)=2;
  acesso = (*p3)*4;
  printf("Acesso \na região de memoria apontada: %d\n\n", acesso);

  printf("Hello World Barbaros Tecnológicos!!! \nA variável do tipo ponteiro aponta o endereço. \nE pode também alterar o valor da Variável! \nVeja RAM que te vejo e sei seu endereço: %p\n", p1);

p1 = &a;
p2 = &c;   

/* Atribuição  de valor ao Ponteiro precisa ser um endereço

Operador Unário '&' endereço de

especificador formato '%p || %x
*/

printf("\n\n1.exibe: %p", p1);
 
 //por que o valor de uma variavel char é 40 e não '@'?
printf("\n\n2.exibe: %p", p2);

/* Para Alterar o valor da variável ponteiro temos: */


printf("\n\nO valor alterado do ponteiro  é \n%i",a); 

endereco_como_parametro(&a, &b, &acesso);

printf("\n\nPassagem de endereço como parâmetro de funções\npermite compartilhar variaveis\n\npermite que uma funçao produza mais de um valor...valores na main.... %d, %d e %d", a, b, acesso);
  return 0;
}