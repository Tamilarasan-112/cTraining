#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
long int mLength, mBinary[70],mRev[70];
long long int  number=0;
void Hex (int* ptr);

/// <summary>This function get the decimal value from user and display the Binary and Hexadecimal value for the given decimal value.</summary>
void BinaryAndHexConverter (long long int number);

void TwosComplement (int digits, int start, int end,int onOff);

int main () {
	printf ("Important:\n");
	printf ("Please don't enter more than 11 digits number!\n");
	printf ("If you want to exit enter [CTRL]+[Z]+[ENTER] (OR) [CTRL]+[C]\n");
	char c, input[13] = { 0 };
	int index = 0, it = 0;
	const char* str = input;
	char* endptr=NULL;
	printf ("\nInput:");
	while ((c = getchar ()) != 'ÿ') {
		bool Invalid = false;
		input[index] = c;
		if ((c == '\n')) {
			for (int j = 0,k=1; j <= index; j++,k++) {
				if (isalpha (input[j]) || input[0] == '\n' || ispunct (input[j]) || input[j] == ' ' || index > 13 || (!isdigit(input[j]) && input[j]!='\n')) {
					if (input[0] == '-' && (!isalpha (input[j])) && (input[0] != '\n') && (input[j] != ' ') && index < 13 && (!ispunct (input[k])))continue;
					else {
						Invalid = true;
						break;
					}
				}
			}
			if (Invalid) {
				printf (RED_COLOR"Invalid!\n"RESET_COLOR);
				const int n = 0;
			}
			else {
				number = strtoll(str,&endptr,10);
				if (number == 0) {
					printf ("Binary:%d\n", 0);
					printf ("HEX:%d\n", 0);
				} else BinaryAndHexConverter (number);
			}
			index = -1;
		}
		index++;
		it = 1;
		if (index==0 && it > 0) printf ("\nInput:");
	}
}

void BinaryAndHexConverter (long long int number) {
	int digits = 0, stepIn = 0, onOff = 0;
	long long int positiveInt = 0;
	//if the given integer is signed value 
	if (number < 0) {
		for (number; number < 0; number++)positiveInt++; //this for loop convert negative value to positive value
		number = positiveInt;
		onOff = 1;
	}
	printf ("Binary:");
	//converted to binary
	while (number > 0) {
		mBinary[digits++] = number % 2;
		number = (long long int)(round ((double)(number / 2)));
	}
	for (int a = digits - 1, b = 0; b <= digits - 1; b++, a--) mRev[b] = mBinary[a];
	//if the digit is 8 or less then 8
	if (digits <= 7 && digits >= 0) TwosComplement (digits, 0, 7, onOff);
	//if the digit is 16 or less then 16
   else if (digits <= 15 && digits >= 8) TwosComplement (digits, 8, 15, onOff);
	//if the digit is 16 or less then 16
	else if (digits <= 31 && digits >= 16) TwosComplement (digits, 16, 31, onOff);
	//if the digit is 64 or less then 64
	else if (digits <= 63 && digits >= 32) TwosComplement (digits, 32, 63, onOff);
	int* ptr = &mBinary[0];
	for (long int k = 0; k <= mLength; k++) {
		if ((mBinary[k] == 0) && (stepIn == 0)) continue;
		else {
			printf ("%d", mBinary[k]);
			stepIn = 1;
		}
	}
	Hex (ptr);
}

/// <summary> This function called by BinaryAndHexConverter function and get binary values from that function and print hexadecimal value</summary>
void Hex (int* ptr) {
	int i = 0,m = 0, stepIn = 0;
	printf ("\nHEX:");
	//Binary value converted into hexadecimal
	for (int k = 0; k < (mLength + 1) / 4; k++) {
		int sum = 0;
		for (int j = 0, exp = 3; j < 4; exp--, j++) sum += (*(ptr++)) * (int)pow (2,exp);
		if ((sum == 0) && (stepIn == 0)) continue;
		else {
			(sum < 10) ? printf ("%d", sum):printf ("%c", sum + 55);
			stepIn = 1;
		}
	}
	printf ("\n");
}

void TwosComplement (int digits, int start, int end, int onOff) {
	int index = 0, lastElementIndex = 0;
	//0/1 span to required digits
	for (index; index < ((end) + 1) - (digits); index++) mBinary[index] = (onOff == 1) ? 1 : 0;
	for (int x = 0; x < (digits); x++)(onOff == 1) ? (mBinary[index++] = (mRev[x] == 1) ? 0 : 1): (mBinary[index++] = mRev[x]);
	mLength = index - 1;
	lastElementIndex = mLength;
	//two's complement
	if ((lastElementIndex == (end)) && (onOff==1) && lastElementIndex>=0){
		if ((mBinary[lastElementIndex] == 1) && lastElementIndex >= 0) while ((mBinary[lastElementIndex] += 1) == 2 && (lastElementIndex > 0)) mBinary[lastElementIndex--] = 0;
		else mBinary[lastElementIndex] = 1;
	}
}