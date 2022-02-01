
#include <stdlib.h>
#include <stdio.h>


void main(){

long numeros[] = {0xFFFFFFFF, 0x00000000, 0x11111111, 0xAAAAAAAA};
long n = numeros[3];

printf("%x\n", n); // aaaaaaaa
}
