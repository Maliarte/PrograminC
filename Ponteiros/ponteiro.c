/*
	FAETERJ-Rio
	FPR - Manhã - Professor Leonardo Vianna
	Data: 01/12/2021
	
	Ponteiros


//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int a, b;		//armazenam números inteiros
	int *p, *q;		//armazenam endereços de memória, nos quais valores inteiros são encontrados
	
	...
	
	a = b;	//válido, pois os tipos são iguais/compatíveis
	a = q;	//inválido, pois os tipos não são iguais/compatíveis
	p = b;	//inválido, pois os tipos não são iguais/compatíveis
	p = q;	//válido, pois os tipos são iguais/compatíveis
	
	... 
}

void main ()
{
	//declaração de variáveis
	int *p;
	int vetor[5] = {6,2,0,3,8};
	int i;
	
	p = vetor; //guarda o endereço inicial do vetor
	
	for (i=0;i<5;i++)
	{
		printf ("%d ", p); //logo é invalido erro
        printf ("%d ", *p); //porem fica 6666 por conta do endereço ser o inicial
        p++;//valido: aritmetica de ponteiros.
	}
	
}
*/
void main ()

{

    printf("VETOR DE INTEIROS: 4BYTES");

	//declaração de variáveis
	int *p;
	int vetor[5] = {6,2,0,3,8};
	int i;
	
	p = vetor;
	
	for (i=0;i<5;i++)
	{
		printf ("%d (endereço %p)\n", *p, p);
		p++;
	}

   
   printf("VETOR DE CHAR: 1BYTE");

	//declaração de variáveis
	char *b;
	char vetor[5] = {'H','I','S','X','D'};
	int i;
	
	p = vetor;
	
	for (i=0;i<5;i++)
	{
		printf ("%c (endereco %p)\n", *b, b);
		b++;
	}

}

/* Vetor é um endereço indexado  */