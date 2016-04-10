/********************************************************************
 *
 * status.h 2016-04-01 Rahul Thai Valappil
 *
 ********************************************************************
 */
/**
 * Minimal system for error handling.
 *
 * Each value of the "status" enum is associated with an error message.
 * Every function (but some of those returning pointers) should return a
 * status.
 *
 ********************************************************************/

#ifndef __STATUS_H
#define __STATUS_H

typedef enum {
    OK,
    ERROPEN,
    ERRACCESS,
    ERRCLOSE,
    ERRALLOC,
    ERRDATE,
    ERRFULL,
    ERREMPTY,
    ERRABSENT,
    ERREXIST,
    ERRINDEX,
    ERRUNABLE,
    ERRCITYNOTFOUND,
    ERRARGLESS,
    ERRARGMORE,
    ERRMAPFILEFAILED,

    ERRUNKNOWN,
} status;

/** get message associated with the given status value (O(1)).
 * @param s the status value
 * @return the associated message
 */
extern char* message( status );

#endif
