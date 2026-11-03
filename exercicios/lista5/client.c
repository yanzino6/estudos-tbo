#include <stdio.h>
#include "item.h"
#include <stdlib.h>

extern void sort(Item *a, int lo, int hi);

int main (int argc , char * argv[])
{
    int n = atoi(argv[1]);
    Item *arr = malloc(n*sizeof(Item));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    

    free(arr);

    return 0;
}