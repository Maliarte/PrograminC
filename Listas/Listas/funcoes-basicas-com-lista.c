#include <stdio.h>

// declaração de tipos
typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

// Protótipo de Funções
void exibir(TLista L);
int inserir(TLista *L, int numero);
TLista buscar(TLista L, int valorBuscado); // Só está aqui porque a função inserir usa ela.
int menu();

int main()
{
    TLista L1 = NULL;
    int opcao, n, v, retorno;

    do
    {
        // exibindo o menu ao usuahrio
        opcao = menu();

        switch (opcao)
        {
        // Inserir elemento
        case 1:
            printf("N: ");
            scanf("%d", &n);

            retorno = inserir(&L1, n);

            if (retorno == 1)
            {
                printf("Elementos inseridos!\n");
            }
            else
            {
                // Caso o elemento que tentou inserir j� esteja presente na lista
                if (retorno == -1)
                {
                    printf("[ERRO]Elemento ja presente na lista!\n");
                }
                else
                {
                    printf("[ERRO]Nao foi possivel inserir!\n");
                }
            }
            break;
        // Exibir Lista
        case 2:
            exibir(L1);
            break;

        // Sair
        case 7:
            printf("\nSaindo...");

            break;
        // opcao invalida
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}

void exibir(TLista L)
{
    // declaracao de variaveis
    TLista aux;

    // testando se a lista esta vazia
    if (!L)
    {
        printf("\nLista Vazia!\n\n");
    }
    else
    {
        printf("\nLista: ");

        aux = L;

        // percorrendo todos os nós da lista
        while (aux)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
}

/*
    Possíveis retornos da função 'inserir()':
        1 : Sucesso na inserção
... (75 linhas)