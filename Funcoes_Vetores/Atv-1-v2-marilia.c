/*
    Dada uma matriz M LINHAxCOLUNA, onde LINHA e
    COLUNA são constantes, e uma linha L,
    desenvolver uma função que retorne um vetor
    de tamanho COLUNA contendo, em cada
    posição, a quantidade de vezes que os
    elementos da linha L encontram-se nas demais
    linhas da matriz.
    Exemplo:

    1 5 7 1 6
    6 2 1 4 7
M = 3 6 9 7 1
    [2 4 5 7 4]
    2  4 8 9 2

L = 3 (ou seja, a 4a linha)

Retornará o seguinte vetor:
V = 3 2 1 3 2

Ou seja:

2 aparece 3x nas demais linhas
4 aparece 2x nas demais linhas
5 aparece 1x nas demais linhas
7 aparece 3x nas demais linhas
4 aparece 2x nas demais linhas

*/

#include <stdio.h>
#include <stdlib.h>

#define L 5
#define C 5

void exibeVetor(int matriz[L][C], int vet[], int linha);

void main()
{
    // declaracao de variaveis
    int l=2;
    int vetor[C] = {0, 0, 0, 0, 0}; // inicializando o vetor com 0
    int matriz[L][C] = {
        {1, 5, 7, 1, 6},
        {6, 2, 1, 4, 7},
        {3, 6, 9, 7, 1},
        {2, 4, 5, 7, 4},
        {2, 4, 8, 9, 2}};

//3  6  9  7  1
//0x 2x 1x 3x 3x
    exibeVetor(matriz, vetor, 2);
}

void exibeVetor(int matriz[L][C], int vet[], int linha)
{

    // declaracao de variaveis

    int varreLinha;
    int exibe; 
    int i, j;

    // percorre coluna da linha selecionada
    for (varreLinha = 0; varreLinha < C; varreLinha++)
    {

        // percorrendo as linhas da matriz
        for (i = 0; i < L; i++)
        {

            // desconsiderar a linha selecionada
            if (i != linha)
            {
                for (j = 0; j < C; j++)
                {
                    if (matriz[linha][varreLinha] == matriz[i][j])
                    {
                        vet[varreLinha]++;
                    }
                }
            }
        }
    }


// exibindo quantas vezes os elementos da linha selecionada aparecem nas outras linhas
for (exibe = 0; exibe < C; exibe++)
    {
         printf("%d vezes %d\n", vet[exibe], matriz[linha][exibe]);
    }
}