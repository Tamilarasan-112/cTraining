// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - Aug 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
/*This program defined for create the new linked list and do the some of the operation such as:
			  Delete – this will delete the list and all the linked elements.
			  Add – this will add an element to the end of the list.
			  Insert – this will insert an element at a particular index (zero based). For example, if the linked list has 4 elements. Calling Insert with an index of 2 will insert the new element between that at index 1 and that at index 2.RemoveAt – this will remove the element at a particular index (zero based).
			  Remove – removes the first occurrence of a specific element.
			  Count – number of elements in the list.
			  Get – gets the element at a particular index.
*/

#include <malloc.h>
#include <stdbool.h>
#include "intlist.h"

LinkedList* Create () {
	LinkedList* pointer = (LinkedList*)malloc (sizeof (LinkedList));
	if(pointer!=NULL){
		pointer->head = NULL;
		pointer->del = false;
		pointer->count = 0;
	}
	return pointer;
}

int Add (LinkedList* list, int num) {
	if (list == NULL)return LIST_NOT_CREATED;//if there is no memory allocated and that memory address is null ,the list is not created  
	if (list->del) return LIST_DELETED;//if the list is deleted once or more times ,can't add the elements in list
	Node* newNode = (Node*)malloc (sizeof (Node)); //memory allocation for new node,it's can store data and pointer.
	if (newNode == NULL) return MEMORY_ALLOCATION_FAILED;
	newNode->data = num; //store the value in the new Node
	newNode->nextPtr = NULL; //store the new node next pointer is null ,we adding the element at last
	if (list->head == NULL) list->head = newNode;
	else {
		Node* temp = list->head;
		while (temp->nextPtr!=NULL) temp = temp->nextPtr;
		temp->nextPtr = newNode;
	}
	list->count++;
	return 0;
}

int Insert (LinkedList* list, int index, int num) {
	if (list == NULL)return LIST_NOT_CREATED;
	if (list->del) return  LIST_DELETED;	//if the list is deleted once or more times ,can't Insert the elements in list
	Node* newNode = (Node*)malloc (sizeof (Node));
	if (newNode == NULL) return MEMORY_ALLOCATION_FAILED;
	if (list->count < index || index < 0) return INDEX_OUTOF_RANGE;
	newNode->data = num;
	if (index == 0) {
		//insert at beginning
		newNode->nextPtr = list->head;
		list->head = newNode;
	} else {
		Node* prev = list->head;
		for (int i = 1; i < index; i++) prev = prev->nextPtr;
		newNode->nextPtr = prev->nextPtr;
		prev->nextPtr = newNode;
	}
	list->count++;
	return 0;
}

int RemoveAt (LinkedList* list, int index) {
	if (list == NULL)return LIST_NOT_CREATED;
	if (list->del) return  LIST_DELETED;
	if (list->head == NULL) return EMPTY_LIST;
	if (list->count <= index || index < 0) return INDEX_OUTOF_RANGE;
	if (index == 0) {
		Node* temp = list->head;
		Node* var = temp->nextPtr;
		free (temp);
		list->head = var;
	} else {
		Node* prev = list->head;
		for (int i = 1; i < index; i++)prev = prev->nextPtr;
		Node* atPos = list->head;
		for (int j = 1; j <= index; j++)atPos = atPos->nextPtr;
		prev->nextPtr = atPos->nextPtr;
		free (atPos);
	}
	list->count--;
	return 0;
}

int Remove (LinkedList* list, int num) {
	if (list == NULL)return LIST_NOT_CREATED;
	if (list->del) return  LIST_DELETED;
	if (list->head == NULL) return EMPTY_LIST;
	Node* var = list->head;
	if (var->data == num) {
		Node* temp = var->nextPtr;
		free (var);
		list->head = temp;
	} else {
		Node* atPos = list->head;
		Node* temp = NULL;
		int j = 0;
		for (j; j <= list->count; j++) {
			if (atPos->data == num) break;
			atPos = atPos->nextPtr;
			if (atPos == NULL) return NOT_FOUND;
		}
		Node* prev = list->head;
		for (int k = 0; k < j - 1; k++) prev = prev->nextPtr;
		prev->nextPtr = atPos->nextPtr;
		free (atPos);
	}
	list->count--;
	return 0;
}

int Count (LinkedList* list) {
	if (list == NULL)return LIST_NOT_CREATED;
	if (list->del) {
		return LIST_DELETED;
	} else return list->count;
}

int Get (LinkedList* list, int index, int* value) {
	if (list == NULL)return LIST_NOT_CREATED;
	if (list->del) return LIST_DELETED;
	if (list->head == NULL) return EMPTY_LIST;
	if (list->count <= index) return INDEX_OUTOF_RANGE;
	Node* atPos = list->head;
	if (index == 0) for (int j = 1; j <= index; j++) atPos = atPos->nextPtr;
	else for (int j = 1; j <= index; j++)atPos = atPos->nextPtr;
	*value = atPos->data;
	return 0;
}

int Delete (LinkedList* list) {
	if (list == NULL)return LIST_NOT_CREATED;
	if (list->del)return  LIST_DELETED;
	if (list->head == NULL) free (list->head);
	else {
		Node* temp = list->head;
		while (temp != NULL) {
			Node* temp1 = temp->nextPtr;
			free (temp);
			list->count--;
			temp = temp1;
		}
		free (temp);
	}
	list->del = true;
	return 0;
}