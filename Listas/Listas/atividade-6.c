/* 
    FPR - Fundamentos de Programação
    Docente: Leonardo Vianna
	Discente: Marília Silva 

    Atividade VI

    Desenvolver uma função que, dada uma string s,
    crie uma lista encadeada L da qual cada nó
    armazenará um caracter de s.
    
    ex:
    L    O     D     O
    tno  ..   ..    ..

    10/10

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0



typedef struct no
{
    char caracter;
    struct no *prox;
} TNo;

typedef TNo *TLista;





//prototipos
void lista(TLista *L, char *string);
void imprimeLista(TLista L);
int inserir(TLista *L, char letra);

void main()
{
    char string[30];
    TLista L = NULL;
    printf("Escreva uma palavra:\n");
    gets(string);
    
    lista(&L, string);

    imprimeLista(L);
}




////////////////////funcoes 

int inserir(TLista *L, char letra)
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
		aux->caracter = letra;
		//Passo 3: Fazer o novo nó apontar (através do campo prox) para o nó que até então era o primeiro da lista 
		aux->prox = *L;
		//Passo 4: Fazer o ponteiro inicial da Lista (L) apontar para o novo nó
		*L = aux;
		
		return TRUE;
	}
}



void lista(TLista *L, char *string)
{
    // Declaracao Variaveis
    int i;

    /* ERRO
    ODOL - na lista encadeada sempre insere na primeira posicao ficando no fist in last out 
    duas opçoes: ou refaz opçao inserer : caro
    ou simplesmente le sua string ao contrario [x]
    for (i = 0; i < (strlen); i++)

    */
    for (i = strlen(string)-1; i >= 0; i--)
    {
        inserir(&(*L), string[i]); //endereço de memoria do ponteiro 'l' pois a funcao inserir modifica a lista

    }
}





void imprimeLista(TLista L)
{
    TLista aux = L;

    while (aux != NULL)
    {
        printf("%c", aux->caracter);
        aux = aux->prox;
    }
}

