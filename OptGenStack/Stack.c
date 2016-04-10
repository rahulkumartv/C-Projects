//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#include "Stack.h"
#include <stdlib.h>
#include "status.h"

//static Stack  available = 0;
//static int counter =0;
/*static void cleanUp(){
    Stack tmp = available;
    while(tmp)
    {
        available = tmp->next;
        free(tmp);
        tmp =available;
    }

}*/

Stack* createStack( int elemSize )
{
    Stack* res = (Stack*)malloc(sizeof(Stack));
    if(!res) return 0;
    res->head =0;
    res->elemSize =elemSize;
    //only changes for reserving memory
    res->available=0;
    ///counter++;
    return res;
}
status top( Stack* s,void* e)
{
    if(!s->head)
    {
        return ERREMPTY;
    }
    memcpy(e,s->head->value,s->elemSize);
    return OK;
}
status pop( Stack* s)
{
    Box* tmp;
    if(!s->head)
    {
        return ERREMPTY;
    }
    //tmp = s->head->next;
    //free(s->head);
   // s->head =  tmp;
    tmp = s->head;
    s->head = s->head->next;
    tmp->next=s->available;
    s->available = tmp;
    return OK;
}
status push( Stack* s, void* e) {
    Box* tmp;
    if(s->available)
    {
        tmp = s->available;
        s->available = s->available->next;
    }
    else
    {
        tmp = (Box*) malloc(sizeof(Box) + s->elemSize - 1);
    }
    if (!tmp)
    {
        return ERRALLOC;
    }
    memcpy(tmp->value,e,s->elemSize);
    tmp->next = s->head;
    s->head = tmp;
    return OK;
}
int isEmpty( Stack* s)
{
    return ( !s->head );
}
void destroyStack( Stack* s)
{
    while(s->head)
    {
        Box* tmp = s->head->next;
        free(s->head);
        s->head = tmp;
    }
    while(s->available)
    {
        Box* tmp = s->available;
        free(s->available);
        s->available = tmp;
    }
    free(s);
}