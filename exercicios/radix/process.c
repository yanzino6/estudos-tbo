#include "process.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

char *readFile(FILE *r,int *size)
{
    int tam;
    *size = 0;
    if (r == NULL || fscanf(r, "%d\n", &tam) != 1 || tam < 0)
        return NULL;

    int i = 0;
    size_t capacidade = (size_t)tam + 1;
    char *text = malloc(capacidade);
    if (text == NULL)
        return NULL;
    int read, last = -1;
    while ((read = fgetc(r)) != EOF)
    {
        if (read=='\n')
            read=' ';

        if (!(read==' '&& last==' '))
        {
            if (i == INT_MAX) {
                free(text);
                return NULL;
            }
            if ((size_t)i + 1 >= capacidade) {
                size_t nova = capacidade > (size_t)INT_MAX / 2
                    ? (size_t)INT_MAX + 1 : capacidade * 2;
                char *maior = realloc(text, nova);
                if (maior == NULL) {
                    free(text);
                    return NULL;
                }
                text = maior;
                capacidade = nova;
            }
            text[i]=read;
            i++;
        }
        last=read;
    }
    if (ferror(r)) {
        free(text);
        return NULL;
    }
    text[i]='\0';
    *size=i;
    return text;
}

void printText(char *t)
{
    printf("%s", t);
    printf("\n");
}

void freeText(char *t)
{
    free(t);
}
