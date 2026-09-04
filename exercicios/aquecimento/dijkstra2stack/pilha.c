#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

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
    else
    {
        new->prox=p->top;
        p->top=new;
    }
    
}

void *removeTopo(pilha *p)
{      
    if (p->top!=NULL)
    {
        node *rm =p->top;
        void *rmdata= p->top->data;

        if (p->top->prox==NULL)
        {
            p->top=NULL;
            free(rm);
        }
        else 
        {
            p->top=rm->prox;
            free (rm);
        }
        return rmdata;
        }
        return NULL;
}

void liberaPilha(pilha *p)
{
    printf("%d", *(int*)p->top->data);
}

int calculadora(char op, int n1, int n2)
{
    switch (op)
    {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            return 0;
    }
}