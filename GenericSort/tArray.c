//
// Created by Rahul Thai Valappil on 3/18/2016.
//
/*tArray.c*/
                                                                                    #include "Array.h"
#include <stdio.h>

int main( )
{
    int a[] ={1,4,2,8,5,7};
    GenericSort(a, sizeof(a)/ sizeof(int), sizeof(int),compareInts);
    DisplayArray(a,sizeof(a)/ sizeof(int));
}
