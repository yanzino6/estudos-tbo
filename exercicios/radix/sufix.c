#include "sufix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

int CUTOFF=20;

struct sufix{
    char *text;
    int len;
    int index;
};

sufix *suf (char *text, int i, int len)
{
    sufix *suf = malloc (sizeof(sufix));
    suf->index=i;
    suf->text=&text[suf->index];
    suf->len=len;
    return suf;
}

sufix **sufArray(int n)
{
    sufix **arr = malloc (n*sizeof(sufix *));
    return arr;
}

void destroySufix(sufix *s)
{
    free(s);
}

void destroySufixArray(sufix **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        destroySufix(arr[i]);
    }
    free(arr);
}

int compareSuf(sufix *a, sufix *b)
{
    int i=0;
    while (a->text[i]==b->text[i]&&a->text[i]!='\0')
    {
        i++;
    }

    return (unsigned char)a->text[i] - (unsigned char)b->text[i];
}

int compareSufQsort(const void *p1, const void *p2)
{
    sufix *const *a =p1;
    sufix *const *b =p2;

    return compareSuf(*a,*b);
}

void printSuf(sufix *suf)
{
    printf("%s\n", suf->text);
}

void buscaSufixos(sufix **arr, int n, const char *query, int context)
{
    size_t tamanho = strlen(query);
    if (tamanho == 0)
        return;

    if (context < 0)
        context = 0;

    int inicio = 0;
    int fim = n;

    while (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        int cmp = strncmp(arr[meio]->text, query, tamanho);

        if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }

    int encontrou = 0;

    for (int i = inicio; i < n; i++) {
        if (strncmp(arr[i]->text, query, tamanho) != 0||encontrou==12)
            break;

        int antes = context;
        if (antes > arr[i]->index)
            antes = arr[i]->index;

        int depois = context;
        if (depois > arr[i]->len - (int)tamanho)
            depois = arr[i]->len - (int)tamanho;

        printf("Encontrado no indice %d do texto: %.*s\n", arr[i]->index,
               antes + (int)tamanho + depois, arr[i]->text - antes);
        encontrou ++;
    }

    if (encontrou==0)
        printf("Consulta nao encontrada.\n");
}

int sufCharAt(const sufix *s, int d)
{

    return d < s->len ? (unsigned char)s->text[d] : -1;
}

void sufCountSort(sufix **a, sufix **aux, int *count, int lo, int hi, int d, int R)
{
    for (int i = lo; i <= hi; i++)
    {
        count[sufCharAt(a[i],d)+2]++;
    }
    for (int r = 0; r < R+1; r++)
    {
        count[r+1]+=count[r];
    }
    for (int i = lo; i <=hi; i++)
    {
        aux[count[sufCharAt(a[i],d)+1]++]=a[i];
    }
    for (int i = lo; i <= hi; i++)
    {
        a[i]=aux[i-lo];
    }
}

void sufMsdRadix(sufix **a, sufix **aux, int lo, int hi, int d)
{
    if (hi<=lo+CUTOFF-1)
    {
        // Os primeiros d caracteres deste grupo ja sao iguais.
        for (int i = lo + 1; i <= hi; i++) {
            sufix *atual = a[i];
            int j = i;
            while (j > lo && strcmp(a[j-1]->text + d, atual->text + d) > 0) {
                a[j] = a[j-1];
                j--;
            }
            a[j] = atual;
        }
        return;
    }
    int *count = sufCreateCountArray(erre);
    sufCountSort(a,aux,count,lo,hi,d,erre);
    // count[0] ja aponta depois do grupo de sufixos terminados (-1).
    for (int r = 0; r < erre; r++)
    {
        sufMsdRadix(a,aux,lo+count[r],lo+count[r+1]-1,d+1);
    }
    free(count);

}

void sufClearArray(int *a, int R)
{
    // TODO: zerar o vetor de contagem.
    for (int i = 0; i < R; i++)
    {
        a[i]=0;
    }

}

int *sufCreateCountArray(int R)
{
    // TODO: alocar o vetor de contagem com R + 2 posicoes.
    int *count=calloc(R+2,sizeof(int));
    return count;
}
