/* Malas de passageiros são sempre colocadas em esteiras de bagagens após a chegada de cada voo. Toda mala tem um identificador onde os 2 últimos algarismos representam a companhia aérea na qual o passageiro voou. O setor de achados e perdidos do aeroporto armazena as bagagens não retiradas destas esteiras em uma de suas 5 salas.  A sala escolhida está relacionada com a companhia aérea usada pelo passageiro. 

a) Faça um programa, com pelo menos duas funções além da main, que inicialmente leia:
para cada uma das companhias aéreas ( no máximo 20):
o código da companhia aérea (número qualquer entre 0 e 99. Código 0 significa fim da entrada de dados) 
o número da sala no setor de achados e perdidos onde guardam as bagagens não retiradas da esteira desta companhia aérea.
Em seguida, para cada passageiro que tentar encontrar uma bagagem leia o identificador de bagagem do passageiro e exibe a sala onde se encontra a mala ou uma mensagem “MALA NAO ENCONTRADA”.
O término da entrada de dados ocorre ao ser lido o valor o (zero) para o código da companhia aérea. 
Versão b) Faça um programa, com pelo menos duas funções além da main, que inicialmente leia:
para cada uma das companhias aéreas ( exatamente 20):
o código da companhia aérea (número qualquer entre 10 e 39). Código 0 significa fim da entrada de dados) 
o número da sala no setor de achados e perdidos onde guardam as bagagens não retiradas da esteira desta companhia aérea.

Em seguida, para cada passageiro que tentar encontrar uma bagagem leia o identificador de bagagem do passageiro e exibe a sala onde se encontra a mala ou uma mensagem “MALA NAO ENCONTRADA”.
O término da entrada de dados ocorre ao ser lido o valor o (zero) para o código da companhia aérea. 


*/
#include <stdio.h>

#define SIZE 8

void preencheArray(int vCodigo[], int vAssento[], float vValor[]);
void compraBilhete(int array1[], float array2[], int ref, int vCodigo[]);
int avaliaTarifa(int array[]);
int verificaPosicao(int vCodigo[], int ref);

int main(void){
    /*
     * CÓDIGO 17 - Posição 0
     * CÓDIGO 48 - Posição 1
     * CÓDIGO 10 - Posição 2
     * CÓDIGO 21 - Posição 3
     * CÓDIGO 96 - Posição 4
     * CÓDIGO 55 - Posição 5
     * CÓDIGO 23 - Posição 6
     * CÓDIGO 16 - Posição 7
     */
    int tarifa;
    int vBancoTarifa[SIZE] = {17,48,10,21,96,55,23,16};
    int vAssento[SIZE];
    float vValor[SIZE];

    preencheArray(vBancoTarifa, vAssento, vValor);
    tarifa = avaliaTarifa(vBancoTarifa);

    while(tarifa != 0){
        if(tarifa == -1){
			tarifa = avaliaTarifa(vBancoTarifa);
		}else{
			compraBilhete(vAssento, vValor, tarifa, vBancoTarifa);
			tarifa = avaliaTarifa(vBancoTarifa);
		}
    }

    return 0;
}

///////////////////////////////////////////////////////////
void preencheArray(int vCodigo[], int vAssento[], float vValor[]){
    for(int i = 0; i < SIZE; i++){
        printf("Informe o valor da tarifa %i: ", vCodigo[i]);
        scanf("%f", &vValor[i]);
        printf("Informe a quantidade disponível da tarifa %i: ", vCodigo[i]);
        scanf("%i", &vAssento[i]);
    }
    return;
}

///////////////////////////////////////////////////////////
void compraBilhete(int array1[], float array2[], int ref, int vCodigo[]){
    int qtd;
    int pos;
    float compra;

    pos = verificaPosicao(vCodigo, ref);
    if(array1[pos] == 0){
        printf("\nNão há assentos disponíveis\n");
    }else{
        printf("\nInforme a quantidade de bilhetes desejada: ");
        scanf("%i", &qtd);

        if(qtd <= array1[pos]){
            compra = array2[pos] * qtd;
            array1[pos]-=qtd;
            printf("Valor da compra ... R$ %.2f\n\n", compra);
        }else{
            printf("Compra não efetuada.\n");
            printf("Quantidade disponível é de %i assentos.\n", array1[pos]);
        }
    }
    return;
}

///////////////////////////////////////////////////////////
int avaliaTarifa(int array[]){
    int input;
    printf("\nInforme o código da tarifa desejada ou 0 para sair: ");
    scanf("%i", &input);
    if(input == 0){
		return 0;
	}else{
		for(int i = 0; i < SIZE; i++){
			if(input == array[i]){
				return input;
			}
		}
	}
    return -1;
}
///////////////////////////////////////////////////////////
int verificaPosicao(int vCodigo[], int ref){
    for(int i = 0; i < SIZE; i++){
		if(ref == vCodigo[i]){
			return i;
		}
	}
    return -1;
}