/*
Considere um vetor que armazene alguns
dados coletados de um grupo de pessoas em
uma pesquisa, a saber: nome, gênero, idade e
altura.
Desenvolver uma função que receba os
parâmetros gênero, faixa de idade (idade inicial
e idade final) e faixa de altura (altura inferior e
altura superior) e retorne a quantidade de
pessoas que atendem aos filtros por ele
representados.
Nota: caso o gênero especificado seja igual a
M, serão considerados os homens que
estiverem nas faixas de idade e altura
especificadas; o mesmo ocorrerá com as
mulheres, quando o gênero for F. Porém, se o
gênero contiver qualquer valor diferente de M
ou F, todas as pessoas que atenderem aos
filtros de idade e altura serão contabilizadas.

*/

typedef struct
{
    char nome[50];
    char genero;
    int idade;
    float altura;
} Pessoa;   // tipo Pessoa

int filtro(char genero, int idadeInicial, int idadeFinal, float AlturaInferior, float AlturaSuperior);

void main(){        

    filtro('M', 20, 30, 1.60, 1.80);

}


int filtro(char genero, int idadeInicial, int idadeFinal, float AlturaInferior, float AlturaSuperior){

    int i, cont=0;
    Pessoa p[5];

    for(i=0; i<5; i++){
        printf("Digite o nome: ");
        scanf("%s", p[i].nome);
        printf("Digite o genero: ");
        scanf(" %c", &p[i].genero);
        printf("Digite a idade: ");
        scanf("%d", &p[i].idade);
        printf("Digite a altura: ");
        scanf("%f", &p[i].altura);
    }

    for(i=0; i<5; i++){
        if(p[i].genero == genero && p[i].idade >= idadeInicial && p[i].idade <= idadeFinal && p[i].altura >= AlturaInferior && p[i].altura <= AlturaSuperior){
            cont++;
        }
    }

    printf("Quantidade de pessoas: %d", cont);

}