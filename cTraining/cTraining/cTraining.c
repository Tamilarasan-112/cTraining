// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// cTraining.c
// Implemented Heap Sort to sort an integer array in ascending order.
// implemented Binary Search to find the index position of a specified element (zero-based).
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"

/// <summary>Returns true if the input is a number.</summary>
bool IsValidInt (char input[]);

/// <summary>Remove any remaining characters from the input buffer.</summary>
void ClearBufferInput ();

/// <summary>Returns 1 if the input successfully parsed.</summary>
int GetArray (int** arr, int* arrSize);

/// <summary>Returns 1 if the input is received successfully.</summary>
int BinarySearch (int target, int array[], int arrSize);

/// <summary>Sort the given integer array.</summary>
void HeapSort (int arr[], int arrSize);

/// <summary>Test all the methods.</summary>
void UnitTest ();

void TestInputMethod ();

void TestSortMethod ();

void TestSearchMethod ();

void TestValidateMethod ();

/// <summary>Return true if the input is a valid choice for testing the sort method.</summary>
bool IsValidChoiceMenu (char choice[]);

/// <summary>Return true if the input is a valid choice for unit test method.</summary>
bool IsValidChoice (char choice[]);

/// <summary>Return 1 if the input is received successfully.</summary>
int GetTarget (int* target);

/// <summary>Test the code manually.</summary>
void ManualTest ();

/// <summary>Display the elements in the given array.</summary>
void Display (int* array, int arrSize);

/// <summary>To build a maximum heap.</summary>
void BuildMaxHeap (int index, int arrSize, int arr[]);

int main () {
   UnitTest ();
}

int GetTarget (int* target) {
   char input[14] = "0", c;
   printf ("\nTarget:");
   int i = 0, it = 0;
   bool isLeadingZero = true;
   while ((c = getchar ()) != '\n') {
      input[i] = c;
      if (isLeadingZero && input[i] == '0') {
         i = (input[0] == '-') ? 2 : 1;
         continue;
      } else if (isLeadingZero) {
         if (input[0] == '-') {
            it++;
            if (it > 1) isLeadingZero = false;
         } else isLeadingZero = false;
      }
      i++;
   }
   input[i] = '\n';
   input[i + 1] = '\0';
   if (IsValidInt (input)) {
      *target = atoi (input);
      return 1;
   } else {
      printf (COLOR_RED"\nInvalid input!\n"COLOR_RESET);
      if (input[strlen (input) - 1] != '\n') ClearBufferInput ();
   }
   return 0;
}

int GetArray (int** arr, int* arrSize) {
   bool isLeadingZero = true;
   char c, subArr[14] = "0";
   int i = 0, n = 1, index = 0, it = 0;
   int* intArr = (int*)malloc (n * sizeof (int));
   printf ("\nInput :");
   while ((c = getchar ()) != '\n') {
      if (i > 12) {
         printf (COLOR_RED"\nInvalid input!\n"COLOR_RESET);
         ClearBufferInput ();
         i = 0;
         return 0;
      }
      subArr[i] = c;
      if (isLeadingZero && subArr[i] == '0') {
         i = (subArr[0] == '-') ? 2 : 1;
         continue;
      } else if (isLeadingZero) {
         if (subArr[0] == '-') {
            it++;
            if (it > 1) isLeadingZero = false;
         } else isLeadingZero = false;
      }
      i++;
      if (c == ' ') {
         subArr[i - 1] = '\n';
         subArr[i] = '\0';
         if ((subArr[0] == '-' || isdigit (subArr[0])) && IsValidInt (subArr)) {
            int* temp = (int*)realloc (intArr, (n++) * sizeof (int));
            if (temp != NULL) {
               intArr = temp;
               intArr[index++] = atoi (subArr);
            }
         } else {
            printf (COLOR_RED"\nInvalid input\n"COLOR_RESET);
            ClearBufferInput ();
            i = 0;
            return 0;
         }
         isLeadingZero = true;
         it = 0;
         i = 0;
      }
   }
   // For last element
   if (i > 0) {
      subArr[i] = '\n';
      subArr[i + 1] = '\0';
      strcpy_s (subArr, 14, subArr);
      if (IsValidInt (subArr)) {
         intArr[index] = atoi (subArr);
         *arrSize = n;
         *arr = intArr;
         return 1;
      } else {
         printf (COLOR_RED"\nInvalid input!\n"COLOR_RESET);
         i = 0;
         return 0;
      }
   } else {
      printf (COLOR_RED"\nInvalid input!\n"COLOR_RESET);
      i = 0;
      return 0;
   }
   return 0;
}

