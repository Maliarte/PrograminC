/* 

Determinada zona eleitoral possui N eleitores  inscritos que poderão votar, uma única vez, em 
um dos C candidatos para o único cargo a ser  definido. 
Pede-se:

a. A declaração de todo(s) o(s) tipo(s) de dados necessário(s) para o armazenamento 
dos números dos candidatos, assim como a  quantidade de votos brancos, nulos e votos 
para cada candidato;

b. Uma função que leia o voto de cada eleitor, considerando que o processo terminará 
quando os N eleitores votarem ou quando o  número -1 for digitado como voto;

c. Uma função que exiba:

        i. O total de votos para cada candidato,  assim com a quantidade de votos  brancos (código 0) e de nulos (código 
        sem candidato associado);
        ii. A quantidade de abstenções (eleitores  que não votaram);
        iii. O número do candidato vencedor (caso tenha mais de 50% dos votos válidos) ou  dos que irão para o segundo turno (os 
        dois mais votados). 

Notas: 

a) o número do candidato deve conter dois 
algarismos apenas;

b) podem considerar que não haverá mais de 
um candidato com a mesma quantidade de 
votos

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 8 // numero de eleitores
#define C 3 // numero de candidatos

typedef struct
{
    char nome[20];
    int votos;  // votos validos
    int codigo; // numero do candidato
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
    Tcandidato candidatos[3];
    Tvotos votos = zerarVotos();

    // Primeiro candidato
    strcpy(candidatos[0].nome, "Fulano");
    candidatos[0].codigo = 90;

    // Segundo candidato
    strcpy(candidatos[1].nome, "Beltrano");
    candidatos[1].codigo = 80;

    // Terceiro candidato
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
    while (i < N && codigo != -1)
    {
        codigo = capturaValida2Dig();
        if (codigo == -1)
        {
            break;
        }
        else if (codigo == 0)
        {
            votos->votos_brancos++;
        }
        else
        {
            pos = buscarVotos(candidatos, C, codigo);
            if (pos >= 0)
            {
                candidatos[pos].votos++;
                votos->votos_validos++;
            }
            else
            {
                votos->votos_nulos++;
            }
        }
        i++;
    }
}

int buscarVotos(Tcandidato *vetor, int quantidade, int codigo)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (vetor[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

void ordenaDecrescente(Tcandidato *candidatos, int tam)
{
    int i, j;
    Tcandidato aux;
    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (candidatos[i].votos < candidatos[j].votos)
            {
                aux = candidatos[i];
                candidatos[i] = candidatos[j];
                candidatos[j] = aux;
            }
        }
    }
}

void exibir(Tcandidato *candidatos, int tam, Tvotos votos)
{
    exibeCandidatos(candidatos, tam);
    exibeVotos(votos);
    exibeVencedor(candidatos, tam, votos);
}

void exibeCandidatos(Tcandidato *vetor, int quantidade)
{
    printf("\nCandidatos: \n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("%s - %d votos\n", vetor[i].nome, vetor[i].votos);
    }
}

void exibeVotos(Tvotos votos)
{
    printf("\nVotos: \n");
    printf("Votos brancos: %d\n", votos.votos_brancos);
    printf("Votos nulos: %d\n", votos.votos_nulos);
    printf("Votos validos: %d\n", votos.votos_validos);
    votos.abstencao = N - (votos.votos_validos + votos.votos_brancos + votos.votos_nulos);
    printf("Abstencao %d ", votos.abstencao);
}

void exibeVencedor(Tcandidato *vetor, int quantidade, Tvotos votos)
{
    int i, maior = 0;
    // for (i = 0; i < quantidade; i++)
    // {
    //     if (vetor[i].votos > maior)
    //     {
    //         maior = vetor[i].votos;
    //     }
    // }

    float intVencedor = (vetor[0].votos * 100) / votos.votos_validos;

    if (intVencedor > 50)
    {
        printf("\nVencedor: %s\n", vetor[0].nome);
        printf("%s - %d votos\n", vetor[0].nome, vetor[0].votos);
    }
    else
    {
        printf("\nSEGUNDO TURNO: \n");
        printf("%s - %d votos\n", vetor[0].nome, vetor[0].votos);
        printf("%s - %d votos\n", vetor[1].nome, vetor[1].votos);
    }
    // for (i = 0; i < quantidade; i++)
    // {
    //     if (vetor[i].votos == maior)
    //     {
    //         printf("%s - %d votos\n", vetor[i].nome, vetor[i].votos);
    //     }
    // }
}