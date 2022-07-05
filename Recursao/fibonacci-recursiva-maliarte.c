/*                              
                            FPR - Fundamentos de Programação
                            Marília Silva | https://maliarte.com.br  
                            
                            * Apoie o projeto de educação tecnológica no Brasil 
                            * deixe uma estrela e saiba mais no instagram @barbarostecnologicos
                            
                            Recursividade

                            Exemplo: calcular o n-ésimo termo da sequência de Fibonacci
                            1 1 2 3 5 8 13 ... 
                            
                            Observação: notem que quanto maior for o valor de n, maior
                            será a diferença entre os tempos de execução apresentados pelas duas versões -
                            iterativa e recursiva. Por que?
*/


//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int fibonacciI (int n); //versão iterativa
int fibonacciR(int n);  //versão recursiva


void main()
{
    int numero;

    printf("entre com um numero: ");
    scanf("%d", &numero);

    printf("%dº termo: %d\n", numero, fibonacciI(numero));
    
    system("pause");

    printf("%dº termo: %d\n", numero, fibonacciR(numero));
}



//implementação das funções

int fibonacciI(int n)
{
    int t1, t2, t3, i;
                                            /*
                                            os dois primeiros termos da sequência são iguais a 1 (e não
                                            são calculados como a soma dos dois anteriores, como os demais)
                                            */
        if (n <= 2)
        {
            return 1;
        }
        else
        {
            t1 = 1; //1º termo da sequência
            t2 = 1; //2º termo da sequência
            for (i = 3; i <= n; i++)
            {
                t3 = t1 + t2; //a cada iteração, o próximo elemento da sequência é calculado, a partir da soma de t1 e t2
                t1 = t2; //atualizando os valores de t1 e t2 para que o próximo valor da sequência possa ser calculado
                t2 = t3;
            }
            //retornando o n-ésimo termo da sequência de Fibonacci
            return t3;
        }
}



int fibonacciR(int n)  
        {
            if (n <= 2) //casos bases: n=1 e n=2
            {
                return 1;
            }
            else //caso geral
            {
                return fibonacciR(n - 1) + fibonacciR(n - 2);
            }
        }