#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>           /*41  ---> 64 --> 32 ---> 99 */

int main(void){
    int i=0;
    srand(time(NULL));*/ origem semente inicializa aleatoriamente
    while(i<5){
        printf("%d ", rand() % 100);  /* quais os valores desses numeros que podem ser gerados . 0 e 99*/ //gera numero rand
        i+=1;
    }
    return 0;
}