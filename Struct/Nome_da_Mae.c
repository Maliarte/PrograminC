
/*
    Atividade no 4 de Fundamentos de Programação - Professor Leonardo Vianna

Um grupo de pessoas foi entrevistado e cada pessoa informou seu nome e o nome de sua mãe.

Estes dados foram armazenados em um vetor do qual cada posição consiste em um struct.

Desenvolver uma função que receba um vetor como o descrito acima e retorne outro contendo, 
para cada mãe, o número de filhos entrevistados (portanto, um outro vetor de
structs).

Nota: considerar que não existem duas ou mais
mães com o mesmo nome.


            1. O programa deve ser feito utilizando a linguagem C;
            2. As soluções apresentadas poderão utilizar apenas as estruturas estudadas em aula;
            3. A atividade deve ser feita individualmente;
            4. Caso seja observada cópia de soluções, todos os alunos envolvidos ficarão sem nota;
            5. O arquivo .c com a solução da atividade deve ser postado no Classroom até o dia 05/12/2021.

*/

#include<stdio.h>
#include<string.h>

#define QUANT_MAX_PESSOAS 3

typedef struct Mae
{
    char nome[30];
    int quantFilhos;
} TMae;



typedef struct Pessoa
{
    char nome[30];
    TMae mae;
} TPessoa;

void main(){

    Tmae vetor[TAM];



}