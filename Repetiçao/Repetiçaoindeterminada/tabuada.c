#include <stdio.h>    

void obterTabuada (int a){
    int x = 1, tab;
    while (x < 11){
        tab = a * x;
        printf ("%i x %i = %i\n", a, x, tab);
        x = x +1;
    }
}
    
int main (void){
    int num, resp;
    
    printf ("===== TABUADA =====\n\n");
    printf ("Digite um numero positivo: ");
    scanf ("%i", &num);
    
    if (num > 0){
        obterTabuada (num);
    
        printf ("\nDigite um novo numero positivo: ");
        scanf ("%i", &resp);
    
        while (resp > 0){
            obterTabuada (resp); 
        
            printf ("\nDigite um novo numero positivo: ");
            scanf ("%i", &resp);   
        }
        printf ("\nERRO. PROGRAMA FINALIZADO.");
    }
    else printf ("\nERRO. PROGRAMA FINALIZADO.");
    return 0;
}    





/*	Mostrar a tabuada de números  informados pelo usuário. A entrada de dados é finalizada quando um número ≤ 0 for digitado. 
 

 #include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    int num, tab=0;

    setlocale (LC_ALL,"Portuguese");

    printf("\nDigite um número: ");
    scanf("%i", &num);

    if (num > 0) {
      while (tab < 10) {
        tab++;
      printf("\n %4i X %2i = %2i", num, tab, tab * num);
      }

      printf("\n\n Digite outro número: ");
      scanf("%i", &num);
    }
    else {
    }

    printf("\n\n\n");

    return 0;
} 
#include <stdio.h>
#include <locale.h>

int main (void)
{
    int numX, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10;

    setlocale (LC_ALL, "portuguese");
    printf("Digite um número positivo ou 0 para finalizar");
    scanf("%i", &numX);

    while (numX>0)
    {
        x1=numX*1;
        x2=numX*2;
        x3=numX*3;
        x4=numX*4;
        x5=numX*5;
        x6=numX*6;
        x7=numX*7;
        x8=numX*8;
        x9=numX*9;
        x10=numX*10;
        printf("TABUADA DE %i:\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i", numX, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10);
        printf("\nDigite um número positivo ou 0 para finalizar");
        scanf("%i", &numX);
    }



    return 0;
} */