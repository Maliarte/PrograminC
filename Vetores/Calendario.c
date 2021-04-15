#include <stdio.h>

void atualizaData(int vetor1[], int vetor2[]){
	int diaMes;

	diaMes = vetor1[1] -1;

	if( (vetor1[0] == vetor2[diaMes]) && (vetor1[1] == 12) ){
		vetor1[0] = vetor1[1] = 1;
		vetor1[2]++;
	}else{
		if(vetor1[0] == vetor2[diaMes]){
			vetor1[0] = 1;
			vetor1[1]++;
		}else{
			vetor1[0]++;
		}
	}

	printf("%d/%d/%d\n", vetor1[0], vetor1[1], vetor1[2]);
}

int main(void){

	int vData[3]; //{dd, mm, aaaa}
	int vCalendario[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	printf("Informe o dia: ");
	scanf("%i", &vData[0]);
	printf("Informe o mês: ");
	scanf("%i", &vData[1]);
	printf("Informe o ano: ");
	scanf("%i", &vData[2]);

	if(vData[2]%4==0 || vData[2]%400==0){
		vCalendario[1] = 29;
	}

	if(vData[0] > vCalendario[vData[1]-1] || vData[1] > 12 || vData[2] > 2100){
		printf("Data inválida\n");
	}else{
		atualizaData(vData, vCalendario);
	}

	return 0;
}
