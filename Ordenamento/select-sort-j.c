
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

*/

//declaração de bibliotecas
#include<stdio.h>
#include<stdlib.h>

#define TAM 7

void selection_sort(int num[], int tamanho) { 
//declaração de variaveis
  int i, j, min, aux;

    /*      No laço externo, na primeira iteração, o índice 
            começa de 0 e cada iteração ele soma uma unidade 
            até o final do vetor 
    */
    for (i = 0; i < (TAM-1); i++) {

      //inicializando min com o menor valor sendo o primeiro elemento do índice 'i' na primeira rodada
      min = i;
      

        //o laço mais interno percorre o vetor começando  
        //desse índice externo + 1 até o final do vetor.

        for (j = (i+1); j < TAM; j++) {

            /*  O primeiro laço o índice inicial é 0. O laço mais interno 
                começa do índice 1 (índice_inicial_externo + 1) 
                e percorre o vetor até achar o menor elemento.
            */
                if(num[j] < num[min]) {   
                min = j;
            
            /*  O elemento passa para a posição inicial do vetor 
                que na primeira iteração do laço é 0. 
            */
                }     
            
                if (i != min) {

                    aux = num[i];
                    num[i] = num[min];
                    num[min] = aux;
                }
        } /*        Ao fim do laço interno, o laço externo incrementa uma unidade, 
                    agora a posição inicial do vetor passa a ser 1
        */
  }
}

void main(){
    int num[7] = {9,7,8,1,2,0,4};
    int tamanho_de_vetor= sizeof(num)/sizeof(int);
    
    //imprimindo exibindo antes
    imprime_selectSort(num, sizeof(num)/sizeof(int)); // () (num, sizeof(TAM[0]/sizeof(int)));
    selection_sort(num,TAM);
    //imprimindo depois */
    imprime_selectSort(num, tamanho_de_vetor);
    printf("%d", tamanho_de_vetor);
}

/* 
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