#include <stdio.h>

#define SIZE 30
#define MINIMO 10

void insereCompanhia(int array[]);
void associaBagagem(int array[]);
void inicializaArray(int array[]);

int main(void){
    /*
     * Companhia 10 -> Sala 1
     * Companhia 11 -> Sala 2
     * Companhia 12 -> Sala 3
     * Companhia 13 -> Sala 4
     * Companhia 14 -> Sala 5
     * Companhia 15 -> Sala 1
     * Companhia 16 -> Sala 2
     * Companhia 17 -> Sala 3
     * Companhia 18 -> Sala 4
     * Companhia 19 -> Sala 5
     * Companhia 20 -> Sala 1
     * Companhia 21 -> Sala 2
     * Companhia 22 -> Sala 3
     * Companhia 23 -> Sala 4
     * Companhia 24 -> Sala 5
     * Companhia 25 -> Sala 1
     * Companhia 26 -> Sala 2
     * Companhia 27 -> Sala 3
     * Companhia 28 -> Sala 4
     * Companhia 29 -> Sala 5
     * Companhia 30 -> Sala 1
     * Companhia 31 -> Sala 2
     * Companhia 32 -> Sala 3
     * Companhia 33 -> Sala 4
     * Companhia 34 -> Sala 5
     * Companhia 35 -> Sala 1
     * Companhia 36 -> Sala 2
     * Companhia 37 -> Sala 3
     * Companhia 38 -> Sala 4
     * Companhia 39 -> Sala 5
     */

    int vCompanhia[SIZE];
    int opcao;

    inicializaArray(vCompanhia);
	insereCompanhia(vCompanhia);
    printf("Informe a opção:\n");
    printf("0 - Sair do programa\n");
    printf("2 - Procurar bagagem\n");
    printf("opção: ");
    scanf("%i", &opcao);
    while(opcao == 2){

        associaBagagem(vCompanhia);

        printf("Informe outra opção:\n");
        printf("0 - Sair do programa\n");
        printf("2 - Procurar mala\n");
        printf("opção: ");
        scanf("%i", &opcao);
    }

    return 0;
}
/////////////////////////////////////////////////////////
void insereCompanhia(int array[]){

    for(int i = 0; i < SIZE; i++){
		array[i] = MINIMO + i;
	}

    return;
}
/////////////////////////////////////////////////////////
void associaBagagem(int array[]){
	int bilhete, mala, local;
	int perdida = 1;

	printf("Informe o número (4 dígitos) do bilhete ou 0 para sair: ");
	scanf("%i", &bilhete);
	while(bilhete > 0){
	mala = bilhete%100;
		for(int i = 0; i < SIZE; i++){
			if(mala == array[i]){
				local = (i % 5) + 1;
				printf("A mala está na sala %d\n", local);
				perdida = 0;
				break;
			}
		}
		if(perdida){
			printf("A bagagem referente ao bilhete %i não foi encontrada\n\n", bilhete);
		}
		perdida = 1;
		printf("Informe o número (4 dígitos) do bilhete ou 0 para sair: ");
		scanf("%i", &bilhete);
	}

	return;
}
/////////////////////////////////////////////////////////
void inicializaArray(int array[]){
    for(int i = 0; i < SIZE; i++){
        array[i] = 0;
    }
}
/////////////////////////////////////////////////////////