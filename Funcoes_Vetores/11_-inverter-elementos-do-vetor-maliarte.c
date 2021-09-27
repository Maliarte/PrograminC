/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	
	Revisão: funções + vetores
	
	Exemplo 5: desenvolver uma função que inverta os elementos de um vetor.
	
	
	Exemplo:
			vetor antes da inversão:
			1  2  3  4  5  6  7  8  9  10
			
			vetor depois da inversão:
			10  9  8  7  6  5  4  3  2  1	           
*/

//importação de bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//declaração de constantes
#define TAM 100

//protótipos de funções
void preencher (int vetor[], int quant);
void exibir (int vetor[], int quant);

void inverter (int vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	
	//preenchendo o vetor v
	preencher (v, TAM);
	
	//exibindo o vetor v antes da inversão
	exibir (v, TAM);
		
	//chamando a função
	inverter (v, TAM);

	//exibindo o vetor v depois da inversão
	exibir (v, TAM);
}

//implementação das funções
void preencher (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	srand(time(NULL));	
	for (i=0;i<quant;i++)
	{
		vetor[i] = 1 + rand()%100;   //gerando números aleatórios no intervalo de 1 a 100
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

void inverter (int vetor[], int quant)
{
	//declaração de variáveis
	int i, j, aux;	
	
	//procedendo com a troca dos elementos do vetor, de forma que o mesmo seja invertido
	for (i=0,j=quant-1;i<j;i++,j--)
	{
		//trocar os elementos das posições 'i' e 'j'
		aux = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = aux;
	}
}