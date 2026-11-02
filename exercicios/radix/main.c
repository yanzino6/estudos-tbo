#include "process.h"

int main ()
{
    FILE *f=fopen("in/abra.txt", "r");
    int tam;
    char *t=readFile(f, &tam);
    printText(t);
    freeText(t);
    fclose(f);
    return 0;
}