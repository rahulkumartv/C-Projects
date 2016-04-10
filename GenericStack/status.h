//
// Created by Rahul Thai Valappil on 3/25/2016.
//

#ifndef GENERICSTACK_STATUS_H
#define GENERICSTACK_STATUS_H
typedef enum
{
    OK,
    ERRALLOC,
    ERROPEN,
    ERRCLOSE,
    ERREMPTY,
    ERRFULL,
    ERRUNKNOWN
}status;
char* errorMessage(status s);
#endif //GENERICSTACK_STATUS_H
