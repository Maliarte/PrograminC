/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	MATRIZES
	
	Exemplo 4: com que valores essa matriz está sendo preenchida?
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 15
#define C 15

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
void preencher (int matriz[L][C])    //O que é feito por esta função???
{
	//declaração de variáveis
	int i, j;
	
	//variando as linhas da matriz
	for (i=0;i<L;i++)
	{
		//variando as colunas da matriz
		for (j=0;j<C;j++)
		{
			//verificando se o número da linha é igual ao da coluna. Em outras palavras, verificando se trata-se de elemento da diagonal principal
			if (i==j)
			{
				matriz[i][j] = 0;  //Todos os elementos da diagonal principal receberão o valor 0
			}
			else
			{
				//verificando se o número da linha é maior do que o da coluna. Ou seja, trata-se de elemento abaixo da diagonal principal.	
				if (i>j)
				{
					matriz[i][j] = -1;
				}
				else
				{
					//O número da linha é menor do que o da coluna. Ou seja, trata-se de elemento acima da diagonal principal.	
					matriz[i][j] = 1;
				}
			}
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
			printf ("%3d ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}