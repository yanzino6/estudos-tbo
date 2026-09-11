#include "item.h"

void sort (Item *a, int lo, int hi )
{   
    int min;
    for (int i = 0; i < hi; i++)
    {   
        min = i;
        for (int j = i+1; j <= hi; j++)
        {
            if (less(a[j],a[min]))
            {
                min=j;
            }
            
        }
        exch(a[i],a[min])
    }
    
}