/* Duas amigas estabeleceram o código abaixo para que suas mensagens não fossem lidas pelas demais pessoas. ( cada letra equivale a um número  entre 1 e 26 e o espaço ao 0)
0 - ' '
1 - a
2 - b
3 - c
.
.
.
x - 24
y - 25
z - 26

Faça a função "traduzir", que recebe um vetor  com uma mensagem ( Secreta) e "traduz" a  sequência  armazenada  em lSecreta  de acordo com o código das amigas.  
Teste para lSecreta = [2,15,13,0,4,9,1];
DICA: crie um vetor de caracteres com as letras na ordem do código

*/
#define TAM 26


void traduzir(*vSecret) {
    
int vTraduz[TAM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};


    return;
}

int main (void) {
int secret;

char vCaracteres[TAM] = {'', 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q','r','s','t', 'u', 'v','w', 'x', 'y', 'z'};

printf ("entre com 6 digitos: ")
scanf("%d", &secret);

traduzir(vSecret[TAM])



    return 0;
}