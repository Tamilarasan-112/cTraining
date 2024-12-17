// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
//CalcCoins.c
//Implemented a method to store the number of coins in each denomination (Rs. 10, Rs. 5, Rs. 2, Rs. 1) for change.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

/// <summary>Returns true if the input amount is Valid; otherwise, false.</summary>
bool IsValidAmount (char* amount);

/// <summary>Returns 1 if coins are counted and stored in the array; otherwise, 0.</summary>
int CalcCoins (int paid, int actualAmount, int coinsCount[], int coins[]);

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
      printf ("You enter the payment 1 to 2,147,483,647 \nPaid amount : ");
      fgets (paidStr, 15, stdin);
      printf ("Actual amount:");
      fgets (actualAmountStr, 15, stdin);
   } while (!(IsValidAmount (paidStr) && IsValidAmount (actualAmountStr)));
   *paid = atoi (paidStr);
   *actualAmount = atoi (actualAmountStr);
   free (paidStr);
   free (actualAmountStr);
}

bool IsValidAmount (char* amount) {
   if (amount[0] == '-') return false;
   char* end;
   long long int num = strtoll (amount, &end, 10);
   if (*end != '\n' || !(num > 0 && num <= 2147483647)) return false;
   return true;
}

int CalcCoins (int paid, int actualAmount, int coinsCount[], int coins[]) {
   int change = paid - actualAmount, i = 0;
   if (change < 0) return 0;
   do {
      coinsCount[i] = change / coins[i];
      change %= coins[i];
      i++;
   } while (change > 0);
   return 1;
}

void ManualTest () {
   int paid = 0, actualAmount = 0, coins[] = { 10,5,2,1 }, coinsCount[] = { 0,0,0,0 }, balance;
   GetAmount (&paid, &actualAmount);
   balance = actualAmount - paid;
   if (!CalcCoins (paid, actualAmount, coinsCount, coins)) printf ("Ask for the balance amount of %d \n", balance);
   for (int i = 0; i < 4; i++)
      printf ("Rs.%d Coins ->%d\n", coins[i], coinsCount[i]);
}

void AutomationTest () {
   bool isPassed;
   int coins[] = { 10,5,2,1 }, paid[] = { 123,1223,213,12312,210 }, actualAmount[] = { 120, 1000,205,12311,210 };
   int expCoinsCount[][4] = { {0,0,1,1 },{22,0,1,1},{0,1,1,1},{0,0,0,1},{0,0,0,0} };
   for (int i = 0; i < 5; i++) {
      isPassed = true;
      int coinsCount[] = { 0,0,0,0 };
      printf ("\nCase %d:", i + 1);
      CalcCoins (paid[i], actualAmount[i], coinsCount, coins);
      for (int j = 0; j < 4; j++) {
         if (expCoinsCount[i][j] != coinsCount[j]) {
            isPassed = false;
            printf ("Failed!\n");
            break;
         }
      }
      if (isPassed) printf ("Passed!\n");
   }
}