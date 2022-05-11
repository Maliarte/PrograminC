/*
	FPR - 2021/2
	Data: 10/12/2021
	
	ARQUIVOS
	
	Exemplo 2: Fazer uma função que crie um arquivo com os números de 1 a N, 
	um por linha.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
int criarArquivo (char nomeArq[], int N);
/*Ao desenvolver uma função que manipule arquivos, opte por passar o NOME DO ARQUIVO (string) - e não uma variável
  FILE*. Dentro da função, você deverá criar a variável FILE*, associá-la ao nome do arquivo ('fopen'), manipule 
  o arquivo e feche-o ao final. Ou seja, todo o processo - desde a declaração da variável FILE* até o fechamento 
  do arquivo - deve ser realizado dentro da função.
*/

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[20];
	int N;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	gets (nomeArq);
	
	//lendo o valor de N
	printf ("Entre com um numero: ");
	scanf ("%d", &N);
	
	//chamando a função
	if (criarArquivo (nomeArq, N) == 0)
	{
		printf ("\nErro na abertura do arquivo!\n");
	}
	else
	{
		printf ("\nArquivo gerado com sucesso!\n");
	}
}

//implementação das funções
int criarArquivo (char nomeArq[], int N)
{
	//declaração de variáveis
	FILE *arq;
	int i;
	
	//abertura do arquivo (para escrita)
	arq = fopen (nomeArq, "w");
	
	//testando se o arquivo foi ou não aberto
	if (arq == NULL)
	{
		return 0;
	}
	else
	{
		//variando os números de 1 a N para serem armazenados no arquivo
		for (i=1;i<=N;i++)
		{
			fprintf (arq, "%d\n", i);
		}
		
		//fechar o arquivo
		fclose (arq);
		
		return 1;
	}
}
