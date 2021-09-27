/*
	FPR - Fundamentos de Programação

	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	Data: 02/09/2021
	
	Revisão: funções + vetores
	
	Exemplo 5 (versão 2): desenvolver uma função que leia valores para um vetor, 
	                      independente de seu tamanho;

    Para tal, considera-se na passagem de parâmetros na função 
    a variável 'quant', sendo essa os valores que serão ocupados dentro do vetor.
    que significa a taxa ocupada dentro desse vetor.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define TAM1 10
#define TAM2 5

//protótipos de funções
void preencher (int vetor[], int quant);
void exibir (int vetor[], int quant);

//na main os argumentos das funções não precisam de caracteres especiais
//apenas na declaração
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
	
	for (i=0;i<quant;i++)
	{
		printf ("Entre com um numero: \n");
		scanf ("%d", &vetor[i]);
	}
}

void exibir (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nElementos do vetor: ");
	for (i=0;i<quant;i++)
	{
		printf ("%d \n", vetor[i]);
	}
}