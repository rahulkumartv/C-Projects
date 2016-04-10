//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#include "Stack.h"
#include <stdlib.h>

Stack* createStack( int capacity)
{
    Stack* res = (Stack*)malloc(sizeof(Stack));
    res->elts = (int*)malloc(sizeof(int));
    res->capacity = 0;
    res->top = -1;
    return res;
}
int top( Stack* s)
{
    return s->elts[s->top];
}
void pop( Stack* s)
{
    s->top--;
}
void push( Stack* s, int e)
{
    s->elts[++(s->top)] = e;
}
int isEmpty( Stack* s)
{
    return s->top == -1;
}
void destroyStack( Stack** s)
{
    free( (*s)->elts);
    free(s);
}