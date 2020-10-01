
#include <stdio.h>
#include <math.h>

void exibeDados(float perim);
    void moldura(void);
    printf(" \n perimetro: %.2f", perim);
    void moldura(void);

float detDist (float xa, float ya, float xb, float yb){
    float dist;
    dist = sqrt(pow(xa-xb)2.0) + pow(ya-yb) 2.0)
    return dist;
}
void moldura(void){
    printf("============================");
    printf("============================");
    return;
}
float calcPerim(float xa, float ya, float xb, float yb, float xc, float  yc){
    float perim, dAB, dAC, dBC;
    dAB = detDist(xa,ya,xb,yb);
    dAC = detDist(xa,ya,xc,yc);
    dBC = detDist(xc,yc,xb,yb);
    perim = dAB+dAC+dBC;
    return perim;

}

int main (void) {
float xa, ya, xb, yb, xc, yc, perim;

    printf("Entre com as coordenadas de A:(x, y) ");
    scanf("%f %f", &xa, &ya);
    printf("Entre com as coordenadas de B:(x, y) ");
    scanf("%f %f", &xb, &yb);
    printf("Entre com as coordenadas de C:(x, y) ");
    scanf("%f %f", &xc, &yc);

    perim=calcPerim(xa,ya,xb,yb,xc,yc);
    exibeDados(perim);

    return 0;
}

