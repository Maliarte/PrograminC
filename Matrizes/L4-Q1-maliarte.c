/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos!
	
	Lista de Exercícios IV (Matrizes)
	
	QUESTÃO 01:
	Faça um função que, dada uma matriz M8×5 de reais, gere a matriz Mt, sua transposta.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 8
#define C 5

//declaração de protótipos
void transposta (float matrizOriginal[L][C], float matrizT[C][L]);

void exibirMatriz (float matriz[L][C]);
void exibirTransposta (float matriz[C][L]);
void preencherAleatorio (float matriz[L][C]);

//main
void main ()
{
	//declaração de variáveis
	float M[L][C];
	float T[C][L];
	
	//preenchendo a matriz original
	preencherAleatorio (M);
	
	//gerando a matriz transposta
	transposta (M, T);
	
	//exibindo as matrizes
	exibirMatriz (M);
	exibirTransposta (T);	
}

//implementação das funções

//exibindo a matriz original
void exibirMatriz (float matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\nElementos da matriz:\n");
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%5.1f ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}

//exibindo a matriz transposta
void exibirTransposta (float matriz[C][L])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\nElementos da matriz transposta:\n");
	for (i=0;i<C;i++)
	{
		for (j=0;j<L;j++)
		{
			printf ("%5.1f ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}

//preenchendo a matriz original com números aleatórios
void preencherAleatorio (float matriz[L][C])
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

void transposta (float matrizOriginal[L][C], float matrizT[C][L])
{
	//declaração de variáveis
	int i, j;
	
	//variando as linhas da matriz transposta
	for (i=0;i<C;i++)
	{
		//variando as colunas da matriz transposta
		for (j=0;j<L;j++)
		{
			//preenchendo os elementos da matriz transposta de forma que MTij = Mji
			matrizT[i][j] = matrizOriginal[j][i];
		}
	}
}