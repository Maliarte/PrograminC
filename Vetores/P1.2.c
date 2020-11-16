/* 
O SEDEX, serviço de entrega do correio, para equilibrar a relação peso x espaço ocupado, calcula o preço a pagar por uma encomenda levando em conta o peso físico (em kg) e o peso cúbico. O peso cúbico é calculado do seguinte modo:
	(Comprimento x Largura x Altura)/6.000

O peso utilizado para calcular o preço a pagar é escolhido da seguinte forma:

Peso Cúbico da Encomenda | Peso Escolhido
Inferior a 5 kg          | Peso Físico
A partir de 5 Kg         | Maior valor entre peso físico e peso cúbico


Independente do peso escolhido, sempre que o peso cúbico ultrapassar 30 kg, é cobrado um valor adicional de 10% do preço básico por peso cúbico excedido.
Exemplos:

1o) preço: 20,00		peso físico: 80 kg 	Dimensões:1860x10x10 --> peso cúbico: 31
     		preço a pagar: 80 * 20,00 +  2 *( 31-30) = 1602,00
2o) preço: 20,00 	peso físico: 80 kg 	Dimensões:1200x10x10 --> peso cúbico: 20
     		preço a pagar: 80 * 20,00 = 1600,00
3o) preço: 20,00 	peso físico: 10 kg 	Dimensões:1200x10x10 --> peso cúbico: 20
     		preço a pagar: 20 * 20,00 = 400,00
4o) preço: 20,00 	peso físico: 10 kg 	Dimensões:1860x10x10 --> peso cúbico: 31
     		preço a pagar: 31 * 20,00 +  2 *( 31-30) = 622,00
5o) preço: 20,00 	peso físico: 1 kg 	Dimensões:240x10x10 --> peso cúbico: 4
     		preço a pagar: 1 * 20,00 = 20,00

a. Faça a função peso_cubico que recebe como parâmetros as três dimensões da encomenda (comprimento, largura e altura) e retorna o seu peso cúbico. Seu protótipo é:
	float peso_cubico(float C, float L, float A);

b. Faça a função preco_encomenda que recebe como parâmetros as três dimensões da encomenda (comprimento, largura e altura), o peso físico e o preço básico e retorna o preço da encomenda. Esta função deverá utilizar, obrigatoriamente, a função do item anterior (item a). Seu protótipo é:
	float preco_encomenda(float C, float L, float A, float pesoFisico, float precobasico);

c. Faça um programa, utilizando adequadamente as funções acima (feitas nos itens a e b) que leia inicialmente o preço básico do kg cobrado pelo SEDEX. A seguir, leia o peso físico e as dimensões do pacote (comprimento, largura e altura) a ser transportado mostrando o preço a pagar.


*/
#include <stdio.h>
#include <locale.h>

void moldura()
{
    printf("\n================================================\n");
    return;
}

float peso_cubico(float comp, float larg, float alt)
{
    float peso = (comp * larg * alt) / 6000;
    return peso;

}

float preco_encomenda(float comp, float larg, float alt, float pesoFisico, float precobasico)
{

    float pesoCubico = peso_cubico(comp, larg, alt);
    float preco, taxa, peso = pesoFisico;

    if (pesoFisico > 5 && pesoCubico > pesoFisico)
    {
        peso = pesoCubico;
    }

    if (pesoCubico > 30)
    {
        taxa = precobasico * 0.1 * (pesoCubico - 30);
        printf("Taxa: R$ %.2f", taxa);
    }
    else
    {
        taxa = 0;
    }

    preco = peso * precobasico + taxa;
    return preco;
}

int main(void)
{
    float precoBasico, pesoFisico, comp, larg, alt;

    printf("Digite o preço base do SEDEX: ");
    scanf("%f", &precoBasico);
    printf("Digite o peso físico da encomenda: ");
    scanf("%f", &pesoFisico);
    printf("Digite as dimensões da encomenda (comprimento, largura e altura): ");
    scanf("%f %f %f", &comp, &larg, &alt);
    moldura();
    printf("Preço à pagar: R$ %.2f", preco_encomenda(comp, larg, alt, pesoFisico, precoBasico));
    moldura();
    return 0;
}
