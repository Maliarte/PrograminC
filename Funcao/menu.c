#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int i;
    do
    {
        printf("\nEscolha uma opção:\n");
        printf("\n(1) opção:\n");
        printf("\n(2) opção:\n");
        printf("\n(3) opção:\n");
        scanf("%d", &i);
        
    } while ( i < 1 || i > 3);
    
 return i;   
}


int main(void){
int op = menu();
printf("Você escolheu:\n%d", i);

}