bool IsValidInt (char input[]) {
   const char* str = input;
   char** endPtr = NULL;
   int strLength = (int)strlen (input);
   long long int num = strtoll (str, endPtr, 10);
   if (input[strLength - 1] != '\n' || !(num >= -2147483647 && num <= 2147483647)
      || input[0] == '\n') return false;
   int k = input[0] == '-' && input[1] != '\n';
   for (; k < strLength - 1; k++)
      if (!(isdigit (input[k]))) return false;
   return true;
}

void ClearBufferInput () {
   char c = '0';
   while (c = getchar () != '\n');
}

void HeapSort (int arr[], int arrSize) {
   // Build a max heap
   for (int parentIndex = (int)floor (arrSize / 2); parentIndex >= 0; parentIndex--)
      BuildMaxHeap (parentIndex, arrSize, arr);
   for (int i = arrSize - 1; i > 0; i--) {
      // Replace the last element with the first element and delete the first element.
      int root = arr[0];
      arr[0] = arr[i];
      arr[i] = root;
      BuildMaxHeap (0, i, arr);
   }
}

void BuildMaxHeap (int index, int arrSize, int arr[]) {
   int largest = index, left = 2 * index + 1, right = 2 * index + 2;
   if (left < arrSize && arr[largest] < arr[left]) largest = left;
   if (right < arrSize && arr[largest] < arr[right])largest = right;
   if (largest != index) {
      int temp = arr[index];
      arr[index] = arr[largest];
      arr[largest] = temp;
      BuildMaxHeap (largest, arrSize, arr);
   }
}

int BinarySearch (int target, int array[], int arrSize) {
   int low = 0, high = arrSize - 1, index = -1, mid;
   do {
      mid = (low + high) / 2;
      if (array[mid] < target)low = mid + 1;
      else high = mid - 1;
      if (array[mid] == target) index = mid;
   } while (low <= high);
   return index;
}

bool IsValidChoice (char choice[]) {
   return (choice[1] == '\n' && (choice[0] >= '1' && choice[0] <= '6'));
}

bool IsValidChoiceMenu (char choice[]) {
   return (choice[1] == '\n' && (choice[0] >= '1' && choice[0] <= '3'));
}

void UnitTest () {
   bool isExit = false;
   char choice[3];
   do {
      printf ("\n___________________________________\nMain Menu:\nTest Input method   -> Enter 1\n");
      printf ("Test Validate method-> Enter 2\nTest Sort method    -> Enter 3\n");
      printf ("Test Search method  -> Enter 4\nManual test         -> Enter 5\nExit                -> ");
      printf ("Enter 6\n___________________________________\nChoice:");
      fgets (choice, 3, stdin);
      if (IsValidChoice (choice)) {
         switch (choice[0]) {
         case '1':
            TestInputMethod ();
            break;
         case '2':
            TestValidateMethod ();
            break;
         case '3':
            TestSortMethod ();
            break;
         case '4':
            TestSearchMethod ();
            break;
         case '5':
            ManualTest ();
            break;
         case '6':isExit = true;
         }
      } else {
         printf (COLOR_RED"\nInvalid choice!\n"COLOR_RESET);
         if (choice[strlen (choice) - 1] != '\n') ClearBufferInput ();
      }
   } while (!isExit);
}

void TestInputMethod () {
   printf ("\nTest GetArray method:\n");
   int* arr;
   printf ("Please enter the integers separated by a single space.");
   int arrSize, ret = GetArray (&arr, &arrSize), target, ret1;
   if (ret == 1 || ret == 0) printf (COLOR_GREEN"\nPassed\n"COLOR_RESET);
   else printf (COLOR_YELLOW"\nFailed\n"COLOR_RESET);
   printf ("\nTest GetTarget method:\n");
   ret1 = GetTarget (&target);
   if (ret1 == 1 || ret1 == 0) printf (COLOR_GREEN"\nPassed\n"COLOR_RESET);
   else printf (COLOR_YELLOW"\nFailed\n"COLOR_RESET);
}

void TestValidateMethod () {
   printf ("\nIsValidInt method\n");
   char ipArrays[][50] = { " \n","-2147483647\n","2147483647\n","213223123123213\n","-1\n","000000000000000000000000\n","\n" };
   int expOp[] = { 0,1,1,0,1,1,0 }, ret = 0;
   for (int i = 0; i < 7; i++) {
      ret = IsValidInt (ipArrays[i]);
      printf ("\ninput :%s->Return %d", ipArrays[i], ret);
      if (ret == expOp[i]) printf (COLOR_GREEN"\nPassed\n"COLOR_RESET);
      else printf (COLOR_YELLOW"\nFailed\n"COLOR_RESET);
   }
}

