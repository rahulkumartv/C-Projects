//
// List.c 2016-04-01 Rahul Thai Valappil
//

#include "List.h"

List* newList ( compFun cmpfn , prFun dspfn )
{
    List* res = (List*)malloc(sizeof(List));
    res->head = 0;
    res->comp = cmpfn;
    res->nelts = 0;
    res->pr = dspfn;
    return res;
}

void delList ( List* list )
{
    while( list->head )
    {
        Node* tmp = list->head->next;
        free( list->head );
        list->head = tmp;
    }
    list->nelts = 0;
    list->head = 0;
    free(list);
}

status nthInList( List* list, int nidex, void** elem )
{

    if( nidex< 1 || nidex>list->nelts )
    {
        return ERRINDEX;
    }
    Node* node = list->head;
    int ndx =1;
    while( node )
    {
        if( ndx == nidex )
        {
            *elem = node->val;
            break;
        }
        else
        {
            node = node->next;
            ndx++;
        }

    }
    return OK;
}

status addListAt( List* list, int index , void* elem )
{
    //Node *node = list->head;
    Node* prevNode = list->head;
    Node *newNode = ( Node* )malloc( sizeof( Node ));
    if( !newNode ) {
        return ERRALLOC;
    }
    newNode->val = elem;
    newNode->next = 0;

    if( index == 1 || list->head == 0 )
    {
        newNode->next = list->head;
        list->head = newNode;
        ++list->nelts;
        return OK;

    }
    int pos;
    for ( pos = 1; pos < index -1; ++pos ) {
        prevNode = prevNode->next;
    }
    if( prevNode )
    {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        ++list->nelts;

    }
    else {
        return ERRINDEX;
    }
    return OK;
}

status remFromListAt( List* list, int index, void** out )
{

    if( index< 1 || index > list->nelts )
    {
        return ERRINDEX;
    }
    Node* node = list->head;
    Node* prevnode = list->head;
    int ndx =1;
    while( node )
    {
        if( ndx == index )
        {

            if( index == 1 )
            {
                list->head = node->next;

            }
            else
            {

                prevnode->next =  node->next;

            }
            *out = node->val;
            free( node );
            list->nelts--;
            break;
        }
        prevnode = node;
        node = node->next;
        ndx++;
    }
    return OK;
}

status remFromList( List* list, void* elem )
{
    if( !(list->comp ) )
    {
        return ERRUNABLE;
    }

    Node* node = list->head;
    Node* prevnode = list->head;
    status res = ERRABSENT;
    while( node )
    {
        if( list->comp( node->val, elem ) == 0 )
        {
            res = OK;
            if( list->head == node )
            {
                list->head = node->next;

            }
            else
            {

                prevnode->next =  node->next;

            }
            free( node );
            list->nelts--;
            break;
        }
        prevnode = node;
        node = node->next;
    }
    return res;
}

status displayList( List* list )
{
    if( !( list->pr ) )
    {
        return ERRUNABLE;
    }
    Node* node = list->head;
    while( node )
    {
        list->pr( node->val );
        node =  node->next;
    }
    return OK;

}

void forEach( List *list, void ( *pFun )( void* ))
{
    Node* node;
    for ( node= list->head; node; node = node->next ) {
        pFun( node->val );
    }
}

int lengthList( List* list ){

    int length = 0;
    Node* node;
    for ( node = list->head; node; node = node->next ) {
        length++;
    }
    return length;
}

status addList( List* list, void* elem )
{
    if( !( list->comp ) )
    {
        return ERRUNABLE;
    }
    Node* newnode = ( Node* )malloc( sizeof( Node ));

    if( !newnode )
    {
        return ERRALLOC;
    }
    newnode->val = elem;
    newnode->next=0;
    list->nelts++;
    if( !list->head )
    {
        list->head = newnode;
        return OK;
    }
    Node* node = list->head;

    while( node->next ) {
        if( list->comp( elem, node->next->val ) <= 0 )
        {
            // Add in between
            Node *tmpNode = node->next;
            node->next = newnode;
            newnode->next = tmpNode;
            return OK;
        }
        node = node->next;
    }
    node->next = newnode;
    return OK;
}

Node* isInList( List* list, void* elem )
{
    Node *res = list->head;
    // element is at the head of the list
    if( list->comp( elem, res->val ) == 0 ) {
        res = ( Node* )1;
        return res;
    }

    while( res->next ){
        if( list->comp( res->next->val, elem ) == 0 ) {
            return res;
        }
        res = res->next;
    }
    return 0;
}
