#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
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

int alturaBst(bst *b)
{

    if (b==NULL)
    {
        return -1;
    }
    

    int hEsq = alturaBst(b->esq)+1;
    int hDir = alturaBst(b->dir)+1;

    if (hEsq>hDir)
    {
        return hEsq;
    }
    else
    {
        return hDir;
    }
    

}

void rec_preorder(bst *t, void (*visit)(bst*))
{
    if (t==NULL)
    {
        return;
    }
    visit(t);
    rec_preorder(t->esq,visit);
    rec_preorder(t->dir,visit);
}

void rec_inorder(bst *t, void (*visit)(bst*))
{
    if (t==NULL)
    {
        return;
    }
    
    rec_inorder(t->esq,visit);
    visit(t);
    rec_inorder(t->dir,visit);
}

void rec_postorder(bst *t, void (*visit)(bst*))
{
    if (t==NULL)
    {
        return;
    }
    
    rec_postorder(t->esq,visit);
    rec_postorder(t->dir,visit);
    visit(t);
}

void nonrec_preorder(bst *t, void (*visit)(bst*))
{   
    pilha *p=criaPilha();
    bst *aux = t;
    push(p,aux);
    while (pilhavazia(p)==0)
    {
        aux=pop(p);
        visit(aux);
        if (aux->dir!=NULL)
        {
            push(p,aux->dir);
        }
        
        if (aux->esq!=NULL)
        {
            push(p,aux->esq);
        }
        
    }
    destroyStack(p);
}

void nonrec_inorder(bst *t, void (*visit)(bst*))
{
    pilha *p=criaPilha();
    bst *aux = t->esq;
    push(p,t);

    while (aux != NULL || pilhavazia(p) == 0)
    {
        while (aux!=NULL)
        {
            push(p,aux);
            aux=aux->esq;
        }
        aux=pop(p);
        visit(aux);
        aux=aux->dir;
    }
    destroyStack(p);
    
}

void nonrec_postorder(bst *t, void (*visit)(bst*))
{
    pilha *p=criaPilha();
    bst *aux = t->esq;
    push(p,t);

    while (aux != NULL || pilhavazia(p) == 0)
    {
        while (aux!=NULL)
        {
            push(p,aux);
            aux=aux->esq;
        }
        aux=pop(p);
        visit(aux);
        aux=aux->dir;
    }
    destroyStack(p);
}

void printValue(bst * b)
{
    if (b!=NULL)
    {
        printf("%d ", b->v);
    }
    
}