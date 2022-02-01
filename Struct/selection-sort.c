/* Um grupo de pessoas foi entrevistado e cada
uma informou o seu nome e o nome de sua mãe.
Estes dados foram armazenados em um vetor do
qual cada posição consiste em um struct.
Desenvolver uma função que receba um vetor
como o descrito acima e retorne outro
contendo, para cada mãe, o número de filhos
entrevistados (portanto, um outro vetor de
structs).
Nota: considerar que não existem duas ou mais
mães com o mesmo nome. 
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 100

typedef struct
{
    char nome[30];
    char mae[30];
} Tpessoa;

typedef struct
{
    char nome[30];
    int qtd;
} Tmae;

void contabilizaMaes(Tpessoa *p, Tmae *vMae, int *totPessoas, int *totmaes);
void imprime(Tmae *vMae, int *totmaes);
int busca(Tmae *vMae, int n, char *nome);
void alimentaVetorPessoas(Tpessoa *p, int *totPessoas);


void main()
{
    int totalPessoas=0,totmaes;
    Tpessoa pessoas[MAX];
    Tmae vMae[MAX];

    alimentaVetorPessoas(pessoas, &totalPessoas);
    //recebe vetor de pessoa e tem que pegar cada filho para ver se tem qtd de mae iguals e incrementa no vetor de mais

    //preenche 'vMae'
    contabilizaMaes(pessoas, vMae, &totalPessoas, &totmaes);

    imprime(vMae, &totmaes);
}
void imprime(Tmae *vMae, int *totmaes)
{
    int i;
    for (i = 0; i < *totmaes; i++)
    {
        printf("\n  mae : %s \n filhos  %d f\n", vMae[i].nome, vMae[i].qtd);
        printf("*********************************************************\n");
    }
}
void alimentaVetorPessoas(Tpessoa *p, int *totPessoas)
//todo vetor é um ponteiro, que aponta o endereço do primeiro elemento podendo ser p[] 
{
    int i;  
    char controle;
    for (i = 0; i < MAX && controle!= 'n'; i++)
    {
        fflush(stdin);
        printf("Nome: ");
        scanf("%s", p[i].nome);

        fflush(stdin);
        printf("Mae: ");
        scanf("%s", p[i].mae);
        (*totPessoas)++;
        printf("Deseja continuar? (s/n): \n");
        controle=getchar();
    }
}
void contabilizaMaes(Tpessoa *p, Tmae *vMae, int *totPessoas, int *totmaes)
{
    int i, j,qtMaes=0;
    for (i = 0; i < *totPessoas; i++)
    {
        if (busca(vMae, qtMaes, p[i].mae)) // verificando se a mae da pessoa na posicao ja nao foi contabilizada
        {
            strcpy(vMae[qtMaes].nome, p[i].mae);// se nao foi contabilizada, copia o nome da mae para o vetor de mae
            for (j = 0; j < *totPessoas; j++) // percorre o vetor de pessoas
            {
                if (strcmp(p[j].mae, p[i].mae) == 0) // verifica se a mae da pessoa na posicao i e igual a mae da pessoa na posicao j
                {
                    vMae[qtMaes].qtd++; // se for, incrementa a quantidade de filhos da mae
                }
            }
            qtMaes++;
        }
    }
    *totmaes=qtMaes;
}
//ponto de partida varre para ver se nao tem nome igual, verifica se tem.
int busca(Tmae *vMae, int n, char *nome)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        if (strcmp(vMae[i].nome, nome) == 0)
        {
            return 0;
        }
    }
    return 1;
}
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX 100
typedef struct
{
    char nome[30];
    char mae[30];
} Tpessoa;
typedef struct
{
    char nome[30];
    int qtd;
} Tmae;
void contabilizaMaes(Tpessoa *p, Tmae *vMae, int *totPessoas, int *totmaes);
void imprime(Tmae *vMae, int *totmaes);
int busca(Tmae *vMae, int n, char *nome);
void alimentaVetorPessoas(Tpessoa *p, int *totPessoas);
void main()
{
    int totalPessoas=0,totmaes;
    Tpessoa pessoas[MAX];
    Tmae vMae[MAX];
    alimentaVetorPessoas(pessoas, &totalPessoas);
    contabilizaMaes(pessoas, vMae, &totalPessoas, &totmaes);
    imprime(vMae, &totmaes);
}
void imprime(Tmae *vMae, int *totmaes)
{
    int i;
    for (i = 0; i < *totmaes; i++)
    {
        printf("\n  mae : %s \n filhos  %d f\n", vMae[i].nome, vMae[i].qtd);
        printf("*********************************************************\n");
    }
}
void alimentaVetorPessoas(Tpessoa *p, int *totPessoas)
{
    int i;
    //char controle; //&& controle!= 'n'
    for (i = 0; i < MAX ; i++)
    {
        fflush(stdin);
        printf("Nome: ");
        scanf("%s", p[i].nome);
        fflush(stdin);
        printf("Mae: ");
        scanf("%s", p[i].mae);
        (*totPessoas)++;
        //printf("Deseja continuar? (s/n): \n");
        //controle=getchar();
    }
}
void contabilizaMaes(Tpessoa *p, Tmae *vMae, int *totPessoas, int *totmaes)
{
    int i, j,qtMaes=0;
    for (i = 0; i < *totPessoas; i++)
    {
        if (busca(vMae, qtMaes, p[i].mae)) // verificando se a mae da pessoa na posicao ja nao foi contabilizada
        {
            strcpy(vMae[qtMaes].nome, p[i].mae);// se nao foi contabilizada, copia o nome da mae para o vetor de mae
            for (j = 0; j < *totPessoas; j++) // percorre o vetor de pessoas
            {
                if (strcmp(p[j].mae, p[i].mae) == 0) // verifica se a mae da pessoa na posicao i e igual a mae da pessoa na posicao j
                {
                    vMae[qtMaes].qtd++; // se for, incrementa a quantidade de filhos da mae
                }
            }
            qtMaes++;
        }
    }
    *totmaes=qtMaes;
}
int busca(Tmae *vMae, int n, char *nome)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        if (strcmp(vMae[i].nome, nome) == 0)
        {
            return 0;
        }
    }
    return 1;
}