/* 
          FPR - Fundamentos de Programação
          Marília Silva | https://maliarte.com.br

* Apoie o projeto de educação tecnológica no Brasil 
* deixe uma estrela e saiba mais no instagram 

            @maliartemar @barbarostecnologis	

Caractere mais importante para sting é o  'barra 0' -> lê-se "\0"

int vetor[30]; 0...29
char vet[30] 0..29 mas diferente do vetor de outro tipo não será ocupado
espaço da memória após \0

ex: char vetor[7] - capacidade de caracteres

| c | a  | r | l  | o | s | \0 |
  0   1    2   3    4   5   6

  oq efetivamente guardou: 

  6 caracteres

                                29/09/2021

                                  STRINGS

    Exemplo 1: Determinar o número de caracteres de uma string.

*/


//importação de bibliotecas

#include <stdio.h>

#include <string.h>


//declaração de protótipos

int quantidadeCaracteres (char str[]);


//main

void main ()

{

    //declaração de variáveis

    char palavra[30];

    int quant;

    

    //lendo a palavra

    fflush (stdin);

    printf ("Entre com uma palavra: ");

    gets (palavra);  //get string - lê uma string, independente do tamanho e dos caracteres que a compõem

    

    //chamando a função

    quant = quantidadeCaracteres (palavra);

    

    //exibindo o resultado

    printf ("\nA palavra %s possui %d caracteres.", palavra, quant);    

}


//implementação das funções

int quantidadeCaracteres (char str[])

{

    //declaração de variáveis

    int i, cont = 0;

    for (i=0;str[i]!='\0';i++)

    {
        cont++;
    }

    //retornando o resultado
    return cont;

}