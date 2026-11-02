#include "process.h"
#include "sufix.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    const int context = 15;
    FILE *f = fopen("in/tale.txt", "r");
    if (f == NULL) {
        perror("in/tale.txt");
        return EXIT_FAILURE;
    }
    int tam;
    char *t = readFile(f, &tam);
    fclose(f);
    if (t == NULL) {
        fprintf(stderr, "Nao foi possivel ler in/tale.txt.\n");
        return EXIT_FAILURE;
    }
    printf("%d\n", tam);
    sufix **arr = sufArray(tam);

    for (int i = 0; i < tam; i++) {
        arr[i] = suf(t, i, tam-i);
    }

    clock_t inicio = clock();
    qsort(arr, tam, sizeof *arr, compareSufQsort);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %.6f segundos\n", tempo);

    char query[256];

    printf("Digite a consulta: ");

    if (fgets(query, sizeof query, stdin) != NULL) {
        // Remove o '\n' que o fgets guarda ao ler o Enter.
        query[strcspn(query, "\n")] = '\0';

        if (query[0] != '\0') {
            buscaSufixos(arr, tam, query, context);
        }
    }
    destroySufixArray(arr, tam);

    freeText(t);
    return EXIT_SUCCESS;
}
