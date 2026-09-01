#ifndef JOSEFO_H_
#define JOSEFO_H_

#include <stdio.h>

typedef struct josefo josefo;
typedef struct node node;


josefo *criaJosefo();

void buscaPessoaJosefo(int i, josefo *j);

void executaJosefo(int n, int m);

node *removePessoaJosefo(int i, josefo *j);

void insereNoJosefo(int v, josefo *j);

void liberaJosefo(josefo *j);
#endif