#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define GREEN_COLOR "\x1b[32m"
#define YELLOW_COLOR "\x1b[33m"
#define BLUE_COLOR "\x1b[34m"

#define UNSUCCESSFUL 0;
#define SUCCESSFUL 1;

/// <summary>Get the input from user and store int passed pointer.</summary>
int GetInt (long long int* number);

/// <summary>Return Successful and covert number into Hexadecimal value.</summary>
int Hex (long long int num, char** hexArray, int* hexDigits);

/// <summary>Return true if the given input is valid.</summary>
bool IsValid (char input[]);

/// <summary>Return Successful and covert number into binary.</summary>
int BinaryConverter (long long int number, int** binary, int* binaryDigits);

void TwosComplement (int digits, int end, bool isNegative, int* binary, int rev[]);

/// <summary>This function will test function by possible inputs.</summary>
void TestCases ();

int main () {
   TestCases ();
}

int GetInt (long long int* number) {
   char input[20] = { '0' };
   const char* str = input;
   char* endptr = NULL;
   printf ("\nInput:");
   fgets (input, 20, stdin);
   if (IsValid (input)) {
      *number = strtoll (str, &endptr, 10);
      return SUCCESSFUL;
   } else {
      printf (RED_COLOR"Invalid!\n"RESET_COLOR);
      *number = 0;
      return UNSUCCESSFUL;
   }
}

bool IsValid (char input[]) {
   if (strlen (input) > 16) {
      printf (BLUE_COLOR"Please Enter the number less then 17 digit!\n"RESET_COLOR);
      return false;
   }
   char* temp = input + 1, * fstChar = input, * scdChar = (input + 1);
   if (*fstChar == '\n') return false;
   for (int j = 0, k = 1; j < strlen (input); j++, k++) {
      if (!(isdigit (*(input)) || *input == '\n')) {
         if (!(*fstChar == '-' && *scdChar != '\n')) return false;
         for (int i = 1; i <= strlen (input); i++) {
            if (!(isdigit (*(temp)) || *temp == '\n')) return false;
            temp++;
         }
      }
      input++;
   }
   return true;
}

int BinaryConverter (long long int number, int** binary, int* binaryDigits) {
   long int binaryArray[70] = { 0 }, rev[70] = { 0 }, copyBinary[130] = { 0 };
   int digits = 0;
   bool isNegative = false;
   if (number == 0) {
      *binary = binaryArray;
      *binaryDigits = 0;
      return SUCCESSFUL;
   }
   if (number < 0) {
      isNegative = true;
      number = -number;
   }
   // if invalid
   if (number > 999999999999999) {
      *binary = binaryArray;
      *binaryDigits = 0;
      return UNSUCCESSFUL;
   }
   //converted to binary
   while (number > 0) {
      binaryArray[digits++] = number % 2;
      number = (long long int)(round ((double)(number / 2)));
   }

   for (int a = digits - 1, b = 0; b <= digits - 1; b++, a--) rev[b] = binaryArray[a];
   if (digits >= 0) {
      if (digits <= 7) {
         TwosComplement (digits, 7, isNegative, binaryArray, rev);
         *binaryDigits = 7;
      } else if (digits <= 15) {
         TwosComplement (digits, 15, isNegative, binaryArray, rev);
         *binaryDigits = 15;
      } else if (digits <= 31) {
         TwosComplement (digits, 31, isNegative, &binaryArray, rev);
         *binaryDigits = 31;
      } else if (digits <= 63) {
         TwosComplement (digits, 63, isNegative, &binaryArray, rev);
         *binaryDigits = 63;
      }
   }
   *binary = binaryArray;
   return SUCCESSFUL;
}

void TwosComplement (int digits, int end, bool isNegative, int* binary, int rev[]) {
   int index = 0, lastElementIndex = 0;
   //0/1 span to required digits
   for (index; index < ((end)+1) - (digits); index++) {
      *binary = (isNegative) ? 1 : 0;
      binary++;
   }
   for (int x = 0; x < (digits); x++) {
      if (isNegative) *binary = (rev[x] == 1) ? 0 : 1;
      else *binary = rev[x];
      binary++;
      index++;
   }
   binary--;
   //add 1 with the last digit
   if ((index - 1 == (end)) && (isNegative)) {
      if ((*binary == 1)) {
         while ((*binary += 1) == 2) {
            *(binary) = 0;
            binary--;
         }
      } else *binary = 1;
   }
}

int Hex (long long int num, char** hexArray, int* hexDigits) {
   char hex[20] = { '0' };
   int length = 0;
   if (num == 0) {
      *hexDigits = 0;
      *hexArray = hex;
      return SUCCESSFUL;
   }
   int* binary = (int*)malloc (sizeof (int));
   BinaryConverter (num, &binary, &length);
   bool isLeadingZero = true;
   int digits = 0;
   //Binary value converted into hexadecimal
   for (int k = 0; k < (length + 1) / 4; k++) {
      int sum = 0;
      for (int j = 0, exp = 3; j < 4; exp--, j++) sum += (*(binary++)) * (int)pow (2, exp);
      if ((sum != 0) || !(isLeadingZero)) {
         if (sum < 10) hex[digits] = (char)(sum + 48);
         else hex[digits] = (char)(sum + 55);
         digits++;
         isLeadingZero = false;
      }
   }
   *hexDigits = digits - 1;
   *hexArray = hex;
   return SUCCESSFUL;
}

void TestCases () {
   long long int testIp[] = { -255,10,255,-999999999,9999999999,-2,0,-999999999999999 };
   int ExpectOut[][64] = { { 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1 },{1,0,1,0},
      { 1,1,1,1,1,1,1,1 },{1,1,0,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,},
      {1,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,0},{0}
   ,{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1} };

   char ExpectOutC[][20] = { "FF01","A","FF","C4653601","2540BE3FF","FE","0","FFFC72815B398001" };
   for (int i = 0; i < 8; i++) {
      bool isEqualBin = true, isEqualHex = true, isLeadingZeroBin = true, isLeadingZeroHex = true;
      long int indexBin = 0, indexHex = 0;
      int* binary = (int*)malloc (sizeof (int));
      char* hexPtr = (int*)malloc (sizeof (char));
      int binaryDigits = 0, hexDigits = 0;
      BinaryConverter (testIp[i], &binary, &binaryDigits);
      printf ("\ninput:%lld", testIp[i]);
      printf ("\nBinary:");
      for (long int k = 0; k <= binaryDigits; k++) {
         if ((*binary != 0) || !(isLeadingZeroBin) || binaryDigits == 0) {
            printf ("%d", *binary);
            if (ExpectOut[i][indexBin++] != *binary) isEqualBin = false;
            isLeadingZeroBin = false;
         }
         binary++;
      }
      Hex (testIp[i], &hexPtr, &hexDigits);
      printf ("\nHex:");
      for (long int k = 0; k <= hexDigits; k++) {
         if ((*hexPtr != 0) || !(isLeadingZeroHex) || hexDigits == 0) {
            printf ("%c", *hexPtr);
            if (ExpectOutC[i][indexHex++] != *hexPtr) isEqualHex = false;
            isLeadingZeroHex = false;
         }
         hexPtr++;
      }
      printf ("\n");
      (isEqualBin && isEqualHex) ? printf (GREEN_COLOR"Passed\n"RESET_COLOR) : printf (YELLOW_COLOR"Failed\n"RESET_COLOR);
   }
}