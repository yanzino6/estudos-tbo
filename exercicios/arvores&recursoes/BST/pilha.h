#ifndef PILHA_H_
#define PILHA_H_
#include "bst.h"

typedef struct pilha pilha;

pilha * criaPilha();

void push(pilha *p, bst *b);

bst * pop(pilha *p);

void destroyStack(pilha *p);

int pilhavazia(pilha *p);

#endif