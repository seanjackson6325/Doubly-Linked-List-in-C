/****************************************************************
*
* Author: Sean Jackson
* Description: Header file for iterator struct and functions
* Last Modified: 03/19/22
*
****************************************************************/

#ifndef DLLITER_H
#define DLLITER_H

#include "dl_list.h"

/////////////////////////////////////////////////////////////////

#define DL_ITER_HEAD 0
#define DL_ITER_TAIL 1

/////////////////////////////////////////////////////////////////

typedef struct
{
	DL_List* list;
	DL_Node* current;
	int index;
} DL_Iter;

/////////////////////////////////////////////////////////////////


// Initialize a list iterator
void DL_Iter__Init(DL_Iter* iter, DL_List* list, bool start);


// Move iterator to next node
void DL_Iter__Next(DL_Iter*);


// Move iterator to previous node
void DL_Iter__Prev(DL_Iter*);


// Move iterator to head of list
void DL_Iter__ToHead(DL_Iter*);


// Move iterator to tail of list
void DL_Iter__ToTail(DL_Iter*);


// Check if node after current position exists
bool DL_Iter__HasNext(DL_Iter*);


// Check if node before current position exists
bool DL_Iter__HasPrev(DL_Iter*);


// Add a value at the position of the iterator
void* DL_Iter__Add(DL_Iter*, void* val);


// Remove a value at the position of the iterator
void* DL_Iter__Remove(DL_Iter*);


// Return the value at the position of the iterator
void* DL_Iter__GetVal(DL_Iter*);


// Get the current index of the iterator
int DL_Iter__GetIndex(DL_Iter*);

#endif // DLLITER_H

/////////////////////////////////////////////////////////////////