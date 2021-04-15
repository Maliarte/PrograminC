#include <stdio.h>

#define SIZE 16

void insereCompanhia(int array[]);
void associaBagagem(int array[]);

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
     */

    int vCompanhia[SIZE] = {0};
    int opcao;

    printf("Informe a opção:\n");
    printf("0 - Sair do programa\n");
    printf("1 - Cadastrar Cia Aérea\n");
    printf("2 - Procurar bagagem\n");
    printf("opção: ");
    scanf("%i", &opcao);
    while(opcao > 0){
        switch(opcao){
            case 1:
                insereCompanhia(vCompanhia);
                break;
            case 2:
                associaBagagem(vCompanhia);
        }

        printf("Informe outra opção:\n");
        printf("0 - Sair do programa\n");
        printf("1 - Cadastrar Cia Aérea\n");
        printf("2 - Procurar mala\n");
        printf("opção: ");
        scanf("%i", &opcao);
    }

    return 0;
}
//////////////////////////////////////////////////////////////////
/////////////////////// FUNÇÕES AUXILIARES ///////////////////////
//////////////////////////////////////////////////////////////////
void insereCompanhia(int array[]){
    int codigo = 1;
    static int i = 0;

    if(codigo > 0 && i < SIZE){
        printf("Informe o código da companhia ou 0 para sair: ");
        scanf("%i", &codigo);
        while(codigo > 0 && i < SIZE){
            array[i] = codigo;
            i++;
            if(i < SIZE){
                printf("Informe o código da próxima companhia ou 0 para sair: ");
                scanf("%i", &codigo);
            }else{
                printf("Espaço esgotado\n\n");
                codigo = 0;
            }
        }
    }else{
        printf("Espaço esgotado\n\n");
        codigo = 0;
    }

    return;
}

//////////////////////////////////////////////////////////////////
void associaBagagem(int array[]){
	int bilhete, mala, local;
	int perdida = 1;

	if(array[0] == 0){
		printf("Não há Companhia aérea cadastrada no sistema\n\n");
	}else{
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
	}

	return;
}
//////////////////////////////////////////////////////////////////