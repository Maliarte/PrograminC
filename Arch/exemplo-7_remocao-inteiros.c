/*
	FAETERJ-Rio
	FPR - Manhã - 2022/1
	Data: 28/04/2022
	
	Arquivos
	
	Exemplo 7: desenvolver uma função que removas todas as ocorrências de um número inteiro em determinado
	arquivo
	
	versão 3: removendo o arquivo original e renomeando o temporário.
*/

//importação de bibliotecas
#include<stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int removerArquivo (char nomeArq[], int numero);

//main
void main()
{
	//declaração de variáveis
	char nomeArquivo[30];
	int num, retorno;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//lendo o número a ser removido	
	printf ("Entre com o numero a ser removido: ");
	scanf ("%d", &num);
	
	//chamando a função e armazenando o retorno
	retorno = removerArquivo (nomeArquivo, num);
	
	//testando o retorno da função
	switch (retorno)
	{
		case -1: printf ("Erro na abertura do arquivo!");
		         break;
		         
		case  0: printf ("Elemento nao encontrado no arquivo!");
		         break;
		        
		default: printf ("Foram feitas %d remocoes do valor %d", retorno, num);		
	}
}

//implementação das funções
int removerArquivo (char nomeArq[], int numero)
{
	//declaração de variáveis
	FILE *arq, *temp;
	int valor, cont=0;
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");
	temp = fopen ("temp.txt", "w");	
	
	//testando se houve erro na abertura dos arquivos
	//if ((arq == NULL) || (temp == NULL))
	if (!arq || !temp)
	{
		return -1;
	}
	else
	{
		//copiando para temp todos os números diferentes daquele que deseja-se remover
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se não é o elemento a ser removido
			if (valor != numero)
			{
				fprintf (temp, "%d\n", valor);
			}
			else
			{
				cont++;
			}
		}
		
		//copiando os elementos do arquivo temporário para o original
		//copiarArquivo("temp.txt", nomeArq);
		
		//apagando o arquivo original do disco
		remove (nomeArq);
		
		//renomeando o temporário
		rename ("temp.txt", nomeArq);
		
		return cont;	
	}
}

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