#include "pilha.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main ()
{
    pilha *pChar = criaPilha();
    pilha *pInt = criaPilha();

    char c;

    while (true)
    {
        scanf("%c", &c);
        if (c=='\n')
        {
            break;
        }
        if (c>47&&c<58)
        {   
            int *val = (int *)malloc(sizeof(int));
            *val = c - '0';
            inserePilha(val, pInt);
            
        }
        else if (c!='('&&c!=')')
        {
            char *val = (char *)malloc(sizeof(char));
            *val=c;
            inserePilha(val,pChar);
        }
        if (c==')')
        {
            int *v1=(int*)removeTopo(pInt);
            int *v2=(int*)removeTopo(pInt);
            char *op=(char*)removeTopo(pChar);
            int *res = (int *)malloc(sizeof(int));
            *res = calculadora(*op,*v2,*v1);
            inserePilha(res,pInt);
            free(v1);
            free(v2);
            free(op);
        }
        
        
    }
    free(pChar);
    int *res=(int*)removeTopo(pInt);
    printf("%d\n", *res);
    free(res);
    free(pInt);
    return 0;
}