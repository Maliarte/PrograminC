/*
	FPR - Fundamentos de Programação
    
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos
	
	Lista de Exercícios IV (Matrizes)
	
	QUESTÃO 02:
	Desenvolver uma função que, dada uma matriz M15×20, determine se um número X se encontra na 
	linha L da matriz.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 15
#define C 20

//declaração de protótipos
int buscarNaLinha (int matriz[L][C], int linha, int numero);

void exibirMatriz (int matriz[L][C]);
void preencherAleatorio (int matriz[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int M[L][C];
	int numero;
	int linha, resp;
	
	//preenchendo a matriz
	preencherAleatorio (M);
	
	//exibindo a matriz
	exibirMatriz (M);
	
	//perguntando qual valor deverá ser buscado
	printf ("\n\nQual elemento deseja buscar? ");
	scanf ("%d", &numero);
	
	//perguntando em qual linha da matriz deseja buscar o valor
	printf ("Em qual linha deseja buscar o elemento? ");
	scanf ("%d", &linha);
	
	//chamando a função
	resp = buscarNaLinha (M, linha, numero);
	
	//exibindo o resultado
	if (resp == 0)
	{
		printf ("\nO valor %d nao foi encontrado na linha %d da matriz.", numero, linha);
	}
	else
	{
		printf ("\nO valor %d foi encontrado %d vezes na linha %d da matriz.", numero, resp, linha);
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

int buscarNaLinha (int matriz[L][C], int linha, int numero)
{
	//declaração de variáveis
	int j, cont = 0;
	
	//percorrendo todas as posições da LINHA desejada
	for (j=0;j<C;j++)
	{
		//comparando cada elemento da matriz com o valor sendo buscado
		if (matriz[linha][j] == numero)
		{
			cont++;
		}
	}

	//retornando a quantidade de ocorrências do número na matriz
	return cont;
}