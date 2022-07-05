/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 02/06/2022
	
	Ponteiros	
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//main
void main ()
{
	//declaração de variáveis
	int v1[10];			//vetor alocado estaticamente
	int *v2;			//o vetor será alocado dinamicamente
	int tamanho;
	
	//perguntando ao usuário o tamanho do vetor
	printf ("Entre com o tamanho do vetor: ");
	scanf ("%d", &tamanho);
	
	//alocando ao vetor memória de forma dinâmica
	v2 = (*int) malloc (tamanho*sizeof(int));	//fazendo casting de *void para *int
	
	/*
		malloc: tenta alocar determinada quantidade de memória (em bytes)
				caso não consiga, retorna NULL.
				se conseguir, retorna o endereço inicial do bloco alocado.
	*/
	
	//verificar se houve fracasso na alocação de memória
	if (v2 == NULL)
	{
		printf ("A memoria solicitada nao foi alocada!");
	}
	else
	{
		//pode manipular o vetor da mesma forma que fazia antes, quando era alocado estaticamente
		...
	}	
}