/*
	Programa masserado que nem pamonha com manteiga para nenem.
	por Marília S. from MEID https://maliarte.com.br

	>>> Resolvemos seus bugs <<<

	1)Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de structs
	contendo as seguintes informações, para cada veículo: placa, modelo, marca, cor,
	quilometragem, ano (modelo/fabricação deve ser um struct), valor e tipo (usado ou
	0 km, conforme o valor do campo quilometragem).

	Pede-se a declaração de uma variável que represente o estoque de veículos da loja[checked],
	incluindo todas as declarações de tipos que possam ser necessárias.

	Além disso, implementar as seguintes funções:
	i.	 Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive),
		 com valor não superior a x reais;
	ii.	 Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
	iii. Retirar do estoque um determinado veículo, dada a sua placa.

___________________________

	Entendendo Strutcs com   [Marília] (https://github.com/maliarte)
	+ ajuda do Universitário [Math] (https://github.com/matheusmartinsdev)

	Dúvida inicial:

			void exibirDadosCarro(Tcar carro){printf("Km: %.1f\n", carro.kmetragem);}

			Não declarei a variavel "carro" em nenhum lugar do programa, apesar disso, o fato de
			atribuir a mesma o tipo ("Tcar"), consigo ter acesso aos campos do mesmo.


	"```" le pergunte:
		marília:
		Sobre declaracao de tipos, sendo um vetor de structs,
		não importa o nome da variável. Se tiver o tipo do structs atrelada,
		você consegue acessar aos campos do mesmo "```"


		le response:
		math:
		Struct é um tipo de dado, um registro.

		[18:04, 22/01/2022] ---

		Math:

		 Só que, esse tipo de dado pode conter dados diferentes dentro de si,
		 como o tipo nota e o tipo disciplina, que são float e char* respectivsmente
		 Esses dados de uma struct, vc consegue acessar por campos
		 Por isso, tenha em mente que
		 campo != posição  campo != índice
		 São conceitos diferentes.

		 Fico meio reticente de dizer SIM e te dar um falso positivo...


	Quando vc fala "sendo um vetor de structs" e depois termina com "acessar aos campos de uma struct",
	vc está dizendo que isso aqui é possível:


typedef struct
{
	char disciplina[4];
	float nota;
} TNotas


void main () {

	 TNota notas[3];

	 strcpy(notas[0].disciplina, "FPR");
	 notas[0].nota = 9.5;
}

>A sua função exibe apenas um elemento Tcar, não um vetor
Para ser um vetor teria de ser:


void exibirDadosCarro(Tcar carros[])

Ou então


void exibirDadosCarro(Tcar *carros)

[6:06 PM, 22/01/2022] Math:
		Repare em como eu fiz aqui q isso vai te dar uma ideia
		Math: E tbm, na sua função exibirDadosCarro, além do seu vetor de carros, vc precisa da quantidade de carros
		Math: Logo, mais um parâmetro
		Math: É o velho "quant"

*/
// importacao de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declarações de tipos que possam ser necessárias.
typedef struct
{
	char modelo[20];
	int fabricacao;
} Tano;

typedef struct
{
	/* para cada veículo: placa, modelo, marca, cor,
	quilometragem, ano (modelo/fabricação deve ser um struct), valor e tipo (usado ou
	0 km, conforme o valor do campo quilometragem)*/
	char placa[7];
	char modelo[20];
	char marca[20];
	char cor[20];
	float kmetragem;
	Tano ano;
	float valor;
	char tipo[10];
} Tcar;

void preencher(Tcar vetor[], int quant);
void exibir(Tcar vetor[], int quant, char modelo[], int ano1, int ano2, float preco);
void exibirDadosCarro(Tcar carro); // exibirDadosCar(vetor[i])
void reajustar(Tcar vetor[], int quant);
void remover(Tcar vetor[], int *quant, char placa[]);

