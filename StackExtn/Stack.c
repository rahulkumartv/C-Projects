//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#include "Stack.h"
#include <stdlib.h>

Stack* createStack( )
{
    Stack* res = (Stack*)malloc(sizeof(Stack));
    *res =0;
    return res;
}
int top( Stack* s)
{
    return (*s)->elt;
}
void pop( Stack* s)
{
    Stack tmp = (*s)->next;
    free(*s);
    *s= tmp;
}
void push( Stack* s, int e)
{
    Stack* tmp = (Stack*)malloc(sizeof(Stack));
    tmp = *s;
    *s = (Stack)malloc(sizeof(Box));
    (*s)->elt =e;
    (*s)->next = tmp;
}
int isEmpty( Stack* s)
{
    return (*s) == 0;
}
void destroyStack( Stack* s)
{
    free(s);
}
