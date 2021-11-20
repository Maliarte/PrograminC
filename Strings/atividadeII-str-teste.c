
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipo da função
int contabilizaStr(char string1[], char string2[]);


void main()
{
    char string1[30];
    char string2[30];
    int quant;

    //limpa buffer de entrada
    fflush(stdin);
    printf("Entre com a primeira Palavra: ");
    gets(string1);

    fflush(stdin);
    printf("Entre com a segunda Palavra: ");
    gets(string2); //guarda caracteres especiais

    
    quant = contabilizaStr(string1, string2);

    //exibindo resultado
    printf("\n A palavra %s e a palavra %s possuem [%d] caracteres iguais.\n", string1, string2, quant);
}

int contabilizaStr(char string1[], char string2[])
{
    int i, j, cont = 0;
    char stringG1[30], stringG2[30];
    //int  a, b;

    strcpy(stringG1, string1);
    strcpy(stringG2, string2);

     
                
    //percorrendo a primeira palavra
    for (i = 0; string1[i] != '\0'; i++)
    {   
            //percorrendo a segunda palavra
            for (j = 0; string2[j] != '\0'; j++)
            {
               
                if (string1[i] == string2[j])  //verificando cada caracter igual
                {
                    cont += 1;
                }
               
            }   
    }
                //decrementando repetição de termos
                if(string1[i] == stringG1[i] || string2[j] == stringG2[j])
                {
                    cont--;
                }
                 
                return cont;
}