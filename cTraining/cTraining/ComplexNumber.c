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
#include <conio.h>

struct ComplexNumber {
   float real;
   float imagin;
};

typedef struct ComplexNumber Complexop;

/// <summary>Test all the operations automatically</summary>
int AutomationTest ();

/// <summary>Get the complex number from the user and display the result of the operations.</summary>
void PrintOperationOutputs ();

/// <summary>Add two complex numbers and return the result.</summary>
Complexop Add (Complexop Op1, Complexop Op2);

/// <summary>Subtract two complex numbers and return the result.</summary>
Complexop Sub (Complexop Op1, Complexop Op2);

/// <summary>Perform the multiplication of two complex numbers and return the result.</summary>
Complexop Multi (Complexop Op1, Complexop Op2);

/// <summary>Compute the modulus of a complex number and return the result.</summary>
float Mod (Complexop Op);

/// <summary>Compute the conjugate of the complex number and return the result.</summary>
Complexop Conjugate (Complexop Op);

/// <summary>Clear the buffered input data.</summary>
void ClearInputBuffer ();

/// <summary>Get the complex number from the user and return the operand.</summary>
int GetInput (Complexop* Op);

/// <summary>Return true if input is valid,else false.</summary>
bool IsValidInput (int ret, char c);

int main () {
   AutomationTest ();
   //PrintOperationOutputs ();
}


Complexop Add (Complexop Op1, Complexop Op2) {
   Complexop Result;
   Result.real = Op1.real + Op2.real;
   Result.imagin = Op1.imagin + Op2.imagin;
   return Result;
}

Complexop Sub (Complexop Op1, Complexop Op2) {
   Complexop Result;
   Result.real = Op1.real - Op2.real;
   Result.imagin = Op1.imagin - Op2.imagin;
   return Result;
}

Complexop Multi (Complexop Op1, Complexop Op2) {
   Complexop Result;
   Result.real = Op1.real * Op2.real - Op1.imagin * Op2.imagin;
   Result.imagin = Op1.real * Op2.imagin + Op1.imagin * Op2.real;
   return Result;
}

float Mod (Complexop Op) {
   float real = (float)pow (Op.real * Op.real + Op.imagin * Op.imagin, 0.5);
   return real;
}

Complexop Conjugate (Complexop Op) {
   Complexop Result;
   Result.real = Op.real;
   Result.imagin = -(Op.imagin);
   return Result;
}

void ClearInputBuffer () {
   while (getchar () != '\n');
}

int GetInput (Complexop* Op) {
   char c;
   printf ("Enter real number: ");
   if (!IsValidInput (!scanf_s ("%f%c", &Op->real, &c, 1), c)) return 0;
   printf ("Enter imaginary number: ");
   if (!IsValidInput (!scanf_s ("%f%c", &Op->imagin, &c, 1), c)) return 0;
   return 1;
}

bool IsValidInput (int ret, char endChar) {
   if (ret) {
      ClearInputBuffer ();
      return false;
   } else if (endChar != '\n') {
      ClearInputBuffer ();
      return false;
   }
   return true;
}

