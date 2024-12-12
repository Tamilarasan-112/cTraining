// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
//CalcCoins.c
//Implemented a method to store the number of coins in each denomination (Rs. 10, Rs. 5, Rs. 2, Rs. 1) for change.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>

/// <summary>Returns true if the input amount is Valid; otherwise, false.</summary>
bool isValidAmount (char* Amount);

/// <summary>Returns 1 if coins are counted and stored in the array; otherwise, 0.</summary>
int CalcCoins (int paid, int actualAmount, int noCoins[], int coins[]);

/// <summary>To manually test the CalcCoins method.</summary>
void ManualTest ();

/// <summary>Gets the amount from the user.</summary>
void GetAmount (int* paid, int* actualAmount);

/// <summary>To automatically test the CalcCoins method.</summary>
void AutomationTest ();

int main () {
   ManualTest ();
   //AutomationTest ();
}

void GetAmount (int* paid, int* actualAmount) {
   char* paidStr = malloc (15 * sizeof (char)), * actualAmountStr = malloc (15 * sizeof (char));
   do {
      printf ("You enter the payment 1 to 2,147,483,647 \nPaid Amount : ");
      fgets (paidStr, 15, stdin);
      printf ("Actual Amount:");
      fgets (actualAmountStr, 15, stdin);
   } while (!(isValidAmount (paidStr) && isValidAmount (actualAmountStr)));
   *paid = atoi (paidStr);
   *actualAmount = atoi (actualAmountStr);
}

bool isValidAmount (char* Amount) {
   if (Amount[0] == '-') return false;
   char* end;
   long long int num = strtoll (Amount, &end, 10);
   int strLen = (int)strlen (Amount);
   if (Amount[strLen - 1] != '\n' || !(num > 0 && num <= 2147483647)) return false;
   for (int i = 0; i < strLen - 1; i++) {
      if (!isdigit (Amount[i])) return false;
   }
   return true;
}

int CalcCoins (int paid, int actualAmount, int noCoins[], int coins[]) {
   int change = paid - actualAmount, i = 0;
   if (change <= 0) return 0;
   while (change > 0) {
      if (change >= coins[i]) {
         noCoins[i] = change / coins[i];
         change %= coins[i];
      }
      i++;
   }
   return 1;
}

void ManualTest () {
   int paid = 0, actualAmount = 0, coins[] = { 10,5,2,1 }, noCoins[] = { 0,0,0,0 };
   GetAmount (&paid, &actualAmount);
   if (!CalcCoins (paid, actualAmount, noCoins, coins)) printf ("No need to give changes\n");
   for (int i = 0; i < 4; i++) {
      printf ("Rs.%d Coins ->%d\n", coins[i], noCoins[i]);
   }
}

void AutomationTest () {
   bool isPassed = true;
   int coins[] = { 10,5,2,1 }, paid[] = { 123,1223,213,12312,210 };
   int actualAmount[] = { 120, 1000,205,12311,210 };
   int expNoCoins[][4] = { {0,0,1,1 },{22,0,1,1},{0,1,1,1},{0,0,0,1},{0,0,0,0} };
   for (int i = 0; i < 5; i++) {
      int noCoins[] = { 0,0,0,0 };
      printf ("Case%d:input:\npaid:%d\nActual amount:%d\n", i + 1, paid[i], actualAmount[i]);
      if (!CalcCoins (paid[i], actualAmount[i], noCoins, coins)) printf ("No need to give changes\n");
      printf ("\nExpected output:\n");
      for (int j = 0; j < 4; j++) {
         printf ("Rs.%d->%d\n", coins[j], expNoCoins[i][j]);
         if (expNoCoins[i][j] != noCoins[j]) isPassed = false;
      }
      printf ("\nActual output:\n");
      for (int j = 0; j < 4; j++) printf ("Rs.%d->%d\n", coins[j], noCoins[j]);
      if (isPassed) printf ("Passed!\n");
      else printf ("Failed!");
   }
}