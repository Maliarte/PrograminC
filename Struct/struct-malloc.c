/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Manhã
	Data: 10/12/2021
	
	Listas dinâmicas / Listas encadeadas / Listas ligadas (linked list)
	
		(continuação da aula de 08/12/2021)
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {			//representando cada nó da lista, com os campos:
	int valor;				//  - valor: o dado armazenado na lista;
	struct No* prox;		//  - prox: o endereço do próximo nó da lista.
} TNo;

typedef TNo* TLista;		//TLista equivale a TNo* (ou seja, TLista é um ponteiro para o struct TNo)

//protótipos de funções
int inserir (TLista* L, int numero);
int remover (TLista* L, int numero);
int alterar (TLista L, int numero, int numeroNovo);
int buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista lista = NULL;		//inicializando 'lista' com NULL; ou seja, uma lista vazia!
	int quant, opcao, num1, num2;
	
	do
	{
		//o menu de opções será apresentado ao usuário até que ele opte por sair do sistema
		opcao = menu ();
		
		//testando a opção escolhida
		switch (opcao)
		{
			//Inserção
			case 1: printf ("Numero a ser inserido: ");
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
					break;
			
			//Remoção
			case 2: printf ("Numero a ser removido: ");
					scanf ("%d", &num1);
			
					//chamando a função
					if (remover (&lista, num1) == TRUE)
					{
						printf ("\n\tRemocao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tRemocao nao realizada!\n");
					}
					break;
			
			//Alteração
			case 3: printf ("Numero a ser alterado: ");
					scanf ("%d", &num1);
					
					printf ("Novo valor: ");
					scanf ("%d", &num2);
			
					//chamando a função
					quant = alterar (lista, num1, num2);
					if (quant > 0)
					{
						printf ("\n\t%d ocorrencias de %d foram alteradas para %d.\n", quant, num1, num2);
					}
					else
					{
						printf ("\n\tAlteracao nao realizada!\n");
					}
					break;
					
			//Busca
			case 4: printf ("Numero a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (buscar (lista, num1) == TRUE)
			        {
			        	printf ("\n\tElemento encontrado na lista!\n");
					}
					else
					{
						printf ("\n\tElemento nao encontrado na lista!\n");
					}
					break;
			
			//Exibição
			case 5: //chamando a função
			        exibir (lista);
			        break;
			       
			//saída do programa 
			case 6: printf ("Fim do programa!\n");
			        break;
			        
			//opção inválida
			default:printf ("Opcao invalida! Tente novamente.\n");
			        break;
		}
		
		system ("pause");
	}
	while (opcao != 6);	  //6 - opção de saída
}

//implementação das funções
int inserir (TLista* L, int numero)
{
	//Passo 1: Alocar memória para o novo nó (aux)	
	TLista aux = (TLista) malloc (sizeof(TNo));    //malloc: retorna *void. Por isso, é necessário fazer casting para que os dois lados da atribuição sejam do mesmo tipo.
	

    
	//testando se a memória não foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else	//a memória foi alocada
	{
		//Passo 2: Armazenar o valor a ser inserido na posição recém-alocada (no campo valor)	
		aux->valor = numero;

        //valor apontado  pelo aux recebe o numero
		
		//Passo 3: Fazer o novo nó apontar (através do campo prox) para o nó que até então era o primeiro da lista	
		
		
		//Passo 4: Fazer o ponteiro inicial da Lista (L) apontar para o novo nó			
	}
}

int removerAntes (TLista* L, int numero)
{	

//ERRO! Para dados consecultivos de mesmo valor apresenta-se um custo de processamento 

/*é sempre um caso base e um teto retornando um valor booleano 


-nao entendi, Marilia.

 */

    if ((*L)->valor == numero)
	{
		//Passo1: armazenar em uma variável auxiliar o endereço do nó a ser removido (neste caso, o primeiro nó)
		aux1 = *L;
		
		//Passo2: fazer com que L aponte para o "segundo" nó da lista.
		*L = (*L)->prox;  //ou   *L = aux1->prox;
		
		//Passo3: liberar a memória apontada pelo auxiliar
		free (aux1);
		
		cont++;
	}
}

int alterar (TLista L, int numero, int numeroNovo)
{
	//declaração de variáveis
	TLista aux;
	int cont = 0;
	
	//fazendo 'aux' apontar, inicialmente, para o primeiro nó da lista
	aux = L;
	
	while (aux != NULL)		//'aux' percorrerá os nós da lista até que ele chegue ao valor NULL
	{
		//verificando se 'aux' está apontando para um nó contendo 'numero'
		if (aux->valor == numero)
		{
			aux->valor = numeroNovo;
			cont++;
		}		
				
		//fazer o aux apontar para o próximo nó
		aux = aux->prox;
	}
	
	//retornando a quantidade de alterações realizadas
	return cont;
}

int buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//fazendo 'aux' apontar, inicialmente, para o primeiro nó da lista
	aux = L;
	
	while (aux != NULL)		//'aux' percorrerá os nós da lista até que ele chegue ao valor NULL
	{
		//verificando se 'numero' foi encontrado na lista
		if (aux->valor == numero)
		{
			return TRUE;
		}		
		
		//fazer o aux apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se a execução chegou a este ponto, o 'numero' não existe na lista
	return FALSE;
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
	}
}

/*
versão utilizando FOR

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux;
	
	for (aux = L; aux != NULL; aux = aux->prox)
	{
		//exibir o valor apontado pelo aux
		printf ("%d ", aux->valor);   //lê-se: aux apontado valor
		//printf ("%d ", (*aux).valor);    equivalente ao comando da linha anterior
	}
}
*/

int menu ()
{
	//declaração de vairáveis
	int op;
	
	//limpando a tela
	system ("cls");
	
	//exibindo o menu de opções ao usuário	
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção desejada
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	//retornando a opção
	return op;
}
