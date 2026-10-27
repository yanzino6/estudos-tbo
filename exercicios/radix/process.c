#include "process.h"
#include <stdio.h>
#include <stdlib.h>

char *readFile(FILE *r)
{
    int tam;
    int i = 0;
    fscanf(r,"%d\n",&tam);
    char *text = malloc(tam*sizeof(char));
    char read,last;
    last='1';
    read='\0';
    while (!feof(r))
    {
        fscanf(r,"%c",&read);
        if (read!='\n')
        {
            if (!(read==' '&& last==' '))
            {
                text[i]=read;
                i++;
            }
            
        }
        last=read;
        //printf("%s", text);
    }
    text=realloc(text,i*sizeof(char));
    
    return text;
}

void printText(char *t)
{
    int i=0;
    printf("%s", t);
    printf("\n");
}

void freeText(char *t)
{
    free(t);
}