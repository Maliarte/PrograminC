#include <stdio.h>

#define SIZE 27
#define PALAVRA 100

void leCodigo(int array[], int referencia);

int main(void){
    int vCod[PALAVRA] = {-1};
    int secreto;
    int i = 0;

    printf("Informe o primeiro código secreto ou -1 para sair: ");
    scanf("%i", &secreto);

    while(secreto >= 0){
        vCod[i] = secreto;
        printf("Informe o próximo código secreto ou -1 para sair: ");
        scanf("%i", &secreto);
        i++;
    }
    leCodigo(vCod, i);
    return 0;
}

void leCodigo(int array[], int referencia){
    char vString[SIZE] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i = 0;
    for(; i <= referencia ; i++){
        printf("%c", vString[array[i]]);
    }
}