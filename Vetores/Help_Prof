/*
 * Para cada aluno de uma turma é lido:
 * Matrícula, nota1, nota2, nota3 e a frequência 
 * ( 15 inteiros representando as faltas do aluno nas 15 aulas do curso: 
 * 0- presente nos dois tempos, 
 * 1- presente em apenas 1 tempo ou 
 * 2- ausente nos dois tempos)
 * 
 * Faça um programa, utilizando a função abaixo, que exiba, para cada aluno:
 * a matrícula, média, presenças, e % de faltas dos alunos 
 * 
 * Função  void  processa_pauta( int * numpresencas, float * percfaltas), 
 * que recebe o endereço de duas variáveis que serão preenchidas com o número de presenças 
 * e o % de faltas de um aluno calculados a partir da leitura  da freqüência
 */

#include <stdio.h>

#define AULA 15

void calculaMedia(float *media);
void processaPauta(int *numPresencas, float *percFaltas);
float exibeNota(int numero);

int main(void){
	
	int matricula, numPresencas;
	float media, percFaltas;
	
	printf("Informe sua matrícula ou 0 para sair: ");
	scanf("%i", &matricula);
	
	while(matricula){
		calculaMedia(&media);
		processaPauta(&numPresencas, &percFaltas);
		
		printf("\n******** MATRÍCULA %i *********\n", matricula);
		printf("Média .............. %.2f\n", media);
		printf("Presenças .......... %i\n", numPresencas);
		printf("%% de faltas ........ %.2f%%\n", percFaltas);
		printf("********************************\n\n");
		
		printf("Informe próxima matrícula ou 0 para sair: ");
		scanf("%i", &matricula);
	}
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////
//////////////////////////// FUNÇÕES AUXILIARES ////////////////////////////
////////////////////////////////////////////////////////////////////////////
void calculaMedia(float *media){
	float nota1, nota2, nota3;
	
	nota1 = exibeNota(1);
	nota2 = exibeNota(2);
	nota3 = exibeNota(3);
	
	*media = (nota1 + nota2 + nota3) / 3;
	return;
}
/////////////////////////////////////////////////////////////////////////////
void processaPauta(int *numPresencas, float *percFaltas){
	int contador = 1, acumulador=0, falta;
	
	while(contador <= AULA){
		printf("Informe a frequencia do aluno na aula %i.\n", contador);
		printf("0- presente nos dois tempos\n"); 
		printf("1- presente em apenas 1 tempo\n");
		printf("2- ausente nos dois tempos\n");
		scanf("%i", &falta);
		while(falta < 0 || falta > 2){
			printf("ERRO!\n");
			printf("Informe a frequencia do aluno na aula %i.\n", contador);
			printf("0- presente nos dois tempos\n"); 
			printf("1- presente em apenas 1 tempo\n");
			printf("2- ausente nos dois tempos\n");
			scanf("%i", &falta);
		}
		printf("\n");
		acumulador+=falta;
		contador++;
	}
	(*numPresencas) = (AULA * 2) - acumulador;
	(*percFaltas) = ((float)acumulador / (AULA * 2)) * 100.00; 
	
	return;
}
//////////////////////////////////////////////////////////////////////////////
float exibeNota(int numero){
	float valor;
	
	printf("Informe a nota %i: ", numero);
	scanf("%f", &valor);
	while(valor < 0 || valor > 10){
		printf("ERRO! VALOR DEVE ESTAR ENTRE 0 E 10\n");
		printf("Informe a nota %i: ", numero);
		scanf("%f", &valor);
	}
	
	return valor;
}
