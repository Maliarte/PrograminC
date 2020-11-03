/* Este operador permite saber o número de bytes ocupado por um determinado tipo de variável. É muito usado na alocação dinâmica de memória.

Sintaxe:

sizeof(tipo);

Exemplo:

A expressão sizeof(float) retorna o número de bytes ocupado por um float.

Como o operador sizeof retorna um valor inteiro podemos visualizar esse valor usando %d.

É possível também utilizar este operador aplicando-o a uma expressão.
*/
#include <stdio.h>

int main(void)
{
  float vteste;
  
  printf(" --- TIPO ---|--- BYTES ---\n");
  printf(" char .......: %li bytes\n", sizeof(char));
  printf(" short.......: %li bytes\n", sizeof(short));
  printf(" int.........: %li bytes\n", sizeof(int));
  printf(" long........: %li bytes\n", sizeof(long));
  printf(" float ......: %li bytes\n", sizeof(float));
  printf(" double......: %li bytes\n", sizeof(double));
  printf(" long double.: %li bytes\n\n", sizeof(long double));
  printf("\nO tamanho de vteste e...: %li \n\n",sizeof vteste);
  //calculando tamanho de vetores
  int vetor[10];
  printf("O tamanho do vetor é %li bytes ", sizeof(vetor));
  return 0;
}
 
