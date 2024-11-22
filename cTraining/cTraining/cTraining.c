// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>;
#include <math.h>
#include <malloc.h>

struct ComplexNumber {
	char real[15];
	char operator;
	char imagin[15];
};

typedef struct ComplexNumber CompNum;

char* Calc (CompNum* num1,CompNum* num2, char operation) {
	num1->imagin[0] = '0';
	num2->imagin[0] = '0';
	char* value = "a+ib";
	switch (operation) {
	case '+':
		value[0] = (atoi (num1->real) + atoi (num2->real))+49;
		value[3] = (atoi (num1->imagin) + atoi (num2->imagin))+49;
		return value;
	case '-':
		value[0] = (atoi (num1->real) > atoi (num2->real)) ? (atoi (num1->real) - atoi (num2->real))+49 : (atoi (num2->real) - atoi (num1->real)) + 49;
		value[3] = (atoi (num1->imagin) > atoi (num2->imagin)) ? (atoi (num1->imagin) - atoi (num2->imagin)) + 49 : (atoi (num2->imagin) - atoi (num1->imagin)) + 49;
		return value;
	case '*':
		value[0] = ((atoi(num1->real) * atoi(num2->real)) - (atoi(num1->imagin) *atoi(num2->imagin)))+49;
		value[3] = ((atoi (num1->real) * atoi (num2->real)) + (atoi (num1->imagin) * atoi (num2->imagin))) + 49;
		return value;
	}
}

char* Add (CompNum* num1, CompNum* num2) {
	char operation = '+';
	return Calc (num1, num2, operation);
}

char* Sub (CompNum* num1, CompNum* num2) {
	char operation = '-';
	return Calc (num1, num2, operation);
}

char* Multi(CompNum* num1, CompNum* num2) {
	char operation = '*';
	return Calc (num1, num2, operation);
}

char* Mod (CompNum *num) {
	char* value = "a+ib";
	*value = (pow (atoi (num->real) * atoi (num->real) + atoi (num->imagin) * atoi (num->imagin),0.5))+49;
	return value;
}

char* conjucate (CompNum* num) {
	char* value = "a+ib";
	value[0] = atoi (num->real)+49;
	value[1]=(num->operator == '-') ? '+' : '-';
	value[3] = atoi (num->imagin) + 49;
	return value;
}

int main () {
	CompNum* num1 = malloc (sizeof (CompNum));
	CompNum* num2 = malloc (sizeof (CompNum));
	if (num1 != NULL) {
		num1->imagin[15] = "2131";
		num1->operator='+';
		num1->real[15] = "32";
	}
	if (num2 != NULL) {
		num1->imagin[15] = "2131";
		num1->operator='+';
		num1->real[15] = "32";
	}

	printf("%s",Add (num1, num2));
}