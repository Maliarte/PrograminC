/*
       Programa desenvolvido por Marília S.
        | AVS de FPR 2021.2 | 02.02.2022 |

        Docente: Leonardo Vianna

Q2) Dadas duas strings s1 e s2, implementar uma função que verifique se a segunda é uma "versão embaralhada" da primeira.
ex..:
    TRUE
    s1 ="CASA"   s2="SAAC",       s2  é      uma versão embaralhada da s1.

    FALSE
    s1 ="TESTE"  s2="COPO",       s2 não é  uma versão embaralhada da s1.
    s1 ="CACHORRO"  s2="HOAORC",  s2 não é  uma versão embaralhada da s1.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototipos
int embaralhada(char string1[], char string2[]);

void main()
{
    // declaracao de variaveis
    char s1[30], s2[30];

    strcpy(s1, "CASA");
    strcpy(s2, "SAAC");

    embaralhada(s1, s2);
}

int embaralhada(char string1[], char string2[])
{
    int i, j;
    int sizestr1, sizestr2;
    /*
     *percorrer  e comparar strings
     *se encontrar o primeiro char diferente
     *retorna falso
     */

    // caso geral
    // comparar tamanhos da string
    // depois comparar caracteres entre strings

    sizestr1 = strlen(string1); // retorna o tamanho de caracteres, ex: casa return 4 caracteres.
    sizestr2 = strlen(string2);

    if (sizestr1 != sizestr2)
    {
        return 0; // acaba funcao com falso
    }

    // percorrendo a string1
    for (i = 0; i < sizestr1; i++)
    {
        //percorrendo string2
        for (j = 0; j < sizestr2; j++)
        {
            if((string1[i] != string2[j]) && () ){

                return 1;
            }
           // C | A | S | A \0
           // S | A | A | C \0
        }
    }
}