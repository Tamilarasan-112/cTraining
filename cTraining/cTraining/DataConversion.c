// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DataConversion.c
// Implemented the program ,which is convert the number in the integer into word.
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>

/// <summary>Print the decimal number into word</summary>
void DataConversion (int num);

/// <summary>Return 1 if the input valid,else 0.</summary>
int Input (int* number);

int main () {
   int num = 0;
   printf ("If want stop the program enter any invalid value.\n");
   do {
      if (!Input (&num)) break;
      DataConversion (num);
   } while (true);
}

int Input (int* number) {
   char c;
   printf ("Please enter the number between 0-999: ");
   if (!scanf_s ("%d%c", &(*number), &c, 1) || !(*number>=0 && *number< 1000) || c != '\n') {
      printf ("invalid input!");
      return 0;
   }
   return 1;
}

void DataConversion (int num) {
   char word1[][7] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
   char word2[][11] = { "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nine teen" };
   char word3[][10] = { "ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","nighty","hundred" };
   int arr[4], i = 0;

   do {
      arr[i++] = num % 10;
      num /= 10;
   } while (num > 0);

   switch (i) {
      case 1:
         printf ("%s\n", word1[arr[0]]);
         break;
      case 2:
         if (arr[0] != 0 && arr[1] == 1)printf ("%s\n", word2[arr[0] - 1]);
         else if (arr[0] != 0) printf ("%s %s\n", word3[arr[1] - 1], word1[arr[0]]);
         else printf ("%s\n", word3[arr[1] - 1]);
         break;
      case 3:
         if (arr[1] == 0)printf ("%s %s %s\n", word1[arr[2]], word3[9], word1[arr[0]]);
         else if (arr[1] == 1 && arr[0] != 0)printf ("%s %s %s\n", word1[arr[2]], word3[9], word2[arr[0] - 1]);
         else printf ("%s %s %s %s\n", word1[arr[2]], word3[9], word3[arr[1] - 1], word1[arr[0]]);
   }
}