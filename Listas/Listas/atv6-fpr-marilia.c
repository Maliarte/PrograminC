/*
    *Desenvolver uma função que, dada uma lista
    *encadeada L do tipo TLista e dois números
    *inteiros A e B, retorne o número de elementos
    *de L que encontram-se no intervalo [A, B]. 
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct no
{
    int valor;
    struct no *prox;
}TNo;

typedef TNo * TLista;

int determinaElementos(TLista L, int A, int B);
int inserir(TLista *L, int numero);

void main()
{
    int a, b, result;
    TLista L = NULL;

    inserir(&L, 2);
    inserir(&L, 3);
    inserir(&L, 4);
    inserir(&L, 5);
    inserir(&L, 6);
    inserir(&L, 7);
    inserir(&L, 8);

    printf("Entre com o primeiro valor: ");
    scanf("%d", &a);

    printf("Entre com o segundo valor: ");
    scanf("%d", &b);

    result = determinaElementos(L, a, b);
    printf("%d", result);
}

int determinaElementos(TLista L, int A, int B)
{
    int cont = 0;
    TLista aux = L; // auxiliar percorre a lista L

    //enquanto houver elementos na lista
    while (aux != NULL)
    {
            //'aux->' eh um campo do meu struct
        if (aux->valor >= A && aux->valor <= B)
        {
            cont++;
        }
        aux = aux->prox;
    }
    return cont;
}
int inserir(TLista *L, int numero)
{
	//Passo 1: Alocar memória para o novo nó (aux)
	TLista aux = (TLista)malloc(sizeof(TNo)); 
	/* malloc: retorna *void. Por isso, é necessário fazer casting para que os dois lados da atribuição sejam do mesmo tipo.*/
	
	//testando se a memória não foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else //a memória foi alocada
	{
		//Passo 2: Armazenar o valor a ser inserido na posição recém - alocada(no campo valor) 
		aux->valor = numero;
		//Passo 3: Fazer o novo nó apontar (através do campo prox) para o nó que até então era o primeiro da lista 
		aux->prox = *L;
		//Passo 4: Fazer o ponteiro inicial da Lista (L) apontar para o novo nó
		*L = aux;
		
		return TRUE;
	}
}