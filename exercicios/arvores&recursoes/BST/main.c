#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    bst *b = criaBST();
    b=insereNaBST(b,15);
    b=insereNaBST(b,15);
    b=insereNaBST(b,2);
    b=insereNaBST(b,11);
    b=insereNaBST(b,2);
    b=insereNaBST(b,4);
    b=insereNaBST(b,42);
    destroiBst(b);
    return 0;
}