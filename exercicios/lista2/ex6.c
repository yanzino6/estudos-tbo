#include <stdio.h>
#include <stdlib.h>

int localMin(int **mat, int N)
{   
    int i=0;
    int j=0;
    int incj=0;
    int inci=0;
    int num, vismin;
    while(1)
    {  
        num = mat[i][j];
        inci=0;
        incj=0;
        vismin=num;
        if (j<N-1)
        {
            if (mat[i][j+1]<vismin)
            {
                vismin=mat[i][j+1];
                incj=1;
            }
            
        }
        if (j>0)
        {
            if (mat[i][j-1]<vismin)
            {
                vismin=mat[i][j-1];
                incj=-1;
            }
            
        }
        if (i<N-1)
        {
            if (mat[i+1][j]<vismin)
            {
                vismin=mat[i+1][j];
                inci=1;
                incj=0;
            }
            
        }
        if (i>0)
        {
            if (mat[i-1][j]<vismin)
            {
                vismin=mat[i-1][j];
                inci=-1;
                incj=0;
            }
            
        }
        if (num==vismin)
        {
            return num;
        }
        i+=inci;
        j+=incj;
    }
    
}

void printaMat(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    
}

int main () 
{
    int N;
    scanf("%d", &N);
    int **mat=malloc(N*sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        mat[i] = malloc (N*sizeof(int));
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n ----     MATRIZ DE ENTRADA      ----\n");
    printaMat(mat,N);
    printf("\n ---- MINIMO LOCAL ENCONTRADO: %d ----", localMin(mat,N));
    return 0;
    
}