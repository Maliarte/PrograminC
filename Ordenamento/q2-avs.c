/*
       Programa desenvolvido por Marília S.
        | AVS de FPR 2021.2 | 02.02.2022 |

        Docente: Leonardo Vianna

Q2) Dadas duas strings s1 e s2, implementar uma função que verifique se a segunda é uma "versão emparelhada" da primeira.
ex..: 
    TRUE
    s1 ="CASA"   s2="SAAC",       s2  é      uma versão embaralhada da s1.

    FALSE
    s1 ="TESTE"  s2="COPO",       s2 não é  uma versão embaralhada da s1.
    s1 ="CACHORRO"  s2="HOAORC",  s2 não é  uma versão embaralhada da s1.
NOVO COMENTÁRIO
Leonardo Vianna
Questão 01:

Nota: 1,4/2,5

Questão 02:

- A função foi declarada como 'void', porém retorna inteiros ao longo de sua execução;

- O código apresentado compara se duas strings são exatamente iguais, nos moldes da função 'strcmp'. Porém, não foi isso o solicitado pelo enunciado.

Nota: 0,2/2,5

Questão 03:

- Foi apresentado um algoritmo de ordenação que nem manipula o vetor passado por parâmetro. É manipulado o vetor 'num', contendo inteiros, mas o vetor a ser ordenador é 'vetor', do tipo 'TPessoa', que consiste em um struct com campos 'nome' e 'idade'.

Nota: 0,5/2,5

Questão 04:

- Para verificar se duas listas são iguais, é necessário remover seus elementos?

- Nenhuma comparação entre os elementos foi feita.

Nota: 0,5/2,5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipos
void emparelhada(char string1[], char string2[]);

void main(){
//declaracao de variaveis
char s1[30], s2[30];

strcpy(s1,"CASA");
stcpy(s2, "SAAC");

emparelhada(s1,s2);

}

void emparelhada(string1, string2){
int i,j;
    /*
     *percorrer  e comparar strings
     *se encontrar o primeiro char diferente
     *retorna falso
    */
     for (i=0;(s1[i] != '\0') && (s2[i] != '\0');i++)
	{
		//encontrar caracteres distintos: não será 0.
		if (s1[i] != s2[i])
		{    
			// EX:A(65) - H(72) = -7
			return (s1[i]-s2[i]); 

     
    if (s1[i] != s2[i])
				{
					//se o caracter da primeira string for menor (alfabeticamente, conforme a tabela ASCII) 
					//do que o da segunda, conclui-se que um número negativo deve ser retornado
					//EX:A(65) H(72) - TABELA ASCII
					if (s1[i] < s2[i])
					{
						return -1;
					}
					else
					{
						//retornando positivo, pois concluiu-se que a segunda string vem antes da primeira, alfabeticamente
						return 1;
					}
				}
                //testando se as duas strings terminaram; se sim, elas são iguais
					if ((s1[i] == '\0') && (s2[i] == '\0'))
					{
						return 0; // ex: s1: |C|A|S|A|\0 s2: |C|A|S|A\0 return '\0'-'\0'= 0 - 0 = 0
					}
					else
					{
						//testando se apenas a primeira terminou: 
                        //ex:  |c|a|s|a|\0 x |c|a|s|a|r|ã|o|\0  return '\0' - 'R' = 0-82 =-82
						if (s1[i] == '\0')
						{
							return -1;
						}
						else
						{
							//apenas a segunda terminou: ex: |c|a|s|a|r|ã|o|\0 x |c|a|s|a|\0 return 'R'-'\0' = 82 -0 =82
							return 1;
						}
					}