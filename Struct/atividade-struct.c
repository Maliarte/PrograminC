/*
    Atividade no 4 de Fundamentos de Programação - Professor Leonardo Vianna

Um grupo de pessoas foi entrevistado e cada pessoa informou seu nome e o nome de sua mãe.

Estes dados foram armazenados em um vetor do qual cada posição consiste em um struct.

Desenvolver uma função que receba um vetor como o descrito acima e retorne outro contendo, 
para cada mãe, o número de filhos entrevistados (portanto, um outro vetor de
structs).

Nota: considerar que não existem duas ou mais
mães com o mesmo nome.


            1. O programa deve ser feito utilizando a linguagem C;
            2. As soluções apresentadas poderão utilizar apenas as estruturas estudadas em aula;
            3. A atividade deve ser feita individualmente;
            4. Caso seja observada cópia de soluções, todos os alunos envolvidos ficarão sem nota;
            5. O arquivo .c com a solução da atividade deve ser postado no Classroom até o dia 05/12/2021.



typedef struct {
	char pessoa[100], mae[100];
} TEntrevista;

typedef struct {
	char mamae[100];
	int filhos;
} TMae;

void main()
{
    int i, *indice, k;
	TEntrevista v[TAM];

    printf("A mae  tem  filhos\n");

    TMae outrov[k];
     printf("A mae  tem  filhos\n");
    *indice = outrov;
     printf("A mae  tem  filhos\n");
    strcpy (v[0].pessoa, "Andre"), strcpy (v[0].mae, "Adriana");
    strcpy (v[1].pessoa, "Ana"), strcpy (v[1].mae, "Adriana");
    strcpy (v[2].pessoa, "Marcelo"), strcpy (v[2].mae, "Adriana");
    strcpy (v[3].pessoa, "Tabata"), strcpy (v[3].mae, "Maria");
    strcpy (v[4].pessoa, "Carlos"), strcpy (v[4].mae, "Rosa");
    strcpy (v[5].pessoa, "Armando"), strcpy (v[5].mae, "Rosa");
    strcpy (v[6].pessoa, "Leticia"), strcpy (v[6].mae, "Adriana");
    strcpy (v[7].pessoa, "Lucia"), strcpy (v[7].mae, "Adriana");

     printf("A mae  tem  filhos\n");

    quantosFilhos (v, outrov, indice);
    *indice=k;
        for(i=0;i<k;i++) 
    {
        printf("A mae %s tem %d filhos\n", outrov[i].mamae, outrov[i].filhos);
    }
}

void quantosFilhos (TEntrevista vetor[], TMae *outroV[], int k)
{
    int i, j, quant=10, repete;
    k=0;

     printf("A mae  tem  filhos\n");

    for(i=0;i<TAM;i++)
    {
        repete=0;
        for(j=0;j<quant;j++)
        {
            if(strcmp(outroV[j]->mamae,vetor[i].mae)==0)
            {
                repete++;
            }
        }
        if(repete==0)
        {
            strcpy(outroV[k]->mamae, vetor[i].mae);
            outroV[k]->filhos=0;
            k++;
        }
    }
    quant = k;
    for(i=0;i<TAM;i++)
    {
        for(j=0;j<k;j++)
        {
            if(strcmp(outroV[j]->mamae,vetor[i].mae)==0)
            {
                outroV[j]->filhos++;
            }
        }
    }
}


*/

//declaracao de bibliotecas
#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct
{
    char nome_individuo[30];
    char nome_mae[30]
} Tquest;

typedef struct
{
    char nome[30];
    int quantidade_de_filhos;
} Tmae;

//prototipos das funcoes

void preencheVetor_Entrevistados(Tquest entrevistados[], Tmae maes[], int *tot_entrevistados, int *total_maes);
//tipo do parametro, pois na assinatura se passa o prototipo, (ERRO: &total_entrevistados)
void contabiliza_Maes(Tquest entrevistados[], Tmae maes[], int *total_entrevistados, int *total_maes);
int buscaNome_mae(maes, total_maes, quantidade_de_filhos);
void exibe_Maes(Tmae maes[], int total_maes);

