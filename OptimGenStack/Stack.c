//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#include "Stack.h"
#include <stdlib.h>
#include "status.h"

static Stack  available = 0;
static int counter =0;
static void cleanUp(){
    Stack tmp = available;
    while(tmp)
    {
        available = tmp->next;
        free(tmp);
        tmp =available;
    }

}

Stack* createStack( )
{
    Stack* res = (Stack*)malloc(sizeof(Stack));
    if(!res) return 0;
    *res =0;
    counter++;
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
    Stack tmp;
    if(!*s)
    {
        return ERREMPTY;
    }
    tmp = (*s)->next;
    (*s)->next =  available;
    available = *s;
    *s=tmp;
    return OK;
}
status push( Stack* s, void* e)
{
    Stack tmp;
    if(!available)
    {
        tmp = (Stack)malloc(sizeof(Box));
    }
    else
    {
        tmp = available;
        available = available->next;
    }
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
        Stack tmp = (*s)->next;
        (*s)->next = available;
        available=(*s);
        *s = tmp;
    }
    free(s);
    counter--;
    if(!counter)
    {
        cleanUp();
    }
}