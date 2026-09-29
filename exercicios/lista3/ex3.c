#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nonRecEuclides(int N, int M)
{
    int res=1;
    int quos;
    while (N%M!=0)
    {
        res = N%M;
        N=M;
        M=res;
    }
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