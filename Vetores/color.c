#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define AJUSTE(a) ( ((a) * 3) - 3 )
#define ALUNOS 60

void preencheArray(int referencia, int array[]);


int main(void){
	int cor;
	int palheta[24] = {-1};
	int matricula = 1;
	
	srand(time(NULL));
		
	while(matricula <= ALUNOS){
		cor = (rand() % 8) + 1; 
		preencheArray(cor, palheta);
		printf("MATRÍCULA %i\n", matricula);
		printf("cor %i ... R = %i / G = %i / B = %i \n\n", cor, palheta[AJUSTE(cor)], palheta[AJUSTE(cor)+1], palheta[AJUSTE(cor)+2]);
		matricula++;
	}
	
	return 0;
}

void preencheArray(int referencia, int array[]){
	int valor[24] = {255,255,255, 0,0,255, 255,0,0, 0,255,0, 255,255,0, 255,0,255, 0,255,255, 0,0,0};
	
	int min = AJUSTE(referencia);
		
	for(int i = min; i < (referencia * 3); i++){
		array[i] = valor[i];
	}
	
	return;
}
