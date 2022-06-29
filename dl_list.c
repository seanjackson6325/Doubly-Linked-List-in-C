/****************************************************************
*
* Author: Sean Jackson
* Description: Source file for linked list struct and functions
* Last Modified: 03/19/22
*
****************************************************************/

#include "dl_list.h"
#include "dl_iter.h"

/////////////////////////////////////////////////////////////////

// create new DL_Node on heap
DL_Node* DL_Node__Create(void* val, DL_Node* prev, DL_Node* next)
{
	DL_Node* node = malloc(sizeof(DL_Node));
	if (node != NULL)
	{
		*node = (DL_Node)
		{
			.prev = prev,
			.next = next,
			.val = val,
		};
	}
}

// destroy node
void DL_Node__Destroy(DL_Node* node, void (*destroy_val)(void*))
{
	if (node != NULL)
	{
		destroy_val(node->val);
		free(node);
	}
}

// create new DL_List on heap
DL_List* DL_List__Create()
{
	DL_List* list = malloc(sizeof(DL_List));
	if (list != NULL)
	{
		*list = (DL_List)
		{
			.head = NULL,
			.length = 0
		};
	}
	return list;
}

// destroy DL_List
// this does not destroy the values stored in the nodes
// it just destroys the memory used by the nodes themselves
void DL_List__Destroy(DL_List* list, void (*destroy_val)(void*))
{
	if (list->head != NULL)
	{
		DL_Node* node = list->head;

		while (node->next != NULL)
		{
			DL_Node* save = node->next;
			DL_Node__Destroy(node, destroy_val);
			node = save;
		}
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////

// add a DL_Node to the end of a DL_List
void DL_List__AddToEnd(DL_List* list, void* val)
{
	if (list->head == NULL)
	{
		list->head = DL_Node__Create(val, NULL, NULL);
	}
	else
	{
		DL_Node* node = list->head;

		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = DL_Node__Create(val, node, NULL);
	}
}

// remove node from end of list
// returns value of end of list if list isn't empty
// returns NULL if list is empty
void DL_List__RemoveFromEnd(DL_List* list, void* val, void (*destroy_type)(void*))
{
	if (list->head != NULL)
	{
		DL_Node* node = list->head;

		while (node->next != NULL)
		{
			node = node->next;
		}
		node->prev->next = NULL;
		DL_Node__Destroy(val, destroy_type);
	}
}

// add a DL_Node to the front of a DL_List
void DL_List__AddToFront(DL_List* list, void* val)
{
	if (list->head == NULL)
	{
		list->head = DL_Node__Create(val, NULL, NULL);
	}
	else
	{
		DL_Node* node = DL_Node__Create(val, NULL, list->head);
		list->head->prev = node;
		list->head = node;
	}
}

// remove node from front of list
// returns value of head of list if list isn't empty
// returns NULL if list is empty
void DL_List__RemoveFromFront(DL_List* list, void* val, void (*destroy_type)(void*))
{
	if (list->head != NULL)
	{
		DL_Node* head = list->head;
		list->head = list->head->next;
		list->head->prev = NULL;
		DL_Node__Destroy(head, destroy_type);
	}
}

/////////////////////////////////////////////////////////////////

// get the current size of the list
size_t DL_List__Length(DL_List* list)
{
	return list->length;
}

/////////////////////////////////////////////////////////////////

void merge(int* arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int* L = malloc_type(int, n1);
	int* R = malloc_type(int, n2);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void DL_List__MergeSort(DL_List* list)
{

}

/////////////////////////////////////////////////////////////////