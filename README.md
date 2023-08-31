# Doubly-Linked-List-in-C
An efficient doubly linked list structure for C/C++. Features include:
- Efficient adding and removing
- The ability to traverse from the head or tail of the list
- Iterator structure that can be used for efficient traversing (and adding and removing in constant time complexity).

## Header Files:

#### dl_list.h

- Include this to get access to DL_List data type and functions

#### dl_iter.h

- Include this to get access to DL_Iter data type and functions

## Data types:

#### DL_List

- Acts as the main structure for the doubly linked list. Variables should not be accessed directly.


#### DL_Iter

- Acts as an iterator for the linked list.

#### DL_Node

- A structure for the nodes in the doubly linked list. Users should not interact with the nodes directly, but instead by using the provided functions.

## Constants:

#### DL_ITER_HEAD

- Used to start an iterator at the head of the list

#### DL_ITER_HEAD

- Used to start an iterator at the tail of the list

## Functions for DL_List:

#### void DL_List__Init(DL_List* list);

- Initialize a new DL_List


#### bool DL_List__Add(DL_List* list, void* val, int i);
- Add a value at position i in the list


#### void* DL_List__Remove(DL_List* list, int i);
- Remove a node at position i
- The value of the node is returned


#### bool DL_List__AddToHead(DL_List* list, void* val);
- Add a new node to the head of the list


#### void* DL_List__RemoveFromHead(DL_List* list);
- Remove the first node (head) from the list
- The value of the removed node is returned


#### bool DL_List__AddToTail(DL_List* list, void* val);
- Add a new node to the tail of the list


#### void* DL_List__RemoveFromTail(DL_List* list);
- Remove a node from the end (tail) of the list
- The value of the removed node is returned

## Functions for DL_Iter:

#### void DL_Iter__Init(DL_Iter* iter, DL_List* list, bool start);
- Initialize a list iterator


#### void DL_Iter__Next(DL_Iter*);
- Move iterator to next node


#### void DL_Iter__Prev(DL_Iter*);
- Move iterator to previous node


#### void DL_Iter__ToHead(DL_Iter*);
- Move iterator to head of list


#### void DL_Iter__ToTail(DL_Iter*);
- Move iterator to tail of list


#### bool DL_Iter__HasNext(DL_Iter*);
- Check if node after current position exists


#### bool DL_Iter__HasPrev(DL_Iter*);
- Check if node before current position exists


#### void* DL_Iter__Add(DL_Iter*, void* val);
- Add a value at the position of the iterator


#### void* DL_Iter__Remove(DL_Iter*);
- Remove a value at the position of the iterator


#### void* DL_Iter__GetVal(DL_Iter*);
- Return the value at the position of the iterator


#### int DL_Iter__GetIndex(DL_Iter*);
- Get the current index of the iterator

## Examples:

    #include "dl_list.h"
    #include "dl_iter.h"
    #include <stdio.h>
    
    int main()
    {
    	// create an array of 10 numbers to add to list
    	int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    	int nums_len = 10;
    
    	// new doubly linked list
    	DL_List list;
    	// initialize list
    	DL_List__Init(&list);
    
    	// loop through array, add each to end of linked list
    	for (int i = 0; i < nums_len; i++)
    	{
    		DL_List__AddToTail(&list, &nums[i]);
    	}
    
    	// create a new iterator
    	DL_Iter iter;
    	// initialize the iterator to start at head of linked list
    	DL_Iter__Init(&iter, &list, DL_ITER_HEAD);
    
    	// use iterator to iterate through list
    	// print out each value
    	while (DL_Iter__HasNext(&iter))
    	{
    		int* val = (int*) DL_Iter__GetVal(&iter);
    		printf("%d\n", *val);
    		DL_Iter__Next(&iter);
    	}
    
    	// set iterator back to head of list
    	DL_Iter__ToHead(&iter);
    
    	// add another value at the beginning of list
    	DL_Iter__Add(&iter, &nums[0]);
    	// move iterator ahead two places in list
    	DL_Iter__Next(&iter);
    	DL_Iter__Next(&iter);
    	// add a new value at the iterator position
    	DL_Iter__Add(&iter, &nums[1]);
    
    	// set iterator to tail of linked list
    	DL_Iter__ToTail(&iter);
    
    	printf("\n\n");
    
    	// use iterator to iterate backwards through list
    	// print out each value
    	while (DL_Iter__HasPrev(&iter))
    	{
    		int* val = (int*)DL_Iter__GetVal(&iter);
    		printf("%d\n", *val);
    		DL_Iter__Prev(&iter);
    	}
    }
