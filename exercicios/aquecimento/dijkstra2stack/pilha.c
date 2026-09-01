#include "pilha.h"
#include <stdlib.h>

typedef struct node{
    struct node *prox;
    void *data;
}node;

struct pilha{

    node *top;
};

pilha *criaPilha()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->top=NULL;
    return p;
}

void inserePilha(void *data, pilha *p)
{
    node *new = (node*)malloc(sizeof(node));
    new->data=data;

    if (p->top==NULL)
    {
        new->prox=NULL;
        p->top=new;
        return;
    }
    
    new->prox=p->top;
    p->top=new;
}

void *removeTopo(pilha *p)
{      
    void *rmdata= p->top->data;
    if (p->top->prox==NULL)
    {
        node *rm =p->top;
        free (rm);
        p->top=NULL;
    }
    else 
    {

    }
    return rmdata;
    
}

void liberaPilha(pilha *p);