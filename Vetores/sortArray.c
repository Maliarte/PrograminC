
#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>

#define  CONTROL  20  

// Elemento de divisão em rand (). void creatArray (tamanho interno)

void creatArray (int tamanho);
void  showArray ( int array[], elementos int );
void  sortArray ( int sArray[], elementos int );

int  main (void) {
	tamanho interno ;
	
	srand(tempo(NULL));
	
	printf("Digite o tamanho do array ou 0 para sair do programa:");
	scanf("%d" , &size);
	
	enquanto(tamanho>0) {
		creatArray(tamanho);
		
		printf ("Digite o tamanho da próxima matriz ou 0 para sair do programa:");
		scanf ( "%d" , &size);
	}
	
	return  0 ;
}

// ////////////////////////////////////////////////////// /////////////////////
// /////////////////////////////// FUNCTIONS ////////////////////// /////////
// ////////////////////////////////////////////////////// /////////////////////

void  creatArray ( int size) {
	int array1 [tamanho];
	
	para ( int i=0 ; i<tamanho; i++) {
		matriz1[i] = rand()%CONTROLE;
	}
	
	printf ( "Matriz: \ n" );
	showArray (array1, tamanho);
	
	printf ( " \ n " );

	sortArray (array1, tamanho);
	
	retorno ;
}

// ////////////////////////////////////////////////////// /////////////////////
void  showArray ( int array[], int elements) {
	
	printf ( " [ " );
	
	for(int i=0; i<elementos; i++) {
		if (i == elementos- 1 ) {
			printf ( " % d ] " , array [i]);
		} else  printf ( "%d , " , array [i]);
	} 
	
	printf ( " \ n " );
	
	return;
}

// ////////////////////////////////////////////////////// /////////////////////

void  sortArray ( int  sArray[], int elements) {
	int array2 [elementos];
    int primeiro = 0 ;
    último int = elementos - 1 ;
	int i = 0 ;
    
    while(i <elementos) {
		
		if ( sArray [i]% 2 == 0 ) {
			matriz2 [primeiro] = sArray [i];
			primeiro ++;
		} else {
			matriz2 [último] = sArray [i];
			último--;
		}
		
		i ++;
	}
	
	printf ( " Ordenado por pares e ímpares: \ n " );
	showArray (array2, elementos);
	
	printf ( " \ n " );
	
	return;
}
// ////////////////////////////////////////////////////// /////////////////////