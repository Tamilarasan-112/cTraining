// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// cTraining.c
// Implemented addition, subtraction, multiplication, modulus, and conjugate for complex numbers.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

struct ComplexNumber {
   float real;
   float imagin;
};

typedef struct ComplexNumber CompNum;

/// <summary>To test all the operations automatically</summary>
void AutomationTest ();

/// <summary>To Test the all the operation manualy. </summary>
void ManualTest ();

/// <summary>To perform addition, subtraction, and multiplication on two complex numbers.</summary>
void Calc (CompNum* num1, CompNum* num2, char operation, CompNum* value);

void Add (CompNum* num1, CompNum* num2, CompNum* value);

void Sub (CompNum* num1, CompNum* num2, CompNum* value);

void Multi (CompNum* num1, CompNum* num2, CompNum* value);

/// <summary>To compute the modulus of a complex number.</summary>
void Mod (CompNum* num, CompNum* value);

/// <summary>To compute the conjugate of the complex number.</summary>
void Conjugate (CompNum* num, CompNum* value);

/// <summary>Clear the buffered input data.</summary>
void ClearInputBuffer ();

/// <summary>Get the complex number from the user.</summary>
void GetInput (CompNum* num);

/// <summary>Return true if the choice is correct, else false.</summary>
bool isValidChoice (char* choice);

int main () {
   //AutomationTest ();
   ManualTest ();

}

void Calc (CompNum* num1, CompNum* num2, char operation, CompNum* value) {
   switch (operation) {
   case '+':
      value->real = num1->real + num2->real;
      value->imagin = num1->imagin + num2->imagin;
      break;
   case '-':
      value->real = num1->real - num2->real;
      value->imagin = num1->imagin - num2->imagin;
      break;
   case '*':
      value->real = num1->real * num2->real - num1->imagin * num2->imagin;
      value->imagin = num1->real * num2->imagin + num1->imagin * num2->real;
   }
}

void Add (CompNum* num1, CompNum* num2, CompNum* value) {
   char operation = '+';
   Calc (num1, num2, operation, value);
}

void Sub (CompNum* num1, CompNum* num2, CompNum* value) {
   char operation = '-';
   Calc (num1, num2, operation, value);
}

void Multi (CompNum* num1, CompNum* num2, CompNum* value) {
   char operation = '*';
   Calc (num1, num2, operation, value);
}

void Mod (CompNum* num, CompNum* value) {
   value->imagin = (float)pow (num->real * num->real + num->imagin * num->imagin, 0.5); //assuming modulus of complex number value stored as imaginary value
}

void Conjugate (CompNum* num, CompNum* value) {
   value->imagin = -(num->imagin);
   value->real = num->real;
}

void ClearInputBuffer () {
   char c;
   while (c = getchar () != '\n');
}

void GetInput (CompNum* num) {
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

void ManualTest () {
    bool isExit = false;
   do {
      char choice[3];
      printf ("Enter 0 if you want to exit, else enter 1. \nchoice:");
      fgets (choice, 3, stdin);
      if (isValidChoice (choice)) {
         if (choice[0] == '0') {
            isExit = true;
         } else {
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
               if (isinf (value->real) || isinf (value->imagin))printf ("The value exceeds float range!\n");
               else printf ("Addition       :%f %fi\n", value->real, value->imagin);
               Sub (num1, num2, value);
               if (isinf (value->real) || isinf (value->imagin))printf ("The value exceeds float range!\n");
               else printf ("Subtraction   :%f %f\n", value->real, value->imagin);
               Multi (num1, num2, value);
               if (isinf (value->real) || isinf (value->imagin))printf ("The value exceeds float range!\n");
               else printf ("Multiplication:%f %f\n", value->real, value->imagin);
               Mod (num1, value);
               if (isinf (value->imagin))printf ("The value exceeds float range!.\n");
               else printf ("Modulus1       :%f\n", value->imagin);
               Mod (num2, value);
               if (isinf (value->imagin))printf ("The value exceeds float range!.\n");
               else printf ("Modulus2       :%f\n", value->imagin);
               Conjugate (num1, value);
               if (isinf (value->real) || isinf (value->imagin))printf ("The value exceeds float range!\n");
               else printf ("Conjugate1     :%f %fi\n", value->real, value->imagin);
               Conjugate (num2, value);
               if (isinf (value->real) || isinf (value->imagin))printf ("The value exceeds float range!\n");
               else printf ("Conjugate2     :%f %fi\n", value->real, value->imagin);
            }
         }
      } else {
         printf ("Invalid choice!\n");
         if (choice[strlen (choice) - 1] != '\n')ClearInputBuffer ();
      }
   } while (!isExit);
}

