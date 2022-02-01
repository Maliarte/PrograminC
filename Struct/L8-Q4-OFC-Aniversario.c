/*
	FAETERJ-Rio
	FPR - Manhã - Professor Leonardo Vianna
	Data: 25/11/2021
	
	Structs
	
	Lista de Exercícios VIII

	Questão 04: 
	Suponha a existência de um vetor de tamanho TAM, cada posição armazenando o nome da 
	pessoa e a sua data de aniversário (representada por um struct do tipo TData, 
	contendo os campos dia e mes). Pede-se o desenvolvimento das seguintes funções:
 	
	- Determinar a quantidade de pessoas que fazem aniversário no mês M;
 	- Exibir os nomes de todas pessoas que fazem aniversário entre as datas d1 e d2, 
	  ambas do tipo Tdata.	
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define TAM 5

//definição de tipos
typedef struct {		//representando a data de aniversário, com os campos dias e mês
	int dia, mes;
} TData;

typedef struct {		//representando cada pessoa, com os campos nome e data de aniversário
	char nome[30];
	TData aniversario;
} TPessoa;

//protótipos das funções
int aniversariantesDoMes (TPessoa vetor[], int quant, int mes);
void exibirAniversariantes (TPessoa vetor[], int quant, TData d1, TData d2);

void preencherVetor (TPessoa vetor[], int quant);
void exibirVetor (TPessoa vetor[], int quant);
int verificaIntervaloDatas (TData data1, TData data2, TData data);

//main
void main ()
{
	//declaração de variáveis
	TPessoa pessoas[TAM];
	int m, resp;
	TData data1, data2;
	
	//preenchendo o vetor
	preencherVetor (pessoas, TAM);
	
	//exibindo os dados do vetor
	exibirVetor (pessoas, TAM);
	
	//testando a função que conta o nº de aniversariantes em determinado mês	
	printf ("\nEntre com um mes para saber a quantidade de aniversariantes: ");
	scanf ("%d", &m);
	
	resp = aniversariantesDoMes (pessoas, TAM, m);
	
	printf ("\n%d pessoas fazem aniversario no mes %d.\n", resp, m);
	
	//testando a função que exibe os nomes dos aniversariantes entre duas datas
	
	//lendo a primeira data
	printf ("\nEntre com a data inicial do intervalo (DD MM): ");
	scanf ("%d %d", &data1.dia, &data1.mes);
	
	//lendo a segunda data
	printf ("\nEntre com a data final do intervalo (DD MM): ");
	scanf ("%d %d", &data2.dia, &data2.mes);
	
	exibirAniversariantes (pessoas, TAM, data1, data2);	
}

//implementação das funções

//Determinar a quantidade de pessoas que fazem aniversário no mês M
int aniversariantesDoMes (TPessoa vetor[], int quant, int mes)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		//verificando se a pessoa da posição 'i' faz aniversário no mês 'mes', passado por parâmetro
		if (vetor[i].aniversario.mes == mes)
		{
			cont++;
		}
	}
	
	//retornando o resultado
	return cont;
}

//Exibir os nomes de todas pessoas que fazem aniversário entre as datas d1 e d2, 
//ambas do tipo Tdata.	
void exibirAniversariantes (TPessoa vetor[], int quant, TData d1, TData d2)
{
	/*exemplo:
		
			d1: 10/06
			d2: 01/10
	*/	
	
	//declaração de variáveis
	int i;
	
	printf ("\nAniversariantes do intervalo dado:\n\n");
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		//verificando se a pessoa da posição 'i' do vetor faz aniversário entre as 
		//datas 'd1' e 'd2'
		if (verificaIntervaloDatas (d1, d2, vetor[i].aniversario) == 1)
		{
			printf ("%s\n", vetor[i].nome);
		}
	}	
}

//verifica se 'data' está no intervalo definido por 'data1' e 'data2'
int verificaIntervaloDatas (TData data1, TData data2, TData data)
{
	/*
		Exemplo:
		
		data1: 15/04      data2:  3/12
		
		5 6 7 8 9 10 11
	*/
	
	//verificando se a data pertence a algum mês no intervalo de data1.mes+1 a data2.mes-1
	if ((data.mes > data1.mes) && (data.mes < data2.mes))
    {
    	return 1;
    }
    else 
    {
    	//verificando se a o mês da 'data' é igual ao mês da data1 ou da data2. Se for, tem que testar também os dias.
    	if (((data.mes==data1.mes) && (data.dia>=data1.dia)) || 
		    ((data.mes==data2.mes) && (data.dia<=data2.dia)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

//função para preencher os dados do vetor, com os nomes e as datas de aniversário das pessoas
void preencherVetor (TPessoa vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		//leitura do nome da pessoa
		fflush (stdin);
		printf ("Nome: ");
		gets (vetor[i].nome);
		
		//leitura da data de nascimento da pessoa
		printf ("Data de aniversario (DD MM): ");
		scanf ("%d %d", &vetor[i].aniversario.dia, &vetor[i].aniversario.mes);
		
		printf ("\n");
	}
}

//função que exibe os dados de todas as pessoas do vetor
void exibirVetor (TPessoa vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		printf ("Nome: %s\n", vetor[i].nome);
		printf ("Aniversario: %d/%d\n\n", vetor[i].aniversario.dia, vetor[i].aniversario.mes);
	}	
}