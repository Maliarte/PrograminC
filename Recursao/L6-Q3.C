/*

                                FPR - Manhã
                                Professor Leonardo Vianna
                                
                                Data: 28/10/2021
                                Lista de Exercícios VI
        
        Questão 03: Fazer uma função recursiva que, dado um número inteiro N, exiba o mesmo na base 2 (binária).
        Exemplo:
                    13 (10) = 1101 (2)
                                    13 | 2
                                         1 6 | 2
                                            0 3 | 2
                                                1 1 | 2
                                                    1 0
                                                    					
										
									binario (0);	CASO BASE!!!
									N=0	
							binario (1);			
							N=1		printf 1%2 = 1	
					binario (3);					
					N=3		printf 3%2 = 1			
		binario (6);								

main:		                        N=6			printf 6%2 = 0					
binario (13);										
N=13		printf 13%2 = 1								


                                
 */
//importação de bibliotecas
#include <stdio.h>
//protótipos das funções
void binario(int N);
//função main
void main()
{
    binario(13);
}
//implementação das funções
void binario(int N)
{
    if (N > 0) //caso geral
    {
        binario(N / 2);
        printf("%d", N % 2);
    }
    //caso base implícito (N = 0)
}