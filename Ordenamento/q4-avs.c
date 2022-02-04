/*
       Programa desenvolvido por Marília S.
        | AVS de FPR 2021.2 | 02.02.2022 |

        Docente: Leonardo Vianna

Q4) Dadas duas listas encadeadas do tipo Tlist, L1 e L2
fazer uma funcao recursiva que verifica se todos elementos de L1 estão em L2.
*/
#include <stdio.h>
#include <stdlib.h> 

//definição de tipos
typedef struct No {
	int valor;			//valor declarado como int, por se tratar de uma lista de inteiros.
	struct No* prox;
} TNo;

typedef TNo* TLista;

void main ()
{
	//declaração de variáveis
	TLista L1 = NULL;			//lista inicialmente vazia
    TLista L2 = NULL;			//lista inicialmente vazia
	int  num1;
	
	
		
	//Inserção
	printf ("Numero a ser inserido: ");
	scanf ("%d", &num1);
			
	//chamando a função
	if (inserir (&lista, num1) == TRUE)
	{
		printf ("\n\tInsercao realizada com sucesso!\n");
}
else
{
	printf ("\n\tInsercao nao realizada!\n");
}
						
}
	
inserir(TLista *L, int num) {
   
	//Passo 1: Alocar memória para o novo nó (aux)
	TLista aux = (TLista) malloc (sizeof(TNo));    
	
	//testando se a memória não foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else	//a memória foi alocada
	{
		//Passo 2: Armazenar o valor a ser inserido na posição recém-alocada (no campo valor)	
		aux->valor = num;
		
		//Passo 3: Fazer o novo nó apontar (através do campo prox) para o nó que até então era o primeiro da lista	
		aux->prox = *L;
		
		//Passo 4: Fazer o ponteiro inicial da Lista (L) apontar para o novo nó			
		*L = aux;
		
		return TRUE;
	}
}


void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a lista está vazia
	if (L == NULL)
	{
		printf ("Lista vazia!");
	}
	else
	{
		printf ("Lista: ");
		
		//fazendo 'aux' apontar, inicialmente, para o primeiro nó da lista
		aux = L;
		
		while (aux != NULL)		//'aux' percorrerá os nós da lista até que ele chegue ao valor NULL
		{
			//exibir o valor apontado pelo aux
			printf ("%d ", aux->valor);   //lê-se: aux apontado valor
			//printf ("%d ", (*aux).valor);    equivalente ao comando da linha anterior
			
			//fazer o aux apontar para o próximo nó
			aux = aux->prox;
		}
		
		printf ("\n\n");
	}
}



void verificaElementos(TLista *L1, TLista *L2)
{

	TLista aux1;
    TLista aux2;
	if (*L1 == *L2)
	{
		aux1 = (*L1);
		(*L1) = aux->prox;
		free(aux1);	
        aux2 = (*L2);
		(*L2) = aux->prox;
		free(aux2);
		verificaElementos(&(*L1,*L2));
    /*
    * STRCMP ???????????? continua
    */
    } 
}