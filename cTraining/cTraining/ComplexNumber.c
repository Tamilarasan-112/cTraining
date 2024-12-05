// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// ComplexNumber.c
// Implemented addition, subtraction, multiplication, modulus, and conjugate for complex numbers.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

struct ComplexNumber {
   float real;
   float imagin;
};

typedef struct ComplexNumber Complexop;

/// <summary>Test all the operations automatically</summary>
void AutomationTest ();

/// <summary>Test the all the operations manually. </summary>
void ManualTest ();

/// <summary>Add two complex numbers and return the result.</summary>
Complexop Add (Complexop op1, Complexop op2);

/// <summary>Subtract two complex numbers and return the result.</summary>
Complexop Sub (Complexop op1, Complexop op2);

/// <summary>Perform the multiplication of two complex numbers and return the result.</summary>
Complexop Multi (Complexop op1, Complexop op2);

/// <summary>Compute the modulus of a complex number and return the result.</summary>
float Mod (Complexop op);

/// <summary>Compute the conjugate of the complex number and return the result.</summary>
Complexop Conjugate (Complexop op);

/// <summary>Clear the buffered input data.</summary>
void ClearInputBuffer ();

/// <summary>Get the complex number from the user and return the operand.</summary>
int GetInput (Complexop* op);

/// <summary>Return true if the choice is correct, else false.</summary>
bool isValidChoice (char* choice);

int main () {
   //AutomationTest ();
   ManualTest ();
}

Complexop Add (Complexop op1, Complexop op2) {
   Complexop result;
   result.real = op1.real + op2.real;
   result.imagin = op1.imagin + op2.imagin;
   return result;
}

Complexop Sub (Complexop op1, Complexop op2) {
   Complexop result;
   result.real = op1.real - op2.real;
   result.imagin = op1.imagin - op2.imagin;
   return result;
}

Complexop Multi (Complexop op1, Complexop op2) {
   Complexop result;
   result.real = op1.real * op2.real - op1.imagin * op2.imagin;
   result.imagin = op1.real * op2.imagin + op1.imagin * op2.real;
   return result;
}

float Mod (Complexop op) {
   float real = (float)pow (op.real * op.real + op.imagin * op.imagin, 0.5);
   return real;
}

Complexop Conjugate (Complexop op) {
   Complexop result;
   result.real = op.real;
   result.imagin = -(op.imagin);
   return result;
}

void ClearInputBuffer () {
   while (getchar () != '\n');
}

int GetInput (Complexop* op) {
   bool isValid = true;
   char c, c1;
   printf ("Enter real number: ");
   if (!scanf_s ("%f%c", &op->real, &c1, 1)) {
      ClearInputBuffer ();
      isValid = false;
   } else if (c1 != '\n') {
      ClearInputBuffer ();
      isValid = false;
   }
   printf ("Enter imaginary number: ");
   if (!scanf_s ("%f%c", &op->imagin, &c, 1)) {
      ClearInputBuffer ();
      isValid = false;
   } else if (c != '\n') {
      ClearInputBuffer ();
      isValid = false;
   }
   if (!(isValid)) return 0;
   return 1;
}

bool isValidChoice (char* choice) {
   return choice[strlen (choice) - 1] == '\n' && (choice[0] == '0' || choice[0] == '1');
}

