/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos
	
	Lista de Exercícios IV (Matrizes)
	
	QUESTÃO 06:
	Considere uma loja que mantém em uma matriz o total vendido por cada funcionário pelos diversos meses 
	do ano. Ou seja, uma matriz de 12 linhas (uma por mês) e 10 colunas (10 funcionários). 
	Pede-se o desenvolvimento de uma função para cada item abaixo:

	a.	Calcular o total vendido durante o ano;
	b.	Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês;
	c.	Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano;
	d.	Determinar o mês com maior índice de vendas;
	e.	Determinar o funcionário que menos vendeu durante o ano.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define MESES 3 //L
#define FUNC 3	//C

//declaração de protótipos
void exibirMatriz(float matriz[MESES][FUNC]);
void preencherAleatorio(float matriz[MESES][FUNC]);

// a) Calcular o total vendido durante o ano
float totalVendas(float matriz[MESES][FUNC]);

//b)Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês atentar ao fato de que i e j
//são apenas variaveis, representar por LINHA(L) e COLUNA(C) pode ajudar
float totalVendasMes(float matriz[MESES][FUNC], int mes);

//c)Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano
float totalVendasFuncionario(float matriz[MESES][FUNC], int funcionario);

//Determinar o mês com maior índice de vendas
int mesMaiorIndiceVendas(float matriz[MESES][FUNC]);

//Determinar o funcionário que menos vendeu durante o ano
int funcMenorIndiceVendas(float matriz[MESES][FUNC]);

//main
void main()
{
	//declaração de variáveis
	float vendas[MESES][FUNC];
	int mes, codeFuncionario;

	//preenchendo a matriz aleatoriamente
	preencherAleatorio(vendas);

	//exibindo a matriz vendas
	exibirMatriz(vendas);

	printf("Total de vendas: %.1f", totalVendas(vendas));
			/* 
														ATENÇÃO 
			para economizar tempo passar o valor desejado como parâmetro(evitando o printf/scanf)
			por ex: printf("%10.2f", totalVendasMes(vendas, 0)); LOGO o valor será JANEIRO
			*/
	printf("\n\nEntre com o mes desejado:\nConsidere |0 - Janeiro ah 11 - Dezembro| ");
	scanf("%d", &mes);

	//o print exibe o valor do retorno das funções.
	printf("\nTotal:%10.2f", totalVendasMes(vendas, mes));

	//dados funcionarios
	printf("\n\nEntre com o codigo:\nConsidere |00000 - PRIMEIRO | 00009 - ULTIMO | ");
	scanf("%d", &codeFuncionario);

	//o print exibe o valor do retorno das funções.
	printf("\nTotal vendas Funcionario: %10.2f", totalVendasFuncionario(vendas, codeFuncionario));
	
	 //função 'mesMaiorIndiceVendas'
    mes = mesMaiorIndiceVendas (vendas);

    printf ("\nMes com maior indice de vendas: %d\n", mes);

    //função 'funcMenorIndiceVendas'
    codeFuncionario = funcMenorIndiceVendas (vendas);
    printf ("\nFuncionario com menor indice de vendas: %d\n", codeFuncionario);
}

//implementação das funções auxiliares exibindo a matriz e preenchendo a matriz com números aleatórios
void exibirMatriz(float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int i, j;

	printf("\n\nElementos da matriz:\n\n");
	for (i = 0; i < MESES; i++)
	{
		for (j = 0; j < FUNC; j++)
		{
			printf("R$ %5.2f ", matriz[i][j]);
		}

		printf("\n");
	}
}

void preencherAleatorio(float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int i, j;

	srand(time(NULL));
	for (i = 0; i < MESES; i++)
	{
		for (j = 0; j < FUNC; j++)
		{
			matriz[i][j] = 1 + rand() % 10; //gerando números aleatórios no intervalo de 1 a 10000
		}
	}
}

//Funções Enunciado a) Calcular o total vendido durante o ano
float totalVendas(float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int i, j;
	float soma = 0;

	for (i = 0; i < MESES; i++)
	{
		for (j = 0; j < FUNC; j++)
		{
			soma = soma + matriz[i][j];
		}
	}
	return soma;
}

// b) Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês
float totalVendasMes(float matriz[MESES][FUNC], int mes)
{
	int j; //coluna
	float soma = 0;

	//OBS: Se não designássemos na main, o valor intuitivo ao usuário seria 1- JAN... logo:

	//mes--;
	//covertendo o mês do intervalo de 1 a 12 (conforme fornecido pelo usuário) para o intervalo de 0 a 11

	for (j = 0; j < FUNC; j++)
	//variamos apenas a coluna pois o mês  é informado pelo usuário, sendo este um parâmetro que terá seu valor atribuído
	//em matriz[meses==linha][coluna]
	{
		//linha fixa coluna varia
		soma += matriz[mes][j]; //soma = soma + matriz[mes][i]
	}
	return soma;
}

//Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano
float totalVendasFuncionario(float matriz[MESES][FUNC], int funcionario)
{
	int i; // linha
	float soma = 0;

	for (i = 0; i < MESES; i++)
	{
		//COLUNA fixa LINHA varia

		soma += matriz[i][funcionario]; //soma = soma + matriz[mes][i]
	}
	return soma;
}

//Determinar o mês com maior índice de vendas
int mesMaiorIndiceVendas(float matriz[MESES][FUNC])
{
	/*
	Após somar o mês todo em uma variável, antes de ir para outro mês você compara 
	com a variável maior. SE for maior você substitui na variável e deixa salvo o mês. 
	Zera a soma e vai pra outra linha 
	*/

	//declaração de variáveis
	int i, j, mes;
	float soma, max = -1;

	//variando os meses
	for (i = 0; i < MESES; i++)
	{
		int mes;
		//zerando a soma, de forma que armazene o total vendido no mês 'i'
		soma = 0;

		//variando as colunas
		for (j = 0; j < FUNC; j++)
		{
			soma += matriz[i][j];
		}

		//verificando se o mês 'i' apresentou o maior índice de vendas até o momento
		if (soma > max)
		{
			//guardando o maior valor vendido em determinado mês
			max = soma;
			mes = i;
			//armazenando o mês, com o cuidado de converter 0..11 para 1..12
			//mes = i+1;
		}

		//retornando o resultado (o mês que apresentou o maior índice de vendas)
		return mes;
	}
}
//Determinar o funcionário que menos vendeu durante o ano
int funcMenorIndiceVendas(float matriz[MESES][FUNC])

{

	//declaração de variáveis

	int i, j, funcionario;

	float soma, min = 100000;

	//variando as colunas

	for (j = 0; j < FUNC; j++)

	{

		//zerando a soma, de forma que armazene o total vendido pelo funcionário 'j'

		soma = 0;

		//variando os meses

		for (i = 0; i < MESES; i++)

		{
			soma += matriz[i][j];
		}

		//verificando se o funcionário 'j' apresentou o menor índice de vendas até o momento

		if (soma < min)
		{
			//guardando o menor valor vendido por determinado funcionário

			min = soma;

			funcionario = j + 1;

			//armazenando o funcionário, com o cuidado de converter 0..9 para 1..10

			//funcionario = j+1;
		}
	}

	//retornando o resultado (o funcionário que apresentou o menor índice de vendas)
	return funcionario;
}
