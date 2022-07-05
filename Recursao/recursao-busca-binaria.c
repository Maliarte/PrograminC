/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 19/05/2022
	
	Recursividade
	
	Busca binária: busca de um elemento em um vetor ordenado crescentemente.	
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define TAM 1000

//protótipos das funções
int buscaBinaria (int vetor[], int tamanho, int valor);
int buscaAuxiliar (int vetor[], int inicio, int fim, int valor);

void preencher (int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int vetor[TAM], resp, num;
	
	//preenchendo o vetor com valores aleatórios
	preencher (vetor, TAM);
	
	//exibindo o vetor
    exibir (vetor, TAM);
	
	//lendo o valor a ser buscado
	printf ("Entre com o numero a ser buscado: ");
	scanf ("%d", &num);
	
	//buscando o elemento no vetor
	resp = buscaBinaria (vetor, TAM, num);	
	
	//verificando o retorno da função
	if (resp == -1)
	{
		printf ("O valor %d nao foi encontrado no vetor\n", num);
	}
	else
	{
		printf ("O valor %d foi encontrado na posicao %d do vetor\n", num, resp);
	}	
}

//implementação das funções
int buscaBinaria (int vetor[], int tamanho, int valor)
{
	return buscaAuxiliar (vetor, 0, tamanho-1, valor);
}

int buscaAuxiliar (int vetor[], int inicio, int fim, int valor)
{
	int meio;
	
	//verificando se ainda existem posições a serem comparadas
	if (inicio <= fim)
	{
		//determinando a posição mediana do subvetor considerado nesta chamada
		meio = (inicio + fim)/2;
		
		printf ("\tComparando com a posicao %d\n", meio);
		
		//verificando se 'valor' está na posição 'meio'
		if (vetor[meio] == valor)
		{
			return meio;
		}
		else
		{
			//verificando se a busca continuará à esquerda da posição 'meio'
			if (vetor[meio] > valor)
			{
				return buscaAuxiliar (vetor, inicio, meio-1, valor);
			}
			else
			{
				//a busca deve continuar à direita da posição 'meio'
				return buscaAuxiliar (vetor, meio+1, fim, valor);
			}
		}
	}
	else
	{
		//não há mais posições a serem tratadas; o elemento não existe no vetor
		return -1;
	}
}

void preencher(int vetor[], int tamanho)
{
    //declaracao de variaveis
    int i;
    
    srand (time(NULL));
    
    //armazenando na primeira posição um valor de 1 a 10
    vetor[0] = 1 + rand()%10;
    
    //corpo da função
    for(i = 1; i < tamanho; i++)
	{
		vetor[i] = vetor[i-1] + rand()%5; //garantindo que o vetor estará ordenado crescentemente
    }
}

void exibir (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\nElementos do vetor: ");
	
	//percorrendo todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		printf ("%d  ", vetor[i]);
	}
	
	printf ("\n\n");
}