/********************************************************************
 *
 * status.c 2016-04-01 Rahul Thai Valappil
 *
 ********************************************************************/
/**
 * Minimal system for error handling.
 *
 * Each value of the "status" enum is associated with an error message.
 * Every function (but some of those returning pointers) should return a
 * status.
 *
 ********************************************************************/

#include "status.h"

/** default error message for unknown errors */
static char* unknownError = "Unknown error";

/** defined error messages */
static char* msg[] = {
        "",
        "File open failed",
        "Access refused",
        "File close failed",
        "Memory allocation failed",
        "Wrong date",
        "Full structure",
        "Empty structure",
        "Value not found",
        "Value already exists",
        "index out of bounds",
        "unable to perform operation",
        "searched city is not found",
        "The arguments supplied less than expected",
        "Too many arguments supplied more than expected",
        "Unable to read the Map file",

        "unknown error"
};

/** get message associated with the given status value.
 *  @param st the status value
 *  @return the associated message
 */
char* message( status st ) {
    return ( st < 0 || st >= ERRUNKNOWN ) ? msg[ERRUNKNOWN] : msg[st];
}
