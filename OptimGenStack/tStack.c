//
// Created by Rahul Thai Valappil on 3/24/2016.
//

#include <stdio.h>
#include "Stack.h"

int main()
{
    int i1=1,i2=2;
    Stack* s= createStack();
    if(!s)
        return 1;
    status res= push(s,&i1);
    if(res)
    {
        fprintf(stderr,"%s\n",errorMessage(res));
        return 2;
    }
    res = push(s,&i2);
    if(res)
    {
        fprintf(stderr,"%s\n",errorMessage(res));
        return 2;
    }

    while(!(isEmpty(s)))
    {
        int* e;
        res = top(s,(void*) &e );
        if(res)
        {
            fprintf(stderr,"%s\n",errorMessage(res));
        }
        else
        {
            printf("%d\n",*e);
        }
        res = pop(s);
        if(res)
        {
            fprintf(stderr,"%s\n",errorMessage(res));
        }
    }
    destroyStack(s);
    return 0;
}
