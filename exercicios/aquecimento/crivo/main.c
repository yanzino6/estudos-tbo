#include "crivo.h"

int main()
{

    crivo *c = criaCrivo(100);
    marcaMultiplos(c);
    mostraPrimos(c);
    liberaCrivo(c);

    return 0;
}