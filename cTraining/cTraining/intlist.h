#include<stdbool.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

#define LIST_DELETED -1011;
#define EMPTY_LIST -1012;
#define INDEX_OUTOF_RANGE -1013;
#define MEMORY_ALLOCATION_FAILED -1014;

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



LinkedList* Create ();

void Display (LinkedList* head);
int Add (LinkedList* head,int num);
int Insert (LinkedList * head,int index, int num);
int RemoveAt (LinkedList* head,int index);
int Remove (LinkedList* head,int num);
int Count (LinkedList* head);
int Get (LinkedList* head,int index,int* value);
int Delete (LinkedList* head);

#endif LINKEDLIST_H 
