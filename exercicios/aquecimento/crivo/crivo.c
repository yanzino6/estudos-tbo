#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "crivo.h"

struct crivo 
{
    bool *arr;
    int tamcrivo;
};

crivo *criaCrivo(int tamCrivo)
{
    crivo *c = (crivo*)malloc(sizeof(crivo));
    c->tamcrivo=tamCrivo+1;
    c->arr = (bool*) malloc(c->tamcrivo*sizeof(bool));
    memset(c->arr, true, c->tamcrivo*sizeof(bool));
    return c;
}

void marcaMultiplos(crivo *c)
{
    
    for (int j = 2; j < c->tamcrivo; j++)
    {
        if (c->arr[j]==true)
        {
            for (int i = 2; i*j < c->tamcrivo; i++)
                {
                    c->arr[i*j] = false;
                }
        }
        
    }
    
    
}

void mostraPrimos(crivo *c)
{
    for (int i = 0; i < c->tamcrivo; i++)
    {
        if (c->arr[i]==true)
        {
            printf("%d ",i);
        }
        
    }
    printf("\n");
}

void liberaCrivo(crivo *c)
{
    free(c->arr);
    free(c);
}