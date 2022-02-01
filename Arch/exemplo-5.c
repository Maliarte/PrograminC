/*
	FPR - 2021/2
	Data: 10/12/2021
	
	ARQUIVOS
	
	Exemplo 5: copiando o conteúdo de um arquivo para outro.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
int copiarArquivo (char origem[], char destino[]);

//main
void main ()
{
	//declaração de variáveis
	char arqO[20], arqD[20];
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser copiado: ");
	gets (arqO);
	
	printf ("Entre com o nome do novo arquivo: ");
	gets (arqD);
	
	//chamando a função
	if (copiarArquivo (arqO, arqD) == 0)
	{
		printf ("\nErro na abertura dos arquivos!\n");
	}
	else
	{
		printf ("\nArquivo %s gerado com sucesso!\n", arqD);
	}
}

//implementação das funções
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