#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max (int *vec, int lo, int hi)
{
    if (lo-hi==0)
    {
        return vec[lo];
    }
    if (vec[lo]>max(vec,lo+1,hi))
    {
        return vec[lo];
    }
    else
    {
        return max(vec,lo+1,hi);
    }
    
}

int main()
{
    int vec[10]={12,12376,32,2,100,9,32,1,9417234,10};
    printf("Maximo eh %d\n",max(vec,0,9));
    return 0;
}