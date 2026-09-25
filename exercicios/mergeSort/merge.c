#include "item.h"
#include <stdlib.h>

int cutoff = 10;

void merge(Item *a, Item *aux,int lo, int mid ,int hi)
{
    for (int i = lo; i <= hi; i++)
    {
        aux[i] = a[i];
    }
    int i=lo,j=mid+1;

    for (int k = lo; k <= hi; k++)
    {
        if (j>hi)
        {
           a[k]=aux[i++];
        }
        else if (i>mid)
        {
            a[k]=aux[j++];
        }
        else if (less(aux[j],aux[i]))
        {
            a[k]=aux[j++];
        }
        else 
        {
            a[k]=aux[i++];
        }
        
    }
    
}
void insertion_sort (Item *a, int lo, int hi ) 
{   
    int min = lo;

    for (int i = lo; i <= hi; i++)
    {
        if (less(a[i],a[min]))
        {
            min = i;
        }
        
    }
    exch(a[min],a[lo]);
    int j;
    for (int i = lo+1; i <= hi; i++)
    {   int temp = a[i];
        for ( j = i; j >= lo && less(temp,a[j-1]); j--)
        {
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
    

}
void merge_sort (Item *a,Item *aux, int lo, int hi )
{   

    if (hi<=lo+cutoff-1)
    {
        insertion_sort(a,lo,hi);
        return;
    }
    int mid = lo + (hi-lo)/2;
    merge_sort(a,aux,lo, mid);
    merge_sort(a,aux, mid +1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort (Item *a, int lo, int hi ) 
{
    int n =(hi-lo)+1;
    Item * aux = malloc(n*sizeof(Item));
    merge_sort(a,aux,lo,hi);
    free(aux);

}