void AutomationTest () {
   float num1Real[] = { 121.2324f,324.2334f,32.3324f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float num1Imagin[] = { -324.00f,-3423.00f,-34.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float num2Real[] = { 23.00f,324.00f,32.324f,-340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float num2Imagin[] = { 534.345f,435.43f,4353.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };

   float expRealAdd[] = { 144.23f,648.23f,64.66f,1.0f,0.0f },expImaginAdd[] = { 210.35f ,-2987.57f,4319.00f,1.0f,0.0f };
   float expRealSub[] = { 98.23f,0.23f,0.01f,1.0f,0.0f },expImaginSub[] = { -858.35f,-3858.43f,-4387.00f,1.0f,0.0f };
   float expRealMulti[] = { 175916.13f,1595528.51f,149047.11f,1.0f,0.0f },expImaginMulti[] = { 57327.93f,-967871.05f,139643.92f,1.0f,0.0f };
   float expImaginMod1[] = { 345.94f,3438.32f,46.92f,1.0f,0.0f},expImaginMod2[] = { 534.84f,542.75f,4353.12f,1.0f,0.0f };

   CompNum* num1 = malloc (sizeof (CompNum));
   CompNum* num2 = malloc (sizeof (CompNum));
   CompNum* value = malloc (sizeof (CompNum));

   for (int i = 0; i < 5; i++) {
      printf ("\nCase%d:\n", i + 1);
      if (value != NULL) {
         num1->real = num1Real[i];
         num1->imagin = num1Imagin[i];
         printf ("Complex number1:\nInput real number:%f\nInput imaginary number:%f\n", num1Real[i],num1Imagin[i]);
         num2->real = num2Real[i];
         num2->imagin = num2Imagin[i];
         printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", num2Real[i], num2Imagin[i]);

         Add (num1, num2, value);
         int ret1 = isinf (value->real) || isinf (value->imagin);
         if (ret1) {
            if (ret1 == expRealAdd[i] && ret1 == expImaginAdd[i]) printf ("Addition Passed!\n");
            else printf ("Addition Failed!\n");
         }
         else {
            if(round(value->real) == round(expRealAdd[i]) && round(value->imagin) == round(expImaginAdd[i])) printf ("Addition Passed!\n");
            else printf ("Addition Failed!\n");
         }

         Sub (num1, num2, value);
         int ret2 = isinf (value->real) || isinf (value->imagin);
         if (ret2) {
            if (ret2 == expRealSub[i] && ret2 == expImaginSub[i]) printf ("Subtraction Passed!\n");
            else printf ("Subtraction Failed!\n");
         } else {
            if (round(value->real) == round(expRealSub[i]) && round(value->imagin) == round(expImaginSub[i])) printf ("Subtraction Passed!\n");
            else printf ("Subtraction Failed!\n");
         }

         Multi (num1, num2, value);
         int ret3 = isinf (value->real) || isinf (value->imagin);
         if (ret3) {
            if (ret3 == expRealMulti[i] && ret3 == expImaginMulti[i]) printf ("Multiplication Passed!\n");
            else printf ("Multiplication Failed!\n");
         } else {
            if (round(value->real) == round(expRealMulti[i]) && round(value->imagin) == round(expImaginMulti[i])) printf ("Multiplication Passed!\n");
            else printf ("Multiplication Failed!\n");
         }

         Mod (num1, value);
         int ret4 = isinf (value->imagin);
         if (ret4) {
            if (ret4 == expImaginMod1[i]) printf ("Modulus Passed!\n");
            else printf ("Modulus Failed!\n");
         } else {
            if (round(value->imagin) == round(expImaginMod1[i])) printf ("Modulus Passed!\n");
            else printf ("Modulus Failed!\n");
         }

         Mod (num2, value);
         int ret5 = isinf (value->imagin);
         if (ret5) {
            if (ret5 == expImaginMod2[i]) printf ("Modulus Passed!\n");
            else printf ("Modulus Failed!\n");
         } else {
            if (round(value->imagin) == round(expImaginMod2[i])) printf ("Modulus Passed!\n");
            else printf ("Modulus Failed!\n");
         }
      }
   }
}