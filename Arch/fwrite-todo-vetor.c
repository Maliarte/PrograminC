/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	
	Arquivos
	
	- Exemplo de uso da função 'fwrite' (escrevendo todo o vetor de uma única vez no arquivo)
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

#define TRUE 1
#define FALSE 0

//definição de tipos
typedef enum {ZERO, USADO} tipoCarro;

typedef struct {			//representa os anos de modelo e fabricação do carro
	int anoModelo;
	int anoFabricacao;
} TAno;

typedef struct {			//representa um carro e todas as suas informações
	char placa[10];
	char modelo[20];
	char marca[20];
	char cor[20];
	float km;
	TAno ano;
	float valor;
	tipoCarro tipo;	
} TCarro;

//protótipos das funções
void preencherVetor (TCarro ag[]);
int salvar (TCarro ag[], int tamanho, char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	TCarro agencia[TAM];	
		
	//preenchendo o vetor para que as demais funções possam ser testadas
	preencherVetor (agencia);
	
	//tentando salvar os dados dos carros no arquivo 'carros.bin'
	if (salvar (agencia, TAM, "carros.bin") == TRUE)
	{
		printf ("\nArquivo gerado com sucesso!");
	}
	else
	{
		printf ("\nFalha na geracao do arquivo!");
	}
}

//implementação das funções

void preencherVetor (TCarro ag[])
{
	//1º carro
	strcpy (ag[0].placa, "ABC 1234");
	strcpy (ag[0].modelo, "HB20");
	strcpy (ag[0].marca, "HYUNDAI");
	strcpy (ag[0].cor, "PRATA");
	ag[0].km = 20000;
	ag[0].ano.anoModelo = 2016;
	ag[0].ano.anoFabricacao = 2015;
	ag[0].valor = 25000;
	ag[0].tipo = USADO;	
	
	//2º carro
	strcpy (ag[1].placa, "BCD 2345");
	strcpy (ag[1].modelo, "CIVIC");
	strcpy (ag[1].marca, "HONDA");
	strcpy (ag[1].cor, "BRANCA");
	ag[1].km = 0;
	ag[1].ano.anoModelo = 2022;
	ag[1].ano.anoFabricacao = 2022;
	ag[1].valor = 90000;
	ag[1].tipo = ZERO;	
	
	//3º carro
	strcpy (ag[2].placa, "CDE 3456");
	strcpy (ag[2].modelo, "HB20");
	strcpy (ag[2].marca, "HYUNDAI");
	strcpy (ag[2].cor, "PRETA");
	ag[2].km = 45000;
	ag[2].ano.anoModelo = 2017;
	ag[2].ano.anoFabricacao = 2017;
	ag[2].valor = 35000;
	ag[2].tipo = USADO;	
	
	//4º carro
	strcpy (ag[3].placa, "EFG 4567");
	strcpy (ag[3].modelo, "HB20");
	strcpy (ag[3].marca, "HYUNDAI");
	strcpy (ag[3].cor, "AZUL");
	ag[3].km = 58000;
	ag[3].ano.anoModelo = 2019;
	ag[3].ano.anoFabricacao = 2018;
	ag[3].valor = 40000;
	ag[3].tipo = USADO;	
	
	//5º carro
	strcpy (ag[4].placa, "FGH 5678");
	strcpy (ag[4].modelo, "ECOSPORT");
	strcpy (ag[4].marca, "FORD");
	strcpy (ag[4].cor, "VERDE");
	ag[4].km = 0;
	ag[4].ano.anoModelo = 2022;
	ag[4].ano.anoFabricacao = 2022;
	ag[4].valor = 85000;
	ag[4].tipo = ZERO;	
}

int salvar (TCarro ag[], int tamanho, char nomeArq[])
{
	//declaração de variáveis
	int i;
	FILE *arq;		//declaração do arquivo
	
	//abrindo o arquivo para escrita (arquivo binário)
	arq = fopen (nomeArq, "wb");
	
	//verificando se houve erro na abertura do arquivo
	if (arq == NULL)
	{
		return FALSE;
	}
	else
	{
		//escrevendo todo o vetor de structs, de uma única vez
		fwrite (ag, sizeof(TCarro), tamanho, arq);
		
		//fechando o arquivo
		fclose (arq);
		
		return TRUE;
	}
}