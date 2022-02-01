#include<stdio.h>
#include<stdlib.h>

#define TAM 7

void selection_sort(int num[], int TAM) { 
//declaração de variaveis
  int i, j, min, aux;

    for (i = 0; i < (TAM-1); i++) {

     
      min = i;

      

        for (j = (i+1); j < TAM; j++) {

            
                if(num[j] < num[min]) {   
                min = j;
            
           
                }     
            
                if (i != min) {

                    aux = num[i];
                    num[i] = num[min];
                    num[min] = aux;
                }
        } 
  }
}

void main(){
    int num[] = {9,7,8,1,2,0,4};
    printf("%d, %d, %d, %d, %d, %d",selection_sort(num,TAM));
}