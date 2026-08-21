#ifndef JOSEFO_H_
#define JOSEFO_H_

#include <stdio.h>

typedef struct josefo josefo;



josefo *criaJosefo(int tam);

void buscaPessoaJosefo(int i, josefo *j);

void executaJosefo();

void removePessoaJosefo(int i, josefo *j);

void insereNoJosefo(int v, josefo *j);

void liberaJosefo(josefo *j);
#endif