/*
                        FPR - Fundamentos de Programação
                            Professor Leonardo Vianna
                            Discente: Marília Silva

                                Data: 11/11/2021
                                AV1 - Q4


Desenvolver uma funçao recursiva que dado um numero inteiro N, exiba as sequências 
de 1 a N(crescente) e de N a 1(decrescente), intercaladas, como no exemplo abaixo.
Retornar a soma de todos elementos apresentados.

ex: N=5
|1| 5 |2| 4 |3| 3 |4| 2 |5| 1

*/

#include <stdio.h>
/* correçao 

18.11.21

função recursiva dificilmente sera declarado uma variavel dentro dela.*/
int exibeNum(int n) {

int soma;
            if(n > 0) { //caso geral 

             //decrementando sequencia
             return 1 + exibeNum(n-1);
             printf("%d", exibeNum(n));
            } if(n <= 0) {  

                    //incrementando sequencia
                    return 1 +  exibeNum(n+1);         
                    printf("%d", exibeNum(n));
                    }                    
            else  //caso base
            {
                return 0;
            }

for(i = 0; i < n; i++){
    soma+= n[i];
}
          
}
int main(){

    int num;

    printf("Entre com o numero: ");
    scanf("%d", &num);

    printf("%d %d %d %d %d %d %d %d %d %d\n", exibeNum(num));
}