void TestSortMethod () {
   printf ("\nHeap sort");
   int ipArrays[][20] = { {2},{1,2,3},{3,2,1},{0,1,2,3,-2147483647,2147483647},
            { 2,1,3,1,2 },{-2,3,2,1,3},{2,12,23,3434,43,435,34,-23 },{34,234,34,4,3,4} };
   int ipArraySizes[] = { 1,3,3,6,5,5,8,6 }, expOp[][20] = { {2},{1,2,3},{1,2,3},{-2147483647,0,1,2,3,2147483647},
      { 1,1,2,2,3 },{-2,1,2,3,3},{-23,2,12,23,34,43,435,3434},{3,4,4,34,34,234} };
   for (int i = 0; i < 8; i++) {
      bool isEqual = true;
      printf ("\ninput :");
      for (int j = 0; j < ipArraySizes[i]; j++)printf ("%d ", ipArrays[i][j]);
      HeapSort (ipArrays[i], ipArraySizes[i]);
      printf ("\noutput:");
      for (int j = 0; j < ipArraySizes[i]; j++) {
         printf ("%d ", ipArrays[i][j]);
         if (ipArrays[i][j] != expOp[i][j]) isEqual = false;
      }
      if (isEqual) printf (COLOR_GREEN"\nPassed\n"COLOR_RESET);
      else printf (COLOR_YELLOW"\nFailed\n"COLOR_RESET);
      printf ("\n");
   }
}

void TestSearchMethod () {
   printf ("\nBinarySearch method\n");
   int ipArrays[][50] = { {1},{-2,-2,-2,-2,-2},{2,12,23,3434,43,435,34,-23 },{34,234,34,4,3,4},{1,0,2,-1,-2,-4,-5 },
      {1,0,2,-1,-2,-4,-5,34,234,34,4,3,4,2,12,23,3434,43,435,34,-23},{-2147483647,2147483647} };
   int ipArraySizes[] = { 1,5,8,6,7,21,2 }, targets[] = { 1,-2,-23,234,-3,10,2147483647 },
      expOut[] = { 0,0,0,5,-1,-1,1 }, ret = 0;
   for (int i = 0; i < 7; i++) {
      HeapSort (ipArrays[i], ipArraySizes[i]);
      printf ("\nInput :");
      Display (ipArrays[i], ipArraySizes[i]);
      ret = BinarySearch (targets[i], ipArrays[i], ipArraySizes[i]);
      printf ("\nTarget:%d->Index:%d\n", targets[i], ret);
      if (ret == expOut[i]) printf (COLOR_GREEN"Passed\n"COLOR_RESET);
      else printf (COLOR_YELLOW"Failed\n"COLOR_RESET);
   }
}

void ManualTest () {
   bool isExit1 = false;
   char choice[3];
   int* array = NULL;
   int arrSize = 0, target;
   do {
      bool isExit2 = false;
      printf ("\n___________________\nManual test:\nSort    -> Enter 1\n");
      printf ("Search  -> Enter 2\nBack    -> Enter 3\n___________________\nChoice:");
      fgets (choice, 3, stdin);
      if (IsValidChoiceMenu (choice)) {
         bool isExit3 = false, isExit5 = false, isExit6 = false;
         switch (choice[0]) {
         case '1':
            do {
               printf ("\nHeap Sort\nPlease enter the integers separated by a single space.");
               if (GetArray (&array, &arrSize) == 1) {
                  HeapSort (array, arrSize);
                  printf ("output:");
                  Display (array, arrSize);
                  isExit3 = true;
               }
            } while (!isExit3);
            break;
         case '2':
            do {
               printf ("Please enter the integers separated by a single space.");
               if (GetArray (&array, &arrSize) == 1) {
                  do {
                     if (GetTarget (&target) == 1) {
                        HeapSort (array, arrSize);
                        printf ("Sorted array:");
                        Display (array, arrSize);
                        printf ("\nindex:%d", BinarySearch (target, array, arrSize));
                        isExit6 = true;
                     }
                  } while (!isExit6);
                  isExit5 = true;
               }
            } while (!isExit5);
            break;
         case '3':isExit1 = true;
         }
      } else {
         printf (COLOR_RED"\nInvalid choice!\n"COLOR_RESET);
         if (choice[strlen (choice) - 1] != '\n') ClearBufferInput ();
      }
   } while (!isExit1);
}

void Display (int* array, int arrSize) {
   for (int i = 0; i < arrSize; i++) printf ("%d ", array[i]);
}