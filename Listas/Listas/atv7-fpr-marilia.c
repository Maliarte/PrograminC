
/*
Desenvolver uma função que, dada uma lista
encadeada L do tipo TLista, exiba os seus
elementos “de trás para frente”; ou seja, o
elemento apontado por L será o último a ser
exibido.
Nota: por ser uma atividade que avalia a
manipulação de listas encadeadas, nenhuma outra
estrutura de dados (como vetores, por exemplo)
pode ser utilizada nesta solução.

*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// definindo struct dos nós
typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista; // definindo struct de suporte para segurar o ponteiro (para n repetir sempre TNo*)

// prototipos
void inserir(TLista *L, int inserirValor);
void exibir(TLista L);
void exibirInverso(TLista L);
void recur(TLista ponteiro);
TLista criaLista();

int main()
{
    int escolha = 0, inserirVal;
    TLista L = criaLista();

    do
    {
        printf("Escolha uma das opcoes a seguir\n[1] - Inserir numero\n[2] - Exibir Lista\n[3] - exibir lista inverso \n[4] - Fechar Programa\nSelecione:\t");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o valor a ser colocado: ");
            scanf("%d", &inserirVal);

            inserir(&L, inserirVal);
            break;
        case 2:
            exibir(L);
            break;
        case 3:
            exibirInverso(L);
            break;
        default:
            printf("Finalizando Aplicaçao...\n");
            break;
            printf("\n");
            // system("pause");
            // system("cls");
        }
    } while (escolha < 4 || escolha > 0);
}
TLista criaLista(){
    TLista L = NULL;
    return L;
}
void inserir(TLista *L, int inserirValor)
{
    TLista novo = (TLista)malloc(sizeof(TNo));
    novo->valor = inserirValor;
    novo->prox = NULL;
// caso lista vazia ou seja , primeiro nó já apontando pra nulo
    if (*L == NULL)
    {
        *L = novo;
    }
    // do contrario há elementos na lista e o novo nó será inserido no final
    else
    {
        TLista aux = *L;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}
void exibir(TLista L)
{
    if (L != NULL)
    {
        recur(L);
    }
    else
    {
        printf("Lista Vazia");
    }
}
void recur(TLista ponteiro)
{

    if (ponteiro != NULL)
    {

        recur(ponteiro->prox);
        printf("%d ", ponteiro->valor);
    }
}
void exibirInverso(TLista l)
{
    if (l != NULL)
    {
        exibirInverso(l->prox);
        printf("%d ", l->valor);
    }
}