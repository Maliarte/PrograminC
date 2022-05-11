Menu principal
2FPR - Manhã - Fundamentos de Programação
Implementações
Leonardo Vianna
•
28 de abr.

Arquivos7_versao3.c
C

fread1.c
C

fread2.c
C

fwrite1.c
C

fwrite2.c
C

Arquivos5.c
C

Arquivos6.c
C

Arquivos7.c
C

Arquivos7_versao2.c
C
Comentários da turma

/*
	FAETERJ-Rio
	FPR - Manhã - 2022/1
	Data: 28/04/2022
	
	Arquivos
	
	Exemplo 5: ler o conteúdo de um arquivo e exibi-lo na tela, independente do tipo de informação que armazena.
	
	(neste caso, consideraremos que o arquivo é constituído por diversos caracteres)
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int leituraArquivo (char nomeArq[]);

//main
void main()
{
	//declaração de variáveis
	char nomeArquivo[30];
	
	//lendo o nome do arquivo cujos dados serão lidos
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a função
	if (leituraArquivo (nomeArquivo) == TRUE)
	{
		printf("Arquivo lido com sucesso!");
	}
	else
	{
		printf("Erro na abertura do arquivo!");
	}
}

//implementação das funções
int leituraArquivo (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;
	char caracter;
	
	//tentativa de abrir o arquivo para leitura
	arq = fopen (nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo	
	if (arq == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo os caracteres do arquivo até se chegar ao seu final
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			//exibindo na tela os caracteres lidos
			printf("%c", caracter);
		}
		
		//fechando o arquivo
		fclose(arq);
		
		return TRUE;
	}
}
Arquivos5.c
Exibindo Arquivos5.c.