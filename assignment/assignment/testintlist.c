#include "intlist.h";
#include <stdbool.h>;


int main () {
	
	//Testcases for LinkedList
	//case1: Create the Linked List, add 3 values and print count
	printf ("\nCase 1:\n");
	Node* list1 = Create ();
	Add (&list1, 100);
	Add (&list1, 200);
	Add (&list1, 300);
	printf ("Expected: 3\n");
	printf ("Output: %d\n", Count (&list1));
	Delete (&list1);

	
	//case2: Create the Linked List, add values,get count and remove values based on index
	printf ("\nCase 2:\n");
	Node* list2 = Create ();
	Add (&list2, 10);
	Add (&list2, 20);
	Add (&list2, 30);
	printf ("Expected: 0\n");
	int length = Count (&list2);
	for (int i = 0; i < length; i++) {
		RemoveAt (&list2, 0);
	}
	printf ("Output: %d\n", Count (&list2));
	Delete (&list2);
	
	//case3: Create the Linked List, delete list 2 times
	printf ("\nCase 3:\n");
	Node* list3 = Create ();
	int n = Delete (&list3);
	printf ("Expected: 1\n");
	printf ("Output1: ");
	printf ("%d\n", n);
	printf ("Expected:0\n");
	int m = Delete (&list3);
	printf ("Output2: ");
	printf ("%d\n", m); 

	//case4: Create the Linked List, delete list and try to insert, add values to list
	printf ("\nCase 4:\n");
	Node* list4 = Create ();
	Delete (&list4);
	printf ("Expected: 0\n");
	int j = Add (&list4, 20);
	printf ("Output1: ");
	printf ("%d\n", j);
	printf ("Expected: 0\n");
	int k = Insert (&list4, 20, 0);
	printf ("Output2: ");
	printf ("%d\n", k);

	//case5: Create the Linked List, add values and remove values based on value itself
	printf ("\nCase 5:\n");
	Node* list5 = Create ();
	Add (&list5, 100);
	Add (&list5, 200);
	Add (&list5, 300);
	Remove (&list5, 200);
	printf ("Expected: 2\n");
	printf ("Output: %d\n", Count (&list5));
	Delete (&list5);

	//case7: Create the Linked List and get values based on index
	printf ("\nCase 7:\n");
	Node* list6= Create ();
	Add (&list6, 10);
	Add (&list6, 20);
	Add (&list6, 30);
	printf ("Expected: 20\n");
	int a = Get (&list6, 1);
	printf ("Output: %d\n", a);
	Delete (&list6);

	//case8: Create an empty Linked List and try to get values based on index
	printf ("\nCase 8:\n");
	Node* list7 = Create ();
	printf ("Expected: 0\n");
	int b = Get (&list7, 1);
	printf ("Output: %d\n", b);
	Delete (&list7);

	//case9: Create a Linked List and try to get values exceeding index range
	printf ("\nCase 9:\n");
	Node* list8 = Create ();
	Add (&list8, 100);
	Add (&list8, 200);
	Add (&list8, 300);
	printf ("Expected: 0\n");
	int c = Get (&list8, 3);
	printf ("Output: %d\n", c);
	Delete (&list8);

	//case10: Create a Linked List, add same values and remove the first occurence
	printf ("\nCase 10:\n");
	Node* list9 = Create ();
	Add (&list9, 100);
	Add (&list9, 100);
	Add (&list9, 100);
	printf ("Expected: 2\n");
	Remove (&list9, 100);
	printf ("Output: %d\n", Count (&list9));
	Delete (&list9);

	//case11: Create a Linked List and try giving negative values as index
	printf ("\nCase 11:\n");
	Node* list10 = Create ();
	Add (&list10, 100);
	Add (&list10, 100);
	Add (&list10, 100);
	printf ("Expected: 0\n");
	int d = Insert (&list10, 10, -2);
	printf ("Output: %d\n", d);
	Delete (&list10);


}