/****************************************************************
*
* Author: Sean Jackson
* Description: Source file for iterator struct and functions
* Last Modified: 03/19/22
*
****************************************************************/

#include "dl_iter.h"

/////////////////////////////////////////////////////////////////


// Initialize a list iterator
void DL_Iter__Init(DL_Iter* iter, DL_List* list, bool start)
{
	iter->index = 0;
	iter->current = start ? list->tail : list->head;
	iter->list = list;
}


// Move iterator to next node
// If the iterator is at the very end of the list, nothing happens
void DL_Iter__Next(DL_Iter* iter)
{
	if (iter->current)
	{
		iter->current = iter->current->next;
		iter->index++;
	}
}


// Move iterator to previous node
void DL_Iter__Prev(DL_Iter* iter)
{
	if (iter->current)
		iter->current = iter->current->prev;
	iter->index--;
}


// Move iterator to head of list
void DL_Iter__ToHead(DL_Iter* iter)
{
	iter->current = iter->list->head;
	iter->index = 0;
}


// Move iterator to tail of list
void DL_Iter__ToTail(DL_Iter* iter)
{
	iter->current = iter->list->tail;
	if (iter->list->length)
		iter->index = iter->list->length - 1;
}


// Check if node after current position exists
bool DL_Iter__HasNext(DL_Iter* iter)
{
	if (iter->current)
		return iter->current;
	return false;
}


// Check if node before current position exists
bool DL_Iter__HasPrev(DL_Iter* iter)
{
	if (iter->current)
		return iter->current->prev->prev;
}


// Add a value at the position of the iterator
void* DL_Iter__Add(DL_Iter* iter, void* val)
{
	if (iter->index == 0)
		return DL_List__AddToHead(iter->list, val);
	if (iter->index == iter->list->length)
		return DL_List__AddToTail(iter->list, val);

	DL_Node* node = malloc(sizeof(DL_Node));
	if (node)
	{
		node->val = val;

		node->next = iter->current;
		node->prev = iter->current->prev;
		iter->current->prev->next = node;
		iter->current->prev = node;
		iter->current = node;

		iter->list->length++;
		return true;
	}
	return false;
}


// Remove a value at the position of the iterator
void* DL_Iter__Remove(DL_Iter* iter)
{

}


// Return the value at the position of the iterator
void* DL_Iter__GetVal(DL_Iter* iter)
{
	if (iter->current)
		return iter->current->val;
	else if (iter->index == iter->list->length)
	return NULL;
}


// Get the current index of the iterator
int DL_Iter__GetIndex(DL_Iter* iter)
{
	return iter->index;
}

/////////////////////////////////////////////////////////////////