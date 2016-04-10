//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#include <stdio.h>
#include "Stack.h"

int main()
{
    int i;
    Stack* s= createStack();
    if(isEmpty(s)) puts("Empty");
    for ( i = 0; i <6 ; ++i) {
        push(s,i);
        printf("%d\n",top(s));
    }

   while(!isEmpty(s)){
        printf("%d\n",top(s));
        pop(s);
    }
    destroyStack( s);
    return 0;
}