#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct bst{
    int key;
    bst *l;
    bst *r;
};

bst *bstInit()
{
    bst *b=NULL;
}

void bstDestroy(bst *b)
{
    if (b!=NULL)
    {
        if (b->l!=NULL)
        {
            bstDestroy(b->l);
        }
        if (b->r!=NULL)
        {
            bstDestroy(b->r);
        }
        free(b);
    }
    
}

int bstHeight(bst *b)
{
    if (b==NULL)
    {
        return -1;
    }
    
    int hleft = bstHeight(b->l)+1;
    int hright = bstHeight(b->r)+1;

    if (hleft>hright)
    {
        return hleft;
    }
    else
    {
        return hright;
    }

}

bst *bstInsertKey(bst *b, int key)
{
    
    if (b==NULL)
    {
        b = malloc(sizeof(bst));
        b->l=NULL;
        b->r=NULL;
        b->key=key;
    }
    
        if (key>b->key)
        {
            b->l=bstInsertKey(b->l,key);
        }
        else if (key<b->key)
        {
            b->r=bstInsertKey(b->r,key);
        }

        return b;
        
    

}