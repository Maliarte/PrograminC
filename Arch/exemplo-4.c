/*
	FPR - 2021/2
	Data: 10/12/2021
	
	ARQUIVOS
	
	Exemplo 4: lendo os dados de um arquivo (sem saber a sua estrutura interna).
	
	Como não sabemos a estrutura interna, o ideal é tratar a informação como uma coleção de caracteres.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
int lerArquivo (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[20];
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	gets (nomeArq);
	
	//chamando a função
	if (lerArquivo (nomeArq) == 0)
	{
		printf ("\nErro na abertura do arquivo!\n");
	}
}

//implementação das funções
int lerArquivo (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;
	char c;
	
	//abertura do arquivo (para leitura)
	arq = fopen (nomeArq, "r");  //r - read   /   w - write   /  a - append
	
	//testando se o arquivo foi ou não aberto
	if (arq == NULL)
	{
		return 0;
	}
	else
	{
		//lendo os valores do arquivo, enquanto existirem
		while (fscanf (arq, "%c", &c) != EOF)   //end of file
		{
			printf ("%c", c);
		}
				
		//fechar o arquivo
		fclose (arq);
		
		return 1;
	}
}
