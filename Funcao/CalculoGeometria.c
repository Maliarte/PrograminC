#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PI 3.14159

float elevarQuadrado (float num)
{
    float resultado;

    resultado = num * num;

    return resultado;
}

float calcAreaRetan (float base, float altura)
{
    float area;

    area = base * altura;

    return area;
}

float calcPerimRetan (float base, float altura)
{
    float perim;

    perim = (2 * base) + (2 * altura);

    return perim;
}

float calcVolumeParalelep (float comprimento, float largura, float altura)
{
    float vol;

    vol = comprimento * largura * altura;

    return vol;
}

float calcAreaCirculo (float raio)
{
    float area;

    area = 2 * PI * elevarQuadrado(raio);

    return area;

}

float calcPerimCirculo (float raio)
{
    float perim;

    perim = 2 * PI * raio;

    return perim;
}

float calcVolumeCilindro (float raio, float altura)
{
    float vol;

    vol = PI * altura * elevarQuadrado(raio);

    return vol;
}

float calcHipotenusa (float primCateto, float segCateto)
{
    float hipotenusa;

    hipotenusa =  sqrt(elevarQuadrado(primCateto) + elevarQuadrado(segCateto));

    return hipotenusa;
}

float calcDistanciaRetas (float xUm, float xDois, float yUm, float yDois)
{
    float distancia;

    distancia = sqrt(elevarQuadrado(xDois - xUm) + elevarQuadrado(yDois - yUm));

    return distancia;
}

float calcPerimTriang(float ladoUm, float ladoDois, float ladoTres)
{
    float perim;

    perim = ladoUm + ladoDois + ladoTres;

    return perim;
}

float calcAreaTriang(float ladoUm, float ladoDois, float ladoTres)
{
    float area, semiperim;

    semiperim = (calcPerimTriang(ladoUm, ladoDois, ladoTres)) / 2;

    area = semiperim*(semiperim - ladoUm)*(semiperim - ladoDois)*(semiperim - ladoTres);
    
    return area;
}

int main (void)
{   
    float volCaixa, diamFuro, comprimentoCaixa, larguraCaixa, alturaCaixa;

    setlocale(LC_ALL, "Portuguese");

    printf("Insira o diâmetro do furo cilíndrico: ");
    scanf("%f", &diamFuro);
    printf("Insira o comprimento da caixa: ");
    scanf("%f", &comprimentoCaixa);
    printf("Insira a largura da caixa: ");
    scanf("%f", &larguraCaixa);
    printf("Insira a altura da caixa: ");
    scanf("%f", &alturaCaixa);

    volCaixa = calcVolumeParalelep(comprimentoCaixa, larguraCaixa, alturaCaixa) - calcVolumeCilindro((diamFuro / 2), alturaCaixa);

    printf("O volume da peça é: %f", volCaixa);

    return 0;
}