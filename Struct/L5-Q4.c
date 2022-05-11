/*
	FPR - Professor Leonardo Vianna
	Turma: Manhã
	Data: 13/04/2022
	
	Lista de Exercícios V (Matrizes)
	
	QUESTÃO 04:
	Fazer uma função que, dada uma matriz M6×6, determine se ela é 
	simétrica.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

#define ORDEM 6

//protótipos das funções
int verificarSimetria (int matriz[ORDEM][ORDEM]);

void preencher (int m[ORDEM][ORDEM]);
void exibir (int m[ORDEM][ORDEM]);

//main
void main ()
{
	//declaração de variáveis
	int m1[ORDEM][ORDEM], 
	    m2[ORDEM][ORDEM] = { {1,3,6,4,7,8},
		                     {3,7,5,6,9,8},
		             		 {6,5,2,5,3,4},
		             		 {4,6,5,1,7,8},
		             		 {7,9,3,7,4,1},
		             		 {8,8,4,8,1,9} },
		resp;
	
	//preenchendo a matriz m1 com números aleatórios
	preencher (m1);
	
	//exibindo a matriz m1
	printf ("Exibindo a matriz m1:\n\n");
	exibir (m1);
	
	//chamando a função
	resp = verificarSimetria (m1);
	
	//exibindo o resultado
	if (resp == TRUE)
	{
		printf ("\n\nA matriz m1 eh simetrica.");
	}
	else
	{
		printf ("\n\nA matriz m1 nao eh simetrica.");
	}

	
	//exibindo a matriz m2
	printf ("\n\n\nExibindo a matriz m2:\n\n");
	exibir (m2);
	
	//chamando a função
	resp = verificarSimetria (m2);
	
	//exibindo o resultado
	if (resp == TRUE)
	{
		printf ("\n\nA matriz m2 eh simetrica.");
	}
	else
	{
		printf ("\n\nA matriz m2 nao eh simetrica.");
	}
}

//implementação das funções
int verificarSimetria (int matriz[ORDEM][ORDEM])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas matriz
	for (i=0;i<ORDEM;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<ORDEM;j++)
		{
			//verificando se os elementos mij e mji são diferentes
			if (matriz[i][j] != matriz[j][i])
			{
				return FALSE;
			}
		}
	}
	
	//se chegou até aqui, não foram encontrados elementos mij e mji diferentes
	return TRUE;
}

void preencher (int m[ORDEM][ORDEM])
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));
	
	//percorrendo as linhas da matriz
	for (i=0;i<ORDEM;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<ORDEM;j++)
		{
			m[i][j] = rand()%20 + 1;
		}
	}
}

void exibir (int m[ORDEM][ORDEM])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<ORDEM;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<ORDEM;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
}