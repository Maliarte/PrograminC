//PARÂMETROS: passagem por valor e por referência


#include <stdio.h>
soma_mais_um(int *n) { //recebe endereço de x (posicao k' mem)
*n += 1;
printf("Dentro da função: x=%d\n", *n);

}
soma( int n, int b) {
int i = n + b;
return i;
}
int main {
int x = 9, y=9;
//por valor: não modifica valores fora da função. é feito uma copia
soma(x, y);
///////////////////////////////////////////////////////////////////

//por referência:modifica valores pelo endereço alterando o mesmo em todo codigo. 
void soma_mais_um(&x, &y);
printf("Depois da função x = %d\n",x);
    return 0;
}