void main()
{
	/*
	1)declaração de uma variável que represente o estoque de veículos da loja [x]
	2)todas as declarações de tipos que possam ser necessárias. ****

	No item dois, o enunciado expande o desenvolvimento da questão. Ora, se tenho um vetor de structs
	contendo dados de veículos, necessito da quantidade dos mesmos, bem como de uma primary key, que
	nesse caso, foi a placa.

	 */
	Tcar Loja[3];
	/* 
	Representação..:	
	
	
									  loja [0, 1, 2]
	char placa[7]	  						'
	char modelo[20];						'
	char marca[20];							'
	char cor[20];							'
	char kmetragem[7];						'
	Tano ano;								'
	float valor;							'
	char tipo[10];							'
										    \/
										campos do struct Tcar
	*/
	int quantCar = 2;
	char placa[8]; // vetor de caracteres + '\0'

	/*
		Recepção de Dados...:
				- preencher e exibir
	*/

	prencher(Loja, quantCar);
	exibir(Loja, quantCar, "HB20", 2015, 2020, 25000);
}

//////////////////////////////////// FIM MAIN /////////////////////////////////////
/* Tipos só na signature bb */
void preencher(Tcar vetor[], int quant)
{
	int i;
	for (i = 0; i < quant; i++)
	{
		// entre....sigin

		strcpy(vetor[i].placa, "KUK0189");
		strcpy(vetor[i].modelo, "SUV");
		strcpy(vetor[i].marca, "Logan");
		strcpy(vetor[i].cor, "verde");

		/*
		De modo geral, o mercado considera de 10 a 15 mil km rodados por ano a média ideal
		para que um carro não seja considerado desgastado. A baixa quilometragem também é
		um dos critérios usados para definir se um carro será considerado um seminovo ou um
		usado. Nesse caso, a média é de até 20 mil km rodados

		*/

		printf("Quilometragem:\n");
		scanf("%f", &vetor[i].kmetragem);

		// Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
		if (vetor[i].kmetragem == 0)
		{
			strcpy(vetor[i].tipo, "NOVO");
			reajustar(vetor, quant);
		}
		if (vetor[i].kmetragem < 20000) // abaixo de 20.000km rodados
		{
			strcpy(vetor[i].tipo, "SEMINOVO");
		}
		else
		{
			strcpy(vetor[i].tipo, "USADO");
		}
		printf("Ano do modelo: ");
		scanf("%d", &vetor[i].ano.modelo);

		printf("Ano de fabricacao: ");
		scanf("%d", &vetor[i].ano.fabricacao);

		printf("Valor: ");
		scanf("%f", &vetor[i].valor);

		printf("\n\n");
	}
}

// i. Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor não superior a x reais;
void exibir(Tcar vetor[], int quant, char modelo[], int ano1, int ano2, float preco)
{
	int i;

	// percorrendo o vetor de carros
	for (i = 0; i < quant; i++)
	{

		if ((strcmp(vetor[i].modelo, modelo) == 0) && (vetor[i].ano.fabricacao >= ano1) && 
		(vetor[i].ano.fabricacao <= ano2) &&(vetor[i].valor <= preco))
			{
				exibirDadosCarro(vetor[i]); 
				// passando uma posição específca do vetor  logo na função  o parâmetro 'carro'
				//representa uma unidade do mesmo

			}
	}
}
// exibir os dados de um carro
void exibirDadosCarro(Tcar carro)
{
	printf("Placa: %s\n", carro.placa);
	printf("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
	printf("Cor: %s\n", carro.cor);
	printf("Km: %.1f\n", carro.kmetragem);
	printf("Ano: %d/%d\n", carro.ano.modelo,
		   carro.ano.fabricacao);
	printf("Valor: R$ %.2f\n", carro.valor);
	printf("Tipo: %s\n\n", carro.tipo);
}

// ii.Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
void reajustar(Tcar vetor[], int quant)
{

	// declaração de variáveis

	int i;

	// percorrer vetor carros

	for (i = 0; i < quant; i++)
	{

		// verificar se trata-se de um carro 0km
		if (strcmp(vetor[i].tipo, "0 km") == 0)
		{
			//reajustando os valores dos carros 0 km (2.5%)
			vetor[i].valor *= 0.025; //vetor[i].valor = vetor[i].valor * 0.025;
		}
	}
}
// iii. Retirar do estoque um determinado veículo, dada a sua placa.
void remover(Tcar vetor[], int *quant, char placa[])
{
	// declaracao de variaveis

	int i, j;

	// percorrendo vetor
	for (i = 0; i < *quant; i++)
	{

		if (strcmp(vetor[i].placa, placa) == 0)
		{

			// versão 1: deslocar todos os elementos da posição i + 1 ao final uma posição para a esquerda
			for (j = 0; j < *quant; j++)
			{
				 vetor[j - 1] = vetor[j];
			}
		}
	}
}