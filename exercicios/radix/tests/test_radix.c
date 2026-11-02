#include "msdRadix.h"
#include "sufix.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void verificaStrings(void)
{
    char *textos[] = {"ba", "a", "", "ab", "\xff", "\x80", "aa"};
    String *a[7], *aux[7], *original[7];
    int ordem[] = {2, 1, 6, 3, 0, 5, 4};
    for (int i = 0; i < 7; i++)
        original[i] = a[i] = createString(textos[i], (int)strlen(textos[i]));
    msdRadix(a, aux, 0, 6, 0);
    for (int i = 0; i < 7; i++) {
        assert(a[i] == original[ordem[i]]);
        destroyString(a[i]);
    }
}

static void verificaSufixos(char *texto)
{
    int n = (int)strlen(texto);
    sufix **a = sufArray(n), **aux = sufArray(n), **esperado = sufArray(n);
    for (int i = 0; i < n; i++)
        esperado[i] = a[i] = suf(texto, i, n-i);
    qsort(esperado, (size_t)n, sizeof *esperado, compareSufQsort);
    sufMsdRadix(a, aux, 0, n-1, 0);
    for (int i = 0; i < n; i++)
        assert(a[i] == esperado[i]);
    destroySufixArray(a, n);
    free(aux);
    free(esperado);
}

int main(void)
{
    verificaStrings();
    verificaSufixos("");
    verificaSufixos("A");
    verificaSufixos("ABRACADABRA!");
    verificaSufixos("BANANABANANABANANABANANABANANA");
    char texto[257];
    memset(texto, 'a', sizeof texto - 1);
    texto[sizeof texto - 1] = '\0';
    verificaSufixos(texto);
    unsigned estado = 42;
    for (int rodada = 0; rodada < 100; rodada++) {
        for (int i = 0; i < 256; i++) {
            estado = estado * 1664525u + 1013904223u;
            texto[i] = (char)(1 + (estado >> 24) % 255);
        }
        verificaSufixos(texto);
    }
    puts("Radix e sufixos: OK");
    return EXIT_SUCCESS;
}
