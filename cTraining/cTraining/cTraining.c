// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c 
// Palindrome checker and Reverse number.
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <ctype.h>
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

/// <summary>Return true if input is valid.</summary>
bool IsValidChoice (char input[]);

/// <summary>Get the user input and return return successful or not.</summary>
int GetText ();

/// <summary>Return true if input text is valid.</summary>
bool IsValidText (char sent[]);

/// <summary>Display given string is palindrome or not and return successful or not.</summary>
int Display (char Text[]);

/// <summary>Return true if the input text is palindrome.</summary>
bool IsPalindromeText (char arr[]);

/// <summary>Get the number from user and return successful or not. </summary>
int GetInt ();

/// <summary>Return reversed version of given number.</summary>
int ReverseNum (int num);

void ClearInputBuffer ();

/// <summary>Display reversed version of given number and palindrome or not and return successful or not.</summary>
int DisplayInt (int num);

/// <summary>Return true if the given integer is valid.</summary>
bool IsValidInt (char input[]);

/// <summary>Get the choice from user and based on choice call the function.</summary>
void Test ();

/// <summary>In this function you can manually test the program.</summary>
void ManualTest ();

/// <summary>Display the test cases are Passed or failed.</summary>
void AutomationTest ();

int main () {
   Test ();
}

bool IsValidChoice (char input[]) {
   int strLength = strlen (input);
   if (strLength > 2)return false;
   for (int j = 0; j < strLength; j++) {
      if (!(isdigit (input[j])) && input[1] != '\n')return false;
   }
   if (!((input[0] >= '1') && (input[0] <= '3')))return false;
   return true;
}

int GetText () {
   char sent[110];
   printf ("\nInput:");
   fgets (sent, 110, stdin);
   if (IsValidText (sent)) {
      return Display (sent);
   } else {
      printf (RED_COLOR"Invalid!\n"RESET_COLOR);
      if (sent[strlen (sent) - 1] != '\n') ClearInputBuffer ();
      return GetText ();
   }
   return UNSUCCESSFUL;
}

bool IsValidText (char input[]) {
   if (input[0] == '\n' || input[0] == '\0') return false;
   return true;
}

bool IsPalindromeText (char sent[]) {
   bool isEqual = false;
   int strLen = strlen (sent), j = 0;
   for (int i = 0; i < strLen; i++) {
      if ((sent[i] >= '0' && sent[i] <= '9') || (sent[i] >= 'a' && sent[i] <= 'z')
         || (sent[i] >= 'A' && sent[i] <= 'z')) {
         sent[j++] = (isupper (sent[i])) ? sent[i] + 32 : sent[i];
      }
   }
   sent[j] = '\0';
   strLen = j;
   char* stPtr = &sent[0], * endPtr = &sent[strLen - 1];
   for (int i = 0; i < strLen; i++) {
      if (*(stPtr++) != *(endPtr--)) isEqual = true;
   }
   if (isEqual)return false;
   return true;
}

int Display (char sent[]) {
   if (IsPalindromeText (sent)) {
      printf (GREEN_COLOR"\nPalindrome\n"RESET_COLOR);
      return SUCCESSFUL;
   }
   printf (YELLOW_COLOR"\nNot a Palindrome\n"RESET_COLOR);
   return UNSUCCESSFUL;
}

int GetInt () {
   char input[15];
   printf ("\ninput:");
   fgets (input, 15, stdin);
   if (IsValidInt (input)) return DisplayInt (atoi (input));
   else {
      printf (RED_COLOR"Invalid!\n"RESET_COLOR);
      if (input[strlen (input) - 1] != '\n') ClearInputBuffer ();
      return GetInt ();
   }
   return UNSUCCESSFUL;
}

bool IsValidInt (char input[]) {
   const char* str = input;
   char* endPtr = NULL;
   int strLength = strlen (input);
   if (strLength - 1 > 10 || strtoll (str, endPtr, 10) > 2147483647)return false;
   for (int j = 0, k = 1; j < strLength - 1; j++, k++) {
      if (input[0] == '-' && input[1] != '\n')continue;
      if (!(isdigit (input[j])))return false;
   }
   return true;
}

