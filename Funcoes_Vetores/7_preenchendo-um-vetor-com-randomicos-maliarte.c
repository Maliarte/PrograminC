/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	Data: 08/09/2021
	
	Revisão: funções + vetores
	
	Exemplo 1: desenvolver uma função que preencha um vetor com números randômicos
*/

//importação de bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//declaração de constantes
#define TAM1 100
#define TAM2 50

//protótipos de funções
void preencher (int vetor[], int quant);
void exibir (int vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	int v1[TAM1], v2[TAM2];
	
	//preenchendo o vetor e exibindo o vetor v1
	preencher (v1, TAM1);
	exibir (v1, TAM1);
	
	//preenchendo o vetor e exibindo o vetor v2
	preencher (v2, TAM2);
	exibir (v2, TAM2);
}

//implementação das funções
void preencher (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	srand(time(NULL));	
	for (i=0;i<quant;i++)
	{   
        //gerando números aleatórios no intervalo de 1 a 100
		vetor[i] = 1 + rand()%100;   
	}
}

void exibir (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nElementos do vetor: ");
	for (i=0;i<quant;i++)
	{
		printf ("%d ", vetor[i]);
	}
}
