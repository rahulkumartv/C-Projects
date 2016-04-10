//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#include "Stack.h"
#include <stdlib.h>
#include "status.h"


Stack* createStack( )
{
    Stack* res = (Stack*)malloc(sizeof(Stack));
    if(!res) return 0;
    *res =0;
    return res;
}
status top( Stack* s,void** e)
{
    if(!s)
    {
        return ERREMPTY;
    }
    *e = (*s)->elt;
    if( !e)
    {
        return ERREMPTY;
    }
    return OK;
}
status pop( Stack* s)
{
    if(!s)
    {
        return ERREMPTY;
    }
    Stack tmp = *s;
    *s= tmp->next;
    free(tmp);
    return OK;
}
status push( Stack* s, void* e)
{
    Stack tmp = (Stack)malloc(sizeof(Box));
    if(!tmp)
    {
        return ERRALLOC;
    }
    tmp->elt = e;
    tmp->next =*s;
    *s = tmp;
    return OK;
}
int isEmpty( Stack* s)
{
    return (*s) == 0;
}
void destroyStack( Stack* s)
{
    while(*s)
    {
        Stack* tmp = *s;
        free(*s);
        *s = tmp;
    }
    free(s);
}
