/*     
        FPR - Fundamentos de Programação
        Atividade4 de Fundamentos de Programação 
        Professor Leonardo Vianna
	    Aluna: Marília Silva 

                                            - Struct

    Um grupo de pessoas foi entrevistado e cada pessoa informou seu nome e o nome de sua mãe.
    Estes dados foram armazenados em um vetor do qual cada posição consiste em um struct.
    Desenvolver uma função que receba um vetor como o descrito acima e retorne outro contendo, 
    para cada mãe, o número de filhos entrevistados (portanto, um outro vetor de structs).

        Nota: considerar que não existem duas ou mais
        mães com o mesmo nome.

            1. O programa deve ser feito utilizando a linguagem C;
            2. As soluções apresentadas poderão utilizar apenas as estruturas estudadas em aula;
            3. A atividade deve ser feita individualmente;
            4. Caso seja observada cópia de soluções, todos os alunos envolvidos ficarão sem nota;
            5. O arquivo .c com a solução da atividade deve ser postado no Classroom até o dia 05/12/2021.
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
int buscaNome_mae(Tmae maes[], int total_maes, char nome_mae[]);
void exibe_Maes(Tmae maes[], int total_maes);

void main()
{

    Tquest entrevistados[TAM];
    Tmae maes[TAM];

    int total_entrevistados = 0;

    int total_maes = 0; //variavel sendo incrementada  na funcao preencher vetor

    preencheVetor_Entrevistados(entrevistados, maes, &total_entrevistados, &total_maes);

    exibe_Maes(maes, total_maes);
}


void preencheVetor_Entrevistados(Tquest entrevistados[], Tmae maes[], int *tot_entrevistados, int *total_maes)
{
    int i, retorno_busca;
    
    for (i = 0; i < TAM; i++)
    {
        printf("\n---Responda ao Questionario:---\n");
        
        fflush(stdin);
        printf("Informe seu nome:\n");
        gets(entrevistados[i].nome_individuo);

        fflush(stdin);
        printf("Informe o nome de sua mae:\n");
        gets(entrevistados[i].nome_mae);
                                                                                        /*invocar a funcao 
                                                                                        nao precisa de tipo 
                                                                                        nem indicar que é um 
                                                                                        vetor*/
        //verificar se o nome da mae informado, ja existe no vetor de maes.
        //retornar -1 -> nao tem maes
        //se retornar qualquer coisa, encontrou mae e retorna 
        retorno_busca = buscaNome_mae(maes, *total_maes, entrevistados[i].nome_mae);

        //se o nome for encontrado, o nome da mae ja contem no vetor 
        //nao altera o valor dentro vetor, porem incrementa a quantidade dos filhos

        //mae nao existe no vetor
        if (retorno_busca == -1)
        {
            /* vetor maes: |insere nome da mae no vetor mae na |    | | | |  - vetor vazio, logo total_maes == 0
                                                                pos 0
            */
             strcpy(maes[(*total_maes)].nome, entrevistados[i].nome_mae);

            //deve-se inicializar a quantidade de filhos para nao pegar lixo de memoria
            maes[(*total_maes)].quantidade_de_filhos = 1; 
            //inserindo o primeiro elemento no vetor maes no campo qtd filhos == inicializar o campo

            //a cada insercao de mae ira incrementar o total de maes - 'quant' do vetor de maes
            (*total_maes)++;   
            
        }
        else
        {
            //acertar em qual indice do vetor maes eu vou colocar o retorno da funcao busca linha 129
            //o retorno busca tem a posicao da mae, incrementa nessa mae a quantidade de filhos
           maes[retorno_busca].quantidade_de_filhos++;
        }
        
        (*tot_entrevistados)++;
        
    }
}

int buscaNome_mae(Tmae maes[], int total_maes, char nome_mae[])
{

    int i;

    for (i = 0; i < total_maes; i++)
    {
        //verificando no vetor de maes se tem o 'nome_mae'
        if (strcmp(maes[i].nome, nome_mae) == 0)
        {
            //encontrou nome da mae essa e a posicao no vetor que a mae foi encontrada.
            return i; //verdadeiro -1, 0,123...
        }
        
    } //saindo do laço é sinal que percorrer logo o 'else' esta implicito

     return -1; //falso nao encontrou nome da mae: nao pode usar 0 pq e uma posicao valida no vetor
}
//ERRO: *total_maes, essa funçao so ira exibir, logo nao precisa de ponteiro
void exibe_Maes(Tmae maes[], int total_maes)
{

    int i;
    for (i = 0; i < total_maes; i++)
    {
        printf("\n\n======================");
        printf("\nMae: %s\npossui %d filhos\n", maes[i].nome, maes[i].quantidade_de_filhos);
        
    }
    printf("======================");
    printf("\nPrograma Finalizado.\n");
    printf("======================");
}
