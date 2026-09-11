#include "item.h"

void sort (Item *a, int lo, int hi ) 
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