/*
 * 1.A Naiky realizou uma pesquisa numa universidade para ajudar a quantificar a produção  de 
 * seu novo modelo de tênis nos diferentes tamanhos. Os modelos serão produzidos nos tamanhos 
 * 35 a 44. 
 * Faça um programa que capture o tamanho de cada aluno entrevistado e exiba na tela o 
 * percentual de alunos por tamanho. Término da entrada de dados: número do tamanho inválido
 * 
 * Exemplo:
 * Entrada: 	35  34 42 35 36 44 46 44 35 36 37 44 87
 * Saída: 		
 * 			tamanho 35 – percentual: 30
 * 	       	tamanho 36 – percentual: 20
 * 			tamanho 37 – percentual: 10
 * 			tamanho 38 – percentual: 0
 * 			tamanho 39 – percentual: 0
 * 			tamanho 40 – percentual: 0
 *			tamanho 41 – percentual: 0
 * 			tamanho 42 – percentual: 10
 * 			tamanho 43 – percentual: 0
 * 			tamanho 44 – percentual: 30
 */
 
#include<stdio.h>

#define TAM 10

int buscaVetor(int v[], int valor);
void preencheArray(int v[], int valor);
void mostraResultado(int v1[], int v2[], int ref);
 
int main(void){
	int tamAluno, posicao, contador = 0;
	int vTamanho[TAM] = {35, 36, 37, 38, 39, 40, 41, 42, 43, 44};
	int vAcumulador[TAM];
	
	preencheArray(vAcumulador, 0);
	
	printf("Informe o número de seu tênis (admitidos valores entre 35 e 44): ");
	scanf("%d", &tamAluno);
	while(tamAluno >= 35 && tamAluno <= 44){
		contador++;
		posicao = buscaVetor(vTamanho, tamAluno);
		vAcumulador[posicao]++;
		printf("Informe o número de seu tênis (admitidos valores entre 35 e 44): ");
		scanf("%d", &tamAluno);
	}
	
	printf("\n////////////////////////////////////////////////////////");
	printf("\n////////////////// DADOS ESTATÍSTICOS //////////////////");
	printf("\n////////////////////////////////////////////////////////\n\n");

	mostraResultado(vTamanho, vAcumulador, contador);
	
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
////////////////////////////////////////////////////////

int buscaVetor(int v[], int valor){
	
	for(int i  = 0; i < TAM; i++){
		if(v[i] == valor){
			return i;
		}
	}
	return -1;
}
////////////////////////////////////////////////////////

void mostraResultado(int v1[], int v2[], int ref){
	int i = 0;
	float pCento;
	
	printf("Total de entrevistados: %d pessoas.\n\n", ref);
	
	for(; i < TAM; i++){
		pCento = ((float)v2[i] / ref) * 100.00;
		printf("Tamanho %d - %4.1f%% - ", v1[i], pCento);
		for(int j = 1; j <= v2[i]; j++){
			printf("*");
		}
		printf("\n");
	} 	
}
////////////////////////////////////////////////////////