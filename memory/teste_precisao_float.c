#include <stdio.h>

void main()
{
    float i = 0.1;
    float j = 0.2;
    float k;

    k = i + j;
    printf("%f", k);

    char palavra[100];
    printf("%x\n", &palavra[0]);                 // endereço Oxffffdc10
    printf("%x\n", &palavra[100]);               // endereçoOxffffdc74
    printf("%d\n", &palavra[100] - &palavra[0]); // 101 '\0'  elementos contínuos
}