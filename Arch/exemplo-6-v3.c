/*
	FPR - 2021/2
	Data: 10/12/2021
	
	ARQUIVOS
	
	Exemplo 6: remover todas as ocorrências de um número em um arquivo.
	
	versão 3: ao final, apagaremos o arquivo orginal; em seguida, renomearemos o temp para o original.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
int removerNumero (char nomeArq[], int numero);

//main
void main ()
{
	//declaração de variáveis
	char nome[20];
	int valor;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	gets (nome);
	
	printf ("Entre com o numero a ser removido: ");
	scanf ("%d", &valor);
	
	//chamando a função
	switch (removerNumero (nome, valor))
	{
		case -1: printf ("\nErro na abertura dos arquivos!\n");
		         break;
		         
		case  0: printf ("\nO numero %d nao foi encontrado no arquivo!\n", valor);
		         break;
		         
		default: printf ("\nRemocao realizada com sucesso!\n");
	}
}

//implementação das funções
int removerNumero (char nomeArq[], int numero)
{
	//declaração de variáveis
	FILE *arq, *tmp;
	int num, cont=0;
	
	//abertura dos arquivos
	arq = fopen (nomeArq, "r");  //r - read   /   w - write   /  a - append
	tmp = fopen ("temp.txt", "w");
	
	//testando se houve erro na abertura de um dos arquivos (ou nos dois)
	if ((arq == NULL) || (tmp == NULL))
	{
		remove ("temp.txt");
		return -1;
	}
	else
	{
		//lendo os valores do arquivo origem, enquanto existirem
		//e jogando no temporario apenas os valores diferentes de 'numero'
		while (fscanf (arq, "%d", &num) != EOF)   //end of file
		{
			if (num != numero)
			{
				fprintf (tmp, "%d\n", num);
			}
			else
			{
				cont++;
			}
		}
				
		//fechar os arquivos
		fclose (arq);
		fclose (tmp);
		
		//removendo o arquivo original
		remove (nomeArq);
		
		//renomeando o arquivo temporário para o nome do arquivo original
		rename ("temp.txt", nomeArq);
		
		return cont;
	}
}