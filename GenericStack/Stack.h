//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "status.h"
typedef struct Box
{
    void* elt;
    struct Box* next;
} Box,*Stack;

Stack* createStack( );
status top( Stack* s,void** e);
status pop( Stack* s);
status push( Stack* s, void* e);
int isEmpty( Stack* s);
void destroyStack( Stack* s);

#endif //STACK_STACK_H
