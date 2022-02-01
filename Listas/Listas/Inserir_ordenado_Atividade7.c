/*

a. Desenvolver uma função que, dada uma
lista encadeada L do tipo TLista, com seus
elementos ordenados crescentemente,
insira um número inteiro em L, de forma
que esta se mantenha ordenada.

b. Considerando um arquivo contendo
valores inteiros, um por linha,
implementar uma função que leia-os e os
armazene em uma lista encadeada do tipo
TLista, de forma que os elementos fiquem
ordenados crescentemente.

Notas:
− O tipo TLista citado é exatamente o tipo que
definimos em nossas aulas, em todas as implementações envolvendo listas encadeadas;

− A função do item b deve chamar a função do item a.


*/

#include <stdio.h>

// declaração de tipos
typedef struct
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

// Protótipo de Funções
void exibir(TLista L);
int inserirOrdenadamente(TLista *L, int numero);
TLista buscar(TLista L, int valorBuscado); // Só está aqui porque a função inserir usa ela.
int insereDoArquivo(TLista *L, char arquivo[]);
int menu();

int main()
{
    TLista L1 = NULL;
    int opcao, n, v, retorno;
    char *arquivo;
    do
    {
        // exibindo o menu ao usu�rio
        opcao = menu();

        switch (opcao)
        {
        // Inserir elemento
        case 1:
            printf("N: ");
            scanf("%d", &n);

            retorno = inserirOrdenadamente(&L1, n);

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

        // Insere numeros do arquivo na lista
        case 3:
            printf("Nome do arquivo: ");
            //__fpurge(stdin); linux
            fflush(stdin);
            gets(arquivo);

            retorno = insereDoArquivo(&L1, arquivo);

            if (retorno)
                printf("\nSUCESSO\n");
            else
                printf("\nFALHOU\n");
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
        0 : Erro na alocação de memória
        -1: O valor a ser inserido já estava presente na lista
*/
int inserirOrdenadamente(TLista *L, int numero)
{
    // Declaração de variáveis
    TLista novo, aux1, aux2;

    novo = (TLista)malloc(sizeof(TNo));

    if (novo == NULL)
    {
        // Se não for possível alocar memória, retorna 0 (false)
        return 0;
    }
    else
    {
        if (buscar((*L), numero))
        {
            // Se o elemento já existir na lista, retorna -1
            return -1;
        }
        else
        {
            novo->valor = numero;

            if (!(*L)) // Verificando se a lista está vazia.
            {
                novo->prox = (*L);
                (*L) = novo;
                return 1;
            }
            else // Se entrou aqui, tem pelo menos 1 TNo
            {
                aux1 = (*L);//ponteiro para o primeiro nó da Lista

                //novo "no campo valor"...
                if (novo->valor < aux1->valor) // verificando se o novo valor é MENOR que o primeiro TNo
                {
                    // Se a condição acima for verdadeira, novo->valor deve ser o primeiro elemento da lista.
                    novo->prox = aux1;
                    (*L) = novo;
                    return 1;
                }
                else // Se entrou aqui, o novo valor é maior que o primeiro TNo, logo, deve ser colocado adiante.
                {
                    aux2 = aux1->prox;
                    while (aux1->prox && novo->valor > aux2->valor) // Verificando se o novo valor é maior que o próximo TNo
                    {
                        aux1 = aux2;
                        aux2 = aux1->prox;
                    }

                    novo->prox = aux2;
                    aux1->prox = novo;

                    return 1;
                }
            }
        }
    }
}

TLista buscar(TLista L, int valorBuscado)
{
    TLista aux1, aux2;

    if (!L)
    {
        return NULL;
    }
    else
    {
        aux1 = L;

        while (aux1)
        {
            if ((aux1->valor) == valorBuscado)
            {
                return aux1;
            }

            aux2 = aux1;
            aux1 = aux2->prox;
        }

        return NULL; // valor não encontrado!
    }
}

int insereDoArquivo(TLista *L, char arquivo[])
{
    FILE *arq;
    int numero;

    arq = fopen(arquivo, "r");

    if (!arq)
    {
        return 0;
    }
    while (fscanf(arq, "%d", &numero) != EOF) // end of file
    {
        inserirOrdenadamente(&(*L), numero);
    }

    // fechar os arquivos
    fclose(arq);

    return 1;
}

int menu()
{
    int op;

    printf("\nMenu de opcoes:\n");
    printf("(1) Inserir\n");
    printf("(2) Exibir Lista\n");
    printf("(3) Insere do arquivo\n");
    printf("(7) Sair\n");
    printf("Entre com a sua opcao: ");
    scanf("%d", &op);

    return op;
}
