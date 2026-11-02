#include "process.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void verifica(const char *entrada, const char *esperado)
{
    FILE *f = tmpfile();
    assert(f != NULL);
    assert(fputs(entrada, f) >= 0);
    rewind(f);
    int n = -1;
    char *texto = readFile(f, &n);
    if (esperado == NULL) {
        assert(texto == NULL);
        assert(n == 0);
    } else {
        assert(texto != NULL);
        assert(n == (int)strlen(esperado));
        assert(strcmp(texto, esperado) == 0);
    }
    freeText(texto);
    fclose(f);
}

int main(void)
{
    // O tamanho declarado nao pode limitar a memoria disponivel para o texto.
    verifica("1\nABRACADABRA!", "ABRACADABRA!");
    verifica("20\nA  B\nC\n", "A B C ");
    verifica("0\n", "");
    verifica("texto sem tamanho", NULL);
    verifica("-1\ntexto", NULL);
    verifica("", NULL);
    puts("Leitura: OK");
    return EXIT_SUCCESS;
}
