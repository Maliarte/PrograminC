/*
       Programa desenvolvido por Marília S.
        | AVS de FPR 2021.2 | 02.02.2022 |

        Docente: Leonardo Vianna

        Q3) Dado um vetor que armazene, em cada uma de suas posicoes:
        *  nome de uma pessoa
        *  sua idade.

        *  Desenvolver uma função que ordene decrescentemente pela idade.

        *  Em caso de idades iguais:
        *  ordenar nomes alfabeticamente


VETOR[2]
      ' nome da pessoa
      ' idade
*/
// importação de bibliotecas
#include <stdio.h>

// declaração de constantes
#define TAM 5

// definição de tipos
typedef struct
{
    char nome[30];
    int idade;
} Tpessoa;

// prototipos
void preencherVetor(Tpessoa vetor[], int quant);
void exibirVetor(Tpessoa vetor[], int quant);
void ordenarDecrescenteIdade(Tpessoa vetor[], int quant);

void main()
{
    int resp;
    Tpessoa vetor[TAM];

    // preenchendo o vetor
    preencherVetor(vetor, TAM);

    // exibindo os dados do vetor
    exibirVetor(vetor, TAM);

    resp = ordenarDecrescenteIdade(vetor, TAM);
    // exibir
    // printf("", resp);
}

// função para preencher os dados do vetor, com os nomes e as datas de aniversário das pessoas
void preencherVetor(Tpessoa vetor[], int quant)
{
    // declaração de variáveis
    int i;

    // percorrendo o vetor
    for (i = 0; i < quant; i++)
    {
        // leitura do nome da pessoa
        fflush(stdin);
        printf("Nome: ");
        gets(vetor[i].nome);

        fflush(stdin);
        printf("Idade: ");
        scanf("%d", &vetor[i].idade);

        printf("\n");
    }
}

// função que exibe os dados de todas as pessoas do vetor
void exibirVetor(Tpessoa vetor[], int quant)
{
    // declaração de variáveis
    int i;

    // percorrendo o vetor
    for (i = 0; i < quant; i++)
    {
        printf("Nome: %s\n", vetor[i].nome);
        printf("Idade: %d\n\n", vetor[i].idade);
    }
}

void ordenarDecrescenteIdade(Tpessoa vetor[], int quant)
{
    int i;

    // ver se idade sao iguais
    for (i = 0; i < quant; i++)
    {
        if (vetor[i].idade == )
    }
}
