#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (int argc, char *argv[])
{
    srand(time(NULL)); // should only be called once
    int r;

    int n = atoi(argv[1]);
    bst *b = criaBST();
    for (int i = 0; i < n; i++)
    {
        r = rand()%1001;
        b=insereNaBST(b,r);
    }

    printf("Altura da bst = %d\n", alturaBst(b));

    nonrec_preorder(b,printValue);

    destroiBst(b);
    return 0;
}