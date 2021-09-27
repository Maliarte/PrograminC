/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	
	Revisão: funções + vetores
	
	Exemplo 4: considerando um vetor com TAM números inteiros, determinar o maior e o menor 
	           elementos do conjunto.
	           
	           Exemplo:    vetor:  10 21 3 4 52 1 4 9 10 1 36
	                       maior: 52  /  menor: 1
	           
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

void maiorMenor (int vetor[], int quant, int *menor, int *maior);

//main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	int x, resp, ma, me;
	
	//preenchendo o vetor v
	preencher (v, TAM);
	
	//exibindo o vetor v
	exibir (v, TAM);
		
	//chamando a função
	maiorMenor (v, TAM, &ma, &me);

	//exibindo os resultados
	printf ("\nMaior: %d  -  Menor: %d", ma, me);
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

void maiorMenor (int vet[], int quant, int *maior, int *menor)
{
	//declaração de variáveis
    int i;
    int big, small;
   
   	//inicializando as variáveis 'big' e 'small'
   	big = vet[0];
   	small = vet[0];
   
   	//varrendo o vetor
   	for (i=1;i<quant;i++)
	{
		//verificando se 'big' precisa ser atualizado
	    if (vet[i] > big)
	    {
	        big = vet[i];
	    }
		else
		{
			//verificando se 'small' precisa ser atualizado
		    if (vet[i] < small)
		    {
		        small = vet[i];
		    }
		}
	}
	
	*maior = big;
	*menor = small;
}