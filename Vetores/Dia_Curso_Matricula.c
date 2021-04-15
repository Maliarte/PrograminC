#include <stdio.h>

void preencheArray(int array[]);

int main(void){
/*
 * CURSO 1,2,3,4     -> dia 6
 * CURSO 5,6,7,8     -> dia 7
 * CURSO 9,10,11,12  -> dia 8
 * CURSO 13,14,15,16 -> dia 9
 * CURSO 17,18,19,20 -> dia 10
 * CURSO 21,22,23,24 -> dia 11
 * CURSO 25,26,27,28 -> dia 13
 * CURSO 29,30,31,32 -> dia 14
 * CURSO 33,34       -> dia 15
 */

	int vAgenda[9];
	int matricula;
	int curso;
	int diaMatricula;

	preencheArray(vAgenda);

	printf("Informe a matrícula ou 0 para sair do programa: ");
	scanf("%i", &matricula);
	while(matricula > 0){
		printf("Informe o código do curso (1 a 34): ");
		scanf("%i", &curso);
		if(curso < 1 || curso > 34){
			printf("\nNúmero de curso inválido\n\n");
		}else{
			if(curso%4 == 0){
				diaMatricula = (curso/4)-1;
			}else{
				diaMatricula = curso/4;
			}
			printf("Aluno %d, o dia de matrícula do curso ", matricula);
			printf("(%d) é %d de janeiro.\n\n", curso, vAgenda[diaMatricula]);
		}
		printf("Informe a matrícula ou 0 para sair do programa: ");
		scanf("%i", &matricula);
	}

	return 0;
}

void preencheArray(int array[]){
	int i = 0;
	int dia = 6;

	for(;i <= 15; i++){
		if(dia == 12){
			dia++;
		}
		array[i] = dia;
		dia++;
	}
}