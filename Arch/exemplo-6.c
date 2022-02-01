/*
	FPR - 2021/2
	Data: 10/12/2021
	
	ARQUIVOS
	
	Exemplo 6: remover todas as ocorrências de um número em um arquivo.
	
	Usamos um arquivo temporário para receber todos os valores do arquivo original (exceto aquele que desejamos
	remover). Em seguida, copiar os valores do arquivo temporário para o original.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
int removerNumero (char nomeArq[], int numero);
int copiarArquivo (char origem[], char destino[]);

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
		
		//copiando os dados do arquivo temporário para o original
		copiarArquivo ("temp.txt", nomeArq);
		
		return cont;
	}
}

int copiarArquivo (char origem[], char destino[])
{
	//declaração de variáveis
	FILE *O, *D;
	char c;
	
	//abertura dos arquivos
	O = fopen (origem, "r");  //r - read   /   w - write   /  a - append
	D = fopen (destino, "w");
	
	//testando se houve erro na abertura de um dos arquivos (ou nos dois)
	if ((O == NULL) || (D == NULL))
	{
		return 0;
	}
	else
	{
		//lendo os valores do arquivo origem, enquanto existirem
		while (fscanf (O, "%c", &c) != EOF)   //end of file
		{
			fprintf (D, "%c", c);
		}
				
		//fechar os arquivos
		fclose (O);
		fclose (D);
		
		return 1;
	}
}
