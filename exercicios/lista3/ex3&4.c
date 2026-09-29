#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nonRecEuclides(int N, int M)
{
    int res=M;
    int quos;
    int rec = 0;
    while (N%M!=0)
    {
        res = N%M;
        N=M;
        M=res;
        rec++;
    }
    printf("Recursao = %d\n", rec);
    return res;
}

int main ()
{
    int N,M;
    scanf("%d",&N);
    scanf("%d",&M);
    if (M>N)
    {
        int aux = M;
        M=N;
        N=aux;
    }
    printf("MDC eh %d\n", nonRecEuclides(N,M));
}