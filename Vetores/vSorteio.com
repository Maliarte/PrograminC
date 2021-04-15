#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30

void preencheArray(int v[], int valor);
int buscaArray(int val, int v[], int qtd);

int main(void){
	int vNumSorteado[30];
	int qtSorteado = 0;
	int aleatorio, posicao;
	int i;
	
	preencheArray(vNumSorteado, -1);
	
	srand(time(NULL));
	for(i = 0; i < 300; i++){
		aleatorio = (rand()%30) + 1;
		posicao = buscaArray(aleatorio, vNumSorteado, qtSorteado);
		if(posicao == -1){
			vNumSorteado[qtSorteado] = aleatorio;
			qtSorteado++;
		}
	}
	
	for(int i = 0; i < qtSorteado; i++){
		printf("%d\n", vNumSorteado[i]);
	}
	
	
	return 0;
}
//////////////////////////////////////////////////////////
void preencheArray(int v[], int valor){

    for(int i = 0; i < TAM; i++){
        v[i] = valor;
    }
}

int buscaArray(int val, int v[], int qtd){
	
	for(int i = 0; i < qtd; i++){
		if(v[i] == val){
			return i;
		}	
	}
	
	return -1;
}