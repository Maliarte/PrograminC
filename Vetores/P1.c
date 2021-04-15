/*
Três copos de água de 200ml em temperaturas diferentes foram misturados em um recipiente isolado e, após certo tempo, alcançaram o equilíbrio térmico (média aritmética das 3 temperaturas).
Faça uma função que recebe como parâmetros o equilíbrio térmico e a temperatura de um dos copos de água e retorna a diferença entre o equilíbrio térmico e a temperatura do copo. Seu protótipo é:
float calcula_diferenca(float equil, float temp);

Faça uma função que recebe como parâmetros um valor inteiro representando o número do copo e um valor real representando a diferença entre o equilíbrio térmico e a temperatura do copo e mostra na tela uma das 3 mensagens abaixo. Seu protótipo é:
void exibe_mensagem(int copo, float difer);

Mensagens possíveis:
“A água do copo Nº DO COPO perdeu X graus” 🡪 caso tenha cedido calor aos demais
“A água do copo Nº DO COPO ganhou X graus” 🡪 caso tenha recebido calor dos demais
“A água do copo Nº DO COPO manteve sua temperatura” 🡪 caso a temperatura do copo lida seja igual ao equilíbrio térmico.
Observação: se a diferença entre o equilíbrio térmico e a temperatura do copo for positiva, a água deste copo recebeu calor; se for negativa, a água deste copo cedeu calor; se for nula, a água deste copo não recebeu nem cedeu calor.

Faça um programa que leia a temperatura da água de cada copo, calcule o equilíbrio térmico (média aritmética das 3 temperaturas) e exiba, para cada copo, uma das 3 mensagens acima.

*/

#include <stdio.h>
#include <locale.h>
#define COPOS 3;

void moldura()
{
    printf("\n================================================\n");
    return;
}

float calcula_diferenca(float equil, float temp)
{
    float diferenca = equil - temp;
    return diferenca;
}
void exibe_mensagem(int copo, float difer)
{
    if (difer == 0)
    {
        printf("A agua do copo %i manteve sua temperatura", copo);
    }
    else
    {
        if (difer < 0) 
        {
            printf("A agua do copo %i perdeu %.1f graus", copo, difer * (-1));
        }
        else
        {
            printf("A agua do copo %i ganhou %.1f graus", copo, difer);
        }
    }
}

float calcula_equilibrio(float totalTemps)
{

    float equil = totalTemps / COPOS;

    return equil;
}
int main(void)
{
    int counterCopos = 0;
    float tempCopo1, tempCopo2, tempCopo3, totalTemps, equil;

    printf("Digite a temperatura do copo 1: ");
    scanf("%f", &tempCopo1);
    printf("Digite a temperatura do copo 2: ");
    scanf("%f", &tempCopo2);
    printf("Digite a temperatura do copo 3: ");
    scanf("%f", &tempCopo3);
    totalTemps = tempCopo1 + tempCopo2 + tempCopo3;

    equil = calcula_equilibrio(totalTemps);
    

    moldura(); 
    exibe_mensagem(1, calcula_diferenca(equil, tempCopo1));
    moldura();
    exibe_mensagem(2, calcula_diferenca(equil, tempCopo2));
    moldura();
    exibe_mensagem(3, calcula_diferenca(equil, tempCopo3));
    moldura();

    return 0;
} 
