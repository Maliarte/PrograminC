/*
	Atividade 12:
		Implementar uma função que, dada uma lista encadeada L1, do tipo TLista, 
		crie uma nova lista L2, também do tipo TLista, 
		contendo os elementos de L1, porém na ordem inversa.

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
int inserir (TLista *L, int numero);
int copiarInvertido (TLista L1, TLista *L2);
int menu ();

void main ()
{
	//Variáveis
	TLista L1 = NULL, L2 = NULL;
	int opcao, n, i;
	
	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();
		
		switch (opcao)
		{
			//Inserir elemento
			case 1: 
					printf("N: ");
					scanf("%d", &n);
					
					if (inserir (&L1, n))
					{
						printf("Elementos inseridos!\n");
					}
					else
					{
						printf("[ERRO]Nenhum elemento inserido!\n");
					}
					break;
					
			//Exibir Lista        
			case 2: 
					printf("[0] L1\n[1] L2\n");
					scanf("%d", &i);
					if (i)
						exibir(L2);
					else
						exibir(L1);
					break;
			
			//Copiar invertido
			case 3:
					if(copiarInvertido (L1, &L2))
					{
						printf("Copiado com sucesso!\n");
					}
					else
					{
						printf("Erro ao copiar!\n");
					}
					
					break;
			//Sair
			case 4:
					printf("\nSaindo...");
					
					break;
			//opção inválida
			default: printf ("Opção invalida! Tente novamente.\n");
		}
		
		system ("pause");
	}
	while (opcao != 4);
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
	TLista novo;
	
	novo = (TLista) malloc (sizeof(TNo));

	if (novo == NULL)
	{
		return 0;
	}
	else
	{
		novo->valor = numero;
		novo->prox = *L;
		*L = novo;
		
		return 1;
	}
}

int copiarInvertido (TLista L1, TLista *L2)
{
	TLista aux1, aux2, novo;
	
	if (!L1) //Caso L1 esteja vazia, não há o que copiar, então, retorna falso.
	{
		return 0;
	}
	else
	{
		aux1 = L1;
		
		while (aux1)
		{
			novo = (TLista) malloc (sizeof(TNo));
			
			if (!novo)
			{
				return 0;
			}
			else
			{
				/*
					O importante para resolver essa questão foi perceber que
					bastaria fazer as inserções em L2 a partir dos elementos
					percorridos por L1, pois isso resulta em L2 com os elementos
					invertidos em relação a L1.
				*/
				novo->prox = (*L2);
				novo->valor = aux1->valor;
				
				(*L2) = novo;
				aux2 = aux1;
				aux1 = aux2->prox;
			}	
		}
		
		//Se a cópia for bem sucedida, retorna true.
		return 1;
	}
	
	
}

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir Lista\n");
	printf ("(3) Copiar Invertido\n");
	printf ("(4) Sair\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	return op;
}