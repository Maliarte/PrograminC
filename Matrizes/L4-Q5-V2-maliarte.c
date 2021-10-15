/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos
	
	Lista de Exercícios IV (Matrizes)
	
	QUESTÃO 05:
	Implementar uma função que, dada uma matriz M10×8, gere um vetor V de tamanho 8, onde cada elemento 
	do vetor consiste na soma dos elementos de uma coluna de M. Ou seja, o elemento V[0] consiste na soma 
	dos elementos da primeira coluna de M, o elemento V[2] consiste na soma dos elementos da segunda coluna 
	de M, e assim por diante.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 10
#define C 8

//declaração de protótipos
void exibirMatriz (int matriz[L][C]);
void preencherAleatorio (int matriz[L][C]);
void exibirVetor (int vetor[], int tamanho);

void somaColunas (int matriz[L][C], int vetor[C]);

//main
void main ()
{
	//declaração de variáveis
	int M[L][C];
	int V[C];
			
	//preenchendo a matriz M aleatoriamente
	preencherAleatorio (M);
	
	//exibindo a matriz M
	exibirMatriz (M);
	
	//chamando a função
	somaColunas (M, V);
	
	//exibindo o vetor
	exibirVetor (V, C);
}

//implementação das funções

//exibindo a matriz original
void exibirMatriz (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\nElementos da matriz:\n");
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%3d ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}

//preenchendo a matriz original com números aleatórios
void preencherAleatorio (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	srand(time(NULL));	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			matriz[i][j] = 1 + rand()%100;   //gerando números aleatórios no intervalo de 1 a 100
		}
	}
}

void exibirVetor (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nVetor: ");
	
	for (i=0;i<tamanho;i++)
	{
		printf ("%d ", vetor[i]);
	}
}

void somaColunas (int matriz[L][C], int vetor[C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo a matriz coluna a coluna
	for (j=0;j<C;j++)
	{
		//zerando o somatória para cada coluna da matriz
		vetor[j] = 0;
		
		for (i=0;i<L;i++)
		{
			vetor[j] += matriz[i][j];  //armazenando a soma no vetor, na posição equivalente à coluna da matriz
		}
	}
}