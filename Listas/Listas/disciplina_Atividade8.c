/*
    Desenvolvido por: Marília S. 
    Apoie o projeto de educaçao tecnológica dando uma estrelinha no repositório origem: 

   (*) https://github.com.br/maliarte  - creative c.

   Fontes ext:

    https://wagnergaspar.com/lista-encadeada-com-a-linguagem-c/
    #:~:text=Seu%20principal%20benef%C3%ADcio%20%C3%A9%20seu,que%20n%C3%A3o%20aponta%20para%20ningu%C3%A9m.

    A necessidade faz o Sapo Pular
    https://www.jurisway.org.br/v2/dhall.asp?id_dh=701
==================================================================================

                DAS UTOPIAS
                Mario Quintana , Espelho Mágico.

                "   
                    Se as coisas são inatingíveis... ora!
                    Não é motivo para não querê-las...
                    Que tristes os caminhos, se não fora
                    A presença distante das estrelas!
                " 
====================================================================================

Listas Encadeadas 


Pense como uma máquina. A necessidade faz o sapo pular.
Nesse caso, a necessidade de armazenar estruturas de dados mais complexas.
Ou seja, a manipulação de um conjunto de informações de tipos de dados primitivos diferentes, 
mas que possuem um relacionamento lógico entre si; 

Armazenar diferentes tipos de dados em uma mesma estrutura. 

Estruturas de dados que iniciam vazias e são modificadas à medida
da necessidade.

Para tal, é preciso criar as estruturas necessárias, neste caso, 
duas estruturas: uma para a lista propriamente dita e outra para os nós da lista.


PROBLEMA:

    1) Considere a existência de 

        uma lista encadeada L1 do tipo: TNotas, que consiste em um ponteiro para TNo1 
     
     com os campos
        * matricula, 
        * disciplina e 
        * nota 

 – além de um ponteiro para o próximo nó da lista.

Pede-se o desenvolvimento de uma função que crie uma lista encadeada L2, do tipo
TDisciplinas (ponteiro para TNo2 com os campos disciplina, media e prox).

Notas:

− Cada nó de L1 representará o
desempenho de um aluno em
determinada disciplina;

− Por sua vez, cada nó da nova lista
armazenará o nome da disciplina e a
média da turma na mesma.

*/

#include <stdio.h>
#include <string.h>

// declaração de tipos

            typedef struct No1
            {
                char matricula[10],
                    disciplina[5];
                float nota;

                struct No1 *prox; //além de um ponteiro para o próximo nó da lista.
            } TNo1;

            typedef TNo1 *TNotas; // o tipo  consiste em um ponteiro para TNo1



            typedef struct No2
            {
                char disciplina[5];
                float media;
                struct No2 *prox;
            } TNo2;

            typedef TNo2 *TDisciplinas;

// Protótipo de Funções
void exibirNotas(TNotas L);
void exibirDisciplinas(TDisciplinas L);
int inserirNota(TNotas *L1, char *matricula, char *disciplina, float nota);
int inserirDisciplina(TDisciplinas *L2, char *disciplina, float media);
TDisciplinas buscarDisciplina(TDisciplinas L, char *disciplina);
float atualizaMedia(TNotas L1, char *disciplina);
int menu();

