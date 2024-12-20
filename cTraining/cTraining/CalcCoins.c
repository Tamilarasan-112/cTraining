// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
//CalcCoins.c
//Implemented a method to store the number of coins in each denomination (Rs. 10, Rs. 5, Rs. 2, Rs. 1) for change.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/// <summary>Returns true if the input amount is Valid; otherwise, false.</summary>
bool IsValidAmount (char* amount);

/// <summary>Returns 1 if coins are counted and stored in the array; otherwise, 0.</summary>
int CalcCoins (int paid, int actualAmount, int coinsCount[], int coins[]);

/// <summary>Get the paid and actual amounts from the user and display the number of coins 
///needed for each denomination for change.</summary>
void PrintBalanceCoins ();

/// <summary>Gets the amount from the user.</summary>
void GetAmount (int* paid, int* actualAmount);

/// <summary>To automatically test the CalcCoins method.</summary>
int AutomationTest ();

int main () {
   PrintBalanceCoins ();
   //AutomationTest ();
}

void GetAmount (int* paid, int* actualAmount) {
   char paidStr[11], actualAmountStr[11]; //Assuming paid and bill amount has 11 characters.
   do {
      printf ("You enter the payment 1 to 2,147,483,647 \nPaid amount : ");
      fgets (paidStr, 11, stdin);
      printf ("Actual amount:");
      fgets (actualAmountStr, 11, stdin);
   } while (!(IsValidAmount (paidStr) && IsValidAmount (actualAmountStr)));
   *paid = atoi (paidStr);
   *actualAmount = atoi (actualAmountStr);
}

bool IsValidAmount (char* amount) {
   if (amount[0] == '-') return false;
   char* end;
   long long int num = strtoll (amount, &end, 10);
   if (*end != '\n' || !(num > 0 && num <= INT_MAX)) return false;
   return true;
}

int CalcCoins (int paid, int actualAmount, int coinsCount[], int coins[]) {
   int change = paid - actualAmount, i = 0;
   if (change < 0) return 0;
   do {
      coinsCount[i] = change / coins[i];
      change %= coins[i++];
   } while (change > 0);
   return 1;
}

void PrintBalanceCoins () {
   int paid = 0, actualAmount = 0, coins[] = { 10,5,2,1 }, coinsCount[] = { 0,0,0,0 }, balance;
   GetAmount (&paid, &actualAmount);
   balance = actualAmount - paid;
   if (!CalcCoins (paid, actualAmount, coinsCount, coins))
      printf ("Ask for the remaining amount %d to be paid \n", balance);
   for (int i = 0; i < 4; i++)
      printf ("Rs.%d Coins ->%d\n", coins[i], coinsCount[i]);
}

int AutomationTest () {
   printf ("\nTest case:");
   int coins[] = { 10,5,2,1 }, paid[] = { 123,1223,213,12312,210 }, actualAmount[] = { 120, 1000,205,12311,210 };
   int expCoinsCount[][4] = { {0,0,1,1},{22,0,1,1},{0,1,1,1},{0,0,0,1},{0,0,0,0} };
   for (int i = 0; i < 5; i++) {
      int coinsCount[] = { 0,0,0,0 };
      CalcCoins (paid[i], actualAmount[i], coinsCount, coins);
      for (int j = 0; j < 4; j++) {
         if (expCoinsCount[i][j] != coinsCount[j]) {
            printf ("Failed!\n An error occurred when the paid amount was %d and the actual amount was %d", paid[i], actualAmount[i]);
            return 0;
         }
      }
   }
   printf ("Passed!\n");
   return 1;
}