#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int lg (long int N)
{
    long int val = 0;

    while (N!=1)
    {
        N=N/2;
        val++;
    }
    
    return val;
}


//muda nada 😂
long int DivideConquerlgFat(int Nin, int Nfim, int brk )
{
    long int val = 0;

    if (Nfim-Nin<=brk)
    {
        for (int i = Nin; i <= Nfim; i++)
        {
            val+=lg(i);
        }
        return val;
    }
    int mid = Nin + (Nfim-Nin)/2;
    val+=DivideConquerlgFat(Nin,mid,brk);
    val+=DivideConquerlgFat(mid+1,Nfim,brk);
    return val;
}

// quebra pq precisa de mais de 64 bits pra ser representado
long int naiveLgFat(long int N)
{
    long int val = 1;
    for (long int i = 2; i <= N; i++)
    {
        val*=i;
    }
    val=lg(val);
    return val;
}

long int lessNaiveLgFat(int N)
{
    long int val = 0;
    for (int i = 2; i <= N; i++)
    {
        val+=lg(i);
    }
    return val;
}

int main ()
{
    int N;
    scanf("%d", &N);

    clock_t inicio = clock();
    //long int resultado = DivideConquerlgFat(2,N,10);
    long int resultado = naiveLgFat(N);
    clock_t fim = clock();

    printf("%ld\n",resultado);
    printf("Tempo gasto: %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}