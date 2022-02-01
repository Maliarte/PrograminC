#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 8 //numero de eleitores
#define C 3 //numero de candidatos

typedef struct
{
    char nome[20];
    int votos;  //votos validos
    int codigo; //numero do candidato
} Tcandidato;

typedef struct
{
    int votos_brancos;
    int votos_nulos;
    int abstencao; // Votos Brancos + Votos Nulos
    int votos_validos;
} Tvotos;

int capturaValida2Dig();
void zerarVotosCandidatos(Tcandidato *zerando, int tam);
Tvotos zerarVotos();
void lerVotos(Tcandidato *candidatos, Tvotos *votos);
void ordenaDecrescente(Tcandidato *candidatos, int tam);
void exibir(Tcandidato *candidatos, int tam, Tvotos votos);
void exibeCandidatos(Tcandidato *vetor, int quantidade);
void exibeVotos(Tvotos vetor);
void exibeVencedor(Tcandidato *vetor, int quantidade, Tvotos votos);
int buscarVotos(Tcandidato *vetor, int quantidade, int codigo);

void main()
{
    Tcandidato candidatos[C];
    Tvotos votos = zerarVotos();

    int quantidade = 0;

    //Primeiro candidato
    strcpy(candidatos[0].nome, "Fulano");
    candidatos[0].codigo = 90;

    //Segundo candidato
    strcpy(candidatos[1].nome, "Beltrano");
    candidatos[1].codigo = 80;

    //Terceiro candidato
    strcpy(candidatos[2].nome, "Siclano");
    candidatos[2].codigo = 70;

    zerarVotosCandidatos(candidatos, C);
    lerVotos(candidatos, &votos);
    ordenaDecrescente(candidatos, C);
    exibir(candidatos, C, votos);
}

void zerarVotosCandidatos(Tcandidato *zerando, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        zerando[i].votos = 0;
    }
}

Tvotos zerarVotos()
{
    Tvotos votosZerados;
    votosZerados.votos_brancos = 0;
    votosZerados.votos_nulos = 0;
    votosZerados.abstencao = 0;
    votosZerados.votos_validos = 0;
    return votosZerados;
}

int capturaValida2Dig()
{
    int codigo;
    printf("Digite o codigo do candidato: ");
    scanf("%d", &codigo);
    while (codigo < -1 || codigo > 99)
    {
        printf("Codigo invalido!\n");
        printf("Digite o codigo do candidato: ");
        scanf("%d", &codigo);
    }
    return codigo;
}

// b. Uma função que leia o voto de cada eleitor,
// considerando que o processo terminará
// quando os N eleitores votarem ou quando o
// número -1 for digitado como voto;

void lerVotos(Tcandidato *candidatos, Tvotos *votos)
{
    int codigo, pos;
    int i = 0;