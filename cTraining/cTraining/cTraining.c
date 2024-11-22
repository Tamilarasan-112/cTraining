// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>;





int main () {
	int paid;
	int Amound;
	int coins=0;
	char c;
	scanf_s("%d", &paid);
	scanf_s("%d", &Amound);
	int change = paid - Amound;
	CalcCoins (&coins, change);
	printf ("%d", coins);
}

int CalcCoins (int *coins, int change) {
	int coin[4] = { 10,5,2,1 };
	int i = 0;
	while (change > 0) {
		if (change % 10 == 0) {
			(*coins)++;
			change /= 10;
		} else if (change % 5 == 0) {
			(*coins)++;
			change /= 5;
		} else if (change % 2 == 0) {
			(*coins)++;
			change /= 2;
		} else if (change % 1 == 0) {
			(*coins)++;
			change /= 1;
		}
	}

}