void PrintOperationOutputs () {
   do {
      printf ("Enter 0 if you want to exit, else enter 1. \nchoice:");
      char c = getch ();
      if (c == '0' || c == '1') {
         if (c == '0') break;
         else {
            Complexop Op1;
            Complexop Op2;
            Complexop Result;
            int ret;
            do {
               printf ("Complex number 1:\n");
               ret = GetInput (&Op1);
               if (!ret) printf ("Invalid complex number!\n");
               else break;
            } while (true);
            do {
               printf ("Complex number 2:\n");
               ret = GetInput (&Op2);
               if (!ret) printf ("Invalid complex number!\n");
               else break;
            } while (true);

            Result = Add (Op1, Op2);
            if (isinf (Result.real) || isinf (Result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Addition       :%f %fi\n", Result.real, Result.imagin);
            Result = Sub (Op1, Op2);
            if (isinf (Result.real) || isinf (Result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Subtraction   :%f %f\n", Result.real, Result.imagin);
            Result = Multi (Op1, Op2);
            if (isinf (Result.real) || isinf (Result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Multiplication:%f %f\n", Result.real, Result.imagin);
            float output = Mod (Op1);
            if (isinf (output))printf ("The result exceeds float range!.\n");
            else printf ("Modulus1       :%f\n", output);
            output = Mod (Op2);
            if (isinf (output))printf ("The result exceeds float range!.\n");
            else printf ("Modulus2       :%f\n", output);
            Result = Conjugate (Op1);
            if (isinf (Result.real) || isinf (Result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Conjugate1     :%f %fi\n", Result.real, Result.imagin);
            Result = Conjugate (Op2);
            if (isinf (Result.real) || isinf (Result.imagin))printf ("The result exceeds float range!\n");
            else printf ("Conjugate2     :%f %fi\n", Result.real, Result.imagin);
         }
      } else printf ("Invalid choice!\n");
   } while (true);
}

int AutomationTest () {
   float op1Real[] = { 121.2324f,324.2334f,32.3324f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op1Imagin[] = { -324.00f,-3423.00f,-34.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op2Real[] = { 23.00f,324.00f,32.324f,-340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op2Imagin[] = { 534.345f,435.43f,4353.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };

   float expRealAdd[] = { 144.23f,648.23f,64.66f,1.0f,0.0f }, expImaginAdd[] = { 210.35f ,-2987.57f,4319.00f,1.0f,0.0f };
   float expRealSub[] = { 98.23f,0.23f,0.01f,1.0f,0.0f }, expImaginSub[] = { -858.35f,-3858.43f,-4387.00f,1.0f,0.0f };
   float expRealMulti[] = { 175916.13f,1595528.51f,149047.11f,1.0f,0.0f }, expImaginMulti[] = { 57327.93f,-967871.05f,139643.92f,1.0f,0.0f };
   float expImaginMod1[] = { 345.94f,3438.32f,46.92f,1.0f,0.0f }, expImaginMod2[] = { 534.84f,542.75f,4353.12f,1.0f,0.0f };
   float expConjImagin1[] = { 324.00f,3423.00f,34.00f,-340000000000000000000000000000000000000.00f,-0.000000000000000000000000000000000000034f };
   float expConjImagin2[] = { -534.345f,-435.43f,-4353.00f,-340000000000000000000000000000000000000.00f,-0.000000000000000000000000000000000000034f };

   Complexop Op1;
   Complexop Op2;
   Complexop Result;

   printf ("\nTest Cases:");
   for (int i = 0; i < 5; i++) {
      Op1.real = op1Real[i];
      Op1.imagin = op1Imagin[i];
      Op2.real = op2Real[i];
      Op2.imagin = op2Imagin[i];

      Result = Add (Op1, Op2);
      bool ret = isinf (Result.real) || isinf (Result.imagin);
      if (!ret) {
         if (round (Result.real) != round (expRealAdd[i]) || round (Result.imagin) != round (expImaginAdd[i])) {
            printf ("Addition Failed!\nComplex number1:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imagin[i]);
            printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imagin[i]);
            return 0;
         }
      }

      Result = Sub (Op1, Op2);
      ret = isinf (Result.real) || isinf (Result.imagin);
      if (!ret) {
         if (round (Result.real) != round (expRealSub[i]) || round (Result.imagin) != round (expImaginSub[i])) {
            printf ("Subtraction Failed!\nComplex number1:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imagin[i]);
            printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imagin[i]);
            return 0;
         }
      }

      Result = Multi (Op1, Op2);
      ret = isinf (Result.real) || isinf (Result.imagin);
      if (!ret) {
         if (round (Result.real) != round (expRealMulti[i]) || round (Result.imagin) != round (expImaginMulti[i])) {
            printf ("Multiplication Failed!\nComplex number1:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imagin[i]);
            printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imagin[i]);
            return 0;
         }
      }

      float output = Mod (Op1);
      ret = isinf (output);
      if (!ret) {
         if (round (output) != round (expImaginMod1[i])) {
            printf ("Modulus Failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imagin[i]);
            return 0;
         }
      }

      float output1 = Mod (Op2);
      ret = isinf (output1);
      if (!ret) {
         if (round (output1) != round (expImaginMod2[i])) {
            printf ("Modulus Failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imagin[i]);
            return 0;
         }
      }

      Result = Conjugate (Op1);
      ret = isinf (Result.real) || isinf (Result.imagin);
      if (!ret) {
         if (round (Result.real) != round (op1Real[i]) || round (Result.imagin) != round (expConjImagin1[i])) {
            printf ("Conjugate Failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imagin[i]);
            return 0;
         }
      }

      Result = Conjugate (Op2);
      ret = isinf (Result.real) || isinf (Result.imagin);
      if (!ret) {
         if (round (Result.real) != round (op2Real[i]) || round (Result.imagin) != round (expConjImagin2[i])) {
            printf ("Conjugate Failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imagin[i]);
            return 0;
         }
      }
   }
   printf ("Passed!\n");
   return 1;
}