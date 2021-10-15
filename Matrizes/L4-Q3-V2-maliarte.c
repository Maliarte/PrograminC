/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos
	Lista de Exercícios IV (Matrizes)
	
	QUESTÃO 03:
	Desenvolver uma função que gere a seguinte matriz M5x5:

			1	2	3	4	5	
			2	3	4	5	6	
			3	4	5	6	7	
			4	5	6	7	8	
			5	6	7	8	9	
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 5
#define C L

//declaração de protótipos
void exibirMatriz (int matriz[L][C]);
void preencher (int matriz[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int M[L][C];
		
	//preenchendo a matriz
	preencher (M);
	
	//exibindo a matriz
	exibirMatriz (M);
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

//preenchendo a matriz conforme especificado no enunciado
void preencher (int matriz[L][C])
{
	//declaração de variáveis
	int i, j, n;
		
	//variando as linhas da matriz
	for (i=0;i<L;i++)
	{
		//inicializando a variável com o primeiro valor a ser armazenado na linha
		n = i+1;
		
		//variando as colunas da matriz
		for (j=0;j<C;j++)
		{
			matriz[i][j] = n;
			n++;
		}
	}
}