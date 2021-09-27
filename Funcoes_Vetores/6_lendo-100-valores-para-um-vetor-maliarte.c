/*
	FPR - Fundamentos de Programação

	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	Data: 02/09/2021
	
	Revisão: funções + vetores
	
	Exemplo 5: desenvolver uma função que leia 100 valores para um vetor
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes: definindo a diretiva universal '#'
#define TAM 3

//protótipos de funções
void preencher (int vetor[TAM]);
void exibir (int vetor[TAM]);

//main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	
	//preenchendo o vetor
	preencher (v);
	
	//exibindo o vetor
	exibir (v);
}

//implementação das funções
void preencher (int vetor[TAM])
{
	//declaração de variáveis
	int i;
	
	for (i=0;i<TAM;i++)
	{
		printf ("Entre com um numero: ");
		scanf ("%d", &vetor[i]);
	}
}

void exibir (int vetor[TAM])
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nElementos do vetor: ");
	for (i=0;i<TAM;i++)
	{
		printf ("%d ", vetor[i]);
	}
}
