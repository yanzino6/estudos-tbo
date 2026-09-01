#include "josefo.h"
#include <stdlib.h>

// Testar implemenacao simples e circular
struct node
{
    struct node *prox;
    int v;
};
struct josefo
{
    node *inicio;
};



josefo *criaJosefo()
{
    josefo *j = (josefo*)malloc(sizeof(josefo));
    j->inicio = NULL;
    return j;
}

void buscaPessoaJosefo(int i, josefo *j);

void executaJosefo(int n, int m)
{
    int count = 1;
    josefo *j = criaJosefo();
    

    for (int i = 1; i <= n; i++)
    {
        insereNoJosefo(i,j);
    }

    node *node= j->inicio;

    while (node->prox!=node)
    {
        
        if (count==m)
        {
            node=removePessoaJosefo(node->v, j);
            count =1;
        }
        
        
        else
        {
            node=node->prox;
            count++;
        }
    }
    printf("O lider eh %d", node->v);
    liberaJosefo(j);
    
}

node *removePessoaJosefo(int i, josefo *j)
{

    if (j->inicio->prox==j->inicio)
    {
        node *ult = j->inicio;
        free(ult);
        j->inicio = NULL;
        return j->inicio;
    }
    node *ant = j->inicio;

    while (ant->prox->v!=i)
    {
        ant=ant->prox;
    }

    node *n = ant->prox;

    if (j->inicio==n)
    {
        j->inicio=n->prox;
    }
    
    ant->prox=n->prox;
    free(n);
    return ant->prox;

}

void insereNoJosefo(int v, josefo *j)
{
    node *novo = (node*)malloc(sizeof(node));
    novo->v=v;
    if (j->inicio==NULL)
    {
        novo->prox=novo;
        j->inicio=novo;

        return;
    }
    
    node *atual = j->inicio;
    while (atual->prox!=j->inicio)
    {
        atual=atual->prox;
    }
    atual->prox=novo;
    novo->prox=j->inicio;
}

void liberaJosefo(josefo *j)
{
    node *n = j->inicio;
    while (j->inicio->prox!=j->inicio)
    {
        node *prox = n->prox;
        free(n);
        n=prox;
    }
    free(n);
    free(j);
    
}