/*
	FPR - Fundamentos de Programação
    
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	MATRIZES
	
	Exemplo 3: desenvolver uma função que determine o número de ocorrências de um valor em uma
	           matriz de reais com 15 linhas e 8 colunas.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 15
#define C 8

//declaração de protótipos
void preencher (float matriz[L][C]);
void exibir (float matriz[L][C]);

int buscar (float matriz[L][C], float num);

//main
void main ()
{
	//declaração da matriz
	float m[L][C];
	float numero;
	int quant;
		
	//preenchendo a matriz
	preencher (m);
	
	//exibindo a matriz
	exibir (m);
	
	//perguntar o valor ao usuário
	printf ("\n\nEntre com o elemento a ser buscado: ");
	scanf ("%f", &numero);
	
	//chamando a função
	quant = buscar (m, numero);	
	
	//escrevendo o resultado
	printf ("\nO elemento %.1f foi encontrado %d vezes na matriz.", numero, quant);
}

//implementação das funções
void preencher (float matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	srand(time(NULL));	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			matriz[i][j] = rand()%10000/100.0;   //gerando números reais aleatórios no intervalo de 0 a 99.99
		}
	}
}

/*
	1 + (rand()%10000/100.0):
	
		rand()%10000: 				0 a 9999
		rand()%10000/100.0:			0 a 99.99
*/


void exibir (float matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\nElementos da matriz:\n");
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%6.2f ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}

int buscar (float matriz[L][C], float num)
{
	//declaração de variáveis
	int i, j, cont = 0;
	
	//percorrendo todas as posições da matriz
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			//comparando cada elemento da matriz com o valor sendo buscado
			if (matriz[i][j] == num)
			{
				cont++;
			}
		}
	}
	
	//retornando a quantidade de ocorrências do número na matriz
	return cont;
}