void ManualTest () {
   do {
      char choice[3];
      printf ("Enter 0 if you want to exit, else enter 1. \nchoice:");
      fgets (choice, 3, stdin);
      if (isValidChoice (choice)) {
         if (choice[0] == '0') {
            break;
         } else {
            Complexop op1;
            Complexop op2;
            Complexop result;
            int ret;

            do {
               printf ("Complex number 1:\n");
               ret = GetInput (&op1);
               if (!ret) printf ("Invalid complex number!\n");
               else break;
            } while (true);
            do {
               printf ("Complex number 2:\n");
               ret = GetInput (&op2);
               if (!ret) printf ("Invalid complex number!\n");
               else break;
            } while (true);

            result = Add (op1, op2);
            if (isinf (result.real) || isinf (result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Addition       :%f %fi\n", result.real, result.imagin);
            result = Sub (op1, op2);
            if (isinf (result.real) || isinf (result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Subtraction   :%f %f\n", result.real, result.imagin);
            result = Multi (op1, op2);
            if (isinf (result.real) || isinf (result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Multiplication:%f %f\n", result.real, result.imagin);
            float output = Mod (op1);
            if (isinf (output))printf ("The result exceeds float range!.\n");
            else printf ("Modulus1       :%f\n", output);
            output = Mod (op2);
            if (isinf (output))printf ("The result exceeds float range!.\n");
            else printf ("Modulus2       :%f\n", output);
            result = Conjugate (op1);
            if (isinf (result.real) || isinf (result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Conjugate1     :%f %fi\n", result.real, result.imagin);
            result = Conjugate (op2);
            if (isinf (result.real) || isinf (result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Conjugate2     :%f %fi\n", result.real, result.imagin);
         }
      } else {
         printf ("Invalid choice!\n");
         if (choice[strlen (choice) - 1] != '\n')ClearInputBuffer ();
      }
   } while (true);
}

void AutomationTest () {
   float op1Real[] = { 121.2324f,324.2334f,32.3324f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op1Imagin[] = { -324.00f,-3423.00f,-34.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op2Real[] = { 23.00f,324.00f,32.324f,-340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op2Imagin[] = { 534.345f,435.43f,4353.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };

   float expRealAdd[] = { 144.23f,648.23f,64.66f,1.0f,0.0f }, expImaginAdd[] = { 210.35f ,-2987.57f,4319.00f,1.0f,0.0f };
   float expRealSub[] = { 98.23f,0.23f,0.01f,1.0f,0.0f }, expImaginSub[] = { -858.35f,-3858.43f,-4387.00f,1.0f,0.0f };
   float expRealMulti[] = { 175916.13f,1595528.51f,149047.11f,1.0f,0.0f }, expImaginMulti[] = { 57327.93f,-967871.05f,139643.92f,1.0f,0.0f };
   float expImaginMod1[] = { 345.94f,3438.32f,46.92f,1.0f,0.0f }, expImaginMod2[] = { 534.84f,542.75f,4353.12f,1.0f,0.0f };

   Complexop op1;
   Complexop op2;
   Complexop result;

   for (int i = 0; i < 5; i++) {
      printf ("\nCase%d:\n", i + 1);
      op1.real = op1Real[i];
      op1.imagin = op1Imagin[i];
      printf ("Complex number1:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imagin[i]);
      op2.real = op2Real[i];
      op2.imagin = op2Imagin[i];
      printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imagin[i]);

      result = Add (op1, op2);
      int ret1 = isinf (result.real) || isinf (result.imagin);
      if (ret1) {
         if (ret1 == expRealAdd[i] && ret1 == expImaginAdd[i]) printf ("Addition Passed!\n");
         else printf ("Addition Failed!\n");
      } else {
         if (round (result.real) == round (expRealAdd[i]) && round (result.imagin) == round (expImaginAdd[i])) printf ("Addition Passed!\n");
         else printf ("Addition Failed!\n");
      }

      result = Sub (op1, op2);
      int ret2 = isinf (result.real) || isinf (result.imagin);
      if (ret2) {
         if (ret2 == expRealSub[i] && ret2 == expImaginSub[i]) printf ("Subtraction Passed!\n");
         else printf ("Subtraction Failed!\n");
      } else {
         if (round (result.real) == round (expRealSub[i]) && round (result.imagin) == round (expImaginSub[i])) printf ("Subtraction Passed!\n");
         else printf ("Subtraction Failed!\n");
      }

      result = Multi (op1, op2);
      int ret3 = isinf (result.real) || isinf (result.imagin);
      if (ret3) {
         if (ret3 == expRealMulti[i] && ret3 == expImaginMulti[i]) printf ("Multiplication Passed!\n");
         else printf ("Multiplication Failed!\n");
      } else {
         if (round (result.real) == round (expRealMulti[i]) && round (result.imagin) == round (expImaginMulti[i])) printf ("Multiplication Passed!\n");
         else printf ("Multiplication Failed!\n");
      }

      float output = Mod (op1);
      int ret4 = isinf (output);
      if (ret4) {
         if (ret4 == expImaginMod1[i]) printf ("Modulus Passed!\n");
         else printf ("Modulus Failed!\n");
      } else {
         if (round (output) == round (expImaginMod1[i])) printf ("Modulus Passed!\n");
         else printf ("Modulus Failed!\n");
      }

      float output1 = Mod (op2);
      int ret5 = isinf (output1);
      if (ret5) {
         if (ret5 == expImaginMod2[i]) printf ("Modulus Passed!\n");
         else printf ("Modulus Failed!\n");
      } else {
         if (round (output1) == round (expImaginMod2[i])) printf ("Modulus Passed!\n");
         else printf ("Modulus Failed!\n");
      }
   }
}