/*
	FPR - Fundamentos de Programação
    
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	
	MATRIZES
	
	Exemplo 2: preencher uma matriz com números randômicos e, em seguida, exibi-la.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 10
#define C 20

//declaração de protótipos
void preencher (int matriz[L][C]);
void exibir (int matriz[L][C]);

//main
void main ()
{
	//declaração da matriz
	int m[L][C];
		
	//preenchendo a matriz
	preencher (m);
	
	//exibindo a matriz
	exibir (m);
}

//implementação das funções
void preencher (int matriz[L][C])
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

void exibir (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\nElementos da matriz:\n");
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%d ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}