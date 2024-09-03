#include "intlist.h"
#include  <stdio.h>

int main () {
	/*Testcases for LinkedList
	case1: Create the Linked List, add 3 values and print count*/
	printf ("\nCase 1:\n");
	LinkedList* list1 = Create ();
	Add (list1, 100);
	Add (list1, 200);
	Add (list1, 300);
	printf ("Expected: 3\n");
	printf ("Output: %d\n", Count (list1));
	Delete (list1);

	//case2: Create the Linked List, add values,get count and remove values based on index
	printf ("\nCase 2:\n");
	LinkedList* list2 = Create ();
	Add (list2, 10);
	Add (list2, 20);
	Add (list2, 30);
	printf ("Expected: 0\n");
	int length = Count (list2);
	for (int i = 0; i < length; i++) RemoveAt (list2, 0);
	printf ("Output: %d\n", Count (list2));
	Delete (list2);

	//case3: Create the Linked List, delete list 2 times
	printf ("\nCase 3:\n");
	LinkedList* list3 = Create ();
	int n = Delete (list3);
	printf ("Expected: 0\n");
	printf ("Output1: ");
	printf ("%d\n", n);
	printf ("Expected:-1011\n");
	int m = Delete (list3);
	printf ("Output2: ");
	printf ("%d\n", m);

	//case4: Create the Linked List, delete list and try to insert, add values to list
	printf ("\nCase 4:\n");
	LinkedList* list4 = Create ();
	Delete (list4);
	printf ("Expected: -1011\n");
	int j = Add (list4, 20);
	printf ("Output1: ");
	printf ("%d\n", j);
	printf ("Expected: -1011\n");
	int k = Insert (list4, 20, 0);
	printf ("Output2: ");
	printf ("%d\n", k);

	//case5: Create the Linked List, add values and remove values based on value itself
	printf ("\nCase 5:\n");
	LinkedList* list5 = Create ();
	Add (list5, 100);
	Add (list5, 200);
	Add (list5, 300);
	Remove (list5, 200);
	printf ("Expected: 2\n");
	printf ("Output: %d\n", Count (list5));
	Delete (list5);

	//case7: Create the Linked List and get values based on index
	printf ("\nCase 7:\n");
	LinkedList* list6 = Create ();
	Add (list6, 10);
	Add (list6, 20);
	Add (list6, 30);
	printf ("Expected: 20\n");
	int value;
	int a = Get (list6, 1, &value);
	if (a == 0) {
		printf ("\nSuccessful\n");
		printf ("\nFrom get func : %d\n", value);
	} else {
		printf ("Unsuccessful\n");
		printf ("error:%d\n", a);
	}
	Delete (list6);

	//case8: Create an empty Linked List and try to get values based on index
	printf ("\nCase 8:\n");
	LinkedList* list7 = Create ();
	printf ("Expected: -1012\n");
	int value2;
	int b = Get (list7, 1, &value2);
	if (b == 0) {
		printf ("Successful\n");
		printf ("\nFrom get func : %d\n", value2);
	} else {
		printf ("Unsuccessful\n");
		printf ("error:%d\n", b);
	}
	Delete (list7);

	//case9: Create a Linked List and try to get values exceeding index range
	printf ("\nCase 9:\n");
	LinkedList* list8 = Create ();
	Add (list8, 100);
	Add (list8, 200);
	Add (list8, 300);
	int value3;
	if (Get (list8, 0, &value3) == 0) {
		printf ("Successful\n");
		printf ("\nFrom get func : %d\n", value3);
	} else {
		printf ("Unsuccessfully\n");
		printf ("error:%d\n", Get (list8, 4, &value3));
	}
	Delete (list8);

	//case10: Create a Linked List, add same values and remove the first occurrence
	printf ("\nCase 10:\n");
	LinkedList* list9 = Create ();
	Add (list9, 100);
	Add (list9, 100);
	Add (list9, 100);
	printf ("Expected: 2\n");
	Remove (list9, 100);
	printf ("Output: %d\n", Count (list9));
	Delete (list9);

	//case11: Create a Linked List and try giving negative values as index
	printf ("\nCase 11:\n");
	LinkedList* list10 = Create ();
	Add (list10, 100);
	Add (list10, 100);
	Add (list10, 100);
	printf ("Expected: -1013\n");
	int d = Insert (list10, 10, -2);
	printf ("Output: %d\n", d);
	Delete (list10);

	//case12:Add the element in new list ,after deleted on other list
	printf ("\nCase 12:\n");
	LinkedList* list11 = Create ();
	LinkedList* list12 = Create ();
	Delete (list12);
	int x = Add (list11, 1);
	if (x == 0)printf ("\nAdded successfully\n");

	//case13:
	printf ("\nCase 13:\n");
	LinkedList* head = Create ();
	LinkedList* head2 = Create ();
	int i = Add (head, 3);
	if (i == 0) printf ("\nsuccessful\n");
	Add (head, 3);
	Add (head, 4);
	Add (head2, 6);
	Add (head2, 4);
	int value4;
	if (Get (head, 1, &value4) == 0)printf ("Successful\n");
	printf ("\nFrom get func : %d\n", value4);
	Delete (head2);
	Insert (head, 2, 0);
	Add (head, 4);
	Insert (head, 6, 2);
	Count (head);
	printf ("expected:-1015\noutput:%d\n", Remove (head, 5));
	RemoveAt (head, 0);
	Remove (head, 4);
	Count (head);

	//case14/:try to add  before create the List
	printf ("\ncase:14\n");
	LinkedList* list = NULL;
	int B = Add (list, 1);
	if (B == 0)printf ("Successful\n");
	else {
		printf ("unsuccessful:%d\n", B);
	}
	
	printf ("\ncase:15\n");
	LinkedList* list13 = Create();
	int ts = Insert (list13, 0, 1);
	if (ts == 0)printf ("successful\n");
	else printf ("Unsuccessful\n");
}