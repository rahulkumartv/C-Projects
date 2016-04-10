//
// List.c 2016-04-01 Rahul Thai Valappil
//
#include "List.h"

List*	newList	(compFun cmpfn ,prFun dspfn)
{
    List* res = (List*)malloc(sizeof(List));
    res->head = 0;
    res->comp = cmpfn;
    res->head = 0;
    res->nelts = 0;
    res->pr = dspfn;
    return res;
}

void 	delList	(List* list)
{
    while( list->head)
    {
        Node* tmp = list->head->next;
        free(list->head);
        list->head = tmp;
    }
    free(list->comp);
    free(list->pr);
    free(list);
}

status 	nthInList	(List* list,int nidex,void** elem)
{
    /* Node *node = list->head;
    int pos;
    for ( pos = 0; pos < nidex && node; ++pos) {
        node = node->next;
    }
    if(node) {
        *elem = node->val;
        return OK;
    }
    else {
        return ERRINDEX;
    }*/

    if( nidex< 1 || nidex>list->nelts)
    {
        return ERRINDEX;
    }
    Node* node = list->head;
    int ndx =1;
    while(node)
    {
        if( ndx == nidex )
        {
            elem = node->val;
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

status 	addListAt	(List* list,int index ,void* elem)
{
    if( index< 1 || index>list->nelts)
    {
        return ERRINDEX;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = elem;
    newnode->next=0;
    if(!newnode)
    {
        return ERRALLOC;
    }
    if( index == 1 && list->head == 0)
    {
        list->head = newnode;
    }
    else{
        Node* node = list->head;
        Node* prevnode = list->head;
        int ndx =1;
        while(node)
        {
            if( ndx == index)
            {

                if( index == 1)
                {
                    newnode->next = list->head;
                    list->head = newnode;
                }
                else
                {

                    newnode->next = node;
                    node->next = newnode;
                }

                list->nelts++;
                break;
            }
            prevnode = node;
            node = node->next;
            ndx++;
        }
    }
    return OK;

}

status 	remFromListAt	(List* list,int index,void** out)
{
    /*Node *node = list->head;
   int pos;
   for ( pos = 0; pos < index && node ; ++pos) {
       node = node->next;
   }
   if(node) {
       *out = node->val;
       Node* tmpNode = node->next;
       free(node);
       node->next = tmpNode;
       --list->nelts;
   }
   else {
       return ERRINDEX;
   }
   return OK;*/
    if( index< 1 || index>list->nelts)
    {
        return ERRINDEX;
    }
    Node* node = list->head;
    Node* prevnode = list->head;
    int ndx =1;
    while(node)
    {
        if( ndx == index)
        {

            if( index == 1)
            {
                list->head = node->next;

            }
            else
            {

                prevnode->next =  node->next;

            }
            out = node->val;
            free(node);
            list->nelts--;
            break;
        }
        prevnode = node;
        node = node->next;
        ndx++;
    }
}

status 	remFromList	(List* list,void* elem)
{
    /* if(!list->comp)
        return ERRUNABLE;

    Node *node = list->head;
    while(node)
    {
        if( list->comp(elem, node->val) == 0 ) {
            Node* tmpNode = node->next;
            free(node);
            node->next = tmpNode;
            --list->nelts;
            return OK;
        }
        node = node->next;
    }
    return ERRABSENT;*/
    if( !(list->comp) )
    {
        return ERRUNABLE;
    }

    Node* node = list->head;
    Node* prevnode = list->head;
    status res = ERRABSENT;
    while(node)
    {
        if(list->comp(node->val,elem) == 0 )
        {
            res = OK;
            if( list->head == node)
            {
                list->head = node->next;

            }
            else
            {

                prevnode->next =  node->next;

            }
            free(node);
            list->nelts--;
            break;
        }
        prevnode = node;
        node = node->next;
    }
    return res;
}

status 	displayList	(List* list)
{
    if( !(list->pr) )
    {
        return ERRUNABLE;
    }
    Node* node = list->head;
    while(node)
    {
        list->pr(node->val);
        node =  node->next;
    }
    return OK;

}

/*void	forEach		(List* list , (void(*)(void*)) func)
{

}*/

int	lengthList	(List* list){

    return list->nelts;
}

status	addList	(List* list,void* elem)
{
    if( !(list->comp) )
    {
        return ERRUNABLE;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = elem;
    newnode->next=0;
    if(!newnode)
    {
        return ERRALLOC;
    }
    Node* node = list->head;
    Node* prevnode = list->head;
    while(node)
    {
        int ncomp =  list->comp(node->val,elem);
        if( ncomp <=0)
        {

                if( list->head == node)
                {
                    newnode->next = list->head;
                    list->head = newnode;
                }
                else
                {

                    newnode->next = node;
                    node->next = newnode;
                }

                list->nelts++;
                break;
        }
        else
        {
            newnode->next = node->next;
            node=newnode;
        }
        prevnode = node;
        node = node->next;
    }
    return OK;
}

Node*	isInList	(List* list,void* elem)
{
    Node* node = list->head;
    Node* prevnode = list->head;
    Node* res = 0;
    while(node)
    {
        if(list->comp(node->val,elem) == 0 )
        {
            if( list->head == node )
            {
                res = (Node*)1;
            }
            else
            {
                res= prevnode;

            }
            break;
        }
        prevnode = node;
        node = node->next;
    }
    return res;
}
