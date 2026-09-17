#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    bst *b;
    struct node *prox;
    
}node;


struct pilha
{
  node *top;
};

pilha * criaPilha()
{
    pilha *p = malloc(sizeof(pilha));
    p->top=NULL;
    return p;
}

void push(pilha *p, bst *b)
{
    node *new = malloc(sizeof(node));
    new->b=b;
    if (p->top==NULL)
    {
        new->prox=NULL;
    }
    else
    {
        new->prox=p->top;
    }
    p->top=new;
}

bst * pop(pilha *p)
{
    if (p->top!=NULL)
    {   
        bst *data = p->top->b;
        node *n = p->top;
        p->top=p->top->prox;
        free(n);
        return data;
    }
    return NULL;
}

void destroyStack(pilha *p)
{
    free(p);
}

int pilhavazia(pilha *p)
{
    if (p->top==NULL)
    {
        return 1;
    }
    return 0;
}