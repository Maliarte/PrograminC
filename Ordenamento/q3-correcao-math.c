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
        * marilia - matheus
        *
        *


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
void selection_sort_idade(Tpessoa num[], int tamanho);
void selection_sort_nome(char string1[], char string2[]);
int compara_strings(char string1[], char string2[]);

void main()
{
    Tpessoa vetor[TAM];

    // preenchendo o vetor
    preencherVetor(vetor, TAM);

    // exibindo os dados do vetor antes de ordenar
    printf("Exibindo ANTES de ordenar: \n");
    exibirVetor(vetor, TAM);

    // ordenar
    ordenarDecrescenteIdade(vetor, TAM);

    printf("Exibindo APOS ordenar: \n");
    // exibir após ordenar
    exibirVetor(vetor, TAM);
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
        // fflush(stdin);
        __fpurge(stdin);
        printf("Nome: ");
        gets(vetor[i].nome);

        // fflush(stdin);
        __fpurge(stdin);
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

/**
 * [Marilia - 26] [Matheus - 27] [Fulanoo - 22]
 * [     0      ] [     1      ] [     2      ]
 */

void ordenarDecrescenteIdade(Tpessoa vetor[], int quant)
{
    int i, j;
    Tpessoa aux;

    for (i = 0; i < quant; i++)
    {
        for (j = i + 1; j < quant; j++) // varrendo a partir do próximo elemento
        {
            // idades diferentes, então devo ordenar por idade
            if (vetor[i].idade != vetor[j].idade)
            {
                if (vetor[i].idade < vetor[j].idade)
                {
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }
            }
            else // se entrou aqui, as idades são iguais
            {
                if (strcmp(vetor[i].nome, vetor[j].nome) < 0)
                {
                    aux = vetor[j];
                    vetor[j] = vetor[i];
                    vetor[i] = aux;
                }
            }
        }
    }
}

int compara_strings(char string1[], char string2[])
{
    int x, y;

    for (x = 0; string1[x]; x++)
    {
        for (y = 0; string2[y]; x++)
        {
            if (string1[x] < string2[y])
            {
                return 1;
            }
        }
    }

    return 0;
}

// void selection_sort_idade(Tpessoa num[], int tamanho)
// {
//     // declaração de variaveis
//     int i, j, min, aux;

//     for (i = 0; i < (tamanho - 1); i++)
//     {
//         min = i;

//         // j iniciando na posicao seguinte ao i
//         for (j = (i + 1); j < tamanho; j++)
//         {
//             // achar o valor minimo
//             if (num[j].idade < num[min].idade)
//             {
//                 /*      comparando o indice do segundo for com o o do primeiro
//                             o index do vetor num, como sendo 'min' ou seja será  o indice de 'i' atual.*/
//                 min = j;
//             }
//         }
//         // comparando o ultimo elemento percorrido em 'i' e se ele for diferente do menor valor
//         // irá fazer a troca. ou seja, i ja é o menor o menor numero entre os numeros analizados
//         if (i != min)
//         {
//             aux = num[i].idade;
//             num[i].idade = num[min].idade;
//             num[min].idade = aux;
//         }
//     }
// }

// void selection_sort_nome(char string1[], char string2[])
// {
//     // declaração de variaveis
//     int i, j, min, aux;

//     // percorrendo um nome (vetor[i].nome)
//     for (j = 0; j < strlen(string1[i].nome); j++)
//     {
//     }
// }
