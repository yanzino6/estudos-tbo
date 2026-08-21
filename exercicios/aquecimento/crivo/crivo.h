#ifndef CRIVO_H_
#define CRIVO_H_
#include <stdio.h>
#include <stdlib.h>


typedef struct crivo crivo;

crivo *criaCrivo(int tamCrivo);

void marcaMultiplos(crivo *c);

void mostraPrimos(crivo *c);

void liberaCrivo(crivo *c);

#endif