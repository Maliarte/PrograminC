/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos!
	
	MATRIZES
	
	Exemplos (apresentação ppt): 
	
	Dada uma matriz M10x20 de inteiros, desenvolver uma função para cada item a seguir:
	- Zerar os elementos de uma matriz;
	- Armazenar o valor 1 em todas as posições da 1ª linha, o número 2 na 2ª, e assim por diante;
	- Preencher a matriz com números aleatórios (função rand);
	- Exibir os elementos da matriz (respeitando a configuração linha por linha);
	- Determinar o número de ocorrências de um número na matriz;
	- Determinar o número de ocorrências de um número na linha L da matriz.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 10
#define C 20

//declaração de protótipos
void zerarMatriz (int matriz[L][C]);
void preencherMatriz1a10 (int matriz[L][C]);
void preencherAleatorio (int matriz[L][C]);
void exibirMatriz (int matriz[L][C]);
int  buscarNaMatriz (int matriz[L][C], int numero);
int  buscarNaLinha  (int matriz[L][C], int linha, int numero);

//main
void main ()
{
	//declaração da matriz
	int m[L][C];
	int valor, resp, linha;
	
	//teste1: zerando a matriz
	zerarMatriz (m);
	exibirMatriz (m);			

	//teste2: preenchendo cada linha com valores fixos (de 1 a 10)
	preencherMatriz1a10 (m);
	exibirMatriz (m);		
	
	//teste3: geração de números aleatórios
	preencherAleatorio (m);
	exibirMatriz (m);
	
	//teste4: buscar um número na matriz
	printf ("\n\nEntre com um valor a ser buscado na matriz: ");
	scanf ("%d", &valor);
	
	resp = buscarNaMatriz (m, valor);
	printf ("\nO numero %d aparece %d vezes na matriz.\n", valor, resp);	
	
	//teste5: buscar 'valor' em determinada linha da matriz
	printf ("\n\nAgora, em qual linha da matriz deseja buscar o numero %d? ", valor);
	scanf ("%d", &linha);
	
	resp = buscarNaLinha (m, linha, valor);
	printf ("\nO numero %d aparece %d vezes na linha %d da matriz.\n", valor, resp, linha);	
}

//implementação das funções

//Preencher a matriz com números aleatórios (função rand)
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

//Exibir os elementos da matriz (respeitando a configuração linha por linha)
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

//Zerar os elementos de uma matriz
void zerarMatriz (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			matriz[i][j] = 0;   //zerando cada posição da matriz
		}
	}
}

//Armazenar o valor 1 em todas as posições da 1ª linha, o número 2 na 2ª, e assim por diante
void preencherMatriz1a10 (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			matriz[i][j] = i+1;
		}
	}
}

//Determinar o número de ocorrências de um número na matriz
int  buscarNaMatriz (int matriz[L][C], int numero)
{
	//declaração de variáveis
	int i, j, cont = 0;
	
	//percorrendo todas as posições da matriz
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			//comparando cada elemento da matriz com o valor sendo buscado
			if (matriz[i][j] == numero)
			{
				cont++;
			}
		}
	}
	
	//retornando a quantidade de ocorrências do número na matriz
	return cont;
}

//Determinar o número de ocorrências de um número na linha L da matriz

/*
//Esta solução é cara, pois deveria percorrer apenas os elementos da linha, porém acessa todos da matriz
int  buscarNaLinha  (int matriz[L][C], int linha, int numero)
{
	//declaração de variáveis
	int i, j, cont = 0;
	
	//percorrendo todas as posições da matriz
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			//verificando se estamos na linha desejada
			if (i == linha)
			{
				//comparando cada elemento da matriz com o valor sendo buscado
				if (matriz[i][j] == numero)
				{
					cont++;
				}
			}
		}
	}
	
	//retornando a quantidade de ocorrências do número na matriz
	return cont;
}
*/

int  buscarNaLinha  (int matriz[L][C], int linha, int numero)
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