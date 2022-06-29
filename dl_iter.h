/****************************************************************
*
* Author: Sean Jackson
* Description: Source file for iterator struct and functions
* Last Modified: 03/19/22
*
****************************************************************/

#pragma once
#include "dl_list.h"
#include "stdbool.h"

/////////////////////////////////////////////////////////////////

typedef struct
{
	DL_Node* current;
} DL_Iter;

/////////////////////////////////////////////////////////////////

// start DL_Iter at front of list
void DL_Iter__Start(DL_List* list, DL_Iter* iter);
// check if DL_Iter is at end of list
bool DL_Iter__HasNext(DL_Iter* iter);
// move pointer to next element
bool DL_Iter__ToNext(DL_Iter* iter);
// move point to previous element
bool DL_Iter__ToPrev(DL_Iter* iter);
// get element from DL_list (returns a void*)
void* DL_Iter__Get(DL_Iter* iter);

/////////////////////////////////////////////////////////////////