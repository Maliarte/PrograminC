/*
 Dado um numero fatorial resolver por recursão

 ex: 3! = 3.2.1 Onde n=3.

 Sendo assim,  N == 0 return 1.
            N != 0 {
                fatorial(n)
            }
 */

#include <stdio.h>
#include <string.h>

//prototipos
int fatorial(int n);

void main()
{
     int n , result;

  result = fatorial(5);
  printf("%d ", result);
}

int fatorial(n)
{
   
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return n * fatorial(n - 1);
        }
   
}