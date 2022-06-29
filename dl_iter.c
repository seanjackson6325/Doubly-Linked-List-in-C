/****************************************************************
*
* Author: Sean Jackson
* Description: Source file for iterator struct and functions
* Last Modified: 03/19/22
*
****************************************************************/

#include "dl_iter.h"

/////////////////////////////////////////////////////////////////

// start DL_Iter at front of list
void DL_Iter__Start(DL_List* list, DL_Iter* iter)
{
	iter->current = list->head;
}

// check if DL_Iter is at end of list
bool DL_Iter__HasNext(DL_Iter* iter)
{
	return (iter->current != NULL);
}

// move pointer to next element
bool DL_Iter__ToNext(DL_Iter* iter)
{
	iter->current = iter->current->next;
}

// move point to previous element
bool DL_Iter__ToPrev(DL_Iter* iter)
{
	iter->current = iter->current->prev;
}

// get element from DL_list (returns a void*)
void* DL_Iter__Get(DL_Iter* iter)
{
	return iter->current->val;
}

/////////////////////////////////////////////////////////////////