int ReverseNum (int num) {
   int posNum = 0;
   posNum = num;
   if (num < 0) posNum = -num;
   char revNumbers[11] = { '0' };
   int i = 0, revNum;
   while (posNum > 0) {
      revNum = posNum % 10;
      posNum /= 10;
      revNumbers[i++] = (char)revNum + 48;
   }
   revNumbers[i] = '\0';
   return atoi (revNumbers);
}

int DisplayInt (int num) {
   int revNumber = ReverseNum (num);
   if (num >= 0 && revNumber == num) {
      printf ("output:%d\n", revNumber);
      printf (GREEN_COLOR"Palindrome\n"RESET_COLOR);
      return SUCCESSFUL;
   } else {
      printf ("output:%d\n", revNumber);
      printf (YELLOW_COLOR"Not a Palindrome\n"RESET_COLOR);
      return UNSUCCESSFUL;
   }
}

void ClearInputBuffer () {
   char ch;
   while (((ch = getchar ()) != '\n'));
}

void Test () {
   printf ("__________________________________\nMain Menu:\nAutomation testing  ->  Enter 1.\nManual testing");
   printf ("      ->  Enter 2.\nExit                ->  Enter 3.\n__________________________________\n");
   printf (MEGENT_COLOR"Choice:"RESET_COLOR);
   char choice[4];
   fgets (choice, 4, stdin);
   if (IsValidChoice (choice)) {
      switch (choice[0]) {
      case '1':
         AutomationTest ();
         break;
      case '2':
         ManualTest ();
         break;
      case '3':break;
      }
   } else {
      if (choice[strlen (choice) - 1] != '\n') ClearInputBuffer ();
      printf (RED_COLOR"Invalid!\n"RESET_COLOR);
      Test ();
   }
   return UNSUCCESSFUL;
}

void ManualTest () {
   printf ("__________________________________\nMenu:\nPalindrome Checker  ->  Enter 1.\nReverse Number");
   printf ("      ->  Enter 2.\n<<<Previous         ->  Enter 3.\n__________________________________\n");
   printf (MEGENT_COLOR"Choice:"RESET_COLOR);
   char choice[4], ch = 0;
   char a = 0;
   int index = 0;
   bool isExit;
   while (fgets (choice, 4, stdin)) {
      isExit = false;
      if (IsValidChoice (choice)) {
         switch (choice[0]) {
         case '1':
            GetText ();
            break;
         case '2':
            GetInt ();
            break;
         case '3':
            Test ();
            isExit = true;
            break;
         }
      } else {
         if (choice[strlen (choice) - 1] != '\n') ClearInputBuffer ();
         printf (RED_COLOR"Invalid!\n"RESET_COLOR);
         ManualTest ();
      }
      if (isExit)break;
      printf ("__________________________________\nMenu:\nPalindrome Checker  ->  Enter 1.\nReverse Number");
      printf ("      ->  Enter 2.\nExit                ->  Enter 3.\n__________________________________\n");
      printf (MEGENT_COLOR"Choice:"RESET_COLOR);
   }
}

void AutomationTest () {
   char textTest[][70] = { "Don’t nod","Was it a car or a cat I saw?","Madam!","Malayalam","Civic","Kukku","Bib","Nun","Level","I did, did I ? ","Mom","Dada" };
   int numTest[] = { 121,94867,123,34543,1,1212132,00000,12101,919,18881,-112,214314334 };
   for (int i = 0, n = 1; i < 12; i++, n++) {
      printf ("\ncase%d :\n", n);
      printf ("\nPalindrome checker\n");
      printf ("\ninput:%s\n", textTest[i]);
      printf ("output:");
      for (int j = (strlen (textTest[i])); j >= 0; j--)printf ("%c", textTest[i][j]);
      (Display (textTest[i]) == 1) ? printf (GREEN_COLOR"Passed!\n"RESET_COLOR) : printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
      printf ("\nReverse Number\n");
      printf ("\ninput:%d\n", numTest[i]);
      (DisplayInt (numTest[i]) == 1) ? printf (GREEN_COLOR"Passed!\n"RESET_COLOR) : printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
   }
}