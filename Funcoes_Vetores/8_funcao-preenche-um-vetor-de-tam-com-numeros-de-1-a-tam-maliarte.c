/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
    
	
	Revisão: funções + vetores
	
    Desenvolver uma função que preencha um vetor de tamanho TAM 
    com os números de 1 a TAM.
*/

//importação de bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//declaração de constantes
#define TAM 1000

//protótipos de funções
void preencher(int vetor[], int quant);
void exibir(int vetor[], int quant);

//main
void main()
{
    //declaração de variáveis
    int v[TAM];

    //preenchendo o vetor e exibindo o vetor v
    preencher(v, TAM);
    exibir(v, TAM);
}

//implementação das funções
void preencher(int vetor[], int quant)
{
    //declaração de variáveis
    int i;

    for (i = 0; i < quant; i++)
    {
        vetor[i] = i + 1;
        //vetor[0] = 0 + 1
        //vetor[1] = 1 + 1
        //vetor[2] = 2 + 1
        //(...)
    }
}

void exibir(int vetor[], int quant)
{
    //declaração de variáveis
    int i;

    printf("\n\nElementos do vetor: ");
    for (i = 0; i < quant; i++)
    {
        printf("%d ", vetor[i]);
    }
}
