#include <stdio.h>
#include <string.h>

//Protótipo das funções
int removeCaracteresRecursiva(char str[], char ch, int i);
int removeCaracteresIterativo(char str[], char ch);

int main ()
{
    char string[20], ch;

    printf("String: ");
    __fpurge(stdin); //fflush(stdin);
    gets(string);

    printf("Caracatere a ser removido da string: ");
    __fpurge(stdin);
    scanf("%c", &ch);

    printf("%d", removeCaracteresIterativo(string, ch));
    printf("\nString: %s", string);
}

int removeCaracteresRecursiva(char str[], char ch, int i)
{
    if (str[i] != '\0')
    {
        if (str[i] == ch)
        {
            //Removendo caractere
            int j;
            for(j=i; str[j] != '\0'; j++)
            {
                str[j] = str[j+1];
            }
            return 1 + removeCaracteresRecursiva(str, ch, i+1);
        }
        else
        {
            return removeCaracteresRecursiva(str, ch, i+1);
        }
    }
    else
    {
        return 0;
    }
}

int removeCaracteresIterativo(char str[], char ch)
{
    int i, j, cont=0;
    for (i=0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            for(j=i; str[j] != '\0'; j++)
            {
                str[j] = str[j+1];
            }
            cont++;
        }
    }

    return cont;
}