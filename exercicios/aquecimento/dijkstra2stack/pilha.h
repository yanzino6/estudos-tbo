#ifndef PILHA_H_
#define PILHA_H_

typedef struct pilha pilha;

pilha *criaPilha();

void inserePilha(void *data, pilha *p);

void *removeTopo(pilha *p);

void liberaPilha(pilha *p);

#endif