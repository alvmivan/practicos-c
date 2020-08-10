#include "List.h"
#include "Constants.h"
#include <stdlib.h>

#ifndef LIST_H
#define LIST_H


// linkea a como anterior de b y b como siguiente de a
void link(Node * a, Node * b)
{
    a->next = b;
    b->prev = a;
}


Node * first(List * list)
{
    // si tiene 0 elementos largar error
    return list->first->next;
}

Node * last(List * list)
{
    // si tiene 0 elementos largar error
    return list->last->prev;
}

Node * createNode(T element)
{
    Node * node = malloc(sizeof(Node));
    node->element = element;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

List * newList()
{
    List * list = malloc(sizeof(List));
    list->first = createNode(NULL);
    list->last = createNode(NULL);
    link(list->first, list->last);
    list->count = 0;
    return list;    
}

Node * addFirst(List* list, T element)
{
    Node * node = createNode(element);
    Node * prev = list->first;
    Node * next = list->first->next;
    link(prev,node);
    link(node, next);
    list->count++;
    return node;
}

Node * addLast(List* list, T element)
{
    Node * node = createNode(element);
    Node * prev = list->last->prev;
    Node * next = list->last;
    link(prev,node);
    link(node, next);
    list->count++;
    return node;
}

Node * getNode(List * list, T element)
{
    Node * current = list->first;
    while(current != NULL && current->element != element)
    {
        current = current->next;
    }
    return current;
}



void removeNode(List * list, Node * node)
{
    link(node->prev, node->next);
    free(node);
    list->count--;
}

void disposeList(List * list)
{
    free(list);
}

void foreach(List * list, void funcpointer(T))
{
    Node * current = list->first->next;
    while(current != list->last)
    {
        (*funcpointer)(current->element);
        current = current->next;
    }
}



#endif