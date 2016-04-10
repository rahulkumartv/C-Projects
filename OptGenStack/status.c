//
// Created by Rahul Thai Valappil on 3/25/2016.
//
#include "status.h"

static char* Message[]={
   "",
   "memory allocation failed",
   "unable to open the file",
   "unable to close the file",
   "empty",
   "full",
   "unknown error"
} ;
char* errorMessage(status s)
{
    if( s<0 || s>= ERRUNKNOWN)
    {
        return Message[ERRUNKNOWN];
    }
    return Message[s];
}
