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
#include <stdbool.h>
#pragma warning(disable : 4996)

struct ComplexNumber {
	float real ;
	float imagin;
};

typedef struct ComplexNumber CompNum;

void Calc (CompNum* num1,CompNum* num2, char operation,CompNum* value) {
	switch (operation) {
	case '+':
		value->real = num1->real + num2->real;
	   value->imagin=num1->imagin + num2->imagin ;
		break;
	case '-':
		value->real = num1->real - num2->real;
		value->imagin=num1->imagin - num2->imagin;
		break;
	case '*':
		value->real = num1->real * num2->real - num1->imagin * num2->imagin;
		value->imagin=num1->real * num2->real + num1->imagin * num2->imagin;
	}
}

void Add (CompNum* num1, CompNum* num2,CompNum* value) {
	char operation = '+';
	Calc (num1, num2, operation,value);
}

void Sub (CompNum* num1, CompNum* num2, CompNum* value) {
	char operation = '-';
	Calc (num1, num2, operation, value);
}

void Multi(CompNum* num1, CompNum* num2, CompNum* value) {
	char operation = '*';
	Calc (num1, num2, operation,value);
}

void Mod (CompNum *num,CompNum* value) {
	value->imagin=pow (num->real* num->real + num->imagin * num->imagin,0.5);
}

void conjucate (CompNum* num,CompNum* value) {
	value->imagin = -(num->imagin);
	value->real = num->real;
}

void ClearInputBuffer () {
	char c;
	while (c = getchar () != '\n');
}

int GetInput (CompNum *num) {
	bool isValid1, isValid2;
	char c, c1;
	do {
		isValid1 = true;
		isValid2 = true;
		printf ("Enter real number: ");
		if (!scanf_s ("%f%c", &num->real, &c1, 1)) {
			ClearInputBuffer ();
			isValid1 = false;
		} else if (c1 != '\n') {
			ClearInputBuffer ();
			isValid1 = false;
		}
		printf ("Enter imaginary number: ");
		if (!scanf_s ("%f%c", &num->imagin, &c, 1)) {
			ClearInputBuffer ();
			isValid2 = false;
		} else if (c != '\n') {
			ClearInputBuffer ();
			isValid2 = false;
		}
		if (!(isValid1 && isValid2)) printf ("Invalid complex number!\n");
	} while (!(isValid1 && isValid2));
}

bool isValidChoice (char* choice) {
	return choice[strlen (choice) - 1] == '\n' && (choice[0] == '0' || choice[0] == '1');
}

int main () {
	bool isExit = false;
	do {
		char choice[3];
		printf ("Enter 0 if you want to exit, else enter 1. \nchoice:");
		fgets (choice, 3, stdin);
		if (isValidChoice (choice)) {
			if (choice[0] == '0') {
				isExit = true;
			}
			else {
				CompNum* num1 = malloc (sizeof (CompNum));
				CompNum* num2 = malloc (sizeof (CompNum));
				CompNum* value = malloc (sizeof (CompNum));
				if (num1 != NULL && num2 != NULL) {
					printf ("Complex number 1:\n");
					GetInput (num1);
					printf ("Complex number 2:\n");
					GetInput (num2);
				}
				if (value != NULL) {
					Add (num1, num2, value);
					printf ("Addtion       :%f %fi\n", value->real, value->imagin);
					Sub (num1, num2, value);
					printf ("Subtraction   :%f %fi\n", value->real, value->imagin);
					Multi (num1, num2, value);
					printf ("Multiplication:%f %fi\n", value->real, value->imagin);
					Mod (num1, value);
					printf ("Modulus1       :%f\n", value->imagin);
					Mod (num2, value);
					printf ("Modulus2       :%f\n", value->imagin);
					conjucate (num1, value);
					printf ("Conjugate1     :%f %fi\n", value->real, value->imagin);
					conjucate (num2, value);
					printf ("Conjugate2     :%f %fi\n", value->real, value->imagin);
				}
			}
		}
		else {
			printf ("Invalid choice!\n");
			if (choice[strlen (choice) - 1] != '\n')ClearInputBuffer ();
		}
	} while (!isExit);
}