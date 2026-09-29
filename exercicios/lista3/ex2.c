#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int contaCollatz (long int N)
{
    int cont=1;
    if (N==1)
    {
        return 1;
    }
    if (N%2==0)
    {
        cont+=contaCollatz(N/2);
    }
    else
    {
       cont+=contaCollatz((N*3)+1);
    }
    return cont;
}

int main () 
{
    long int vec[100000];

    for (long int i = 1; i < 100000; i++)
    {
        vec[i]=contaCollatz(i);
    }
    int greatest = vec[0];
    int greatestIndex = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (vec[i]>greatest)
        {
            greatest=vec[i];
            greatestIndex=i;
        }
        
    }
    printf("Maior numero de chamadas recursivas vem com o número %d, que eh %d", greatestIndex, greatest-1);
    return 0;
}