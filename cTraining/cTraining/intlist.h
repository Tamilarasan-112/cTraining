#include <stdbool.h>

#define LIST_DELETED -1011;
#define EMPTY_LIST -1012;
#define INDEX_OUTOF_RANGE -1013;
#define MEMORY_ALLOCATION_FAILED -1014;
#define NOT_FOUND -1015;
#define LIST_NOT_CREATED -1016;
//Declaring node structure 
struct node {
	int data;
	struct node* nextPtr;
};


struct linkedlist {
	struct node* head;//nested structure
	bool del;
	int count;
};

typedef struct linkedlist LinkedList;
typedef struct node Node;

/// <summary>Create – this function will create a new linked list.</summary>
LinkedList* Create ();

/// <summary>Add - this function add the elements in list at end.</summary>
int Add (LinkedList* head, int num);

/// <summary>Insert – this will insert an element at a particular index (zero based).</summary>
int Insert (LinkedList* head, int index, int num);

/// <summary>RemoveAt – this will remove the element at a particular index (zero based).</summary>
int RemoveAt (LinkedList* head, int index);

/// <summary>Remove – this will removes the first occurrence of a specific element.</summary>
int Remove (LinkedList* head, int num);

/// <summary>Count – this will return number of elements in the list.</summary>
int Count (LinkedList* head);

/// <summary>Get – gets the element at a particular index position from header pointer Element to index.</summary>
int Get (LinkedList* head, int index, int* value);

/// <summary>Delete – this will delete the list and all the linked elements.</summary>
int Delete (LinkedList* head);
