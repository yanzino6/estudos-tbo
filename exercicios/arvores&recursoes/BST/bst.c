#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct bst 
{
    bst *esq;
    bst *dir;
    int v;
};

bst *criaBST()
{
    bst *b = NULL;
    return b;
}

bst *insereNaBST(bst *b, int v)
{

    if (b == NULL)
    {
        b = (bst*)malloc(sizeof(bst));
        b->dir=NULL;
        b->esq=NULL;
        b->v=v;
        printf("%d inserido\n", v);
    }

    if (v==b->v)
    {
    }
    
    else if (v>b->v)
    {
        b->dir=insereNaBST(b->dir,v);
    }
    else if (v<b->v)
    {
        b->esq=insereNaBST(b->esq,v);
    }
    
    return b;
}

void destroiBst(bst *b)
{

    if (b==NULL)
    {
        return;
    }

    destroiBst(b->dir);
    destroiBst(b->esq);

    free(b);
    
}

void imprimeBst(bst *b, int space)
{   

}