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
			  in this all function return 0 and 1 are process is not completed and completed

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//create node structure 
typedef struct node {
	int data;
	struct node* nextPtr;
}Node;


int num;

int* process;
int* del=&process;


//Create – this will create a new linked list.
Node* Create () {

	Node* head = NULL;
	*del = 2;
	return head;
}


//Add - Adds an item to end of the list 
/*this function  add the elements in list at end ,by using the pointer .
if the head is null,store the newnode pointer in head pointer,
otherwise go through the list get the last node and next pointer, store the newnode next pointer*/
int Add (Node** head,int num) {

	Node* newNode = (Node*)malloc (sizeof (Node)); //memory allocation for newnode,it's can store data and pointer.
	if (newNode == NULL) {
		printf ("error:memory allocation is failed\n");
		return;
	}

	//if the list is deleted once or more times ,can't add the elements in list
	if (*del < 2) {
		printf ("error:List is deleted,can't add\n");
		return 0;
	}
	
	
	newNode->data = num; //store the value in the new Node
	newNode->nextPtr = NULL; //store the new node next pointer is null ,we adding the element at last

	
	if (*head == NULL) {
		*head = newNode;
	
	} else {
		Node* temp = *head;

		while (temp->nextPtr != NULL) {

			temp = temp->nextPtr;

		}
		temp->nextPtr = newNode;
		
	}
	return 1;
}

//Insert – this will insert an element at a particular index (zero based).
//For example, if the linked list has 4 elements.Calling Insert with an index 
//of 2 will insert the new element between that at index 1 and that at index 2.

/*this function insert node at index .in this function go throgth the list and get previous node next pointer for give index node,
which is pointer to the newnode and also it's stored the index position next node data in the list ,
so newnode next pointer store the the previous node next pointer and the previous node next pointer store the newnode  */
int Insert (Node**head,int index, int num) {

	Node* newNode = (Node*)malloc (sizeof (Node));
	if (newNode == NULL) {
		printf ("error:memory allocation is failed\n");
		return;
	}
	//if the list is deleted once or more times ,can't Insert the elements in list
	if (*del < 2) {
		printf ("error:List is deleted,can't insert\n");
		return 0;
	}

	if (*head == NULL) {
		printf ("error:Empty list\n");
		return 0;
	}
	
	
	Node* temp = *head;
	int count = Count (&temp);
	if (count <= index) {
		printf ("error:Index out of range\n");
		return 0;
	}
	newNode->data = num;
	if (index == 0) {
		//insert at begining
		newNode->nextPtr = *head;
		*head = newNode;
		
	} else {
		
		Node* prev = *head;
		for (int i = 1; i < index; i++) {
			prev = prev->nextPtr;
		}
		newNode->nextPtr = prev->nextPtr;
		prev->nextPtr = newNode;
		
	}
	return 0;
}

//RemoveAt – this will remove the element at a particular index (zero based).
/*this function remove the node at the index, same as insertat function, but in this function we need previous and index node,
because index node which store the next node pointer and this pointer must be store in previous node nextpointer.*/
void RemoveAt (Node** head,int index) {

	if (*head == NULL) {
		printf ("error:Empty is list\n");
		return;
	}
	Node* temp = *head;
	int count = Count (&temp);
	
	if (count <= index) {
		printf ("error:Index out of range\n");
		return;
	}
	if (index == 0) {
		
		Node* temp = *head;
		Node*var=temp->nextPtr;
		free (temp);
		*head = var;
		
	} else {
		Node* prev = *head;
		for (int i = 1; i < index; i++) {
			prev = prev->nextPtr;
		}
		Node* atPos = *head;
		for (int j = 1; j <= index; j++) {
			atPos = atPos->nextPtr;
		}
		prev->nextPtr = atPos->nextPtr;
		free (atPos);
		
	}
}

//Remove – removes the first occurrence of a specific element.
/*this function remove the first occurrence of a given Element by compare the give element with each elements in list ,
find element node and also it'f get the previous node.then it's store the element node next pointer in previous node next pointer*/
int Remove (Node**head,int num) {
	Node* temp = *head;
	int count = Count (&temp);
	if (*head == NULL) {
		printf ("error:Empty list\n");
		return 0;
	}
	
	Node* var = *head;
	if (var->data == num) {
		Node* temp = var->nextPtr;
		free (var);
		*head = temp;
		
	} else {
		Node* atPos = *head;
		Node* temp = NULL;
		int j = 0;
		for (j; j <= count; j++) {
			if (atPos->data == num) {

				break;
			}
			atPos = atPos->nextPtr;
		}
		Node* prev = *head;
		for (int k = 0; k < j - 1; k++) {
			prev = prev->nextPtr;
		}
		prev->nextPtr = atPos->nextPtr;
		free (atPos);
		
	}
	return 1;
}
////Display-it's display the list elements
void Display (Node** head) {
	
	
	if (*head == NULL) {
		printf ("error:Empty list\n");
		return;
	} else {
		Node* temp = *head;
		printf ("error:List elements:\n");
		while (temp != NULL) {
			printf ("%d\n", temp->data);
			temp = temp->nextPtr;
		}
	}
	
}
//Count – number of elements in the list.
int Count(Node** head) {
	if (*head == NULL) {
		return 0;
	}
	else {
		int length = 0;
		Node* temp = *head;
		while (temp != NULL) {

			temp = temp->nextPtr;
			length++;
		}
		
		return length;
	
	}
	
}




//Get – gets the element at a particular index position from header pointer Element to index.
int Get (Node**head,int index) {

	if (*head == NULL) {
		printf ("error:Empty list\n");
		return 0;
	}
	Node* temp = *head;
	int count = Count (&temp);
	if (count <= index) {
		printf ("error:Index out of range\n");
		return 0;
	}
	if (index == 0) {
		Node* atPos = *head;
		for (int j = 1; j <= index; j++) {
			atPos = atPos->nextPtr;
		}
		return atPos->data;
	} else {
		Node* atPos = *head;
		for (int j = 1; j <= index; j++) {
			atPos = atPos->nextPtr;
		}
		return atPos->data;
		
	}
}

//Delete – this will delete the list and all the linked elements.

int Delete (Node** head) {
	
	Node* ptr = *head;
	int count = Count (&ptr);
	if (*head == NULL) {
		free (*head);
		

	} else{
		Node* temp = *head;
		while (temp != NULL) {
			int* temp1 = temp->nextPtr;
			free (temp);
			count--;
			temp = temp1;
		}
		free (temp);
		
	}
	
	(*del) -= 1;
	if (*del == 1) {
		
		return 1;
	}
	else {
		printf ("error:List is already deleted\n");
		return 0;
	}
	
	
}



