/*
	FAETERJ-Rio
	FPR - Manhã - 2022/1
	Data: 28/04/2022
	
	Arquivos
	
	Exemplo 6: copiar o conteúdo de um arquivo para outro.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int copiarArquivo (char arqO[], char arqD[]);

//main
void main()
{
	//declaração de variáveis
	char nomeArqOrigem[30], 
	     nomeArqDestino[30];
	     
	//obtendo o nome do arquivo a ser copiado
	printf ("Entre com o nome do arquivo a ser copiado: ");
	fflush (stdin);
	gets (nomeArqOrigem);
	
	//obtendo o nome do arquivo a ser criado
	printf ("Entre com o nome do arquivo a ser criado: ");
	fflush (stdin);
	gets (nomeArqDestino);
	
	//chamando a função
	if (copiarArquivo (nomeArqOrigem, nomeArqDestino) == TRUE)
	{
		printf ("\nCopia realizada com sucesso!");
	}
	else
	{
		printf ("\nErro na abertura dos arquivos!");
	}
}

//implementação das funções
int copiarArquivo (char arqO[], char arqD[])
{
	//declaração de variáveis
	FILE *arq1, *arq2;
	char caracter;
	
	//tentando abrir os dois arquivos
	arq1=fopen(arqO, "r");
	arq2=fopen(arqD, "w");
	
	//testando se houve erro na abertura do arquivo
	if((arq1==NULL) || (arq2 == NULL))
	{
		fclose (arq1);
		fclose (arq2);
		
		return FALSE;
	}
	else
	{
		//lendo o conteúdo do arquivo de origem
		while (fscanf (arq1, "%c", &caracter) != EOF) 
		{
			//escrevendo os valores lidos no arquivo de destino
			fprintf (arq2, "%c", caracter);
		}
		
		//fechando os arquivos
		fclose (arq1);
		fclose (arq2);
		
		return TRUE;
	}
}