#include <stdio.h>

#define SIZE 5

void inicializa(float v[]){
	for(int i = 0; i < SIZE; i++){
		v[i] = -1;
	}
}

int main(void){
	float vCR[SIZE];
	int matricula, cursoAluno, posicao;
	float crAluno;

  inicializa(vCR);
	
	printf("Informe a matrícula ou 0 para sair: ");
	scanf("%i", &matricula);
	while(matricula > 0){
		printf("Informe o curso: ");
		scanf("%i", &cursoAluno);
		if(cursoAluno >= 101 && cursoAluno <= 105){
			printf("Informe o CR: ");
			scanf("%f", &crAluno);
			posicao = cursoAluno - 101;
			
			if(crAluno > vCR[posicao]){
				vCR[posicao] = crAluno;
			}
		}else{
			printf("Número do curso selecionado é invalido\n\n");
		}
		
		printf("Informe a matrícula ou 0 para sair: ");
		scanf("%i", &matricula);
	}
	for(int i = 0; i < SIZE; i++){
		printf("Maior CR curso %d ... %.1f\n", (101 + i), vCR[i]);
	}
	
	return 0;
}
