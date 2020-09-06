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
    vol = calcAreaRetan(largura,comprimento)* altura;
    return vol;
}

float calcAreaCirculo (float raio)
{
    float area;
    area = 2 * PI * pow(raio,2);
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

    semiperim = calcPerimTriang(ladoUm, ladoDois, ladoTres)/ 2;
    area = semiperim*(semiperim - ladoUm)*(semiperim - ladoDois)*(semiperim - ladoTres);
    return area;
}

float areaTotal (float a, float b, float c, float d, float e)
{
    float area, areaRetanAB, areaRetanHipotenusaE, areaRetanCD, areaTriang, hipotenusa;

    hipotenusa = calcHipotenusa (a, d);
    areaRetanAB = calcAreaRetan(a, b);
    areaRetanCD = calcAreaRetan(c, d);
    areaRetanHipotenusaE = calcAreaRetan (hipotenusa, e);
    areaTriang = calcAreaTriang(a, d,hipotenusa);

    area = areaRetanAB + areaRetanCD + areaRetanHipotenusaE+ areaTriang;

    return area;
}

int main (void)
{
    setlocale(LC_ALL, "Portuguese");

    printf("%f", areaTotal(1, 1, 1, 1, 1));

    return 0;
}