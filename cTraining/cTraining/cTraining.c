// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// cTraining.c
// Sort array and Search Element.
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include<stdlib.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"

/// <summary>Return true if input is number.</summary>
bool IsValidInt (char input[]);

/// <summary>Remove the Remaining char from input buffer.</summary>
void ClearBufferInput ();

/// <summary>Return 1 if get a input successfully.</summary>
int GetArray (int** arr, int* arrSize);

/// <summary>Return index of the target element if found else return -1.</summary>
int BinarySearch (int target, int array[], int arrSize);

/// <summary>Sort the given Array.</summary>
void HeapSort (int arr[], int arrSize);

/// <summary>To test The All Methods.</summary>
void UnitTest ();

/// <summary>Sort the given Array.</summary>
void BubbleSort (int arr[], int arrSize);

void TestInputMethod ();

void TestSortMethod ();

void TestSearchMethod ();

void TestValidateMethod ();

/// <summary>Return true if input Valid Choice for test Sort.</summary>
bool IsValidChoiceMenu (char choice[]);

/// <summary>Return true if input Valid Choice for unit test.</summary>
bool IsValidChoice (char choice[]);

/// <summary>Return 1 if get a input successfully.</summary>
int GetTarget (int* target);

/// <summary>To test the code Manually.</summary>
void ManualTest ();

void Display (int* array, int arrSize);

int main () {
   UnitTest ();
   /*int arr[] = { 1,1,2,2,3 };
   printf ("%d", BinarySearch (3, arr, 5));*/
}

int GetTarget (int* target) {
   char input[12] = "0";
   printf ("\nTarget:");
   fgets (input, 12, stdin);
   input[strlen (input) - 1] = '\0';
   if (IsValidInt (input)) {
      *target = atoi (input);
      return 1;
   } else {
      printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
      if (input[strlen (input) - 1] != '\n')ClearBufferInput ();
   }
   return 0;
}

