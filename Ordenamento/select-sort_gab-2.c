/*      Faculdade de Educação Tecnologica do Estado do Rio de Janeiro.            
        Mecanismo de Ordenação por Seleção: Select Sort.    
        Fundamentos de Programação - FPR
        Docente: Marília Silva.    
        Discente: Leonardo Vianna.
            
=======================================================================================

    Descrição do algoritmo
    ______________________
    

    O programa é composto por dois laços de repetição 'for', um laço externo e outro interno. 
    O laço externo serve para controlar o índice inicial e o interno percorre todo o vetor. 

    Complexidade
    ____________

    O selection sort compara a cada interação um elemento com os outros, 
    visando encontrar o menor. Dessa forma, podemos entender que não 
    existe um melhor caso mesmo que o vetor esteja ordenado ou em ordem 
    inversa serão executados os dois laços do algoritmo, o externo e o 
    interno. A complexidade deste algoritmo será sempre O (n^2) enquanto que,
    por exemplo, os algoritmos heapsort e mergesort possuem complexidades O (nlog n).


    Vantagens
    __________

    * Ele é um algoritmo simples de ser implementado em comparação aos demais.
    * Não necessita de um vetor auxiliar (in-place).
    * Por não usar um vetor auxiliar para realizar a ordenação, ele ocupa menos memória.
    * Ele é uns dos mais velozes na ordenação de vetores de tamanhos pequenos.
 
    Desvantagens
    ____________
    * Ele é um dos mais lentos para vetores de tamanhos grandes.
    * Ele não é estável.
    * Ele faz sempre  (n^2-n)/2 comparações, independentemente do vetor estar ordenado ou não.

*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 7

void exibeVetor(int *v, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("| %d |\t", v[i]);
        printf("\n\n");
}

void selection_sort(int num[], int tamanho)
{
    // declaração de variaveis
    int i, j, min, aux;

    for (i = 0; i < (tamanho - 1); i++)
    {
        min = i;

        for (j = (i + 1); j < tamanho; j++)
        {
           
            if (num[j] < num[min])
            {
                min = j;
            }
            
        }
        // comparando o ultimo elemento percorrido em 'i' e se ele for diferente do menor valor
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

    // exibindo vetor desordenado
    exibeVetor(num, TAM);

    selection_sort(num, TAM); 

    // exibindo vetor ordenado
    exibeVetor(num, TAM);
}   