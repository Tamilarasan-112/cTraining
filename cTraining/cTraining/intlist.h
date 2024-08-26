#include <stdbool.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H 
#define LIST_DELETED -1011;
#define EMPTY_LIST -1012;
#define INDEX_OUTOF_RANGE -1013;
#define MEMORY_ALLOCATION_FAILED -1014;
#define NOT_FOUND -1015;
#define LIST_NOT_CREATED -1016;
struct node {
	int data;
	struct node* nextPtr;
};

//create node structure 
struct linkedlist {
	struct node* head;//nested structure
	bool del;
	int count;
};

typedef struct linkedlist LinkedList;
typedef struct node Node;

/// <summary>Create – this function will create a new linked list.</summary>
LinkedList* Create ();

/// <summary>Add - Adds an item to end of the list. this function add the elements in list at end, by using the pointer .if the head is null,store the new node pointer in head pointer,otherwise go through the list get the last node and next pointer, store the new node next pointer</summary>
int Add (LinkedList* head, int num);

/// <summary>Insert – this will insert an element at a particular index (zero based).this function insert node at index.in this function go through the list and get previous node next pointer for give index node,which is pointer to the new node and also it's stored the index position next node data in the list ,so new node next pointer store the the previous node next pointer and the previous node next pointer store the new node.</summary>
int Insert (LinkedList* head, int index, int num);

/// <summary>RemoveAt – this will remove the element at a particular index (zero based).this function remove the node at the index, same as insert at function, but in this function we need previous and index node,because index node which store the next node pointer and this pointer must be store in previous node next pointer.</summary>
int RemoveAt (LinkedList* head, int index);

/// <summary>Remove – removes the first occurrence of a specific element.this function remove the first occurrence of a given Element by compare the give element with each elements in list ,find element node and also it's get the previous node.then it's store the element node next pointer in previous node next pointer.</summary>
int Remove (LinkedList* head, int num);

/// <summary>Count – number of elements in the list.</summary>
int Count (LinkedList* head);

/// <summary>Get – gets the element at a particular index position from header pointer Element to index.</summary>
int Get (LinkedList* head, int index, int* value);

/// <summary>Delete – this will delete the list and all the linked elements.</summary>
int Delete (LinkedList* head);

#endif LINKEDLIST_H 