int GetArray (int** arr, int* arrSize) {
   bool isExit = false;
   char c, subArr[12] = "0";
   int i = 0, n = 1, index = 0;
   int* intArr = (int*)malloc (n * sizeof (int));
   printf ("\nInput:");
   while ((c = getchar ()) != '\n') {
      if (i > 11) {
         printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
         ClearBufferInput ();
         i = 0;
         return 0;
      }
      subArr[i++] = c;
      if (c == ' ') {
         subArr[i - 1] = '\0';
         if ((subArr[0] == '-' || isdigit (subArr[0])) && IsValidInt (subArr)) {
            int* temp = (int*)realloc (intArr, (n++) * sizeof (int));
            if (temp != NULL) {
               intArr = temp;
               intArr[index++] = atoi (subArr);
            }
         } else {
            printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
            ClearBufferInput ();
            i = 0;
            return 0;
         }
         i = 0;
      }
   }
   //for last element
   if (i > 0) {
      subArr[i] = '\0';
      strcpy_s (subArr, i + 1, subArr);
      if (IsValidInt (subArr)) {
         intArr[index] = atoi (subArr);
         *arrSize = n;
         *arr = intArr;
         return 1;
      } else {
         printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
         i = 0;
         return 0;
      }
   } else {
      printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
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
   if (strLength > 11 || !(num >= (signed)2147483648 && num <= 2147483647) || input[0] == '\n')return false;
   if (input[0] == '-' && input[1] != '\n') {
      for (int k = 1; k < strLength; k++)
         if (!(isdigit (input[k])))return false;
   } else {
      for (int j = 0; j < strLength; j++)
         if (!(isdigit (input[j])))return false;
   }
   return true;
}

void ClearBufferInput () {
   char c = '0';
   while (c = getchar () != '\n');
}

void HeapSort (int arr[], int arrSize) {
   //max heap
   for (int noOfPid = (int)round ((arrSize / 2) - 0.5) - 1; noOfPid >= 0; noOfPid--) {
      for (int i = (int)round ((arrSize / 2) - 0.5) - 1; i >= 0; i--) {
         int left = 2 * i + 1, right = 2 * i + 2;
         if (left < arrSize && (arr[left] > arr[i])) {
            int temp1 = arr[i];
            arr[i] = arr[left];
            arr[left] = temp1;
         }
         if (right < arrSize && (arr[right] > arr[i])) {
            int temp2 = arr[i];
            arr[i] = arr[right];
            arr[right] = temp2;
         }
      }
   }
   for (int i = arrSize - 1; i > 0; i--) {
      //replace last element to first and delete first element
      int root = arr[0];
      arr[0] = arr[i];
      arr[i] = root;
      for (int noOfPid = (int)round ((i / 2) - 0.5) - 1; noOfPid >= 0; noOfPid--) {
         for (int j = (int)round ((i / 2) - 0.5) - 1; j >= 0; j--) {
            int left = 2 * j + 1, right = 2 * j + 2;
            if (left < i && (arr[left] > arr[j])) {
               int temp1 = arr[j];
               arr[j] = arr[left];
               arr[left] = temp1;
            }
            if (right < i && (arr[right] > arr[j])) {
               int temp2 = arr[j];
               arr[j] = arr[right];
               arr[right] = temp2;
            }
         }
      }
   }
}

void BubbleSort (int arr[], int arrSize) {
   for (int i = 0; i < arrSize; i++) {
      for (int j = i + 1; j < arrSize; j++) {
         if (arr[i] > arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
}

int BinarySearch (int target, int array[], int arrSize) {
   bool isFound = false;
   int midIndex = (arrSize % 2 == 0) ? (int)round ((arrSize / 2) - 0.5) - 1 : (int)round ((arrSize / 2) - 0.5);
   int minIndex = arrSize - 1;
   if (array[midIndex] == target) {
      isFound = true;
      minIndex = midIndex;
   }
   if (array[midIndex] < target) {
      for (int i = midIndex + 1; i < arrSize; i++) {
         if (array[i] == target && minIndex >= i) return i;
      }
   } else {
      for (int i = midIndex - 1; i >= 0; i--) {
         if (array[i] == target && minIndex >= i) {
            minIndex = i;
            isFound = true;
         }
      }
   }
   if (isFound)return minIndex;
   else return -1;
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
      printf ("\n___________________________________\nMain Menu:\nTest Input Method   -> Enter 1\nTest Validate Method-> Enter 2\nTest Sort Method    -> Enter 3\n");
      printf ("Test Search Method  -> Enter 4\nManual Test         -> Enter 5\nExit                -> Enter 6\n___________________________________\nChoice:");
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
         case '6':
            isExit = true;
         }
      } else {
         printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
         if (choice[strlen (choice) - 1] != '\n')ClearBufferInput ();
      }
   } while (!isExit);
}

void TestInputMethod () {
   int* arr;
   int arrSize, ret = GetArray (&arr, &arrSize);
   if (ret == 1 || ret == 0) printf (COLOR_GREEN"\nPassed\n"COLOR_RESET);
   else printf (COLOR_YELLOW"\nFailed\n"COLOR_RESET);
}

void TestValidateMethod () {
   //IsValidInt method
   printf ("\nIsValidInt Method\n");
   char input[][20] = { "21312","-23213","231231P312","213223123123213","-1","0","\n" };
   int expOut[] = { 1,1,0,0,1,1,0 }, ret = 0;
   for (int i = 0; i < 7; i++) {
      ret = IsValidInt (input[i]);
      printf ("\ninput:%s->Return %d", input[i], ret);
      if (ret == expOut[i])printf (COLOR_GREEN"\nPassed\n"COLOR_RESET);
      else printf (COLOR_YELLOW"\nFailed\n"COLOR_RESET);
   }
}

void TestSortMethod () {
   bool isExit = false, isHeap = false, isBubble = false, isValid = true;
   do {
      printf ("\n__________________________\nMenu:\nHeap Sort   -> Enter 1\nBubble Sort -> Enter 2\nBack        -> Enter 3");
      printf ("\n__________________________\nChoice:");
      char choice[3];
      fgets (choice, 3, stdin);
      if (IsValidChoiceMenu (choice)) {
         switch (choice[0]) {
         case '1':
            isHeap = true;
            printf ("\nHeap Sort\n");
            break;
         case '2':
            isBubble = true;
            printf ("\nBubble Sort\n");
            break;
         case '3':
            isExit = true;
         }
      } else {
         printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
         if (choice[strlen (choice) - 1] != '\n')ClearBufferInput ();
         isValid = false;
      }
      if (!isExit && isValid) {
         int input11[][20] = { {2,1,3,1,2},{-2,3,2,1,3},{2,12,23,3434,43,435,34,-23 },{34,234,34,4,3,4} };
         int input12[] = { 5,5,8,6 }, expOut1[][20] = { {1,1,2,2,3},{-2,1,2,3,3},{-23,2,12,23,34,43,435,3434},{3,4,4,34,34,234} };
         for (int i = 0; i < 4; i++) {
            bool isEqual = true;
            printf ("\ninput:");
            for (int j = 0; j < input12[i]; j++)printf ("%d,", input11[i][j]);
            if (isHeap)HeapSort (input11[i], input12[i]);
            else BubbleSort (input11[i], input12[i]);
            printf ("\noutput:");
            for (int j = 0; j < input12[i]; j++) {
               printf ("%d,", input11[i][j]);
               if (input11[i][j] != expOut1[i][j]) isEqual = false;
            }
            if (isEqual)printf (COLOR_GREEN"\nPassed\n"COLOR_RESET);
            else printf (COLOR_YELLOW"\nFailed\n"COLOR_RESET);
            printf ("\n");
         }
      }
   } while (!isExit);
}

void TestSearchMethod () {
   printf ("\nBinarySearch Method\n");
   //Binary search method
   int input21[][20] = { {2,1,3,1,2},{-2,-2,-2,1,-3},{2,12,23,3434,43,435,34,-23 },{34,234,34,4,3,4} };
   int input22[] = { 5,5,8,6 }, target[] = { 3,-2,5,34 }, expOut3[] = { 4,1,-1,3 }, ret1 = 0;
   for (int i = 0; i < 4; i++) {
      HeapSort (input21[i], input22[i]);
      printf ("\nInput:");
      for (int j = 0; j < input22[i]; j++)printf ("%d,", input21[i][j]);
      ret1 = BinarySearch (target[i], input21[i], input22[i]);
      printf ("\nTarget:%d->Index:%d\n", target[i], ret1);
      if (ret1 == expOut3[i])printf (COLOR_GREEN"Passed\n"COLOR_RESET);
      else printf (COLOR_YELLOW"Failed\n"COLOR_RESET);
   }
}

void ManualTest () {
   bool isExit1 = false, isExit2 = false;
   char choice[3];
   int* array = NULL;
   int arrSize = 0, target;
   do {
      printf ("\n___________________\nManual Test:\nSort    -> Enter 1\n");
      printf ("Search  -> Enter 2\nBack    -> Enter 3\n___________________\nChoice:");
      fgets (choice, 3, stdin);
      if (IsValidChoiceMenu (choice)) {
         bool isExit5 = false;
         switch (choice[0]) {
         case '1':
            do {
               printf ("\n__________________________\nMenu:\nHeap Sort   -> Enter 1\nBubble Sort -> Enter 2\nBack        -> Enter 3");
               printf ("\n__________________________\nChoice:");
               char choice[3];
               bool isExit3 = false, isExit4 = false;
               fgets (choice, 3, stdin);
               if (IsValidChoiceMenu (choice)) {
                  switch (choice[0]) {
                  case '1':
                     do {
                        printf ("\nHeap Sort\n");
                        if (GetArray (&array, &arrSize) == 1) {
                           HeapSort (array, arrSize);
                           Display (array, arrSize);
                           isExit3 = true;
                        }
                     } while (!isExit3);
                     break;
                  case '2':
                     do {
                        printf ("\nBubble Sort\n");
                        if (GetArray (&array, &arrSize) == 1) {
                           BubbleSort (array, arrSize);
                           Display (array, arrSize);
                           isExit4 = true;
                        }
                     } while (!isExit4);
                     break;
                  case '3':
                     isExit2 = true;
                  }
               } else {
                  printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
                  if (choice[strlen (choice) - 1] != '\n')ClearBufferInput ();
               }
            } while (!isExit2);
            break;
         case '2':
            do {
               if (GetArray (&array, &arrSize) == 1 && GetTarget (&target) == 1) {
                  HeapSort (array, arrSize);
                  Display (array, arrSize);
                  printf ("\nindex:%d", BinarySearch (target, array, arrSize));
                  isExit5 = true;
               }
            } while (!isExit5);
            break;
         case '3':
            isExit1 = true;
         }
      } else {
         printf (COLOR_RED"\nInvalid!\n"COLOR_RESET);
         if (choice[strlen (choice) - 1] != '\n')ClearBufferInput ();
      }
   } while (!isExit1);
}

void Display (int* array, int arrSize) {
   printf ("\nOutput:");
   for (int i = 0; i < arrSize; i++)printf ("%d,", array[i]);
}