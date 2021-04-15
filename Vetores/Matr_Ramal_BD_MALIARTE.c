#include <stdio.h>
#define TAM 5
int busca(int vetor[], int ref){
	for(int i = 0; i < TAM; i++){
		if(ref == vetor[i]){
			return i;
		}
	}
	return -1;
}

int main(void){
	int entrada, ref;
	int vMatricula[5] = {1234, 234, 9871, 7878, 4356};
	int vRamal[5] = {888, 777, 777, 666, 111};

	printf("Informe a matrícula do funcionário.\n||Matriculas BD MALIARTE||\n1234\n234\n9871\n7878\n4356\nOU 0 PARA SAIR ");
	scanf("%d", &entrada);
	while(entrada > 0){
        ref = busca(vMatricula, entrada);
        if(ref >= 0){
            printf("O ramal é %d\n", vRamal[ref]);
        }else{
            printf("Matrícula não reconhecida\n");
        }
        printf("Informe a matrícula do funcionário ou 0 para sair: ");
        scanf("%d", &entrada);
	}

	return 0;
}
