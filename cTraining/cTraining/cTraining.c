// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c 
// Palindrome checker and Reverse number.
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <ctype.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define GREEN_COLOR "\x1b[32m"
#define YELLOW_COLOR "\x1b[33m"
#define BLUE_COLOR "\x1b[34m"
#define CYAN_COLOR "\x1b[36m"
#define MEGENT_COLOR "\x1b[35m"

#define SUCCESSFUL 1;
#define UNSUCCESSFUL 0;
#define INVALID_INPUT -1;

/// <summary>Return successful or not for getting choice from user.</summary>
int GetChoice ();

/// <summary>Return true if input is valid.</summary>
bool IsValidChoice (char input[], int index);

/// <summary>Return successful or not and call the function GetText/GetInt.</summary>
int CallFunc (char* choice);

/// <summary>Get the user input and return return successful or not.</summary>
int GetText ();

/// <summary>Return length of the given string. </summary>
int StrLen (char sent[]);

/// <summary>Return true if input text is valid.</summary>
bool IsValidText (char* stPtr);

/// <summary>Display given string is palindrome or not and return successful or not.</summary>
int Display (char Text[]);

/// <summary>Return true if the input text is palindrome.</summary>
bool IsPalindromeText (char arr[]);

/// <summary>Get the number from user and return successful or not. </summary>
int GetInt ();

/// <summary>Return reversed version of given number.</summary>
int ReverseNum (int num);

/// <summary>Return true if given integer is palindrome.</summary>
bool IsPalindromeInt (int num);

/// <summary>Display reversed version of given number and palindrome or not and return successful or not.</summary>
int DisplayInt (int num);

/// <summary>Return true if the given integer is valid.</summary>
bool IsValidInt (char input[], int index);

/// <summary>Get the choice from user and return successful or not.</summary>
int Test ();

/// <summary>Display passed or failed and return unsuccessful if input is Invalid.</summary>
int ManualTest ();

/// <summary>Display the test cases are Passed or failed.</summary>
void AutomationTest ();

bool mIsAutomation;
int main () {
   Test ();
}

int GetChoice () {
   printf ("__________________________________\nMenu:\nPalindrome Checker  ->  Enter 1.\nReverse Number      ->  Enter 2.\nExit                ->  Enter 3.\n__________________________________\n");
   printf (MEGENT_COLOR"Choice:"RESET_COLOR);
   char* choice = (char*)malloc (2 * sizeof (char));
   char a;
   int index = 0;
   if (choice != NULL) {
      while ((a = getchar ())) {
         if (index > 1) {
            char* temp = realloc (choice, (2 + index) * sizeof (char));
            if (temp != NULL) choice = temp;
         }
         choice[index] = a;
         if (a == '\n') {
            if (IsValidChoice (choice, index) && index <= 1) return CallFunc (choice);
            else {
               printf (RED_COLOR"Invalid!\n"RESET_COLOR);
               return GetChoice ();
            }
         }
         index++;
      }
   }
   return UNSUCCESSFUL;
}

int CallFunc (char* choice) {
   switch (choice[0]) {
   case '1':return GetText ();
   case '2':return GetInt ();
   case '3':return UNSUCCESSFUL;
   default:
      printf (RED_COLOR"Invalid!\n"RESET_COLOR);
      return INVALID_INPUT;
   }
}

int GetText () {
   char c;
   char* sent = (char*)malloc (100 * sizeof (char));
   if (sent != NULL) {
      int index = 0;
      printf ("\nInput:");
      while ((c = getchar ())) {
         if (index > 98) { //if the input characters are more then the size of array then reallocate the memory for the new character.
            char* temp = realloc (sent, (index + 2) * sizeof (char));
            if (temp != NULL) sent = temp;
         }
         sent[index] = c;
         if (c == '\n') {
            sent[index] = '\0';
            if (IsValidText (&sent[0])) return Display (sent);
            else {
               printf (RED_COLOR"Invalid!\n"RESET_COLOR);
               return GetText ();
            }
         }
         index++;
      }
   }
   return UNSUCCESSFUL;
}

bool IsValidText (char* stPtr) {
   if (*stPtr == '\0' || *stPtr == '\n') return false;
   return true;
}

int StrLen (char sent[]) {
   int length = 0;
   while (sent[length++] != '\0');
   return length;
}

bool IsPalindromeText (char sent[]) {
   bool isEqual = false;;
   int strLen = StrLen (sent), templength = strLen, j = 0;
   for (int i = 0; i < templength; i++) {
      if ((sent[i] >= '0' && sent[i] <= '9') || (sent[i] >= 'a' && sent[i] <= 'z')
         || (sent[i] >= 'A' && sent[i] <= 'z')) {
         sent[j++] = (isupper (sent[i])) ? sent[i] + 32 : sent[i];
      }
   }
   sent[j] = '\0';
   strLen = j;
   char* stPtr = &sent[0], * endPtr = &sent[strLen - 1];
   if (mIsAutomation) printf ("output:");
   for (int i = 0; i < strLen; i++) {
      if (mIsAutomation) printf ("%c", *(endPtr));
      if (*(stPtr++) != *(endPtr--)) isEqual = true;
   }
   if (isEqual)return false;
   return true;
}

int Display (char sent[]) {
   if (mIsAutomation) {
      if (!IsValidText (&sent[0])) {
         printf (RED_COLOR"Invalid!\n"RESET_COLOR);
         return INVALID_INPUT;
      }
   }
   if (IsPalindromeText (sent)) {
      printf (GREEN_COLOR"\nPalindrome\n"RESET_COLOR);
      return SUCCESSFUL;
   }
   printf (CYAN_COLOR"\nNot a Palindrome\n"RESET_COLOR);
   return UNSUCCESSFUL;
}

