/* 
 Comunicação entre criação de uma função e a diretiva global. 
 Cuidado que deve-se ter para não repetir o 'nome' da diretiva global 
 reservado o valor, ex

 #define TAM 7

 criação da função/declaração da mesma
 
 exibe(int vetor[], int tamanho); -correto

 exibe(int vetor[], int TAM); - ERROR! segundo parametro com
 o mesmo nome da diretiva, conflito.

 seria equivalente à fazer a declaração (int TAM) em qualquer
 lugar do código.

 ao invocar uma função, deve-se atentar-se a ordem da chamada, com qualquer
 valor ou nome da função

 exibe(num, 7); //chamando a funçao na main

======


Analisando Tamanho do Vetor  

Caso Geral

sizeof(num)/sizeof(int) || num/num[0]
retorna tamanho em byter do dado informado

=====

ctrl + fn + f2 - alterar variavel local
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 7
void exibeVetor(int *v, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", v[i]);
    printf("\n");
}
void selection_sort(int num[], int tamanho)
{
    // declaração de variaveis
    int i, j, min, aux;

    for (i = 0; i < (tamanho - 1); i++)
    {
        min = i;

        //j iniciando na posicao seguinte ao i
        for (j = (i + 1); j < tamanho; j++)
        {
            //achar o valor minimo
            if (num[j] < num[min])
            {
                /*      comparando o indice do segundo for com o o do primeiro
                            o index do vetor num, como sendo 'min' ou seja será  o indice de 'i' atual.*/
                min = j;
            }
        }
        //comparando o ultimo elemento percorrido em 'i' e se ele for diferente do menor valor
        //irá fazer a troca. ou seja, i ja é o menor o menor numero entre os numeros analizados
        if (i != min)
        {
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
        }
    }
}

void main()
{
    int num[] = {9, 7, 8, 1, 2, 0, 4};
    //exibindo vetor antes desordo
    exibeVetor(num, TAM);
    selection_sort(num, 7); //equivalente ao de cima
    exibeVetor(num, TAM);
}