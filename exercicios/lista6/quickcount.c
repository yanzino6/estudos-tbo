#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <sys/time.h>
#include <time.h>

int CUTOFF = 20;

void shuffle(Item *a, int N) {
    struct timeval tv; gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N-1; i > 0; i--) {
        int j = (unsigned int) (drand48()*(i+1));
        exch(a[i], a[j]);
    }
}

int partition(Item *a,int lo, int hi)
{
    int s = a[lo];
    int i = lo;
    int j = hi+1;

    while (1)
    {
        while (less(a[++i],s));
        while (less(s,a[--j]));
        if (i>=j)
        {
            break;
        }
        exch(a[i],a[j]);
    }
    exch(a[lo],a[j]);
    return j;
}

void insertionSort(Item *a,int lo, int hi)
{
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


void quickSort(Item *a, int lo, int hi)
{
    if (hi<=lo+CUTOFF-1)
    {
        insertionSort(a,lo,hi);
        return;
    }
    
    int j = partition(a,lo,hi);
    quickSort(a,lo,j-1);
    quickSort(a,j+1,hi);
}

void sort(Item *a, int lo, int hi)
{
    shuffle(a,hi-lo+1);
    clock_t in = clock();
    for (int i = lo; i < hi; i++)
    {
        if (a[i]>a[i+1])
        {
            int sent = a[i];
            a[i]=a[i+1];
            a[i+1]=sent;
        }
        
    }
    
    quickSort(a,lo,hi);
    //insertionSort(a,lo,hi);
    clock_t end = clock();

    double time = (double)(end - in)/CLOCKS_PER_SEC;
    printf("%f\n",time);
}