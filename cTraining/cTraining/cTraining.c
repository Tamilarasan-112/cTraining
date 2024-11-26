// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>

bool isValidAmount (char* Amount);
int CalcCoins (int paid, int actualAmount, int* rs10_Coins, int* rs5_Coins, int* rs2_Coins, int* rs1_Coins);
void Display ();
int GetAmount (int* paid, int* actualAmount);

int main () {
	Display ();
}

int GetAmount (int *paid,int *actualAmount) {
	char* paidStr = malloc (15 * sizeof (char)), * actualAmountStr = malloc (15 * sizeof (char));
	do {
		printf ("You enter the payment 1 to 2,147,483,647 \n");
		printf ("Paid Amount:");
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
	long long int num = strtoll(Amount,&end,10);
	int strLen = strlen (Amount);
	if (Amount[strLen - 1] != '\n' || !(num > 0 && num <= 2147483647))return false;
	for (int i = 0; i < strLen-1; i++) {
		if (!isdigit (Amount[i]))return false;
	}
	return true;
}

int CalcCoins (int paid,int actualAmount, int* rs10_Coins, int* rs5_Coins, int* rs2_Coins, int* rs1_Coins) {
	int change = paid - actualAmount;
	if (change <= 0) {
		printf ("No need to give changes\n");
		return 0;
	}
	if (change >= 10) {
		*rs10_Coins = change / 10;
		change %= 10;
	}
	if (change >= 5) {
		*rs5_Coins = change / 5;
		change %= 5;
	}
	if (change >= 2) {
		*rs2_Coins = change / 2;
		change %= 2;
	}
	if (change >= 1) {
		*rs1_Coins = change / 1;
		change %= 1;
	}
	return 1;
}

void Display () {
	int paid=0, actualAmount=0;
	int rs10_Coins=0, rs5_Coins=0, rs2_Coins=0, rs1_Coins=0;
	GetAmount (&paid,&actualAmount);
	CalcCoins (paid, actualAmount, &rs10_Coins, &rs5_Coins, &rs2_Coins, &rs1_Coins);
	printf ("Rs.10 Coins ->%d\nRs.5 Coins->%d\nRs.2 Coins->%d\nRs.1 Coins->%d\n", rs10_Coins, rs5_Coins, rs2_Coins, rs1_Coins);
}