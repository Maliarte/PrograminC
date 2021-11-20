/*

    FPR - Fundamentos de Programação

       FPR - Fundamentos de Programação
      Notes by Marília Silva | https://maliarte.com.br

        * Apoie o projeto de educação tecnológica no Brasil 
        * deixe uma estrela e saiba mais no instagram 

            @maliartemar @barbarostecnologis	

            STRINGS[]   &&  characteres 
                %s      -     %c

    Exemplo 2: Determinar o número de ocorrências de um caracter em determinada string.    

leitura de string: já é um vetor, logo não precisa de scanf
já caractere precisa
*/


//importação de bibliotecas

#include <stdio.h>
#include <string.h>


//declaração de protótipos

int quantidadeLetra (char palavra[], char letra);


//main

void main ()

{
    //declaração de variáveis
    char letra, str[30];

    int quant;

    //lendo a string
    fflush (stdin);
    printf ("Entre com uma palavra/frase: ");
    gets (str);  //get string - lê uma string, independente do tamanho e dos caracteres que a compõem

    //lendo a letra a ser buscada na string
    fflush (stdin);
    printf ("Entre com uma letra: ");
    letra = getche();        //getche - exibe  caracter digitado ou:  scanf ("%c", &letra);

    //chamando a função
    quant = quantidadeLetra (str, letra);

    //exibindo o resultado
    printf ("\nForam encontradas %d ocorrencias da letra %c na string %s.", quant, letra, str);    

}


//implementação das funções
int quantidadeLetra (char palavra[], char letra)

{
    //declaração de variáveis
    int i, cont=0;

    //percorrendo a string
    for (i=0;palavra[i]!='\0';i++)
    {
        //verificando se a letra foi encontrada na string
        if(palavra[i]==letra)
        {
            cont++;
        }
    }

    //retornando a quantidade de ocorrências da letra na string
    return cont;

}