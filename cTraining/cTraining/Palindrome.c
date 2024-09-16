
#include <ctype.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define GREEN_COLOR "\x1b[32m"
#define YELLOW_COLOR "\x1b[33m"
#define BLUE_COLOR "\x1b[34m"
#define CYAN_COLOR "\x1b[36m"
#define MEGENT_COLOR "\x1b[35m"
#define SUCCESSFUL 1;
#define UNSUCCESSFUL 0;
#define INVALID_INPUT -1012;

/// <summary>This function will display the options for user and get the option from user and then pass the option to the CallFunc function.</summary>
int GetChoice ();

/// <summary>This function will return user input choice is valid or not. </summary>
bool IsValidChoice (char input[], int index);

/// <summary>This function will call the GetText/GetInt function based on option.</summary>
int CallFunc (char* choice);

/// <summary>This function will get the word/sentence from user and pass the data to Display function.</summary>
int GetText ();

/// <summary>This function return length of the given string. </summary>
int StrLen (char sent[]);

/// <summary>This function will return given text is valid or not</summary>
bool IsValidText (int index, char* stPtr);

/// <summary>This Function display given string is palindrome or not.</summary>
int Display (char Text[]);

/// <summary>This function will compare the given input string and reversed string of input and return true or false.</summary>
bool IsPalindromeText (char arr[]);

/// <summary>This function will get the number from user and call the DisplayInt function.</summary>
int GetInt ();

/// <summary>This function will return reversed version of given number.</summary>
int ReverseNum (int num);

/// <summary>This function will return given integer is palindrome or not.</summary>
bool IsPalindromeInt (int num);

/// <summary>This function will display reversed version of given number and palindrome or not.</summary>
int DisplayInt (int num);

/// <summary>This function will return given integer is valid or not.</summary>
bool IsValidInt (char input[], int index);

/// <summary>This function will get the number of test cases from user and display operation is passed or failed.</summary>
int TestCases ();


int GetChoice () {
	printf ("__________________________________\nMenu:\nPalindrome Checker  ->  Enter 1.\nReverse Number      ->  Enter 2.\n__________________________________\n");
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
					return UNSUCCESSFUL;
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
			//converted to lowercase
			if (isupper (c)) c = c + 32;
			if (ispunct (c) || c == ' ') continue;
			if (index > 98) {
				char* temp = realloc (sent, (index + 2) * sizeof (char));
				if (temp != NULL) sent = temp;
			}
			sent[index] = c;
			if (c == '\n') {
				sent[index] = '\0';
				if (IsValidText (index, &sent[0])) return Display (sent);
				else {
					printf (RED_COLOR"Invalid!\n"RESET_COLOR);
					return UNSUCCESSFUL;
				}
			}
			index++;
		}
	}
	return UNSUCCESSFUL;
}

bool IsValidText (int index, char* stPtr) {
	if (*stPtr == '\n') return false;
	return true;
}

int StrLen (char sent[]) {
	int length = 0;
	while (sent[length] != '\0')length++;
	return length;
}

bool IsPalindromeText (char sent[]) {
	int strLen = StrLen (sent);
	char* stPtr = &sent[0];
	char* endPtr = &sent[strLen - 1];
	for (int i = 0; i < strLen; i++) {
		if (*(stPtr++) != *(endPtr--)) return false;
	}
	return true;
}

int Display (char sent[]) {
	if (IsPalindromeText (sent)) {
		printf (GREEN_COLOR"Palindrome\n"RESET_COLOR);
		return SUCCESSFUL;
	}
	printf (CYAN_COLOR"Not a Palindrome\n"RESET_COLOR);
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
				if (IsValidInt (input, index)) {
					int num = atoi (input);
					return DisplayInt (num);
				} else {
					printf (RED_COLOR"Invalid!\n"RESET_COLOR);
					return -1012;
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
		revNumbers[i] = (char)revNum + 48;
		i++;
	}
	revNumbers[i] = '\0';
	revNum = atoi (revNumbers);
	return revNum;
}

bool IsPalindromeInt (int num) {
	int revNum = ReverseNum (num);
	if (num == revNum)return true;
	return false;
}

bool IsValidInt (char input[], int index) {
	for (int j = 0, k = 1; j <= index; j++, k++) {
		if ((!(isdigit (input[j]) || input[j] == '\n')) || input[0] == '\n')return false;
	}
	int num = atoi (input);
	if (num > 2147483647) return false;
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
	if (IsPalindromeInt (num)) {
		printf ("output:%d\n", ReverseNum (num));
		printf (GREEN_COLOR"Palindrome\n"RESET_COLOR);
		return SUCCESSFUL;
	} else {
		printf ("output:%d\n", ReverseNum (num));
		printf (CYAN_COLOR"Not a Palindrome\n"RESET_COLOR);
		return UNSUCCESSFUL;
	}
}

int TestCases () {
	int n = 1, i = 1;
	char c;
	printf ("\nEnter the Number of test cases :");
	scanf_s ("%d%c", &n, &c, 1);
	if (c != '\n' || isalpha (c)) {
		printf (RED_COLOR"Invalid!\n"RESET_COLOR);
		return INVALID_INPUT;
	}
	while (n > 0) {
		printf ("\nCase %d:\n", i++);
		if (GetChoice () == 1) printf (GREEN_COLOR"Passed!\n"RESET_COLOR);
		else printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
		n--;
	}
	return SUCCESSFUL;
}