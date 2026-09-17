#include "item.h"

void sort (Item *a, int lo, int hi )
{
    int sw=1;

    while (sw==1)
    {
        sw=0;
        for (int i = lo; i < hi; i++)
        {
            if (a[i]>a[i+1])
            {
                exch(a[i],a[i+1]);
                sw=1;
            }
        }
        if (sw==0)
            {
                break;
            }
        for (int i = hi; i > lo; i--)
        {
            if (a[i]<a[i-1])
            {
                exch(a[i],a[i-1]);
                sw=1;
            }
            
        }
        
    }
    
    
}