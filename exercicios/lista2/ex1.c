#include <stdio.h>
#include <stdlib.h>

void showOrder(int *aux,int *arr1, int *arr2, int N)
{
    int j=0;
    int i=0;
    for (int k = 0; k < 2*N; k++)
    {
        if (i>N-1)
        {
            aux[k]=arr2[j++];
        }
        else if (j>N-1)
        {
            aux[k]=arr1[i++];
        }
        else if (arr1[i]<arr2[j])
        {
            aux[k]=arr1[i++];
        }
        else
        {
            aux[k]=arr2[j++];
        }
    }
    
}

void printArr(int *arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main (int argc, char *argv[]) 
{
    int n=atoi(argv[1]);

    int *arr1 = malloc (n*sizeof(int));
    int *arr2 = malloc (n*sizeof(int));
    int *aux = malloc (2*n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    showOrder(aux,arr1,arr2,n);
    printArr(aux,2*n);
    free(aux);
    free(arr1);
    free(arr2);
}