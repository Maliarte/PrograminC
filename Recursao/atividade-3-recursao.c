/* 

        FPR - Fundamentos de Programação Atividade III - Marília Silva 

Implementar uma função recursiva que, dados uma string 's' e dois caracteres 'c1' e 'c2' 
altere todas as ocorrências de c1 para c2, e retorne a quantidade de alterações realizadas.
Exemplo 1:
            s: “ALGORITMOS”
            c1: ‘O’
            c2: ‘X’
            
Após a execução da função, a string s será “ALGXRITMXS” e o valor 2 será retornado
(pois 2 ocorrências de ‘O’ foram alteradas por  ‘X’).

Exemplo 2:
            s: “CASA”
            c1: ‘E’
            c2: ‘O’

Após a execução da função, a string s permanecerá inalterada e o valor 0 será
retornado (pois não existe o caracter ‘E’ na string). 
----------------Comentarios--------------------------
10/10

- A 'main' ficou responsável por zerar a variável 'i';


*/

#include <stdio.h>
#include <string.h>

//prototipo funcao
//i == posição substituindo o for na versao iterativa
int trocaCaracteres(char string[], char caractere1, char caractere2, int i); 
void main()
{
    char string[30];
    char c1;
    char c2;
    
    printf("Entre com a Palavra que deseja alterar: ");
    gets(string);
    printf("Entre com o 1 caractere: ");
    fflush(stdin);
    scanf("%c", &c1);
    printf("Entre como 2 caractere: ");
    fflush(stdin);
    scanf("%c", &c2);

    //exibindo string antes
    printf("%s \n", string);

    //exibindo string antes
    printf("%s \n", string);

    //string depois - primeira chamada recursiva o 'i' recebe 0
    printf("%d ocorrencias ", trocaCaracteres (string, c1, c2, 0));

}


int trocaCaracteres(char string[], char caractere1, char caractere2, int i) 
{

    //percorrendo string
    //iterativa for(i=0, i != '0'; i++) 

    if(string[i] != '\0') //caso geral
    {
        
                if(string[i] ==  caractere1 ) //caso geral encontro o caracterer
                {
                        string[i] = caractere2;
                        //econtrei o elemento
                        return 1 + trocaCaracteres(string, caractere1, caractere2, i+1); 
                } else {
                    return trocaCaracteres(string, caractere1, caractere2, i+1);
                }     
	  //cont = 0
    
    } else  {   
                return 0;
            }
       
}
