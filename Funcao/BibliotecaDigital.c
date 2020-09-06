#include <stdio.h>

int somaAlgarismos (int a){
	 int soma, div1, div2;
	 div1 = a/10;
	 div2 = a%10;
	 soma = div1 + div2;
	 return soma;
}

int main (void){
	int dia, mes, ano, diaSoma, mesSoma, ano1, anoSoma;
	
	printf ("Entre com o dia do seu nascimento: ");
	scanf ("%d", &dia);
	
	printf ("Entre com o mes do seu nascimento: ");
	scanf ("%d", &mes);
	
	printf ("Entre com o ano do seu nascimento com 4 digitos: ");
	scanf ("%d", &ano);
	
	diaSoma = somaAlgarismos (dia);
	mesSoma = somaAlgarismos (mes);
	ano1 = ano %100;
	anoSoma = somaAlgarismos (ano1);
	
	printf ("SENHA: %d%d%d", diaSoma, mesSoma, anoSoma);
	
	return 0;
}	