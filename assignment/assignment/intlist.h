#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct node {
	int data;
	struct node* nextPtr;
}Node;

Node* Create (); 

void Display (Node** head);
int Add (Node** head,int num);
int Insert (Node** head,int index, int num);
void RemoveAt (Node** head,int index);
int Remove (Node** head,int num);
int Count (Node** head);
int Get (Node** head,int index);
int Delete (Node** head);

#endif LINKEDLIST_H 
