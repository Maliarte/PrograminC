#include <stdio.h>
/*sem parametro e sem retorno, sua tarefa consiste em exibir resultado na tela
void soma(void){
int n1, n2, s;

printf("informe a primeira e a segunda parcela da soma: ");
scanf("%d %d", &n1, &n2);
s = n1 + n2;
printf("%d + %d = %d", n1, n2, s);
return;

} 

int main(void) {

    soma(); //nao recebe valor pois captura valores
    return 0;
}
// sem parametro e com retorno
int soma(void){
    int n1, n2, s;
    printf("\nentre com a parcela 1 \n seguida da parcela 2: " );
    scanf("%d %d", &n1, &n2);
    s = n1+n2;
    return s;
}


int main() {
    int s;
    s = soma();
    printf("A soma eh: %d", s);
    return 0;

   
}


//com parametro e com retorno
void moldura(void){
    printf("\n\n***********\nRESULTADO\n***********\n\n");
}
int soma(int n1, int n2) {
    int s;
    s = n1 + n2;
    return s;
}

int main (void) {
    int n1,n2,s;
    printf("informe a primeira e a segunda parcela da soma: ");
    scanf("%d %d", &n1, &n2);
    s = soma(n1,n2);
    moldura();
    printf("%d + %d = %d\n",n1, n2, s);
    return 0;
    
}*/
void soma(int n1, int n2) {
    int s;
    s = n1 +n2;
    printf("%d + %d = %d\n",n1, n2, s);
    return;
}
// sem parametro e com retorno
int main (void) {
    int n1, n2, s;
    printf("informe a primeira e a segunda parcela da soma: ");
    scanf("%d %d", &n1, &n2);
    soma(n1,n2);
   
    return 0;
}

