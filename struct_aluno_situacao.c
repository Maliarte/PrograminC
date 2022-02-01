/*
	FAETERJ-Rio
	FPR - 2021/2 - Manhã
	Data: 18/11/2021
	
	STRUCTS
	
	Exercício:
	
	Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno, as notas 
	de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

		- A declaração do vetor, assim como de todos os tipos de dados necessários, caso existam;
		- Uma função que leia os dados de todos os alunos da turma;
		- Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a sua situação;
		- Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos os alunos 
		que estão nesta situação.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

//definição de tipos
typedef struct {
	char nome[30];
	float av1,
	      av2,
	      media;
	char situacao[10];
} TAluno;

//protótipos das funções
void leituraDadosAlunos (TAluno vetor[], int quant);
void calculaMediaSituacao (TAluno vetor[], int quant);
void exibirAlunosPorSituacao (TAluno vetor[], int quant, int sit);

//main
void main ()
{
	//declaração de variáveis
	TAluno turma[TAM];
	
	//lendo nome e as notas da av1 e av2 de cada aluno
	leituraDadosAlunos (turma, TAM);
	
	//calculando a média e a situação de cada aluno
	calculaMediaSituacao (turma, TAM);
	
	//exibindo os alunos aprovados
	printf ("\n\nAlunos aprovados:\n");
	exibirAlunosPorSituacao (turma, TAM, 1);
	
	//exibindo os alunos reprovados
	printf ("\n\nAlunos reprovados:\n");
	exibirAlunosPorSituacao (turma, TAM, 2);
	
	//exibindo os alunos em AVF
	printf ("\n\nAlunos em AVF:\n");
	exibirAlunosPorSituacao (turma, TAM, 3);
}

//implementação das funções
void leituraDadosAlunos (TAluno vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//lendo os dados de cada aluno
	for (i=0;i<quant;i++)
	{
		fflush (stdin);
		printf ("Nome: ");
		gets (vetor[i].nome); //A função gets() lê uma string do teclado. Sua forma geral é:
		
		printf ("AV1: ");
		scanf ("%f", &vetor[i].av1);
		
		printf ("AV2: ");
		scanf ("%f", &vetor[i].av2);
	}
}

void calculaMediaSituacao (TAluno vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//calculando a média e a situação de cada aluno
	for (i=0;i<quant;i++)
	{
		//calculando a média, a partir dos valores da AV1 e da AV2
		vetor[i].media = (vetor[i].av1 + vetor[i].av2)/2;
		
		//calculando a situação, a partir da média
		if (vetor[i].media >= 6)
		{
			strcpy (vetor[i].situacao, "APROVADO");
		}
		else
		{
			if (vetor[i].media < 4)
			{
				strcpy (vetor[i].situacao, "REPROVADO");
			}
			else
			{
				strcpy (vetor[i].situacao, "AVF");
			}
		}
	}
}

void exibirAlunosPorSituacao (TAluno vetor[], int quant, int sit)
{
	//declaração de variáveis
	char busca[10];
	int i;
	
	//colocando em 'busca' a situação dos alunos que devem ser exibidos
	switch (sit)
	{
		case 1: strcpy (busca, "APROVADO");
		        break;
		        
		case 2: strcpy (busca, "REPROVADO");
		        break;
		        
		case 3: strcpy (busca, "AVF");
		        break;
	}
	
	//buscando no vetor os alunos com a situação desejada (e definida pelo parâmetro 'sit')
	for (i=0;i<quant;i++)
	{
		if (strcmp(vetor[i].situacao, busca) == 0)
		{
			printf ("Nome: %s\nAV1: %.1f  AV2: %.1f Media: %.1f\n\n", vetor[i].nome, vetor[i].av1, vetor[i].av2, vetor[i].media);
		}
	}
}