/*
Dadas duas listas encadeadas L1 e L2, ambas do
tipo TLista, ordenadas crescentemente e sem
repetição de elementos, criar uma terceira lista
L3, contendo todos os elementos de L1 e L2.
Como as duas originais, a nova lista deve ter
seus elementos ordenados crescentemente, e
sem repetição de valores.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *prox;
} TNo;

typedef TNo *TLista;


// funções prototipo;
TLista cria_lista();
void imprime_lista(TLista l);
TLista uniao(TLista l1, TLista l2);
int pertence(TLista l, int x);
//void ordena(TLista *l);
void insere_lista_ordenada(TLista *lista, int x);

// função para criar uma lista vazia
TLista cria_lista()
{
    return NULL;
}
// função para imprimir a lista
void imprime_lista(TLista l)
{
    while (l != NULL)
    {
        printf("%d ", l->info);
        l = l->prox;
    }
    printf("\n");
}
/* função para verificar se a lista está vazia
int lista_vazia(TLista l)
{
    return l == NULL;
}*/
// função para verificar se um elemento está na lista
int pertence(TLista l, int x)
{
    TNo * aux;
    aux = l;
    while (aux != NULL)
    {
        if (aux->info == x)
            return 1;
        aux = aux->prox;
    }
    return 0;
}
/*// função para contar o número de elementos da lista
int conta_elementos(TLista l){
    int cont = 0;
    while(l != NULL){
        cont++;
        l = l->prox;
    }
    return cont;
}
// função para verificar se a lista está ordenada
int ordenada(TLista l)
{
    while (l != NULL && l->prox != NULL && l->info < l->prox->info)
    {
        l = l->prox;
    }
    return l == NULL;
}
// função para ordenar a lista
void ordena(TLista *l)
{
    TLista p = *l;
    TLista ant = NULL;
    TLista atual = p;
    TLista prox = p->prox;
    while (atual != NULL)
    {
        while (prox != NULL && prox->info < atual->info)
        {
            ant = atual;
            atual = prox;
            prox = prox->prox;
        }
        if (ant == NULL)
        {
            *l = prox;
        }
        else
        {
            ant->prox = prox;
        }
        atual->prox = prox;
        if (prox != NULL)
        {
            prox->prox = atual;
        }
    }
}*/
// função faz uniao ordenada sem repetição de elementos
TLista uniao(TLista l1, TLista l2)
{
    TLista l3 = cria_lista();
    TLista aux = l1;
    while (aux != NULL)
    {
        insere_lista_ordenada(&l3, aux->info);
        aux = aux->prox;
    }
    aux = l2;
    while (aux != NULL)
    {
        if (!pertence(l3, aux->info))
        {
            insere_lista_ordenada(&l3, aux->info);
        }
        aux = aux->prox;
    }
    return l3;
}
// função para inserir um elemento na lista de for ordenada
void insere_lista_ordenada(TLista *lista, int x)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    novo->info = x;
    novo->prox = NULL;
    TLista p = *lista;
    TLista ant = NULL;
    while (p != NULL && p->info < x)
    {
        ant = p;
        p = p->prox;
    }
    if (ant == NULL)
    {
        *lista = novo;
    }
    else
    {
        ant->prox = novo;
    }
    novo->prox = p;
}
// teste
void main()
{
    TLista l1 = cria_lista();
    TLista l2 = cria_lista();
    int i, opcao;
    imprime_lista(l1);
    imprime_lista(l2);
    do
    {
        printf("Digite um valor para a lista 1: ");
        scanf("%d", &i);
        if (pertence(l1, i))
        {
            printf("Elemento já existe na lista 2\n");
        }
        else
        {
            insere_lista_ordenada(&l1, i);
        }
        printf("continuar? (1-sim/2-nao)");
        scanf("%d", &opcao);
        imprime_lista(l1);

    } while (opcao != 2);
    do
    {
        printf("Digite um valor para a lista 2: ");
        scanf("%d", &i);
        if (pertence(l2, i))
        {
            printf("Elemento já existe na lista 2\n");
        }
        else
        {
            insere_lista_ordenada(&l2, i);
        }
        printf("continuar? (1-sim/2-nao)");
        scanf("%d", &opcao);
        imprime_lista(l2);
    } while (opcao != 2);
    printf("Lista 1: ");
    imprime_lista(l1);
    printf("Lista 2: ");
    imprime_lista(l2);
    printf("Lista 3: ");
    imprime_lista(uniao(l1, l2));
}