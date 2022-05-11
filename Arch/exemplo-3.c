/*
	FPR - 2021/2
	Data: 10/12/2021
	
	ARQUIVOS
	
	Exemplo 3: lendo os elementos de um arquivo, sabendo que os números estão dispostos
	um por linha.
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
	int numero;
	
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
		while (fscanf (arq, "%d", &numero) != EOF)   //end of file
		{
			printf ("%d\n", numero);
		}
				
		//fechar o arquivo
		fclose (arq);
		
		return 1;
	}
}
