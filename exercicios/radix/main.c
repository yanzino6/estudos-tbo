#include "process.h"

int main ()
{
    FILE *f=fopen("in/abra.txt", "r");
    char *t=readFile(f);
    printText(t);
    freeText(t);
    fclose(f);
    return 0;
}