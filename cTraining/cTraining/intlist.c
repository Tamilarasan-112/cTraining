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
			  in this all function return 0 and 1 are process is incompleted and completed

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "intlist.h"



//Create – this will create a new linked list.
LinkedList* Create () {
	LinkedList* pointer = (LinkedList*)malloc (sizeof (LinkedList));
	pointer->head = NULL;
	pointer->del = false;
	pointer->count = 0;
	return pointer;
}


//Add - Adds an item to end of the list 
/*this function  add the elements in list at end ,by using the pointer .
if the head is null,store the newnode pointer in head pointer,
otherwise go through the list get the last node and next pointer, store the newnode next pointer*/
int Add (LinkedList* list, int num) {

	Node* newNode = (Node*)malloc (sizeof (Node)); //memory allocation for newnode,it's can store data and pointer.

	//if the list is deleted once or more times ,can't add the elements in list
	if (list->del == true) {
		return LIST_DELETED;
	};

	if (newNode == NULL) {
	
		return MEMORY_ALLOCATION_FAILED;
	};

	newNode->data = num; //store the value in the new Node
	newNode->nextPtr = NULL; //store the new node next pointer is null ,we adding the element at last


	if (list->head == NULL) {
		list->head = newNode;
		list->count++;

	} else {
		Node* temp = list->head;

		while (temp->nextPtr != NULL) {

			temp = temp->nextPtr;

		}
		temp->nextPtr = newNode;
		list->count++;

	}
	return 0;

}

//Insert – this will insert an element at a particular index (zero based).
//For example, if the linked list has 4 elements.Calling Insert with an index 
//of 2 will insert the new element between that at index 1 and that at index 2.

/*this function insert node at index .in this function go throgth the list and get previous node next pointer for give index node,
which is pointer to the newnode and also it's stored the index position next node data in the list ,
so newnode next pointer store the the previous node next pointer and the previous node next pointer store the newnode  */
int Insert (LinkedList* list, int index, int num) {

	//if the list is deleted once or more times ,can't Insert the elements in list

	if (list->del == true) {
		return  LIST_DELETED;
	};

	Node* newNode = (Node*)malloc (sizeof (Node));
	if (newNode == NULL) {
		return MEMORY_ALLOCATION_FAILED;
	}
	

	if (list->head == NULL) {
		
		return EMPTY_LIST;
	}

	
	if (list->count <= index) {
		
		return INDEX_OUTOF_RANGE;
	}
	newNode->data = num;
	if (index == 0) {
		//insert at begining
		newNode->nextPtr = list->head;
		list->head = newNode;
		list->count++;

	} else {

		Node* prev = list->head;
		for (int i = 1; i < index; i++) {
			prev = prev->nextPtr;
		}
		newNode->nextPtr = prev->nextPtr;
		prev->nextPtr = newNode;
		list->count++;

	}
	return 0;
	
}

//RemoveAt – this will remove the element at a particular index (zero based).
/*this function remove the node at the index, same as insertat function, but in this function we need previous and index node,
//because index node which store the next node pointer and this pointer must be store in previous node nextpointer.*/
int RemoveAt (LinkedList* list, int index) {

	if (list->del == true) {
		return  LIST_DELETED;
	};

	if (list->head == NULL) {
		
		return EMPTY_LIST;
	}

	//int count = Count (list);

	if (list->count <= index) {
		return INDEX_OUTOF_RANGE;
	}
	if (index == 0) {

		Node* temp = list->head;
		Node* var = temp->nextPtr;
		free (temp);
		list->head = var;
		list->count--;

	} else {
		Node* prev = list->head;
		for (int i = 1; i < index; i++) {
			prev = prev->nextPtr;
		}
		Node* atPos = list->head;
		for (int j = 1; j <= index; j++) {
			atPos = atPos->nextPtr;
		}
		prev->nextPtr = atPos->nextPtr;
		free (atPos);
		list->count--;

	}
	return 0;
	
}
//
////Remove – removes the first occurrence of a specific element.
///*this function remove the first occurrence of a given Element by compare the give element with each elements in list ,
//find element node and also it'f get the previous node.then it's store the element node next pointer in previous node next pointer*/
int Remove (LinkedList* list, int num) {

	if (list->del == true) {
		return  LIST_DELETED;
	};

	
	if (list->head == NULL) {
		
		return EMPTY_LIST;
	}

	

	Node* var = list->head;
	if (var->data == num) {
		Node* temp = var->nextPtr;
		free (var);
		list->head = temp;
		list->count--;

	} else {
		Node* atPos = list->head;
		Node* temp = NULL;
		int j = 0;
		for (j; j <= list->count; j++) {
			if (atPos->data == num) {

				break;
			}
			atPos = atPos->nextPtr;
		}
		Node* prev = list->head;
		for (int k = 0; k < j - 1; k++) {
			prev = prev->nextPtr;
		}
		prev->nextPtr = atPos->nextPtr;
		free (atPos);
		list->count--;

	}
	return 0;
}
////Display-it's display the list elements
void Display (LinkedList* list) {

	if (list->del == true) {
		return LIST_DELETED;
	};
	if (list->head == NULL) {
		return EMPTY_LIST;
	} else {
		Node* temp = list->head;
		
		while (temp != NULL) {
			printf ("\n%d\n", temp->data);
			temp = temp->nextPtr;
		}
	}

}
//Count – number of elements in the list.
int Count (LinkedList* list) {
	if (list->del == true) {
		return  LIST_DELETED;
	}
	else {
		return list->count;
	}


}




////Get – gets the element at a particular index position from header pointer Element to index.
int Get (LinkedList* list, int index, int* value) {

	if (list->del == true) {
		return LIST_DELETED;
	};

	if (list->head == NULL) {
		return EMPTY_LIST;
	}
	
	if (list->count <= index) {
		return INDEX_OUTOF_RANGE;
	}
	if (index == 0) {
		Node* atPos = list->head;
		for (int j = 1; j <= index; j++) {
			atPos = atPos->nextPtr;
		}
		return atPos->data;
	} else {
		Node* atPos = list->head;
		for (int j = 1; j <= index; j++) {
			atPos = atPos->nextPtr;
		}
		*value= atPos->data;
		return 0;
		
	}
}

//Delete – this will delete the list and all the linked elements.

int Delete (LinkedList* list) {

	if (list->del == true) {
		return  LIST_DELETED;
	};

	
	if (list->head == NULL) {
		free (list->head);
	} else {
		Node* temp = list->head;
		while (temp != NULL) {
			int* temp1 = temp->nextPtr;
			free (temp);
			list->count--;
			temp = temp1;
		}
		free (temp);

	}

	list->del = true;
	return 0;

}



