/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 02/06/2022
	
	Ponteiros	

    //declaração de variáveis
	int a, b;		//armazenam valores inteiros
	int *p, *q;		//armazenam enedereços de memória nos quais se encontram valores inteiros
	
	...
	
	a = b;		//válido (as duas variáveis são do mesmo tipo)
	a = p;		//inválido, pois são de tipos incompatíveis
	q = b;		//inválido, pois são de tipos incompatíveis
	p = q;		//válido (as duas variáveis são do mesmo tipo)


	...
	
	a = b;		//válido (as duas variáveis são do mesmo tipo)
	a = *p;	    //válido, pois 'a' (int) receberá o conteúdo do enedereço p (que também é int)
	q = &b;	    //válido, pois 'q' (*int) receberá o endereço de b (ou seja, o endereço de um int) 
	p = q;		//válido (as duas variáveis são do mesmo tipo)
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int v[5] = {1,2,3,4,5};		//v: guarda o endereço inicial do vetor (ou seja, o endereço no qual está armazenado o elemento 1)
	int *p;						//p: guardará o endereço de memória no qual se encontrará um número inteiro	
	
	p = v;	//p guardará o endereço inicial do vetor (onde está o elemento 1)
	
	printf ("%d (%p)\n", *p, p);
	
	p++;
	
	printf ("%d (%p)\n", *p, p);

//ponteiro v4
    int i;
	
	p = v;	//p guardará o endereço inicial do vetor (onde está o elemento 1)
	

	//exibindo todos os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%d (%p)\n", *p, p);
		p++;
	}
//ponteiro v6
    
    //exibindo todos os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%d (%p)\n", *(v+i), v);    //v[i]  ===>   *(v+i)
	}
}
