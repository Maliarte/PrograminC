/*
FAETERJ-Rio
FPR - Manhã - Professor Leonardo Vianna
Data: 24/11/2021
Structs
Lista de Exercícios VIII
Questão 01:
Uma loja de automóveis mantém os carros à venda sob a forma de
um vetor de structs
contendo as seguintes informações, para cada veículo: placa,
modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve ser um struct),
valor e tipo (usado ou
0 km, conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que represente o estoque
de veículos da loja,
incluindo todas as declarações de tipos que possam ser
necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de fabricação
entre a1 e a2 (inclusive),
 com valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0 km,
considerando um aumento de 2.5%;
iii. Retirar do estoque um determinado veículo, dada a sua
placa.
*/
//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//declaração de constantes
#define CAP 5


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
void exibirCarros(TCarro vetor[], int quantidade, char mod[], int ano1, int ano2, float preco);
void reajustarCarro0km(TCarro vetor[], int quantidade);
int  removerCarro(TCarro vetor[], int *quantidade, char placa[]);
void lerDadosCarros(TCarro vetor[], int quantidade);
void exibirDadosCarro(TCarro carro);
void exibirTodosCarros(TCarro vetor[], int quantidade);
//main
void main() {
	
	//declaração de variáveis
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
	strcpy (placa, "XYZ1234");

		if (removerCarro (loja, &quantCarros, placa) == 1)
		{
			printf ("\n\tO carro de placa %s foi retirado docadastro com sucesso!\n", placa);
		} else {
			printf ("\n\tErro: o carro de placa %s nao encontra-seno cadastro!\n", placa);
		}

	//tentando remover um carro cuja placa existe na loja
	strcpy (placa, "ABC1234");
	if (removerCarro (loja, &quantCarros, placa) == 1)
	{
		printf ("\n\tO carro de placa %s foi retirado docadastro com sucesso!\n", placa);
	}else
	{
		printf ("\n\tErro: o carro de placa %s nao encontra-se no cadastro!\n", placa);
	}

	//exibindo os carros da loja, após as operações realizadas
	exibirTodosCarros (loja, quantCarros);
}


///////////////////////////////////////////implementação das funções

//Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2(inclusive), com valor não superior a x reais
void exibirCarros(TCarro vetor[], int quantidade, char mod[], int ano1, int ano2, float preco)
{
	//declaração de variáveis
	int i;
	//percorrendo o vetor de carros
	for (i = 0; i < quantidade; i++)
	{
		if ((strcmp(vetor[i].modelo, mod) == 0) && ((vetor[i].ano.fabricacao >= ano1) && (vetor[i].ano.fabricacao <= ano2)) && (vetor[i].valor <= preco))
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
			//vetor[i].valor = vetor[i].valor + vetor[i].valor *(2.5 / 100);
			//vetor[i].valor = vetor[i].valor + vetor[i].valor * 0.025;
			vetor[i].valor += vetor[i].valor * 0.025;
		}
	}
}
//Retirar do estoque um determinado veículo, dada a sua placa

//versão 2: deslocar apenas o último elemento do vetor para a posição onde encontra - se o carro a ser removido 
int removerCarro(TCarro vetor[], int *quantidade, char placa[])
{
	//declaração de variáveis
	int i;
	//percorrendo o vetor de carros
	for (i = 0; i < *quantidade; i++)
	{
		//verificando se a placa foi encontrada
		if (strcmp(vetor[i].placa, placa) == 0)
		{
			//remover o elemento da posição i
			//versão 2: apenas o último elemento será deslocado para a posição i
			vetor[i] = vetor[(*quantidade) - 1];

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
void lerDadosCarros(TCarro vetor[], int quantidade)
{
	//declaração de variáveis
	int i, tipoCarro;
	//lendo os dados dos carros da loja
	for (i = 0; i < quantidade; i++)
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

	printf ("Tipo (digite 0 para 0 KM ou 1 para USADO):");
	scanf ("%d", &tipoCarro);
	if (tipoCarro == 0)
	{
				strcpy(vetor[i].tipo, "0 KM");
				vetor[i].quilometragem = 0;
	}
	else
	{
				strcpy(vetor[i].tipo, "USADO");
				printf("Quilometragem: ");
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
	void exibirTodosCarros(TCarro vetor[], int quantidade)
	{
		//declaração de variáveis
		int i;
		printf("\n\nExibindo todos os carros da loja:\n\n");
		//exibindo todos os carros da loja
		for (i = 0; i < quantidade; i++)
		{
			exibirDadosCarro(vetor[i]);
		}
	}