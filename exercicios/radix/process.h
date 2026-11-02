#ifndef PROCESS_H_
#define PROCESS_H_
#include <stdio.h>

// Retorna NULL em erro e zera size; o tamanho declarado e uma estimativa.
char *readFile(FILE *r, int *size);

void printText(char *t);

void freeText(char *t);

#endif
