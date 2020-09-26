#include <stdio.h>
#include <locale.h>
#include <time.h>
int main (void)
{
    
    int num, qtdNumAnalise, cont = 0; //primeiro declara variaveis

    setlocale (LC_ALL,"Portuguese"); // instrução fica depois das variaveis

    printf("Informe quantos números serão analisados: ");
    scanf("%i", &qtdNumAnalise);
    srand(time(NULL));
    //printf("%d", rand() % 100);
        while (cont < qtdNumAnalise)
        {
            num = rand() % 100;
           // printf("\nEscreva o número: ");//
           // scanf("%i", &num);
    if (num >=1 && num <= 15) {
               
                    printf("\nO número %i está dentro do intervalo.\n", num);
    }            
     else
    {
                    printf("\nO número %i está fora do intervalo.\n", num);
                }
            cont=cont+1;
        }
    printf("%")    
    return 0;
}