void main()
{

    Tquest entrevistados[TAM];
    Tmae maes[TAM];

    int total_entrevistados = 0;

    int total_maes = 0; //variavel sendo incrementada  na funcao preencher vetor

    preencheVetor_Entrevistados(entrevistados, maes, &total_entrevistados, &total_maes);

    //contabiliza_Maes(entrevistados, maes, &total_entrevistados, &total_maes);

    exibe_Maes(maes, total_maes);
}

///////////

void preencheVetor_Entrevistados(Tquest entrevistados[], Tmae maes[], int *tot_entrevistados, int *total_maes)
{
    int i, retorno_busca;
    for (i = 0; i < TAM; i++)
    {
        printf("---Responda ao Questionario:---\n");
        fflush(stdin);
        printf("Informe seu nome:\n");
        gets(entrevistados[i].nome_individuo);

        fflush(stdin);
        printf("Informe o nome de sua mae:\n");
        gets(entrevistados[i].nome_mae);

        //verificar se o nome da mae informado, ja existe no vetor de maes.
        //invocar a funcao nao precisa de tipo nem indicar que é um vetor

        retorno_busca = buscaNome_mae(maes, total_maes, entrevistados[i].nome_mae);
        //se o nome for encontrado o nome da mae ja contem no vetor nao altera o valor dentro vetor, porem incrementa
        //a quantidade dos filhos

        //mae nao existe no vetor
        if (retorno_busca == -1)
        {
            /* vetor maes: |insere nome da mae no vetor mae na |    | | | |  - vetor vazio, logo total_maes == 0
                                                                pos 0
            */
             strcpy(maes[(*total_maes)].nome, entrevistados[i].nome_mae);

            //deve-se inicializar a quantidade de filhos para nao pegar lixo de memoria

            maes[(*total_maes)].quantidade_de_filhos=1; //inserindo o primeiro elemento no vetor maes no campo qtd filhos == inicializar o campo

            //a cada insercao de mae ira incrementar o total de maes - 'quant' do vetor de maes
            (*total_maes)++;   
        }
        else
        {
            //acertar em qual indice do vetor maes eu vou colocar o retorno da funcao busca
           maes[i].quantidade_de_filhos++;
        }
        
        (*tot_entrevistados)++;
        
    }
}
/*
void contabiliza_Maes(Tquest entrevistados[], Tmae maes[], int *total_entrevistados, int *total_maes)
{

    int i, j, quantidade_Maes = 0;

    for (i = 0; i < *total_entrevistados; i++)
    {
        //busca o nome da mae
        if (buscaNome_mae(maes, quantidade_Maes, entrevistados[i].nome_mae))

            strcpy(maes[quantidade_Maes].nome, entrevistados[i].nome_mae); // se nao foi contabilizada, copia o nome da mae para o vetor de mae
        for (j = 0; j < *total_entrevistados; j++)                         // percorre o vetor de pessoas
        {
            if (strcmp(entrevistados[j].nome_mae, entrevistados[i].nome_mae) == 0) // verifica se a mae da pessoa na posicao i e igual a mae da pessoa na posicao j
            {
                maes[quantidade_Maes].quantidade_de_filhos++; // se for, incrementa a quantidade de filhos da mae
            }
        }
        quantidade_Maes++;
    }
}
*/
int buscaNome_mae(Tmae maes[], int total_maes, char nome_mae[])
{

    int i;

    for (i = 0; i < total_maes; i++)
    {
        //verificando no vetor de maes se tem o 'nome_mae'
        if (strcmp(maes[i].nome, nome_mae) == 0)
        {
            return i; //verdadeiro -1, 0,123...
        }
        else
        {
            return -1; //falso
        }
    }
}
//ERRO: *total_maes, essa funçao so ira exibir, logo nao precisa de ponteiro
void exibe_Maes(Tmae maes[], int total_maes)
{

    int i;
    for (i = 0; i < total_maes; i++)
    {
        printf("Mae: %s\npossui %d filhos\n", maes[i].nome, maes[i].quantidade_de_filhos);
        
    }
    printf("Finalizado.\n");
}
