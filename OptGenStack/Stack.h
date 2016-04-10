//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "status.h"
typedef struct Box
{
    char value[1];
    struct Box* next;
} Box;
/*typedef struct
{
    int elemSize;
    struct Box* head;
}Stack;
*/
//chnage as to hiold avaialable memory motre generic way
typedef struct
{
    int elemSize;
    struct Box* available,*head;
}Stack;

Stack* createStack( int elemSize );
status top( Stack* s,void* e);
status pop( Stack* s);
status push( Stack* s, void* e);
int isEmpty( Stack* s);
void destroyStack( Stack* s);

#endif //STACK_STACK_H
