/********************************************************************
 *
 * List.h 2016-04-01 Rahul Thai Valappil
 *
 ********************************************************************
 */
/**
 *
 * Creation of a generic (simply linked) List structure.
 *
 * To create a list, one must provide two functions (one function to
 * compare / order elements, one function to display them). Unlike arrays,
 * indices begins with 1.
 *
 ********************************************************************/

#ifndef __List_H
#define __List_H

#include <stdlib.h>
#include "status.h"

/** Typical simple link structure: a Node is a "value / next" pair */
typedef struct Node {
    void		*val;
    struct Node	*next;
} Node;

/** Comparison function for list elements.
 *  Must follow the "strcmp" convention: result is negative if first is less
 *  than second, null if both are equal, and positive otherwise.
 */
typedef int ( *compFun ) ( void* , void* );

/** Display function for list elements */
typedef void( *prFun ) ( void* );

/** The list embeds a counter for its size and the two function pointers */
typedef struct List {
    int nelts;
    Node * head;
    compFun comp;
    prFun pr;
} List;


/** Empty List creation by dynamic memory allocation.
 *  @param(1) comparison function between elements
 *  @param(2) function for list elements
 *  @return a new (empty) list if memory allocation OK
 *  @return 0 otherwise
 */
List* newList( compFun, prFun );

/** destroy the list by deallocating used memory.
 *  @param(1) the list to destroy */
void delList( List* );

/** get the Nth element of the list.
 * @param(1) the list
 * @param(2) the index of the element in list
 * @param(3) (out) the searched element
 * @return OK if element found
 * @return ERRINDEX if index out of list bounds
 */
status nthInList( List*, int, void** );

/** Insert element at a given position in the list.
 *  @param(1) the list to store the element in
 *  @param(2) the position of the insertion point
 *  @param(3) the element to insert
 *  @return ERRINDEX if position is out of list bounds
 *  @return ERRALLOC if memory allocation failed
 *  @return OK otherwise
 */
status addListAt( List*, int, void* );

/** remove the element located at a given position in list.
 *  @param(1) the list to remove the element from
 *  @param(2) the position of the element to remove
 *  @param(3) (out) the removed element
 *  @return ERRINDEX if position is out of list bounds
 *  @return OK otherwise
 */
status remFromListAt( List*, int, void** );

/** remove given element from given list.
 *  user should provide a comparison function during list creation.
 *  @param(1) the list to remove the element from
 *  @param(2) the element to remove
 *  @return ERRABSENT if element is not found in list
 *  @return ERRUNABLE if no comparison function has been provided
 *  @return OK otherwise
 */
status remFromList( List*, void* );

/** display list the elements according to display function provided during list creation
 *  @param(1) the list to display.
 *  @return ERRUNABLE if no comparison function has been provided
 *  @return OK otherwise
*/
status displayList( List* );

/** sequentially call given function with each element of given list (O(NxF)).
 *  @param(1) the list
 *  @param f the function
 */
void forEach( List*, void( * )( void* ) );

/** compute and return the number of elements in given list.
 *  @param(1) the list
 *  @return the number of elements in given list
 */
int lengthList( List* );

/** add given element to given list according to comparison function.
 *  @param(1) the list (supposedly sorted according to compFun function)
 *  @param(2) the element to add
 *  @return ERRALLOC if memory allocation failed
 *  @return ERRUNABLE if no comparison function has been provided
 *  @return OK otherwise
 */
status addList( List*, void* );

/** tests whether the list contains given element.
 *  @param(1) the list
 *  @param(2) the searched element
 *  @return 0 if element is not found in list
 *  @return 1 if element is at the head of the list (no predecessor)
 *  @return (a pointer to) the predecessor of the search element otherwise
 */
Node* isInList( List*, void* );

#endif
