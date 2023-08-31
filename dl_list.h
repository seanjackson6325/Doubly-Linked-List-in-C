/****************************************************************
*
* Author: Sean Jackson
* Description: Header file for list and node structs and functions
* Last Modified: 03/19/22
*
****************************************************************/

#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/////////////////////////////////////////////////////////////////

typedef struct DL_Node
{
	struct DL_Node *prev, *next;
	void* val;
} DL_Node;

typedef struct
{
	DL_Node *head, *tail;
	size_t length;
} DL_List;

/////////////////////////////////////////////////////////////////


// Initialize a new DL_List
void DL_List__Init(DL_List* list);


// Add a value at position i in the list
bool DL_List__Add(DL_List* list, void* val, int i);


// Remove a node at position i
// The value of the node is returned
void* DL_List__Remove(DL_List* list, int i);


// Add a new node to the head of the list
bool DL_List__AddToHead(DL_List* list, void* val);


// Remove the first node (head) from the list
// The value of the removed node is returned
void* DL_List__RemoveFromHead(DL_List* list);


// Add a new node to the tail of the list
bool DL_List__AddToTail(DL_List* list, void* val);


// Remove a node from the end (tail) of the list
// The value of the removed node is returned
void* DL_List__RemoveFromTail(DL_List* list);

#endif // DLL_H

/////////////////////////////////////////////////////////////////