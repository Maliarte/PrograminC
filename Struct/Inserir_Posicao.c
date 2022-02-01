/*
	Atividade 11:
		Desenvolver uma função que insira um número inteiro N na i-ésima posição
		de uma lista encadeada L, do tipo TLista.
		
		Observação: caso a posição i informada seja inválida, 
		a função deverá retornar o valor 0; caso contrário, o retorno será igual a 1.
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
int inserirInteiro (TLista L, int numero, int i);
int menu ();

void main ()
{
	//Variáveis
	TLista L1 = NULL;
	int opcao, n, i;
	
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
					exibir(L1);
					break;
			
			//Inserir na i-ésima
			case 3:
					printf("Valor: ");
					scanf("%d", &n);
					printf("I: ");
					scanf("%d", &i);
					
					if(inserirInteiro (L1, n, i))
					{
						printf("Inserido com sucesso!\n");
					}
					else
					{
						printf("Erro ao inserir!\n");
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

int inserirInteiro (TLista L, int numero, int i)
{
	TLista aux1 = L, aux2 = aux1, novo;
	int cont=0;//Contador para o número de posições da lista
		
	while (aux1) //Percorrendo a lista
	{	
		//Se a posição da lista for igual a posição escolhida, insere
		if (cont == i) 
		{
			novo = (TLista) malloc (sizeof(TNo));
			
			novo->prox = aux1; //O novo elemento aponta para aux1;
			novo->valor = numero; //recebendo o valor passado por parâmetro.
			
			aux2->prox = novo; //O elemento anterior aponta para o novo.
			
			return 1; // Fim da função
		}
		
		aux2 = aux1;
		aux1 = aux2->prox;
		
		cont++;//Incrementando o contador de posições
	}
	
	//Se chegou aqui, é porque a posição escolhida não existe.
	return 0;
}

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir Lista\n");
	printf ("(3) Inserir na I-esima\n");
	printf ("(4) Sair\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	return op;
}