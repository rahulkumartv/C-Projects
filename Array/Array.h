//
// Created by Rahul Thai Valappil on 3/18/2016.
//

#ifndef PROJECTS_ARRAY_H
#define PROJECTS_ARRAY_H
#define MAXDISP 100

int* CreateArray( int nElmts);
int* CreateRandomArray( int nElmts);
void DestroyArray(int** a);
void DisplayArray(int* a, int nElmts);
void SimpleSort( int* a, int nElmts);
#endif //PROJECTS_ARRAY_H
