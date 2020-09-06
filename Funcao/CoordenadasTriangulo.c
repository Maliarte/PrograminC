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

float calcDistanciaRetas (float xUm, float yUm, float xDois,float yDois)
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

int main (void)
{
    float aX, aY, bX, bY, cX, cY, dX, dY, eX, eY, fX, fY, gX, gY, areaTotal, areaADFG, areaABCD, areaABE, areaBCE, areaCDE, areaAEF, areaEFG, areaDEG;
    float dAB
    setlocale(LC_ALL, "Portuguese");

    printf("Insira as coordenadas do ponto A (formato : x y): ");
    scanf("%f %f", &aX, &aY);

    printf("Insira as coordenadas do ponto B (formato : x y): ");
    scanf("%f %f", &bX ,&bY);

    printf("Insira as coordenadas do ponto C (formato : x y): ");
    scanf("%f %f", &cX, &cY);

    printf("Insira as coordenadas do ponto D (formato : x y): ");
    scanf("%f %f", &dX, &dY);

    printf("Insira as coordenadas do ponto E (formato : x y): ");
    scanf("%f %f", &eX, &eY);

    printf("Insira as coordenadas do ponto F (formato : x y): ");
    scanf("%f %f", &fX, &fY);

    printf("Insira as coordenadas do ponto G (formato : x y): ");
    scanf("%f %f", &gX, &gY);

    dAB= calcDistanciaRetas (aX, aY, bX,bY);
    dAE= calcDistanciaRetas (aX, aY, eX,eY);
    dEB = calcDistanciaRetas (bX, bY, eX,eY);
    dBC = calcDistanciaRetas (bX, bY, cX,cY);
    dEF = calcDistanciaRetas (eX, eY, fX,fY);
    dAF= calcDistanciaRetas (aX, aY, fX,fY);
    dGF = calcDistanciaRetas (gX, gY, fX,fY);
    dGE = calcDistanciaRetas (gX, gY, eX,eY);
    dAD= calcDistanciaRetas (aX, aY, dX,dY);
    areaPrisma1= 4* calcAreaTriang(dAB,dAE,dEB) + calcAreaRetan(dAB,dBC);
    areaPrisma2 = 2* calcAreaTriang(dAF,dAE,dEF) + calcAreaRetan(dAD,dGF) + calcAreaTriang(dGF,dEF,dGE);
    
    areaTotal = areaPrisma1+areaPrisma2;
    printf("A área total da superfície da figura é: %f", areaTotal);

    return 0;