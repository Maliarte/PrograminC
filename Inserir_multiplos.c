/*
	Atividade 10: 
		Implementar uma função que armazene em uma lista encadeada
		os n primeiros múltiplos do número x.
		
		Observação: os elementos devem estar dispostos do menor múltiplo para o maior.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h> 

//definição de tipos
typedef struct No {
	int valor;		
	struct No* prox;
} TNo;

typedef TNo* TLista;





//protótipos das funções

	void exibir (TLista L);

	int inserirMultiplos (TLista *L, int n, int x);

	int inserir (TLista *L, int numero);

	int menu ();



void main ()
{
	//lista inicialmente vazia
	TLista L1 = NULL;	

	int opcao, n, x, r;
	
	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();
		
		switch (opcao)
		{
			//Inserir multiplos
			case 1: 
					printf("N: ");
					scanf("%d", &n);
					
					printf("X: ");
					scanf("%d", &x);
					
					r = inserirMultiplos (&L1, n, x);
					
					if (r)
					{
						printf("%d elementos inseridos!", r);
					}
					else
					{
						printf("Nenhum elemento inserido!");
					}
					break;
					
			//Exibir Lista        
			case 2: 
					exibir(L1);
					break;
			
			//Sair
			case 3:
					printf("\nSaindo...");
					break;
			//opção inválida
			default: printf ("Opção invalida! Tente novamente.\n");
		}
		
		system ("pause");
	}
	while (opcao != 3);
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux;
	
	//testando se a lista está vazia
	if (L == NULL)   //if (!L)
	{
		printf ("\nLista Vazia!\n\n");
	}
	else
	{
		printf ("\nLista: ");
		
		//inicializando 'aux' de forma que aponte para o primeiro nó da lista
		aux = L;
		
		//percorrendo todos os nós da lista
		while (aux != NULL) //while (aux) 
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//andar com o 'aux' de forma que ele aponte para o próximo nó
			aux = aux->prox;
		}
	}
}

int inserir (TLista *L, int numero)
{
	//Declaração de variáveis
	TLista aux;
	
	aux = (TLista) malloc (sizeof(TNo));

	if (aux == NULL)
	{
		return 0;
	}
	else
	{
		aux->valor = numero;
		aux->prox = *L;
		*L = aux;
		
		return 1;
	}
}

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir Multiplos\n");
	printf ("(2) Exibir Lista\n");
	printf ("(3) Sair\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	return op;
}

int inserirMultiplos (TLista *L, int n, int x)
{
	//Declaração de variáveis
	TLista aux;
	int i=n, cont=0;
	
	for (;i>=1;i--)
	{
		cont += inserir(L, i*x);
	}
	
	return cont;
}