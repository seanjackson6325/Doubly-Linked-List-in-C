/****************************************************************
*
* Author: Sean Jackson
* Description: Source file for list and node structs and functions
* Last Modified: 03/19/22
*
****************************************************************/

#include "dl_list.h"
#include <stdio.h>

/////////////////////////////////////////////////////////////////


// Initialize a new DL_List
void DL_List__Init(DL_List* list)
{
	list->head = list->tail = NULL;
	list->length = 0;
}

// Add a value at position i in the list
bool DL_List__Add(DL_List* list, void* val, int i)
{
	if (i <= 0)
		return DL_List__AddToHead(list, val);
	if (i >= list->length)
		return DL_List__AddToTail(list, val);

	DL_Node* node = malloc(sizeof(DL_Node));
	if (node)
	{
		node->val = val;

		DL_Node* current = list->head;
		while (i > 0)
		{
			current = current->next;
			i--;
		}

		node->next = current;
		node->prev = current->prev;
		current->prev->next = node;
		current->prev = node;
		
		list->length++;
		return true;
	}
	return false;
}


// Remove a node at position i
// The value of the node is returned
void* DL_List__Remove(DL_List* list, int i)
{
	if (i <= 0)
		return DL_List__RemoveFromHead(list);
	if (i >= list->length)
		return DL_List__RemoveFromTail(list);

	if (!list->length)
		return NULL;
	else
	{
		DL_Node* current = list->head;
		while (i > 0)
		{
			current = current->next;
			i--;
		}
		
		current->prev->next = current->next;
		current->next->prev = current->prev;

		void* val = current->val;
		free(current);
		list->length--;
		return val;
	}
}


// Add a new node to the head of the list
bool DL_List__AddToHead(DL_List* list, void* val)
{
	DL_Node* node = malloc(sizeof(DL_Node));
	if (node)
	{
		node->prev = NULL;
		node->next = list->head;
		node->val = val;

		if (!list->length)
			list->tail = node;
		else
		{
			list->head->prev = node;
		}
		
		list->head = node;
		list->length++;
		return true;
	}
	return false;
}


// Remove the first node (head) from the list
// The value of the removed node is returned
void* DL_List__RemoveFromHead(DL_List* list)
{
	if (!list->length)
		return NULL;
	else
	{
		DL_Node* temp = list->head;
		if (list->length == 1)
			list->tail = list->head = NULL;
		else
		{
			temp->next->prev = NULL;
			list->head = temp->next;
		}

		void* val = temp->val;
		free(temp);
		list->length--;
		return val;
	}
}


// Add a new node to the tail of the list
bool DL_List__AddToTail(DL_List* list, void* val)
{
	DL_Node* node = malloc(sizeof(DL_Node));
	if (node)
	{
		node->prev = list->tail;
		node->next = NULL;
		node->val = val;
		
		if (!list->length)
			list->head = node;
		else
			list->tail->next = node;
		
		list->tail = node;
		list->length++;
		return true;
	}
	return false;
}


// Remove a node from the end (tail) of the list
// The value of the removed node is returned
void* DL_List__RemoveFromTail(DL_List* list)
{
	if (!list->length)
		return NULL;
	else
	{
		DL_Node* temp = list->tail;
		if (list->length == 1)
			list->head = list->tail = NULL;
		else
		{
			temp->prev->next = NULL;
			list->tail = temp->prev;
		}

		void* val = temp->val;
		free(temp);
		list->length--;
		return val;
	}
}

/////////////////////////////////////////////////////////////////