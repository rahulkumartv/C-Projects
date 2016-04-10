//
// Created by Rahul Thai Valappil on 3/18/2016.
//
/*tArray.c*/
                                                                                    #include "Array.h"
#include <stdio.h>

int main()
{
    int size;
    int* a, *ra;
    printf("array size ?");
    scanf("%d",&size);
    a =CreateArray(size);
    ra =CreateRandomArray(size);
    DisplayArray(a,size);
    DisplayArray(ra,size);
    SimpleSort(a,size);
    SimpleSort(ra,size);
    DisplayArray(a,size);
    DisplayArray(ra,size);
    DestroyArray(&a);
    DestroyArray(&ra);
    DisplayArray(a,size);
    DisplayArray(ra,size);

}
