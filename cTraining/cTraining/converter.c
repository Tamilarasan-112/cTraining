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
long int mLength, mBinary[70], mRev[70], mCopyBinary[70];
long long int  mNumber = 0;
char mInput[13] = { 0 };
void Hex (int* ptr);
/// <summary>
///  this function will check the given input is valid or or not.
/// </summary>
bool IsValid (int index);

/// <summary>This function get the decimal value from user and display the Binary 
///and Hexadecimal value for the given decimal value.</summary>
void BinaryAndHexConverter (long long int mNumber);

void TwosComplement (int digits, int end, bool onOff);

void TestCases (long long int positiveInt, int digits, bool onOff);

int main () {
	printf ("Important:\n");
	printf ("Please don't enter more than 11 digits number!\n");
	printf ("If you want to exit click [CTRL]+[Z]+[ENTER] (OR) [CTRL]+[C]\n");
	char c;
	int index = 0, it = 0;
	const char* str = mInput;
	char* endptr = NULL;
	printf ("\nInput:");
	bool isValid = true;
	while ((c = getchar ()) != 'ÿ') {
		mInput[index] = c;
		if (c == '\n' || c == '\x1a') {
			if (IsValid (index)) {
				mNumber = strtoll (str, &endptr, 10);
				(mNumber == 0) ? printf ("Binary:0\nHEX:0\n") : BinaryAndHexConverter (mNumber);
			} else {
				printf (RED_COLOR"Invalid!\n"RESET_COLOR);
				const int mNumber = 0;
			}
			index = -1;
		}
		index++;
		it = 1;
		if (index == 0 && it > 0) printf ("\nInput:");
	}
}

void BinaryAndHexConverter (long long int mNumber) {
	int digits = 0;
	bool onOff = false, isLeadingZero = false;
	long long int positiveInt = 0;
	//if the given integer is signed value 
	if (mNumber < 0) {
		for (mNumber; mNumber < 0; mNumber++)positiveInt++; //this for loop convert negative value to positive value
		mNumber = positiveInt;
		onOff = true;
	}
	positiveInt = mNumber;
	//converted to binary
	while (mNumber > 0) {
		mBinary[digits++] = mNumber % 2;
		mNumber = (long long int)(round ((double)(mNumber / 2)));
	}
	for (int a = digits - 1, b = 0; b <= digits - 1; b++, a--) mRev[b] = mBinary[a];
	if (digits >= 0) {
		//if the digit is 8 or less then 8
		if (digits <= 7) TwosComplement (digits, 7, onOff);
		//if the digit is 16 or less then 16
		else if (digits <= 15) TwosComplement (digits, 15, onOff);
		//if the digit is 32 or less then 32
		else if (digits <= 31) TwosComplement (digits, 31, onOff);
		//if the digit is 64 or less then 64
		else if (digits <= 63) TwosComplement (digits, 63, onOff);
	}
	int* ptr = &mBinary[0];
	int* ptr1 = &mBinary[0];
	for (int i = 0; i <= mLength; i++) {
		mCopyBinary[i] = mBinary[i];
	}
	TestCases (positiveInt, digits, onOff);
	printf ("Binary:");
	for (long int k = 0; k <= mLength; k++) {
		if ((mBinary[k] == 0) && (isLeadingZero == false)) continue;
		else {
			printf ("%d", mBinary[k]);
			isLeadingZero = true;
		}
	}
	Hex (ptr);
}

/// <summary> This function called by BinaryAndHexConverter function and get binary values from that function 
///and print hexadecimal value</summary>
void Hex (int* ptr) {
	int i = 0, m = 0;
	bool isLeadingZero = false;
	printf ("\nHEX:");
	//Binary value converted into hexadecimal
	for (int k = 0; k < (mLength + 1) / 4; k++) {
		int sum = 0;
		for (int j = 0, exp = 3; j < 4; exp--, j++) sum += (*(ptr++)) * (int)pow (2, exp);
		if ((sum == 0) && (isLeadingZero == false)) continue;
		else {
			(sum < 10) ? printf ("%d", sum) : printf ("%c", sum + 55);
			isLeadingZero = true;
		}
	}
	printf ("\n");
}

void TwosComplement (int digits, int end, bool onOff) {
	int index = 0, lastElementIndex = 0;
	//0/1 span to required digits
	for (index; index < ((end)+1) - (digits); index++) mBinary[index] = (onOff == true) ? 1 : 0;
	for (int x = 0; x < (digits); x++)(onOff == true) ? (mBinary[index++] = (mRev[x] == 1) ? 0 : 1) : (mBinary[index++] = mRev[x]);
	mLength = index - 1;
	lastElementIndex = mLength;	if ((lastElementIndex == (end)) && (onOff == true) && lastElementIndex >= 0) {
		if ((mBinary[lastElementIndex] == 1) && lastElementIndex >= 0)
			while ((mBinary[lastElementIndex] += 1) == 2 && (lastElementIndex > 0)) mBinary[lastElementIndex--] = 0;
		else mBinary[lastElementIndex] = 1;
	}
}

bool IsValid (int index) {
	if (index > 11) {
		printf (BLUE_COLOR"Please Enter the number less then 12 digit!\n"RESET_COLOR);
		return false;
	}
	for (int j = 0, k = 1; j <= index; j++, k++) {
		if (mInput[0] != '\n') {
			if (isdigit (mInput[j]) || mInput[j] == '\n') continue;
			else {
				if (mInput[0] == '-' && mInput[1] != '\n') {
					for (int i = 1; i <= index; i++) {
						if (isdigit (mInput[i]) || mInput[i] == '\n') continue;
						else return false;
					}
				} else return false;
			}
		} else return false;
	}
	return true;
}

void TestCases (long long int positiveInt, int digits, bool onOff) {
	int lastElementIndex = mLength, x = 0;
	long long int n = 0;
	if ((onOff == true) && lastElementIndex >= 0) {
		for (x; x <= mLength; x++) (mCopyBinary[x] = (mCopyBinary[x] == 1) ? 0 : 1);
		if ((mCopyBinary[lastElementIndex] == 1) && lastElementIndex >= 0)
			while ((mCopyBinary[lastElementIndex] += 1) == 2 && (lastElementIndex > 0)) mCopyBinary[lastElementIndex--] = 0;
		else mCopyBinary[lastElementIndex] = 1;
	}
	for (int i = mLength, j = 0; 0 <= i; i--, j++) n += (mCopyBinary[j]) * (long long int)pow (2, i);
	(n == positiveInt) ? printf (GREEN_COLOR"Passed\n"RESET_COLOR) : printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
}