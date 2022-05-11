/*
	FPR - Professor Leonardo Vianna
	Turma: Manhã
	Data: 13/04/2022
	
	Lista de Exercícios V (Matrizes)
	
	QUESTÃO 05:
	Implementar uma função que, dada uma matriz M10×8, gere um vetor V 
	de tamanho 8, onde cada elemento do vetor consiste na soma dos 
	elementos de uma coluna de M. Ou seja, o elemento V[0] consiste na 
	soma dos elementos da primeira coluna de M, o elemento V[1] consiste 
	na soma dos elementos da segunda coluna de M, e assim por diante.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 10
#define C 8

//protótipos das funções
void preencherVetor (int m[L][C], int v[C]);

void preencherMatriz (int m[L][C]);
void exibirMatriz (int m[L][C]);
void exibirVetor (int v[], int tamanho);

//main
void main ()
{
	//declaração de variáveis
	int matriz[L][C];
	int vetor[C];
	
	//preenchendo a matriz com números aleatórios
	preencherMatriz (matriz);
	
	//exibindo a matriz
	printf ("Exibindo a matriz:\n\n");
	exibirMatriz (matriz);
	
	//chamando a função
	preencherVetor (matriz, vetor);
	
	//exibindo o vetor
	exibirVetor (vetor, C);
}

//implementação das funções
void preencherVetor (int m[L][C], int v[C])
{
	//declaração de variáveis
	int i, j, soma;
	
	//percorrendo as colunas da matriz
	for (j=0;j<C;j++)
	{
		//zerando a soma para cada nova coluna
		soma = 0;
		
		//percorrendo as linhas da matriz
		for (i=0;i<L;i++)
		{
			soma = soma + m[i][j];
		}
		
		//armazenando no vetor a soma da coluna j
		v[j] = soma;
	}
}

void preencherMatriz (int m[L][C])
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = rand()%5 + 1;
		}
	}
}

void exibirMatriz (int m[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
}

void exibirVetor (int v[], int tamanho)
{
	//declaração de variáveis
	int i;

	printf ("\nElementos do vetor: ");

	//percorrendo as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		printf ("%d ", v[i]);
	}
	
	printf ("\n\n");	
}