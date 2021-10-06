#include <stdio.h>
#include <stdlib.h>
#include "str_function.h"

int main()
{
    FILE* f;
    f=fopen( "test.txt", "r");
    char a[256]={};
    char* lptr;
    size_t num = 10;
    getlinei(&lptr , &num, f);
    putsi(lptr);
    printf("\n");
    getlinei(&lptr , &num, f);
    putsi(lptr);
    printf("\n");
    getlinei(&lptr , &num, f);
    putsi(lptr);
    fclose(f);
}
