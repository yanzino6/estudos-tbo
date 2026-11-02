#ifndef MSDRADIX_H_
#define MSDRADIX_H_

typedef struct String String;

void countSort(String **a, String **aux, int *count, int lo, int hi, int d ,int R);

void msdRadix(String* *a,String* *aux,int lo, int hi, int d);

void clearArray(int *a, int R);

int *create_count_array(int R);

String *createString(char *s, int len);

void destroyString(String *s);

void setText(String *s,char *text);

#endif
