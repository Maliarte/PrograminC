/*                  27/12

    FACULDADE DE EDUCAÇÃO TECNOLÓGICA DO ESTADO DO RIO DE JANEIRO
    
    Atividade nº 7 de Fundamentos de Programação - Professor Leonardo Vianna

    a. Desenvolver uma função que, dada uma lista encadeada L do tipo TLista, com seus
    elementos 
	ordenados crescentemente, insira um número inteiro em L, de forma que esta 
    se mantenha ordenada. 
    
                percorrer a lista ate achar um valor maior do que o q se quer inserir.


    b. Considerando um arquivo contendo valores inteiros, um por linha, 
    implementar uma função que leia-os e os  armazene em uma lista encadeada do tipo TLista, 
    de forma que os elementos fiquem ordenados crescentemente.


Notas:

− O tipo TLista citado é exatamente o tipo que
definimos em nossas aulas, em todas as
implementações envolvendo listas
encadeadas;
−  A função do item b deve chamar a função do
item a
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No
{					 //representando cada nó da lista, com os campos :
	int valor;		 // - valor: o dado armazenado na lista;
	struct No *prox; // - prox: o endereço do próximo nó da lista.

} TNo;

typedef TNo *TLista; //TLista equivale a TNo* (ou seja, TLista é um ponteiro para o struct TNo)

// procedimento para inserir no início
void inserir_no_inicio(TNo **lista, int num)
{
	TNo *novo = malloc(sizeof(TNo));

	if (novo)
	{
		novo->valor = num;
		novo->prox = *lista;
		*lista = novo;
	}
	else
		printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(TNo **lista, int num)
{
	TNo *aux, *novo = malloc(sizeof(TNo));

	if (novo)
	{
		novo->valor = num;
		novo->prox = NULL;

		// é o primeiro?
		if (*lista == NULL)
			*lista = novo;
		else
		{
			aux = *lista;
			while (aux->prox)
				aux = aux->prox;
			aux->prox = novo;
		}
	}
	else
		printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(TNo **lista, int num, int ant)
{
	TNo *aux, *novo = malloc(sizeof(TNo));

	if (novo)
	{
		novo->valor = num;
		// é o primeiro?
		if (*lista == NULL)
		{
			novo->prox = NULL;
			*lista = novo;
		}
		else
		{
			aux = *lista;
			while (aux->valor != ant && aux->prox)
				aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}
	else
		printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(TNo **lista, int num)
{
	TNo *aux, *novo = malloc(sizeof(TNo));

	if (novo)
	{
		novo->valor = num;
		// a lista está vazia?
		if (*lista == NULL)
		{
			novo->prox = NULL;
			*lista = novo;
		} // é o menor?
		else if (novo->valor < (*lista)->valor)
		{
			novo->prox = *lista;
			*lista = novo;
		}
		else
		{
			aux = *lista;
			while (aux->prox && novo->valor > aux->prox->valor)
			{
				aux = aux->prox;
				novo->prox = aux->prox;
				aux->prox = novo;
			}
		}
	} else
		printf("Erro ao alocar memoria!\n");
}

void imprimir(TNo *no)
{
	printf("\n\tLista: ");
	while (no)
	{
		printf("%d ", no->valor);
		no = no->prox;
	}
	printf("\n\n");
}

int main()
{

	int opcao, valor, anterior;
	TNo *lista = NULL;

	do
	{
		printf("\n\t0 - Sair\n\t1 - Inserir Inicio\n\t2 - inserir Fim\n\t3 - Inserirn Meio\n\t4 - Inserir Ordenado\n\t5 - Imprimir\n");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_inicio(&lista, valor);
			break;
		case 2:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_fim(&lista, valor);
			break;
		case 3:
			printf("Digite um valor e o valor de referencia: ");
			scanf("%d%d", &valor, &anterior);
			inserir_no_meio(&lista, valor, anterior);
			break;
		case 4:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_ordenado(&lista, valor);
			break;
		case 5:
			imprimir(lista);
			break;
		default:
			if (opcao != 0)
				printf("Opcao invalida!\n");
		}

	} while (opcao != 0);

	return 0;
}

int inserir(TLista *L, int numero)
{
	//Passo 1: Alocar memória para o novo nó (aux)
	TLista aux = (TLista)malloc(sizeof(TNo));

	//malloc: retorna *void. Por isso, é necessário fazer casting para que os dois lados da tribuição sejam do mesmo tipo.

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

void exibir(TLista L)
{
	//declaração de variáveis
	TLista aux;
	//verificando se a lista está vazia
	if (L == NULL)
	{
		printf("Lista vazia!");
	}
	else
	{
		//printf ("Lista: ");
		//fazendo 'aux' apontar, inicialmente, para o primeiro nó da lista
		aux = L;
		while (aux != NULL) //'aux' percorrerá osnós da lista até que ele chegue ao valor NULL
		{
			//exibir o valor apontado pelo aux
			printf("%d ", aux->valor); //lê-se: aux apontado valor

			//printf ("%d ", (*aux).valor); equivalente ao comando da linha anterior

			//fazer o aux apontar para o próximo nó
			aux = aux->prox;
		}
		printf("\n\n");
	}
}