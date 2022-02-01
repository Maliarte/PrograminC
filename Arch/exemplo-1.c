/*
	FPR - 2021/2 - Maliarte
	Data: 10/12/2021
	
*	ARQUIVOS
*	
* 																
*	fopen()  - Abre um arquivo.
*	fclose() -  Fecha o arquivo garantindo a transferência do buffer.
*	fflush() - Descarrega o buffer.
*	fscanf() - Leitura de entrada formatada (semelhante ao scanf()).
*	fprintf()  Escrita de saída formatada (semelhante ao printf()).
*	fgets()    Obtém uma string do arquivo.
*	fgetc()    Obtém um caracter do arquivo.
*	fputs()    Insere uma string no arquivo.
*	fputc()    Insere um caracter no arquivo.
*	fread()    Lê um bloco de dados do arquivo.
*	fwrite()   Escreve um bloco de dados no arquivo.
*	fseek()    Reposiciona o ponteiro.
*	rewind()   Reposiciona o ponteiro para o início do arquivo.
*	ftell()    Retorna a posição do ponteiro.


Associação do arquivo
	O primeiro passo para trabalhar com um arquivo é fazer a associação do arquivo físico com um
	arquivo lógico. Para isso utilizamos o tipo FILE, definido na biblioteca stdio.h. A abertura/associação
	do arquivo é feita pela função fopen(const char* arquivo, const char* modo), em que arquivo é o
	diretório/nome do arquivo a ser aberto e modo é o modo que a associação é feita. Os tipos de
	associação estão descritos na Tabela 2.

	Tabela 2: Modos de abertura de arquivos
	"r" Abre o arquivo somente para leitura, a partir do início. O arquivo deve existir.
	”w” Cria um arquivo vazio para escrita. Se já havia o arquivo, ele é perdido.
	”a” Adiciona no final do arquivo. Se o arquivo não existir, a função o cria.
	”r+” Abre o arquivo para leitura e escrita, a partir do início. O arquivo deve existir.
	”w+” Cria um arquivo vazio para leitura e escrita. Se já havia o arquivo, ele é perdido.
	”a+” Abre para adição ou leitura no final do arquivo. Se o arquivo não existir, a função o cria.

No Windows, o caracter “b” pode ser adicionado ao modo (ex: “ab”, “w+b”, etc) para
especificar que o arquivo deve ser aberto no modo binário. Em sistemas POSIX (inclusive Linux), esse
caracter é ignorado.Também é possível utilizar o caracter “t”, para abertura de no modo texto.
O código a seguir mostra um exemplo da associação.

	
* Exemplo 1: Fazer um programa que crie um arquivo com os números de 1 a N, um por linha.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//main
void main ()
{
	//declaração de variáveis
	
	FILE *arq;	/*********************** iniciar o arquivo ***************************************/	
	
	char nomeArq[20]; //teste.txt
	int i, N;					
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");//teste.txt
	gets (nomeArq);
	
	//lendo o valor de N
	printf ("Entre com um numero: ");
	scanf ("%d", &N);
	
	/******************************** abertura do arquivo (para escrita) **************************/
	arq = fopen (nomeArq, "w");	//w - write   /   r - read   /   a - append 



	//sucesso: retorna endereço do arquivo para 'arq', erro: retorna null
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
		
		/*********************** fechar o arquivo ***************************************/
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