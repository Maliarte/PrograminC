/*


															Disciplina FPR
															Prof. Leonardo
															Aluna. Marília
        Desenvolver uma função que, dada uma
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

Nota: 3/10
- Por que, para este problema, criar o struct "Lista', armazenando o campo 'tam'?
R: Pensei que toda lista fosse um struct, contendo tnós.
o enunciado pede "Desenvolver uma função que, dada uma lista encadeada L do tipo TLista"
logo, deduzi por essa fórmula.

- Sem escritas nas funções!!!!  
R: Não entendi Professor. Isso quer dizer que deveria ter impresso algo, ou que não escrevi os parametros?

- 'lista' é ou não passado por referência?
R: é passada por referência, uma vez que inserir altera a mesma.

- Para que a função de inserção ao final?
R: Para ter as duas versões, não pode?

- O código apresenta 4 funções de inserção. Por que não enviar apenas aquela que foi solicitada e, portanto, deverá ser corrigida?

R: Justamente. Ainda não evoluí a esse ponto. E ainda não entendi, o sr poderia, por gentileza
escrever em código? 

- Manipulação de arquivos?
R:  Essa eu engoli mosca.

- E se o número a ser inserido for maior do que todos na lista?
R: Deveria ter uma função validadora, revendo o código sem prazo de entrega, vejo que poderia 
ter utilizado uma função que conheço, a select sort. Ela poderia sem implementada para listas?


Muito Obrigada por seu Feedback, Professor Leonardo. Isso é fundamental, para ver meus erros. Atenciosamente, Marilia.
Boa tarde, Marília.

Seguem minhas considerações sobre o seu trabalho de métodos de ordenação, sobre o método Selection Sort:

1) No início, quando fez uma introdução sobre os métodos de ordenação, você fez uma leitura rápida sobre o material;
2) Após esta introdução, você já começa a falar sobre o algoritmo, sem ter falado ainda em que consiste o método;
3) O meu maior questionamento foi esse: você deixar claro que compreendeu a dinâmica do método. Você explica detalhadamente, por exemplo, cada parte do 'for', diz que 'min' recebe o valor de 'i'. Mas por que? Por que isso acontece no Selection Sort? Se você tivesse explicado em que consistia o método e, em seguida, explicasse o código, seria mais fácil de compreender a sua apresentação, e de enxergar que você domina o método em si;
4) Quando você explica o 'for' interno, você fala que não tem lógica o 'j' começar com 'i' e, por isso, começa com 'i+1'? De novo, por que? Por que não começa com 0, por exemplo, se a primeira posição do vetor é 0? As respostas a essas perguntas estão no domínio do método;
5) Quando o valor de 'min' é atualizado, não existe uma troca naquele momento! 'min' armazenará a posição do menor elemento da posição 'i' em diante. Terminada esta estrutura de repetição, a troca ocorrerá (se i' for diferente de 'min'). Porém, quando você explica essa parte do código (do 'i' ser diferente de 'min'), você não deixa claro o que ocorre ali que, na prática, é uma troca, armazenando o menor elemento na posição 'i';
6) Quando você cita as complexidades, era importante ter pesquisado um pouco mais e, ao menos, deixar claro se algoritmos O(n²) é melhor ou pior do que algoritmos O (n.log 2 n);
7) Quando falamos de vetores grandes, 100 não é grande. Estamos falando de conjuntos muito maiores de valores;
8) Em seu material, você cita duas desvantagens (de maneira escrita), sobre estabilidade e número de comparações, mas não fala sobre elas;
9) Ao apresentar as ilustrações, era mais uma oportunidade de você falar sobre o funcionamento do método. Não são comparadas posições consecutivas. Cada posição 'i' é comparada com todas as que estão além dela, até o final do vetor.

Destaco a sua didática, a forma que você faz a sua explicação, muito à vontade. 
Docência a caminho? rs

Atenciosamente,
 
*/

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

/*
void ordenarLista(int num[], int tamanho)
{
    // declaração de variaveis
    int i, j, min, aux;

    for (i = 0; i < (tamanho - 1); i++)
    {
        min = i;

        //j iniciando na posicao seguinte ao i
        for (j = (i + 1); j < tamanho; j++)
        {
            //achar o valor minimo
            if (num[j] < num[min])
            {
                /*      comparando o indice do segundo for com o o do primeiro
                            o index do vetor num, como sendo 'min' ou seja será  o indice de 'i' atual.
                min = j;
            }
        }
        //comparando o ultimo elemento percorrido em 'i' e se ele for diferente do menor valor
        //irá fazer a troca. ou seja, i ja é o menor o menor numero entre os numeros analizados
        if (i != min)
        {
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
        }
    }
}



}
*/

void criar_lista(Lista *lista){
    lista -> inicio = NULL;
    lista -> tam = 0;
}

// procedimento para inserir no início
void inserir_no_inicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            aux = lista->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(Lista *lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // é o primeiro?
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir ordenado
void inserir_ordenado(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if(novo->valor < lista->inicio->valor){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("\n\tLista tam %d: ", lista.tam);
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, anterior;
    //No *lista = NULL;
    Lista lista;

    criar_lista(&lista);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - inserir no Fim\n\t3 - Inserir no Meio\n\t4 - Inserir Ordenado\n\t5 - Imprimir Lista\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            imprimir(lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}