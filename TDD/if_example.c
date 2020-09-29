#include <stdio.h>

int main(void) {
int x =2;
if (42)
{
    puts("42 is not equal to zero and this is considered truth");

}
if  (x>3) {
    puts("X is greater than 3");
}

else {
    puts ("x is less than 3");
   
} /* As chaves sao opcionais. Sem as chaves, somente uma instrucao sera considerada como parte de cada ramo, como mostra  o codigo comentado abaixo*/
    return 0;
}