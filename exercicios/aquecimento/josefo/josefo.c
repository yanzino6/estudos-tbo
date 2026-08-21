#include "josefo.h"

// Testar implemenacao simples e circular

struct josefo
{
    josefinho *inicio;
    int tamJosefo;
};

typedef struct josefinho
{
    josefinho *prox;
    int v;
}josefinho;

josefo *criaJosefo(int tam);

void buscaPessoaJosefo(int i, josefo *j);

void executaJosefo();

void removePessoaJosefo(int i, josefo *j);

void insereNoJosefo(int v, josefo *j);

void liberaJosefo(josefo *j);