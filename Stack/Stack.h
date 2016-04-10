//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef struct
{
    int* elts;
    int capacity;
    int top;
} Stack;

Stack* createStack( int capacity);
int top( Stack* s);
void pop( Stack* s);
void push( Stack* s, int e);
int isEmpty( Stack* s);
void destroyStack( Stack** s);

#endif //STACK_STACK_H
