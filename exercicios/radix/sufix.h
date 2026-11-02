#ifndef SUFIX_H_
#define SUFIX_H_

typedef struct sufix sufix;

sufix *suf (char *text, int i, int len);

sufix **sufArray(int n);

int compareSuf(sufix *a, sufix *b);

int compareSufQsort(const void *p1, const void *p2);

void destroySufix(sufix *s);

void destroySufixArray(sufix **arr, int n);

void printSuf(sufix *suf);

void buscaSufixos(sufix **arr, int n, const char *query, int context);

int sufCharAt(const sufix *s, int d);

void sufCountSort(sufix **a, sufix **aux, int *count, int lo, int hi, int d, int R);

void sufMsdRadix(sufix **a, sufix **aux, int lo, int hi, int d);

void sufClearArray(int *a, int R);

int *sufCreateCountArray(int R);

#endif
