#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipo da função
int contabilizaStr   (char string1[], char string2[]);
void removeCaracteres (char string[]);

void main()
{
    char string1[30];
    char string2[30];

    //limpa buffer de entrada
    fflush(stdin);
    printf("Entre com a primeira Palavra: ");
    gets(string1);

    fflush(stdin);
    printf("Entre com a segunda Palavra: ");
    gets(string2); //guarda caracteres especiais

    //exibindo resultado
    printf("\n A palavra %s e a palavra %s possuem [%d] caracteres iguais.\n", string1, string2, contabilizaStr(string1, string2));
}

int contabilizaStr(char string1[], char string2[])
{
    int i, j, cont = 0;
    char stringG1[strlen(string1) + 1], stringG2[strlen(string2) + 1];
                                                                                // Exemplo: CASA | strlen(string1) vai retornar 4
                                                                                // stringG1[4+1] == stringG1[5]

    strcpy(stringG1, string1);
    strcpy(stringG2, string2);

    removeCaracteres(stringG1);                                                    // casa\0 == cas\0\0
    removeCaracteres(stringG2);                                                   // cocada == coad\0\0

        //percorrendo a primeira palavra
        for (i = 0; stringG1[i] != '\0'; i++)
        {
            //percorrendo a segunda palavra
            for (j = 0; stringG2[j] != '\0'; j++)
            {
                if (stringG1[i] == stringG2[j]) //verificando cada caracter igual
                {
                    cont += 1;
                }
            }
        }

    return cont;
}

void removeCaracteres(char string[])
{
    //declaração de variáveis
    int i, j,  pos;
    
    //percorrendo a primeira palavra
    for (i = 0; string[i] != '\0'; i++)
    {
        //percorrendo a segunda palavra
        for (j = i + 1; string[j] != '\0'; j++)
        {
            if (string[i] == string[j])
            //verificando cada caracter igual
            {

                for (pos = j; string[pos] != '\0'; pos++)
                {
                    string[pos] = string[pos+1];
                }
            
            }
        }
    }
}