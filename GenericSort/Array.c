//
// Created by Rahul Thai Valappil on 3/18/2016.
//
#include <stdio.h>
#include "Array.h"
#include <stdlib.h>
#include <time.h>

int* CreateArray( int nElmts)
{
    int* reslt = (int*)malloc(nElmts* sizeof(int));
    int nIdx;
    for ( nIdx = 0; nIdx < nElmts; ++nIdx) {
        reslt[nIdx] = 0;
    }
    return reslt;
}

int* CreateRandomArray( int nElmts)
{
    int* reslt = (int*)malloc(nElmts* sizeof(int));
    int nIdx;
    srand(time(NULL));
    for ( nIdx = 0; nIdx < nElmts; ++nIdx) {
        reslt[nIdx] = rand()/(2*nElmts);
    }
    return reslt;
}
void DisplayArray(int* a, int nElmts)
{
    printf("[ ");
    if( !a)
    {
        nElmts=0;
    }
    if( nElmts > MAXDISP )
    {
        printf("%d , %d . . . (%d) . .%d , %d ", a[0], a[1],nElmts,a[nElmts-2],a[nElmts-1]);
    }
    else
    {
        int nIdx;
        for ( nIdx = 0; nIdx < nElmts; ++nIdx) {
            printf("%d ", a[nIdx]);
        }

    }
    putchar(']');

}
void DestroyArray(int** a)
{
    free( *a);
    *a =0;
}

void GenericSort( void* a, int nElmts,int elsize, int(*compare)(void*,void*))
{
    int i,j;
    int last = nElmts*elsize;
    void* tmp = malloc(elsize);
    for ( i = 0; i < last-elsize; i+=elsize) {
        for ( j = i+elsize; j < last; j+=elsize) {
            if( compare(a+i,a +j))
            {
                memcpy(tmp,a+i,elsize);
                memcpy(a+i,a+j,elsize);
                memcpy(a+j,tmp,elsize);
            }
        }

    }
}
int compareInts( void* p1, void* p2)
{
return *(int*)p1 - *(int*)p2;
}