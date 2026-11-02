#define _POSIX_C_SOURCE 200809L
#include "process.h"
#include "sufix.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static double agora(void)
{
    struct timespec t;
    if (clock_gettime(CLOCK_MONOTONIC, &t) != 0) {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }
    return t.tv_sec + t.tv_nsec / 1e9;
}

static int comparaTempo(const void *a, const void *b)
{
    double x = *(const double *)a, y = *(const double *)b;
    return (x > y) - (x < y);
}

static double mediana(double *tempos, int n)
{
    qsort(tempos, n, sizeof *tempos, comparaTempo);
    return n % 2 ? tempos[n/2] : (tempos[n/2-1] + tempos[n/2]) / 2;
}

static void *aloca(size_t bytes)
{
    void *p = malloc(bytes ? bytes : 1);
    if (p == NULL) {
        fprintf(stderr, "Memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

static int comparaEntrada(const char *caminho, int repeticoes)
{
    FILE *f = fopen(caminho, "r");
    if (f == NULL) {
        perror(caminho);
        return 1;
    }
    int n;
    char *texto = readFile(f, &n);
    fclose(f);
    if (texto == NULL) {
        fprintf(stderr, "%s: nao foi possivel ler o texto.\n", caminho);
        return 1;
    }

    size_t bytes = (size_t)n * sizeof(sufix *);
    sufix **original = aloca(bytes);
    sufix **radix = aloca(bytes);
    sufix **quick = aloca(bytes);
    sufix **aux = aloca(bytes);
    double *temposRadix = aloca((size_t)repeticoes * sizeof(double));
    double *temposQsort = aloca((size_t)repeticoes * sizeof(double));
    for (int i = 0; i < n; i++)
        original[i] = suf(texto, i, n-i);

    int falhou = 0;
    // A rodada -1 aquece os algoritmos e nao entra na mediana.
    for (int rodada = -1; rodada < repeticoes; rodada++) {
        memcpy(radix, original, bytes);
        memcpy(quick, original, bytes);
        double tempoRadix = 0, tempoQsort = 0;
        // Alterna quem roda primeiro para reduzir o efeito da ordem.
        for (int vez = 0; vez < 2; vez++) {
            if ((rodada + 1 + vez) % 2 == 0) {
                double inicio = agora();
                sufMsdRadix(radix, aux, 0, n-1, 0);
                tempoRadix = agora() - inicio;
            } else {
                double inicio = agora();
                qsort(quick, n, sizeof *quick, compareSufQsort);
                tempoQsort = agora() - inicio;
            }
        }
        // Cada sufixo tem tamanho distinto: a ordem correta e unica.
        for (int i = 0; i < n; i++) {
            if (radix[i] != quick[i]) {
                fprintf(stderr, "%s: ordenacoes divergem na posicao %d.\n", caminho, i);
                falhou = 1;
                break;
            }
        }
        if (falhou)
            break;
        if (rodada >= 0) {
            temposRadix[rodada] = tempoRadix;
            temposQsort[rodada] = tempoQsort;
        }
    }

    if (!falhou) {
        double r = mediana(temposRadix, repeticoes);
        double q = mediana(temposQsort, repeticoes);
        printf("%-24s %10d %14.6f %14.6f", caminho, n, r * 1000, q * 1000);
        if (r > 0)
            printf(" %12.2f\n", q / r);
        else
            printf(" %12s\n", "n/d");
    }
    free(temposQsort);
    free(temposRadix);
    free(aux);
    free(quick);
    free(radix);
    destroySufixArray(original, n);
    freeText(texto);
    return falhou;
}

int main(int argc, char **argv)
{
    int repeticoes = 7, primeiro = 1;
    if (argc > 1 && strcmp(argv[1], "-r") == 0) {
        char *fim;
        if (argc < 3)
            goto uso;
        errno = 0;
        long valor = strtol(argv[2], &fim, 10);
        if (errno || *fim || fim == argv[2] || valor < 1 || valor > INT_MAX)
            goto uso;
        repeticoes = (int)valor;
        primeiro = 3;
    }
    if (primeiro == argc)
        goto uso;

    printf("Mediana de %d repeticoes; somente ordenacao; tempos em ms.\n", repeticoes);
    printf("%-24s %10s %14s %14s %12s\n", "Entrada", "Sufixos", "Radix (ms)", "qsort (ms)", "qsort/radix");
    int falhou = 0;
    for (int i = primeiro; i < argc; i++)
        falhou |= comparaEntrada(argv[i], repeticoes);
    return falhou ? EXIT_FAILURE : EXIT_SUCCESS;

uso:
    fprintf(stderr, "Uso: %s [-r repeticoes] arquivo...\n", argv[0]);
    return EXIT_FAILURE;
}
