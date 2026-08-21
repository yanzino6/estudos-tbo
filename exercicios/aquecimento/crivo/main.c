#include "crivo.h"
#include <time.h>

int main(int argc,char * argv[])
{   
    int n = atoi(argv[1]);
    crivo *c = criaCrivo(n);
    marcaMultiplos(c);
    mostraPrimos(c);
    liberaCrivo(c);

    return 0;
}