int GetInt () {
   char c;
   int index = 0, stop = 0;
   char* input = (char*)malloc (9 * sizeof (char));
   if (input != NULL) {
      printf ("\nInput:");
      while (c = getchar ()) {
         input[index] = c;
         if (index > 7) {
            char* temp = realloc (input, (index * 2) * sizeof (char));
            if (temp != NULL) input = temp;
         }
         if (c == '\n' || c == '\x1a') { // To handle the console from exiting when Ctrl+C .
            if (IsValidInt (input, index)) return DisplayInt (atoi (input));
            else {
               printf (RED_COLOR"Invalid!\n"RESET_COLOR);
               return GetInt ();
            }
         }
         index++;
      }
   }
   return UNSUCCESSFUL;
}

int ReverseNum (int num) {
   char revNumbers[11] = { '0' };
   int i = 0, revNum;
   while (num > 0) {
      revNum = num % 10;
      num /= 10;
      revNumbers[i++] = (char)revNum + 48;
   }
   revNumbers[i] = '\0';
   return atoi (revNumbers);
}

bool IsPalindromeInt (int num) {
   if (num == ReverseNum (num))return true;
   return false;
}

bool IsValidInt (char input[], int index) {
   for (int j = 0, k = 1; j <= index; j++, k++) {
      if ((!(isdigit (input[j]) || input[j] == '\n')) || input[0] == '\n')return false;
   }
   if (atoi (input) > 2147483647) return false;
   return true;
}

bool IsValidChoice (char input[], int index) {
   if (index > 1) return false;
   for (int j = 0, k = 1; j <= index; j++, k++) {
      if ((!(isdigit (input[j]) || input[j] == '\n')) || input[0] == '\n')return false;
   }
   return true;
}

int DisplayInt (int num) {
   if (mIsAutomation) {
      if (num < 0) {
         printf (RED_COLOR"Invalid!\n"RESET_COLOR);
         return INVALID_INPUT;
      }
   }
   if (IsPalindromeInt (num)) {
      printf ("output:%d\n", num);
      printf (GREEN_COLOR"Palindrome\n"RESET_COLOR);
      return SUCCESSFUL;
   } else {
      printf ("output:%d\n", ReverseNum (num));
      printf (CYAN_COLOR"Not a Palindrome\n"RESET_COLOR);
      return UNSUCCESSFUL;
   }
}

int Test () {
   printf ("__________________________________\nMenu:\nAutomation testing  ->  Enter 1.\nManual testing      ->  Enter 2.\nExit                ->  Enter 3.\n__________________________________\n");
   printf (MEGENT_COLOR"Choice:"RESET_COLOR);
   char* choice = (char*)malloc (2 * sizeof (char));
   char a;
   int index = 0;
   if (choice != NULL) {
      while ((a = getchar ())) {
         if (index > 1) {
            char* temp = realloc (choice, (2 + index) * sizeof (char));
            if (temp != NULL) choice = temp;
         }
         choice[index] = a;
         if (a == '\n') {
            if (IsValidChoice (choice, index) && index <= 1) {
               switch (choice[0]) {
               case '1':
                  mIsAutomation = true;
                  AutomationTest ();
               case '2':
                  mIsAutomation = false;
                  return ManualTest ();
               case '3':return UNSUCCESSFUL;
               default:
                  printf (RED_COLOR"Invalid!\n"RESET_COLOR);
                  return Test ();
               }
            } else {
               printf (RED_COLOR"Invalid!\n"RESET_COLOR);
               return Test ();
            }
         }
         index++;
      }
   }
   return UNSUCCESSFUL;
}

int ManualTest () {
   int n, i = 1;
   char c;
   printf ("if you want exit enter 0,else enter any number (1-9):");
   while (scanf_s ("%d%c", &n, &c, 1)) {
      if (c != '\n' || isalpha (c) || n > 9) {
         printf (RED_COLOR"Invalid!\n"RESET_COLOR);
         return UNSUCCESSFUL;
      }
      switch (n) {
      case 0:return UNSUCCESSFUL;//to exit from test
      default:
         printf ("\nCase %d:\n", i++);
         if (GetChoice () == 1)printf (GREEN_COLOR"Passed!\n"RESET_COLOR);
         else printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
      }
      printf ("if you want exit enter 0 button ,else enter number (1-9):");
   }
   printf (RED_COLOR"Invalid!\n"RESET_COLOR);
   return  UNSUCCESSFUL;
}

void AutomationTest () {
   char textTest[][70] = { "Don’t nod","Was it a car or a cat I saw?","Madam!","Malayalam","Civic","\0","Bib","Nun","Level","I did, did I ? ","madama","AdaaDa" };
   int numTest[] = { 121,94867,123,34543,1,1212132,00000,12101,919,18881,-112,214314334 };
   for (int i = 0, n = 1; i < 12; i++, n++) {
      printf ("\ncase%d :\n", n);
      printf ("\nPalindrome checker\n");
      printf ("\ninput:%s\n", textTest[i]);
      (Display (textTest[i]) == 1) ? printf (GREEN_COLOR"Passed!\n"RESET_COLOR) : printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
      printf ("\nReverse Number\n");
      printf ("\ninput:%d\n", numTest[i]);
      (DisplayInt (numTest[i]) == 1) ? printf (GREEN_COLOR"Passed!\n"RESET_COLOR) : printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
   }
}