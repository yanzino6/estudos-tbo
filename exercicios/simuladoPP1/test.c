#include <stdio.h>

int main ()
{
    char nome1[18];
    char nome2[18];

    scanf("%s\n",nome1);
    scanf("%s\n",nome2);

    printf("%ld", nome1-nome2);


   return 0;
}