// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// cTraining.c
// Palindrome checker and Reverse number.
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define GREEN_COLOR "\x1b[32m"
#define YELLOW_COLOR "\x1b[33m"
#define BLUE_COLOR "\x1b[34m"
#define CYAN_COLOR "\x1b[36m"
#define MEGENT_COLOR "\x1b[35m"

#define SUCCESSFUL 1;
#define UNSUCCESSFUL 0;

/// <summary>Return true if input is valid.</summary>
bool IsValidChoice (char input[]);

/// <summary>Get the user input.</summary>
void GetText (char input[], int charArrSize);

/// <summary>Return true if input text is valid.</summary>
bool IsValidText (char sent[]);

/// <summary>Display given string is palindrome or not and return successful or not.</summary>
int Display (char Text[]);

/// <summary>Return true if the input text is palindrome.</summary>
bool IsPalindromeText (char arr[]);

/// <summary>Get the number from user. </summary>
void GetInt (char input[]);

/// <summary>Return reversed version of given number.</summary>
long long int ReverseNum (int num);

/// <summary>remove the remaining characters from the input buffer.</summary>
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

int TestPalindromeMethod (char textTest[]);

int TestReverseNumMethod (char numTest[]);

int main () {
   Test ();
}

bool IsValidChoice (char input[]) {
   return (strlen (input) <= 2 && ((input[0] >= '1') && (input[0] <= '3')));
}

void GetText (char input[], int charArrSize) {
   bool isExit = false;
   do {
      printf ("\nInput:");
      fgets (input, charArrSize, stdin);
      if (IsValidText (input))isExit = true;
      else {
         printf (RED_COLOR"\nInvalid!\n"RESET_COLOR);
         if (input[strlen (input) - 1] != '\n')ClearInputBuffer ();
      }
   } while (!isExit);
}

bool IsValidText (char input[]) {
   int strLength = (int)strlen (input);
   if (input[strLength - 1] == '\n' && input[0] != '\n') {
      for (int i = 0; i < strLength; i++)
         if (isalnum (input[i]))return true;
   }
   return false;
}

bool IsPalindromeText (char sent[]) {
   int strLen = (int)strlen (sent), j = 0;
   for (int i = 0; i < strLen; i++)
      if ((sent[i] >= '0' && sent[i] <= '9') || (sent[i] >= 'a' && sent[i] <= 'z')
         || (sent[i] >= 'A' && sent[i] <= 'z'))
         sent[j++] = (isupper (sent[i])) ? sent[i] + 32 : sent[i];
   sent[j] = '\0';
   strLen = j;
   for (int i = 0, j = strLen - 1; i < strLen; i++, j--)
      if (sent[i] != sent[j]) return false;
   return true;
}

int Display (char sent[]) {
   if (IsPalindromeText (sent)) {
      printf (GREEN_COLOR"Palindrome\n"RESET_COLOR);
      return SUCCESSFUL;
   }
   printf (YELLOW_COLOR"Not a Palindrome\n"RESET_COLOR);
   return UNSUCCESSFUL;
}

void GetInt (char input[]) {
   bool isExit = false;
   do {
      printf ("\ninput:");
      fgets (input, 15, stdin);
      if (IsValidInt (input)) isExit = true;
      else {
         printf (RED_COLOR"Invalid!\n"RESET_COLOR);
         if (input[strlen (input) - 1] != '\n') ClearInputBuffer ();
      }
   } while (!isExit);
}

bool IsValidInt (char input[]) {
   const char* str = input;
   char** endPtr = NULL;
   int strLength = (int)strlen (input);
   long long int num = strtoll (str, endPtr, 10);
   if (!(num >= -2147483647 && num <= 2147483647) || input[0] == '\n')return false;
   if (input[0] == '-' && input[1] != '\n') {
      for (int k = 1; k < strLength - 1; k++)
         if (!isdigit (input[k]))return false;
   } else {
      for (int j = 0; j < strLength - 1; j++)
         if (!(isdigit (input[j])))return false;
   }
   return true;
}

long long int ReverseNum (int num) {
   int posNum = num, i = 0, revNum;
   if (num < 0) posNum = -num;
   char revNumbers[11] = { '0' };
   const char* str = revNumbers;
   char** endPtr = NULL;
   while (posNum > 0) {
      revNum = posNum % 10;
      posNum /= 10;
      revNumbers[i++] = (char)revNum + 48;
   }
   revNumbers[i] = '\0';
   return strtoll (str, endPtr, 10);
}

