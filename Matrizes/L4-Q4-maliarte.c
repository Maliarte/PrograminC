/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos
	
	Lista de Exercícios IV (Matrizes)
	
	QUESTÃO 04:
	Fazer uma função que, dada uma matriz M6×6, determine se ela é simétrica.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 6
#define C L

#define FALSE 0
#define TRUE 1

//declaração de protótipos
void exibirMatriz (int matriz[L][C]);
void preencherAleatorio (int matriz[L][C]);

int simetrica (int matriz[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int M1[L][C];
	int M2[L][C] = {{1,2,3,4,5,6},
	                {2,8,1,5,2,4},
					{3,1,6,3,1,3},
					{4,5,3,2,8,7},
					{5,2,1,8,4,0},
					{6,4,3,7,0,5}};
		
	//preenchendo a matriz M1 aleatoriamente
	preencherAleatorio (M1);
	
	//exibindo a matriz M1
	exibirMatriz (M1);
	
	//chamando a função
	if (simetrica (M1) == TRUE)
	{
		printf ("M1 e' simetrica!\n\n");
	}
	else
	{
		printf ("M1 nao e' simetrica!\n\n");
	}
	
	//exibindo a matriz M2
	exibirMatriz (M2);
	
	//chamando a função
	if (simetrica (M2) == TRUE)
	{
		printf ("M2 e' simetrica!");
	}
	else
	{
		printf ("M2 nao e' simetrica!");
	}
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

// acrescentamos o contador (cont) para visualizar a quantidade de comparações.
int simetrica (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;//, cont=0;
	
	//percorrendo todos os elementos da matriz
	for (i=0;i<L;i++)	
	{
		for (j=0;j<C;j++)
		{
			//cont++; 
			
			//buscando a condição para não ser simétrica
			if (matriz[i][j] != matriz[j][i]) 
			{
				//printf ("\nForam feitas %d comparacoes!\n", cont);
				
				return FALSE;
			}			
		}
	}
	
	//printf ("\nForam feitas %d comparacoes!\n", cont);
	
	//se chegou até aqui, é pq nenhum elemento mij é diferente do mji. Portanto, a matriz é simétrica.
	return TRUE;
}