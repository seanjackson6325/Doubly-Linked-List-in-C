/****************************************************************
*
* Author: Sean Jackson
* Description: header file for linked list struct and functions
* Last Modified: 03/19/22
*
****************************************************************/

#pragma once
#include <stdlib.h>
#include <string.h>
#include "pc.h"

/////////////////////////////////////////////////////////////////

// struct for DL_Node
typedef struct DL_Node
{
	struct DL_Node* prev;
	struct DL_Node* next;
	void* val;
} DL_Node;

// struct for DL_List
typedef struct
{
	DL_Node* head;
	size_t length;
	void (*destroy_type)(void*);
} DL_List;

/////////////////////////////////////////////////////////////////

// create new DL_Node on heap
DL_Node* DL_Node__Create(void* val, DL_Node* prev, DL_Node* next);
// destroy DL_Node
void DL_Node__Destroy(DL_Node* node, void (*destroy_val)(void*));

// create new DL_List on heap
DL_List* DL_List__Create();
// destroy DL_List
void DL_List__Destroy(DL_List* list, void (*destroy_val)(void*));

// add a DL_Node to the end of a DL_List
void DL_List__AddToEnd(DL_List* list, void* val);

// remove node from end of list
// returns value of end of list if list isn't empty
// returns NULL if list is empty
void DL_List__RemoveFromEnd(DL_List* list, void* val, void (*destroy_type)(void*));

// add a DL_Node to the front of a DL_List
void DL_List__AddToFront(DL_List* list, void* val);

// remove node from front of list
// returns value of head of list if list isn't empty
// returns NULL if list is empty
void DL_List__RemoveFromFront(DL_List* list, void* val, void (*destroy_type)(void*));

/////////////////////////////////////////////////////////////////

// get the current size of the list
size_t DL_List__Length(DL_List* list);

/////////////////////////////////////////////////////////////////