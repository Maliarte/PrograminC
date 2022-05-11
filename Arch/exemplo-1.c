/*
	FPR - 2021/2
	Data: 10/12/2021
	
	ARQUIVOS
	
	Exemplo 1: Fazer um programa que crie um arquivo com os números de 1 a N, 
	um por linha.
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	FILE *arq;					//para manipulação de um arquivo, é necessária uma variável do tipo FILE* (stdio.h)
	char nomeArq[20];			//nome do arquivo. Por exemplo, "teste.txt"
	int i, N;					
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	gets (nomeArq);
	
	//lendo o valor de N
	printf ("Entre com um numero: ");
	scanf ("%d", &N);
	
	//abertura do arquivo (para escrita)
	arq = fopen (nomeArq, "w");	//w - write   /   r - read   /   a - append 			
	
	//testando se o arquivo foi ou não aberto
	if (arq == NULL)
	{
		printf ("\nErro na abertura do arquivo!\n");
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
		
		printf ("\nArquivo gerado com sucesso!\n");
	}
}

/*
	Notem que o nome do arquivo é referenciado apenas no momento da abertura, através do comando 'fopen'.
	Neste momento, o nome do arquivo é associado à variável 'arq' e, a partir daí, apenas a variável 'arq' é
	referenciada.
	
	Importante ter atenção à seguinte sequência de passos:
	
	1. Declaração da variável do tipo FILE*
	2. Abertura do arquivo (especificando o tipo de acesso - write/read/append). Neste momento, a variável
	   do tipo FILE* é associada ao caminho especificado no primeiro argumento da função 'fopen'
	3. Uma vez aberto o arquivo, manipule-o: seja lendo ou escrevendo no mesmo
	4. Não esquecer de, ao final, fechar o arquivo (comando 'fclose')
*/