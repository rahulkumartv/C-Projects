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

void SimpleSort( int* a, int nElmts)
{
    int i,j;
    for ( i = 0; i < nElmts-1; i++) {
        for ( j = i+1; j < nElmts; j++) {
            if( a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }

    }
}