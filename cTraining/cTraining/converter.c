#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define GREEN_COLOR "\x1b[32m"
#define YELLOW_COLOR "\x1b[33m"
#define BLUE_COLOR "\x1b[34m"
long int mLength, mBinary[70], mRev[70], mCopyBinary[130];
long long int  mNumber = 0;
char mInput[20] = { 0 };

/// <summary>This function will convert binary values to hexadecimal value.</summary>
void Hex (int* ptr);

/// <summary>This function will check the given input is valid or or not.</summary>
bool IsValid (int index, bool* isNegative);

/// <summary>This function get the decimal value from user and display the Binary 
/// and Hexadecimal value for the given decimal value.</summary>
void BinaryAndHexConverter (long long int mNumber, bool* isNegative);

void TwosComplement (int digits, int end, bool* isNegative);

/// <summary>This function will convert the binary into decimal and compare the given decimal value and 
/// converted decimal value to display passed or failed.</summary>
void TestCases (long long int positiveInt, int digits, bool* isNegative);

int main () {
	printf ("Important:\nPlease don't enter more than 16 digits number!\nIf you want to exit press [Enter]\n");
	char c = '0';
	int index = 0;
	const char* str = mInput;
	char* endptr = NULL;
	printf ("\nInput:");
	while ((c = getchar ())) {
		bool x = false;
		mInput[index] = c;
		if (mInput[0] == '\n') return 0;
		if (c == '\n' || c == '\x1a' || c == 'ÿ') { // To handle the console from exiting when Ctrl+C or Ctrl+Enter is pressed.
			if (IsValid (index, &x)) {
				mNumber = strtoll (str, &endptr, 10);
				(mNumber == 0) ? printf (GREEN_COLOR"Passed\n"RESET_COLOR"Binary:0\nHEX:0\n"):BinaryAndHexConverter (mNumber, &x);
			} else {
				printf (RED_COLOR"Invalid!\n"RESET_COLOR);
				const int mNumber = 0;
			}
			index = -1;
		}
		index++;
		if (index == 0) printf ("\nInput:");
	}
}

void BinaryAndHexConverter (long long int mNumber, bool* isNegative) {
	int digits = 0;
	bool isLeadingZero = true;
	long long int positiveInt = mNumber;
	//converted to binary
	while (mNumber > 0) {
		mBinary[digits++] = mNumber % 2;
		mNumber = (long long int)(round ((double)(mNumber / 2)));
	}
	for (int a = digits - 1, b = 0; b <= digits - 1; b++, a--) mRev[b] = mBinary[a];
	if (digits >= 0) {
		if (digits <= 7) TwosComplement (digits, 7, isNegative);
		else if (digits <= 15) TwosComplement (digits, 15, isNegative);
		else if (digits <= 31) TwosComplement (digits, 31, isNegative);
		else if (digits <= 63) TwosComplement (digits, 63, isNegative);
	}
	int* ptr = &mBinary[0];
	for (int i = 0; i <= mLength; i++) mCopyBinary[i] = mBinary[i];
	TestCases (positiveInt, digits, isNegative);
	printf ("Binary:");
	for (long int k = 0; k <= mLength; k++) {
		if ((mBinary[k] != 0) || !(isLeadingZero)) {
			printf ("%d", mBinary[k]);
			isLeadingZero = false;
		}
	}
	Hex (ptr);
}

void Hex (int* ptr) {
	int i = 0, m = 0;
	bool isLeadingZero = true;
	printf ("\nHEX:");
	//Binary value converted into hexadecimal
	for (int k = 0; k < (mLength + 1) / 4; k++) {
		int sum = 0;
		for (int j = 0, exp = 3; j < 4; exp--, j++) sum += (*(ptr++)) * (int)pow (2, exp);
		if ((sum != 0) || !(isLeadingZero)) {
			(sum < 10) ? printf ("%d", sum) : printf ("%c", sum + 55);
			isLeadingZero = false;
		}
	}
	printf ("\n");
}

void TwosComplement (int digits, int end, bool* isNegative) {
	int index = 0, lastElementIndex = 0;
	//0/1 span to required digits
	for (index; index < ((end)+1) - (digits); index++) mBinary[index] = (*isNegative == true) ? 1 : 0;
	for (int x = 0; x < (digits); x++)(*isNegative == true) ? (mBinary[index++] = (mRev[x] == 1) ? 0 : 1) : (mBinary[index++] = mRev[x]);
	mLength = index - 1;
	lastElementIndex = mLength;
	//add 1 with the last digit
	if ((lastElementIndex == (end)) && (*isNegative == true) && lastElementIndex >= 0) {
		if ((mBinary[lastElementIndex] == 1) && lastElementIndex >= 0)
			while ((mBinary[lastElementIndex] += 1) == 2 && (lastElementIndex > 0)) mBinary[lastElementIndex--] = 0;
		else mBinary[lastElementIndex] = 1;
	}
}

bool IsValid (int index, bool* isNegative) {
	if (index > 16) {
		printf (BLUE_COLOR"Please Enter the number less then 17 digit!\n"RESET_COLOR);
		return false;
	}
	for (int j = 0, k = 1; j <= index; j++, k++) {
		if (!(isdigit (mInput[j]) || mInput[j] == '\n')) {
			if (!(mInput[0] == '-' && mInput[1] != '\n')) return false;
			*isNegative = true;
			if (j == 0 && mInput[0] == '-')mInput[0] = '0';
			for (int i = 1; i <= index; i++) 
				if (!(isdigit (mInput[i]) || mInput[i] == '\n')) return false;
		}
	}
	return true;
}

void TestCases (long long int positiveInt, int digits, bool* isNegative) {
	int lastElementIndex = mLength, x = 0;
	long long int n = 0;
	if ((*isNegative == true) && lastElementIndex >= 0) {
		for (x; x <= mLength; x++) (mCopyBinary[x] = (mCopyBinary[x] == 1) ? 0 : 1);
		if ((mCopyBinary[lastElementIndex] == 1) && lastElementIndex >= 0)
			while ((mCopyBinary[lastElementIndex] += 1) == 2 && (lastElementIndex > 0)) mCopyBinary[lastElementIndex--] = 0;
		else mCopyBinary[lastElementIndex] = 1;
	}
	for (int i = mLength, j = 0; 0 <= i; i--, j++) n += (mCopyBinary[j]) * (long long int)pow (2, i);
	(n == positiveInt) ? printf (GREEN_COLOR"Passed\n"RESET_COLOR) : printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
}