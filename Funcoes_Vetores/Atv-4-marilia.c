/*
Considere uma string s contendo apenas letras
e algarismos. Desenvolver uma função
recursiva que verifique se as letras de s estão
em seu início (e, consequentemente, os
algarismos ao seu final). Se estiverem, a função
retornará 1; caso contrário, 0.
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int verificaLetras(s);

void main(){

    char s[10];
    strcpy(s, "cacau123");

    printf("%d", verificaLetras(s);
}

//verificando dse si eh uma letra


int verificaLetras(s){

    for(i=0; i<strlen(s); i++){
        if ((s[i]>='a')&&(s[i]<='z' == 0){
            return verificaLetras(s[i+1]);
        }
    }
    
}