/*
 * Um concurso de duplas sertanejas, realizado em dois dias diferentes, organiza a apresentação
 * dos participantes pela diferença entre suas alturas. Faça um programa (usando as funções 
 * abaixo), que capture o número de cada dupla e a altura,em cm, de seus 2 integrantes 
 * informando, para cada dupla: o dia ( 1 ou 2), o nº da dupla, maior altura e menor altura de
 * seus integrantes.
 * No primeiro dia, ficam as duplas com diferença de altura inferior ou igual a 15 cm e no 
 * segundo dia as demais duplas. O término do  processamento ocorre quando é informado ‘0’ como 
 * número da dupla.
 * 
 * No final, seu programa deve exibir o nº da dupla com maior diferença e o número da dupla com 
 * menor diferença (a diferença entre as alturas varia de 0 a 230cm)
 * 
 * a)Faça uma função que  coloque nas variáveis cujos endereços são fornecidos na chamada da 
 * função, o número da dupla e as  duas alturas lidas do teclado. 
 * Protótipo desta função: void Ler (int * num, int *alt1, int *alt2);
 * 
 * b)Faça uma função que coloque em ordem crescente as alturas armazenadas nas variáveis cujos 
 * endereços são fornecidos na chamada da função ( na 1ª o mais alto e na segunda o mais baixo) 
 * e retorne  a diferença entre as duas alturas
 * Ex: mais alto 190,   mais baixo: 160  diferença: 30cm 
 * Protótipo da função: int Ordenar (int *alt1,  int *alt2);
 * 
 */
#include <stdio.h>

void ler(int *num, int *alt1, int *alt2);
int ordenar(int *alt1, int *alt2);

int main(void){
	int num, alt1, alt2, diferenca, dia, maxAlt=0, minAlt=230, minDupla=-1, maxDupla=-1;
	
	printf("Informe o número da dupla ou 0 para sair: ");
	ler(&num, &alt1, &alt2);
	while(num > 0){
		ordenar(&alt1, &alt2);
		diferenca = ordenar(&alt1, &alt2);
		if(diferenca > maxAlt){
			maxAlt = diferenca;
			maxDupla = num;
		}
		if(diferenca < minAlt){
			minAlt = diferenca;
			minDupla = num;
		}
		if(diferenca <= 15){
			dia = 1;
		}else{
			dia = 2;
		}
		
		printf("\nA dupla %i deve se apresentar no dia %i.\n\n", num, dia);
		printf("Informe o número da próxima dupla ou 0 para sair: ");
		ler(&num, &alt1, &alt2);
	}
	
	printf("\nA dupla %i tem a maior diferenca, %i cm.\n", maxDupla, maxAlt);
	printf("A dupla %i tem a menor diferença, %i cm.\n\n", minDupla, minAlt);
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////
//////////////////////////// FUNÇÕES AUXILIARES ////////////////////////////
////////////////////////////////////////////////////////////////////////////

void ler(int *num, int *alt1, int *alt2){
	
	scanf("%i", &(*num));
	if((*num) != 0){
		printf("Informe a altura (em cm) do participante 1: ");
		scanf("%i", &(*alt1));
		printf("Informe a altura (em cm) do participante 2: ");
		scanf("%i", &(*alt2));
	}
}
////////////////////////////////////////////////////////////////////////////
int ordenar(int *alt1, int *alt2){
	int diferenca, swap;

	if((*alt1) < (*alt2)){
		swap=(*alt1);
		(*alt1)=(*alt2);
		(*alt2)=swap;
	}
		
	diferenca = (*alt1) - (*alt2);

	return diferenca;
}