int main()
{
                        
    TNotas L1 = NULL;  
    TDisciplinas L2 = NULL;

    char matricula[10], disciplina[5];
    int opcao, retorno;

    float nota;

    do
    {
        // exibindo o menu ao usuário
        opcao = menu();

        switch (opcao)
        {
        // Inserir Nota
        case 1:
            printf("Matricula: ");
            fflush(stdin); //_fpurge
            gets(matricula);

            printf("Disciplina: ");
            fflush(stdin);
            gets(disciplina);

            printf("Nota: ");
            scanf("%f", &nota);

            retorno = inserirNota(&L1, matricula, disciplina, nota);

            if (retorno == 1)
            {
                printf("Elementos inseridos!\n");
            }
            else
            {
                printf("[ERRO]Nao foi possivel inserir!\n");
            }

            // Verificando se a disciplina informada já está em L2
            TDisciplinas pDisciplina = buscarDisciplina(L2, disciplina);

            if (pDisciplina != NULL) // Se entrou aqui, a disciplina já está na lista
            {
                pDisciplina->media = atualizaMedia(L1, disciplina);
            }
            else // Se entrou aqui, não está na lista
            {
                inserirDisciplina(&L2, disciplina, nota);
            }
            break;
        // Exibir Lista de Notas
        case 2:
            exibirNotas(L1);
            break;

        case 3:
            exibirDisciplinas(L2);
            break;

        // Sair
        case 0:
            printf("\nSaindo...");

            break;
        // opcao invalida
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void exibirDisciplinas(TDisciplinas L)
{
    // declaracao de variaveis
    TDisciplinas aux;

    // testando se a lista esta vazia
    if (!L)
    {
        printf("\nSem disciplinas!\n\n");
    }
    else
    {
        aux = L;

        // percorrendo todos os nós da lista
        while (aux)
        {
            printf("[%s][%.1f] -> ", aux->disciplina, aux->media);
            aux = aux->prox;
        }
    }
}

void exibirNotas(TNotas L)
{
    // declaracao de variaveis
    TNotas aux;

    // testando se a lista esta vazia
    if (!L)
    {
        printf("\nSem notas!\n\n");
    }
    else
    {
        aux = L;

        // percorrendo todos os nós da lista
        while (aux)
        {
            printf("[%s][%s][%.1f] -> ", aux->matricula, aux->disciplina, aux->nota);
            aux = aux->prox;
        }
    }
}

/*
    Possíveis retornos da função 'inserirNota()':
        1 : Sucesso na inserção
        0 : Erro na inserção
*/
int inserirNota(TNotas *L1, char *matricula, char *disciplina, float nota)
{
    // Declaração de variáveis
    TNotas novo;

    novo = (TNotas)malloc(sizeof(TNo1));

    if (novo == NULL)
    {
        // Se não for possível alocar memória, retorna 0 (false)
        return 0;
    }

    strcpy(novo->matricula, matricula);
    strcpy(novo->disciplina, disciplina);
    novo->nota = nota;
    novo->prox = *L1;

    *L1 = novo;

    // Caso a inserção seja feita, retorna 1
    return 1;
}

/*
    Possíveis retornos da função 'inserirDisciplina()':
        1 : Sucesso na inserção
        0 : Erro na inserção
*/
int inserirDisciplina(TDisciplinas *L2, char *disciplina, float nota)
{
    // Declaração de variáveis
    TDisciplinas novo;

    novo = (TDisciplinas)malloc(sizeof(TNo2));

    if (novo == NULL)
    {
        // Se não for possível alocar memória, retorna 0 (false)
        return 0;
    }

    strcpy(novo->disciplina, disciplina);
    novo->media = nota;
    novo->prox = *L2;

    *L2 = novo;

    // Caso a inserção seja feita, retorna 1
    return 1;
}

TDisciplinas buscarDisciplina(TDisciplinas L, char *disciplina)
{
    TDisciplinas aux1 = NULL;

    if (!L)
    {
        return NULL;
    }
    else
    {
        aux1 = L;

        while (aux1)
        {
            if (strcmp(aux1->disciplina, disciplina) == 0)
            {
                return aux1;
            }

            aux1 = aux1->prox;
        }

        return NULL; // valor não encontrado!
    }
}

float atualizaMedia(TNotas L1, char *disciplina)
{
    TNotas aux1;
    int cont = 0;
    float acumulaNotas = 0, media;

    aux1 = L1;

    while (aux1)
    {
        if (strcmp(aux1->disciplina, disciplina) == 0)
        {
            acumulaNotas += aux1->nota;
            cont++;
        }

        aux1 = aux1->prox;
    }

    media = (acumulaNotas / cont);

    return media;
}

int menu()
{
    int op;

    printf("\nMenu de opcoes:\n");
    printf("(1) Inserir NOTA\n");
    printf("(2) Exibir Notas\n");
    printf("(3) Exibir Disciplinas\n");
    printf("(0) Sair\n");
    printf("Entre com a sua opcao: ");
    scanf("%d", &op);

    return op;
}