int DisplayInt (int num) {
   long long int revNumber = ReverseNum (num);
   if (num >= 0 && revNumber == num) {
      printf ("output:%lld\n", revNumber);
      printf (GREEN_COLOR"Palindrome\n"RESET_COLOR);
      return SUCCESSFUL;
   } else {
      printf ("output:%lld\n", revNumber);
      printf (YELLOW_COLOR"Not a Palindrome\n"RESET_COLOR);
      return UNSUCCESSFUL;
   }
}

void ClearInputBuffer () {
   char ch;
   while (((ch = getchar ()) != '\n'));
}

void Test () {
   char choice[4];
   bool isExit = false;
   do {
      printf ("__________________________________\nMain Menu:\nAutomation testing  ->  Enter 1.\nManual testing");
      printf ("      ->  Enter 2.\nExit                ->  Enter 3.\n__________________________________\n");
      printf (MEGENT_COLOR"Choice:"RESET_COLOR);
      fgets (choice, 4, stdin);
      if (IsValidChoice (choice)) {
         switch (choice[0]) {
         case '1':
            AutomationTest ();
            break;
         case '2':
            ManualTest ();
            break;
         case '3':isExit = true;
         }
      } else {
         if (choice[strlen (choice) - 1] != '\n') ClearInputBuffer ();
         printf (RED_COLOR"Invalid!\n"RESET_COLOR);
      }
   } while (!isExit);
}

void ManualTest () {
   int charArrSize = 100;
   char choice[4], textIp[100], numberIp[20];
   bool isExit = false;
   do {
      printf ("__________________________________\nMenu:\nPalindrome Checker  ->  Enter 1.\nReverse Number");
      printf ("      ->  Enter 2.\n<<<Previous         ->  Enter 3.\n__________________________________\n");
      printf (MEGENT_COLOR"Choice:"RESET_COLOR);
      fgets (choice, 4, stdin);
      if (IsValidChoice (choice)) {
         switch (choice[0]) {
         case '1':
            GetText (textIp, charArrSize);
            Display (textIp);
            break;
         case '2':
            GetInt (numberIp);
            DisplayInt (atoi (numberIp));
            break;
         case '3':isExit = true;
         }
      } else {
         if (choice[(int)strlen (choice) - 1] != '\n') ClearInputBuffer ();
         printf (RED_COLOR"Invalid!\n"RESET_COLOR);
      }
   } while (!isExit);
}

void AutomationTest () {
   char textTest[][200] = { "Don’t nod\n","@@#@#@\n","Tamilarasan.Ramalingam@trumpf.com\n","Was it a car or a cat I saw?\n","Madam!\n","Malayalam\n","Civic\n","\n","Kukku\n","Bib\n","Nun\n","Level\n","I did, did I ?\n","Mom\n","Dada\n",
 "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad\n","Appa\n","     \n" };
   int expOut1[] = { 1,-1,0,1,1,1,1,-1,0,1,1,1,1,1,0,0,1,-1 };
   char numTest[][20] = { "   \n","121\n","94867\n","123\n","34543\n","1\n","1212132\n","00000\n","12101\n","919\n","18881\n","- 112\n","2147483648\n","3abs\n","Amma\n","2147483647\n","-2147483647\n","\n" };
   int expOut2[] = { -1,1,0,0,1,1,0,1,0,1,1,-1,-1,-1,-1,0,0,-1 };
   for (int i = 0, n = 1; i < 18; i++, n++) {
      printf ("\ncase%d :\n", n);
      printf ("\nPalindrome checker:\n");
      printf ("\ninput:%s", textTest[i]);
      printf ("output:");
      for (int j = (int)strlen (textTest[i]) - 2; j >= 0; j--) printf ("%c", textTest[i][j]);
      printf ("\n");
      (TestPalindromeMethod (textTest[i]) == expOut1[i]) ? printf (GREEN_COLOR"\nPassed!\n"RESET_COLOR) : printf (YELLOW_COLOR"\nFailed\n"RESET_COLOR);
      printf ("\nReverse Number:\n");
      printf ("\ninput:%s", numTest[i]);
      (TestReverseNumMethod (numTest[i]) == expOut2[i]) ? printf (GREEN_COLOR"\nPassed!\n"RESET_COLOR) : printf (YELLOW_COLOR"\nFailed\n"RESET_COLOR);
   }
}

int TestPalindromeMethod (char textTest[]) {
   if (IsValidText (textTest)) return Display (textTest);
   else return -1;
}

int TestReverseNumMethod (char numTest[]) {
   if (IsValidInt (numTest)) return DisplayInt (atoi (numTest));
   else return -1;
}