/*
	FPR - Fundamentos de Programação

	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
    
	
	Revisão: funções + vetores
	
	Exemplo 3: desenvolver uma função que, dado um número inteiro x, 
    determine o número de vezes que ele aparece em um vetor de tamanho TAM.

        Tome nota com a Mali: 
        TAM é uma constante que é utilizada para definir o número de endereços 
        de memória que um vetor vai ocupar.
        já o quant é apenas uma variável de controle de quantas posições estão sendo utilizados pelo algoritmo

        ex:
        #define TAM 10

        int vetor[TAM];
        nesse momento, nosso vetor possui 10 posições reservadas
        como não inserimos nenhum valor nele, o quant está valendo 0.
        o quant deve estar declarado na main. pois é uma variavél de controle do vetor.
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
int buscar (int vetor[], int quant, int numero);

//main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	int x;
    int resp;
	
	//preenchendo o vetor e exibindo o vetor v
	preencher (v, TAM);
	exibir (v, TAM);
	
	//perguntando o valor a ser buscado no vetor
	printf ("\nQual valor deseja buscar? ");
	scanf ("%d", &x);
	
	//chamando a função
	resp = buscar (v, TAM, x);

	//exibindo o resultado
	printf ("\nO numero %d apareceu %d vezes no vetor.", x, resp);
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

int buscar (int vetor[], int quant, int numero)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		//verificando se o 'numero' foi encontrado na posição 'i' do vetor
		if (vetor[i] == numero)
		{
			cont++;
		}
	}
	
	//retornando o resultado
	return cont;
}