#include "msdRadix.h"
#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct String {
    char *c;
    int len;
};

void countSort(String **a, String **aux, int *count, int lo, int hi, int d ,int R)
{
    clearArray(count,R+2);
    for (int i = lo; i <= hi; i++)
    {
        count[char_at(a[i],d)+2]++;
    }
    for (int r = 0; r < R+1; r++)
    {
        count[r+1]+=count[r];
    }
    for (int i = lo; i <= hi; i++)
    {
        int p = count[char_at(a[i],d)+1]++;
        aux[p]=a[i];
    }
    for (int i = lo; i <= hi; i++)
    {
        a[i]=aux[i-lo];
    }

}

int *create_count_array(int R)
{
    return calloc(R + 2, sizeof(int));
}

void clearArray(int *a, int R)
{
    for (int i = 0; i < R; i++)
    {
        a[i]=0;
    }

}

void msdRadix(String* *a,String* *aux,int lo, int hi, int d)
{
    if (hi<=lo)
    {
        return;
    }

    int *count = create_count_array(erre);
    countSort(a,aux,count,lo,hi,d,erre);
    for (int r = 0; r < erre; r++)
    {
        msdRadix(a,aux,lo+count[r],lo+count[r+1]-1,d+1);
    }
    free(count);
}

String *createString(char *s, int len)
{
    String *created=malloc(sizeof(String));
    created->len=len;
    created->c=s;
    return created;
}

void destroyString(String *s)
{
    free(s);
}

void setText(String *s,char *text)
{
    s->c=text;
}
