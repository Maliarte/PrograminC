/*
	Atividade 9: 
		Implementar uma função que destrua todos os elementos de uma lista encadeada do tipo TLista.
		Observação: apresentar a solução em duas versões: uma iterativa e outra recursiva.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h> 

//definição de tipos
typedef struct No {
	int valor;			//valor declarado como int, por se tratar de uma lista de inteiros.
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
void exibir (TLista L);
void destruir_iterativa (TLista *L);
void destruir_recursiva (TLista *L);
int inserir (TLista *L, int numero);
int menu ();

void main ()
{
	//declaração de variáveis
	TLista L1 = NULL;			//lista inicialmente vazia
	int opcao, num; 
	
	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();
		
		switch (opcao)
		{
			//Inserir
			case 1: 
				printf("Valor: ");
				scanf("%d", &num);
				if(inserir(&L1, num))
				{
					printf("Elemento inserido com sucesso!\n");
				}
				else
				{
					printf("[ERRO] Elemento nao inserido!!!\n");
				}
				break;
				
			//Iterativa
			case 2: destruir_iterativa(&L1);
					break;
				
			//Recursiva
			case 3: destruir_recursiva(&L1);
			        break;
			        
			//Exibir Lista        
			case 4: exibir(L1);
					break;
			//Sair
			case 5: printf("Saindo...");
					break;
				
			//opção inválida
			default: printf ("Opção invalida! Tente novamente.\n");
		}
		
		system ("pause");
	}
	while (opcao != 5);
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

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir Valor\n");
	printf ("(2) Destruir Iterativa\n");
	printf ("(3) Destruir Recursiva\n");
	printf ("(4) Exibir Lista\n");
	printf ("(5) Sair\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	return op;
}

void destruir_iterativa (TLista *L)
{
	TLista aux1;
	
	while (*L) 
	{
		aux1 = (*L);
		(*L) = aux1->prox;
		free(aux1);
	}
}

void destruir_recursiva (TLista *L)
{
	TLista aux;
	if (*L)
	{
		aux = (*L);
		(*L) = aux->prox;
		free(aux);
		destruir_recursiva(&(*L));
	}
}