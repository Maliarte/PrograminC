/*
	FPR - Fundamentos de Programação
	
    Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos!
		
	Structs
	
	Lista de Exercícios VIII
	
	Questão 01:
	
	Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de structs 
	contendo as seguintes informações, para cada veículo: placa, modelo, marca, cor, 
	quilometragem, ano (modelo/fabricação deve ser um struct), valor e tipo (usado ou 
	0 km, conforme o valor do campo quilometragem). 

	Pede-se a declaração de uma variável que represente o estoque de veículos da loja, 
	incluindo todas as declarações de tipos que possam ser necessárias.

	Além disso, implementar as seguintes funções: 
	i.	 Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), 
	     com valor não superior a x reais;
	ii.	 Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
	iii. Retirar do estoque um determinado veículo, dada a sua placa.

==============================
Carros:

Chery QQ Smile, a partir de 28.740
Fiat Mobi Easy 33.490
Renault Kwid Life, a partir de 34.790
Fiat Uno 42.990
Fiat 500 Cult 1.4 39.411
Caoa Chery Tiggo  (SUV - Sport Utility Vehicle)

*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//declaração de constantes
#define CAP 2

//definição de tipos
typedef struct
{
	int modelo; 
	int fabricacao;
} TAno;

typedef struct
{
	char placa[8]; 
	char modelo[20];
	char marca[20];
	char cor[20];
	float quilometragem;
	TAno ano;
	float valor;
	char tipo[6];
} TCarro;


//protótipos das funções

void lerDadosCarros(TCarro vetor[], int quantidade);

void exibirCarros(TCarro vetor[], int quantidade, char mod[], int ano1, int ano2, float preco);
void reajustarCarro0km(TCarro vetor[], int quantidade);
int removerCarro(TCarro vetor[], int *quantidade, char placa[]);

void exibirDadosCarro(TCarro carro);
void exibirTodosCarros(TCarro vetor[], int quantidade);



void main()

{ //declaração de variáveis
				/* 
				   declaração de uma variável que represente o estoque de veículos da loja,  
				   incluindo todas as declarações de tipos que possam ser necessárias.
				*/
	TCarro loja[CAP]; 
	int quantCarros = CAP;
	char placa[8];

	//preenchendo o vetor de structs
	lerDadosCarros(loja, quantCarros);

	//exibindo os dados dos carros
	exibirTodosCarros(loja, quantCarros);

	//a partir de agora, serão feitas chamadas para testar se as funções estão corretas


	//exibindo carros a partir de alguns filtros
	printf ("\n\nExibindo: HB20 - fabricacao entre 2015 e 2020 - valor máximo: 25000:\n\n");
	exibirCarros (loja, quantCarros, "HB20", 2015, 2020, 25000);


	//reajustando os valores dos carros 0 km (2.5%)
	reajustarCarro0km (loja, quantCarros);

	//tentando remover um carro cuja placa não existe na loja
	//removerCarro(TCarro vetor[], int *quantidade, char placa[]);
	
	strcpy (placa, "XYZ1234");

	if (removerCarro (loja, &quantCarros, placa) == 1)
	{ printf ("\n\tO carro de placa %s foi retirado do cadastro com sucesso!\n", placa);
	}else{
			printf ("\n\tErro: o carro de placa %s nao encontra-se no cadastro!\n", placa); }
	
	//tentando remover um carro cuja placa existe na loja 

	strcpy (placa, "ABC1234");
		if (removerCarro (loja, &quantCarros, placa) == 1)
		{
			printf ("\n\tO carro de placa %s foi retirado do cadastro com sucesso!\n", placa);
		} else {
			printf ("\n\tErro: o carro de placa %s nao encontra-se no cadastro!\n", placa);
		}

	//exibindo os carros da loja, após as operações realizadas
	exibirTodosCarros (loja, quantCarros);
}




///////////////////////////////////////////////////// FIM MAIN /////////////////////////////////
//implementação das funções/////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lerDadosCarros(TCarro vetor[], int quantidade)
{
	//declaração de variáveis
	int i; 
	int tipoCarro;

	//lendo os dados dos carros da loja
	for(i = 0; i < quantidade; i++)
	{
		fflush(stdin);
		printf("Placa: ");
		gets(vetor[i].placa); 

		fflush(stdin);
		printf("Modelo: ");
		gets(vetor[i].modelo);
		
		fflush(stdin);
		printf("Marca: ");
		gets(vetor[i].marca);
		
		fflush(stdin);
		printf("Cor: ");
		gets(vetor[i].cor);
		
		printf("Digite: \n");
		printf (" [0] - 0 KM | [1] - USADO): ");
		scanf ("%d", &tipoCarro);
		
		if (tipoCarro == 0)
		{
			strcpy(vetor[i].tipo, "0 KM");
			vetor[i].quilometragem = 0;
		} else {
			strcpy(vetor[i].tipo, "USADO");
			printf("Quilometragem:\n");
			scanf("%f", &vetor[i].quilometragem);
			}

			printf ("Ano do modelo: ");
			scanf ("%d", &vetor[i].ano.modelo);
			
			printf ("Ano de fabricacao: ");
			scanf ("%d", &vetor[i].ano.fabricacao);

			printf ("Valor: ");
			scanf ("%f", &vetor[i].valor);

			printf ("\n\n");
	}
}


//Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive),com valor não superior a x reais	
void exibirCarros(TCarro vetor[], int quantidade, char mod[], int ano1, int ano2, float preco)
{	
	//declaração de variáveis
	int i;

	//percorrendo o vetor de carros
	for (i = 0; i < quantidade; i++)
	{    /* exibirCarros (loja, quantCarros, "HB20", 2015, 2020, 25000);*/
		if ((strcmp (vetor[i].modelo, mod) == 0)        &&
					((vetor[i].ano.fabricacao >= ano1)  &&  
					(vetor[i].ano.fabricacao <= ano2))  &&
					(vetor[i].valor <= preco))
		{
			exibirDadosCarro(vetor[i]);
		}
	}
}

//Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5 %
void reajustarCarro0km(TCarro vetor[], int quantidade)
{
	//declaração de variáveis
	int i;

	//percorrendo o vetor de carros
	for (i = 0; i < quantidade; i++)
	{
		//verificando se trata-se de um carro 0 KM
		if (strcmp(vetor[i].tipo, "0 KM") == 0)
		{
			//vetor[i].valor = vetor[i].valor +
			vetor[i].valor *(2.5 / 100);
			
			//vetor[i].valor = vetor[i].valor +
			//vetor[i].valor * 0.025;
			vetor[i].valor += vetor[i].valor * 0.025;
		}
	}
}
//Retirar do estoque um determinado veículo, dada a sua placa

//versão 1: deslocar todos os elementos da posição i+1 ao final uma posição para a esquerda 
int removerCarro(TCarro vetor[], int *quantidade, char placa[])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo o vetor de carros
	for (i = 0; i < *quantidade; i++)
	{
		//verificando se a placa foi encontrada
		if (strcmp(vetor[i].placa, placa) == 0)
		{
			//remover o elemento da posição i
			//versão 1: deslocar todos os elementos da posição i + 1 ao final uma posição para a esquerda 
			for (j = i + 1; j < *quantidade; j++)
			{  	
				//vetor anterior recebe a posicao do j  *****veja linha 312*****
				vetor[j - 1] = vetor[j];


				/* 
				observação: 
								não é necessário copiar campo a campo.
								O ideal é copiar todo o struct de uma só vez!
				*/
			}
			//atualizando a quantidade de elementos do vetor

			(*quantidade)--;
			
			//retornando 1, representando que a remoção foi realizada 	
			return 1;
		}
	}
	//retornando 0, representando que a remoção não foi realizada (ou seja, a placa não foi encontrada no vetor) 
	return 0;
}

//exibir os dados de um carro
void exibirDadosCarro(TCarro carro)
{
	printf("Placa: %s\n", carro.placa);
	printf("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
	printf("Cor: %s\n", carro.cor);
	printf("Km: %.1f\n", carro.quilometragem);
	printf("Ano: %d/%d\n", carro.ano.modelo,
		   carro.ano.fabricacao);
	printf("Valor: R$ %.2f\n", carro.valor);
	printf("Tipo: %s\n\n", carro.tipo);
}


void exibirTodosCarros(TCarro vetor[], int quantidade)
{
	//declaração de variáveis
	int i;
	printf("\n\nExibindo todos os carros da loja:\n\n");

	//exibindo todos os carros da loja
	for (i = 0; i < quantidade; i++)
	{
		printf("=============================");
		exibirDadosCarro(vetor[i]);
		printf("=============================");
	}
}

/* 
apendice

[strcmp]
			A função strcmp tem a sintaxe strcmp(st1, st2)
			e compara duas strings, st1 e st2 , devolvendo 0 se forem iguais. 
			Se a string st1 for lexicograficamente superior a st2 será devolvido um número inteiro positivo, 
			se st1 for menor que st2 será devolvido um número negativo. 
versões: similar ao vetor de inteiros abaixo

versão 1: desloca vetor + caro
ex: placa na posicao 2

vetor[j]

           i     ________j_________
10 | 60 |- 54 -| 18 | 24 | 17 | 25
0   1     2    3    4    5    6

_____________________________
10 | 60 | 18 | 24 | 17 | 25 | 25
0   1     2    3    4    5    6

for(i = 0; i < *quantidade; i++) 
{
	//existe placa
	strcmp((vetor[i].placa, placa)=0)
	{
		for (j = i + 1; j < *quantidade; j++)
			{  	
				
				vetor[j - 1] = vetor[j];

			}
	}
}





*/