#include "item.h"
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
int CUTOFF = 20;

void shuffle(Item *a, int N) {
    struct timeval tv; gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N-1; i > 0; i--) {
        int j = (unsigned int) (drand48()*(i+1));
        exch(a[i], a[j]);
    }
}

void insertion_sort(Item *a, int lo, int hi) {
    
    //int min = lo;
    //for (int i = lo; i <= hi; i++)
   // {
       // if (less(a[i],a[min]))
       // {
      //      min=i;
     //   }
        
    //}
    //exch(a[lo],a[min]);

    for (int i = hi; i > lo; i--)
    {
        compexch(a[i-1],a[i]);
    }
    

    for (int i = lo+2; i <= hi; i++)
    {   
        int sent = a[i];
        int j;
        for ( j = i; less(sent,a[j-1]); j--)
        {
            a[j]=a[j-1];
        }
        a[j]=sent;
    }
    

}

int partition (Item *a, int lo, int hi)
{
    int v = a[lo];
    int i=lo;
    int j=hi+1;

    while (1)
    {
        while (less(a[++i],v))
        {
            if (i==hi)
            {
                break;
            }
            
        }
        while (less(v,a[--j]))
        {
            if (j==lo)
            {
                break;
            }
            
        }
        if (i>=j)
        {
            break;
        }
        
        exch(a[i],a[j]);
    }
    exch(a[lo],a[j]);
    return j;

}

void quick_sort (Item *a, int lo, int hi ) 
{
    if (hi<=lo+CUTOFF-1)
    {   
        insertion_sort(a,lo,hi);
        return;
    }

    // if (hi<=lo)
    // {
    //     return;
    // }
    

    int j = partition(a,lo,hi);
    quick_sort(a,lo,j-1);
    quick_sort(a,j+1,hi);
    
}

void sort(Item *a, int lo, int hi)
{
    shuffle(a, hi - lo + 1);
    clock_t inicio = clock();
    quick_sort(a, lo, hi);
    clock_t fim = clock();
    double tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo_decorrido);
}