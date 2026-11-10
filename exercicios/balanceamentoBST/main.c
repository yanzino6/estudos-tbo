#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{

    srand(time(NULL));
    float h=0;

    for (int i = 0; i < 10; i++)
    {
        bst *b=bstInit();
        
        for (int i = 0; i < 1000000; i++)
        {
            int x = rand();
            b=bstInsertKey(b,x);
        }
        int altura = bstHeight(b);
        h += (float) altura;
        printf("Atura eh %d\n",altura);

        bstDestroy(b);
    }

    printf("Altura media eh %.2f\n",h/10);
    
    return 0;
}