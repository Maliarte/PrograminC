/*2) Faça um programa que obtenha do teclado a quantidade N de valores a serem sorteados
entre 0 e 100. Seu programa deve exibir, para cada número sorteado, se ele está dentro
ou fora do intervalo [1..15]
I. Número sorteado está dentro ou fora do intervalo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

 int main (void){
     int resp, num, i = 0;
     
     setlocale (LC_ALL, "Portuguese");
     printf ("Digite a quantidade de números, de 0 a 100, a serem sorteados: ");
     scanf ("%d", &resp);
     srand (time (NULL));
     
      while ( i < resp){
          num = rand() % 101;
          printf ("Número sorteado: %d ", num);
          if (num == 0 || num > 15) printf ("[número fora do intervalo]\n");
          else printf ("[número dentro do intervalo]\n");
          i = i + 1;
      }
      return 0;
 } 
 
      
//II. Quantos sorteados caíram dentro do intervalo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

 int main (void){
     int resp, num, i = 0, contador = 0;
     
     setlocale (LC_ALL, "Portuguese");
     printf ("Digite a quantidade de números, de 0 a 100, a serem sorteados: ");
     scanf ("%d", &resp);
     srand (time (NULL));
     
      while ( i < resp){
          num = rand() % 101;
          printf ("Número sorteado: %d ", num);
          if (num == 0 || num > 15) printf ("[número fora do intervalo]\n");
          else { 
              printf ("[número dentro do intervalo]\n");
              contador = contador + 1;
          }
          i = i + 1;
      }
     printf ("Total de números dentro do intervalo: %d", contador);
      return 0;
 }
 
//III. Qual a Soma de todos os números sorteados?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

 int main (void){
     int resp, num, i = 0, soma = 0;
     
     setlocale (LC_ALL, "Portuguese");
     printf ("Digite a quantidade de números, de 0 a 100, a serem sorteados: ");
     scanf ("%d", &resp);
     srand (time (NULL));
     
      while ( i < resp){
          num = rand() % 101;
          printf ("Número sorteado: %d ", num);
          if (num == 0 || num > 15) printf ("[número fora do intervalo]\n");
          else  printf ("[número dentro do intervalo]\n");
          i = i + 1;
          soma = soma + num;
      }
      printf ("\nSoma dos números sorteados: %d", soma);
      return 0;
 }
 
// Qual o Valor médio dos números sorteados

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

 int main (void){
     int resp, num, i = 0, soma = 0, valorMedio;
     
     setlocale (LC_ALL, "Portuguese");
     printf ("Digite a quantidade de números, de 0 a 100, a serem sorteados: ");
     scanf ("%d", &resp);
     srand (time (NULL));
     
      while ( i < resp){
          num = rand() % 101;
          printf ("Número sorteado: %d ", num);
          if (num == 0 || num > 15) printf ("[número fora do intervalo]\n");
          else  printf ("[número dentro do intervalo]\n");
          i = i + 1;
          soma = soma + num;
          valorMedio = soma / resp;
      }
      printf ("\nValor médio dos números sorteados: %d", valorMedio);
      return 0;
 }
 
//V. Qual o Valor médio dos números sorteados fora do intervalo?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

 int main (void){
     int resp, num, i = 0, soma = 0, valorMedio, contador = 0;
     
     setlocale (LC_ALL, "Portuguese");
     printf ("Digite a quantidade de números, de 0 a 100, a serem sorteados: ");
     scanf ("%d", &resp);
     srand (time (NULL));
     
      while ( i < resp){
          num = rand() % 101;
          printf ("Número sorteado: %d ", num);
          if (num == 0 || num > 15){ 
          printf ("[número fora do intervalo]\n");
          soma = soma + num;
          contador = contador + 1;
          } else  printf ("[número dentro do intervalo]\n");
          i = i + 1;
      }
      valorMedio = soma / contador;
      printf ("\nValor médio dos números sorteados fora do intervalo: %d", valorMedio);
      return 0;
 }
 */
 
 
 
      
 