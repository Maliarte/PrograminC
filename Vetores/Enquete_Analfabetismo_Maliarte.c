/* SRA
 Faça um programa que leia o grau de instrução (inteiro) e a idade de um grupo de 50 pessoas 
e exiba a idade média em cada grau de instrução e a idade do mais velho 
(considere que não há empate) em cada grau de instrução. 
 
 * Graus de instrução: 
 * 			1 (analfabeto), 
 * 			2 (primeiro grau), 
 * 			3 (segundo grau), 
 * 			4 (superior), 
 * 			5 (mestrado), 
 * 			6 (doutorado), 
 * 			7 (outros). 
 
Faça pelo menos duas funções auxiliares (além da main).

 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM 50
#define MAXESCOLA 7

void preencheArray(int v[], int valor);
int validaIdade();
int validaEscolaridade();
void valoraArray(int v[], int pos, int valor);
void mostraMaisVelho(int v[]);
void exibeMedia(int vIdade[], int vEscolaridade[], int ref);

int main(void){
	int vIdade[TAM];
	int vEscolaridade[TAM];
	int idade;
	int escolaridade;
	int qtd = 1;
	
	srand(time(NULL));
	
	preencheArray(vIdade, -1);
	preencheArray(vEscolaridade, -1);
	
	
		
	while(qtd <= TAM){
		printf("Informe sua idade: ");
		idade = validaIdade();
		printf("%i\n", idade);
		valoraArray(vIdade, qtd-1, idade);
		escolaridade = validaEscolaridade();
		valoraArray(vEscolaridade, qtd-1, escolaridade);
		qtd++;
	}
	
	printf("\n////////////////////////////////////////////////////////");
	printf("\n////////////////// DADOS ESTATÍSTICOS //////////////////");
	printf("\n////////////////////////////////////////////////////////\n\n");
	
	mostraMaisVelho(vIdade);
	
	for(int i = 1; i <= MAXESCOLA; i++){
		exibeMedia(vIdade, vEscolaridade, i);
	}
	
	return 0;
}

////////////////////////////////////////////////////////
///////////////// FUNÇÕES AUXILIARES ///////////////////
////////////////////////////////////////////////////////

void preencheArray(int v[], int valor){
	
	for(int i = 0; i < TAM; i++){
		v[i] = valor;
	}
}

///////////////////////////////////////////////////////
int validaIdade(){
	int idade = rand()%80;
	
	while(idade < 18){
		idade = rand()%80;
	}
	
	return idade;
}
	
///////////////////////////////////////////////////////
int validaEscolaridade(){
	int escolaridade;
	
	printf("Informe sua escolaridade:\n");
	printf("1 (analfabeto)\n");
	printf("2 (primeiro grau)\n");
	printf("3 (segundo grau)\n");
	printf("4 (superior)\n");
	printf("5 (mestrado)\n");
	printf("6 (doutorado)\n");
	printf("7 (outro)\n");
	escolaridade = (rand()%7) + (1);
	printf("Escolaridade = %i\n\n", escolaridade);
		
	return escolaridade;
}
	
///////////////////////////////////////////////////////	
void valoraArray(int v[], int pos, int valor){
	
	v[pos] = valor;
}

void mostraMaisVelho(int v[]){
	int max=-1;
	for(int i = 0; i < TAM; i++){
		if(v[i] > max){
			max = v[i];
		}
	}
	printf("Participante mais velho ... %d anos\n\n", max);
}

///////////////////////////////////////////////////////
void exibeMedia(int vIdade[], int vEscolaridade[], int ref){
	int cont = 0, soma = 0;
	
	for(int i = 0; i < TAM; i++){
		if(vEscolaridade[i] == ref){
			soma+=vIdade[i];
			cont++;
		}
	}
	
	printf("Nível %i - Idade média %.1f\n", ref, (float)soma/cont);
}
///////////////////////////////////////////////////////