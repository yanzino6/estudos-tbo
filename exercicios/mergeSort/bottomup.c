#include "item.h"
#include <stdlib.h>
#include <time.h>
#define MIN(X,Y) ((X < Y) ? (X) : (Y))

int CUTOFF = 10;

void merge(Item *a, Item *aux,int lo, int mid ,int hi)
{
    for (int i = lo; i <= hi; i++)
    {
        aux[i]=a[i];
    }

    int i = lo;
    int j= mid+1;

    for (int k = lo; k <= hi; k++)
    {
        if (less(mid,i))
        {
            a[k]=aux[j++];
        }
        else if (less(hi,j))
        {
            a[k]=aux[i++];
        }
        else if (less(aux[i],aux[j]))
        {
            a[k]=aux[i++];
        }
        else
        {
            a[k]=aux[j++];
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
    for (int i = lo+2; i <= hi; i++)
    {   int temp = a[i];
        for ( j = i; j >= lo && less(temp,a[j-1]); j--)
        {
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
    

}

void sort (Item *a, int lo, int hi )
{
    int N =(hi-lo)+1;
    int y=N-1;
    Item * aux = malloc(N*sizeof(Item));

    for (int i = 0; i <= hi; i+=CUTOFF)
    {
        insertion_sort(a,i,MIN(i+CUTOFF-1,hi));
    }
    

    for (int sz = CUTOFF; sz < N; sz*=2)
    {
        for (int i = lo; i < N-sz; i+=(sz*2))
        {
            int x = i + (sz*2) - 1;
            if(!less(a[i+sz],a[i+sz-1]))
            {
                continue;
            }
            merge(a,aux,i,i+sz-1,MIN(y,x));
        }
    }
    free(aux);
}