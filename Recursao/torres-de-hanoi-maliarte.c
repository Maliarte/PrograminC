/*
	FPR - Fundamentos de Programação
	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos
	
	    Recursividade

        | Teoria |

        Torre de Hanói é um quebra-cabeça que consiste em uma base contendo três pinos. 
        Onde estão dispostos alguns discos uns sobre os outros, em ordem crescente de 
        diâmetro, de cima para baixo. O problema consiste em passar todos os discos de um 
        pino para outro qualquer, usando um dos pinos como auxiliar, de maneira que um disco
        maior nunca fique em cima de outro menor em nenhuma situação. 
        
        O número de discos pode variar sendo que o mais simples contém apenas três.

        Atualmente, a Torre de Hanói tem sido tradicionalmente considerada como um procedimento 
        para avaliação da capacidade de memória de trabalho, e principalmente de planejamento e 
        solução de problemas.

        | Prática |

        O problema das Torres de Hanoi: movimentar n discos do pino origem para o pino destino, respeitando as seguintes regras:

                i. apenas um disco pode ser movimentado por vez;
                ii. é proibido colocar um disco maior sobre um menor.

*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
//n discos, pinos  2^n-1 (2^3-1) = 7 movimentos
// 3 discos da origem p destino usando aux
void Hanoi(int n, char O, char D, char aux);

void main()
{
    int n = 3;
    printf("Hanoi de %d discos:\n\n", n);
    Hanoi(n, 'A', 'C', 'B');
    // printf("Total de movimentos: %d: ", Hanoi(n, 'A', 'C', 'B'));
}



//implementação das funções
void Hanoi(int n, char O, char D, char aux)
{
    //printf ("Hanoi de %d discos:\n\n", n);
    if (n > 0) //Caso geral
    {
        Hanoi(n - 1, O, aux, D);
        printf("movimente %c ->  para %c\n", O, D);
        Hanoi(n - 1, aux, D, O);
    }
                        /*              
                        
                                                === NOTAS ===
                        
                            Perceba que o caso base é implícito, de forma que n <= 0 .
                        
                            Logo, o else {} comportaria esse caso
                        */
}

/*                                                      TOTAL MOVIMENTOS
int Hanoi( int n, char O, char D, char aux)

 if (n > 0) //Caso geral
    {
        return 1 + Hanoi(n - 1, O, aux, D);
        printf("movimente %c ->  para %c\n", O, D);
        return 1 + Hanoi(n - 1, aux, D, O);
    } else 
    {
        return 0;
    }

*/