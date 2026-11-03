#include <stdio.h>
#include <stdlib.h>
#include "item.h"

void merge (Item *a, Item *aux, int lo, int mid, int hi, int *acessos)
{
    int i = lo;
    int j= mid +1;

    for (int k = lo; k <= hi; k++)
    {
        if (i>mid)
        {
            a[k]=aux[j++];
            *acessos+=2;
        }
        else if (j>hi)
        {
            a[k]=aux[i++];
            *acessos+=2;
        }
        else if (less(aux[j],aux[i]))
        {
            a[k]=aux[j++];
            *acessos+=4;
        }
        else
        {
            a[k]=aux[i++];
            *acessos+=4;
        }
        
    }
    
}

void mergeSort(Item *a, Item *aux, int lo, int hi, int *acessos)
{
    if (hi<=lo)
    {
        return;
    }

    int mid =lo + (hi-lo)/2;

    mergeSort(aux,a,lo,mid,acessos);
    mergeSort(aux,a,mid+1,hi,acessos);
    merge(a,aux,lo,mid,hi,acessos);
    
}

void sort(Item *a, int lo, int hi)
{
    int N = hi-lo+1;
    int acessos=0;
    Item *aux = malloc(N*sizeof(Item));
    for (int i = 0; i < N; i++)
    {
        aux[i] = a[i];
    }
    mergeSort(a,aux,lo,hi,&acessos);
    printf("Acessos: %d\n", acessos);
    free(aux);
}