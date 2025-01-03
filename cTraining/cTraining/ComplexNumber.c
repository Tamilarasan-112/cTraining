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
   float Real;
   float Imaginary;
};

typedef struct ComplexNumber Complexop;

/// <summary>Test all the operations automatically</summary>
int AutomationTest ();

/// <summary>Get the complex number from the user and display the result of the operations.</summary>
void PrintOperationOutputs ();

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

/// <summary>Return true if input is valid,else false.</summary>
bool IsValidInput (int ret, char c);

int main () {
   AutomationTest ();
   //PrintOperationOutputs ();
}


Complexop Add (Complexop op1, Complexop op2) {
   Complexop result = { op1.Real + op2.Real,op1.Imaginary + op2.Imaginary };
   return result;
}

Complexop Sub (Complexop op1, Complexop op2) {
   Complexop result = { op1.Real - op2.Real , op1.Imaginary - op2.Imaginary };
   return result;
}

Complexop Multi (Complexop op1, Complexop op2) {
   Complexop result = { op1.Real * op2.Real - op1.Imaginary * op2.Imaginary,op1.Real * op2.Imaginary + op1.Imaginary * op2.Real };
   return result;
}

float Mod (Complexop op) {
   float real = (float)pow (op.Real * op.Real + op.Imaginary * op.Imaginary, 0.5);
   return real;
}

Complexop Conjugate (Complexop op) {
   Complexop result = { op.Real,-(op.Imaginary) };
   return result;
}

void ClearInputBuffer () {
   while (getchar () != '\n');
}

int GetInput (Complexop* op) {
   char c;
   printf ("Enter real number: ");
   if (!IsValidInput (!scanf_s ("%f%c", &op->Real, &c, 1), c)) return 0;
   printf ("Enter imaginary number: ");
   if (!IsValidInput (!scanf_s ("%f%c", &op->Imaginary, &c, 1), c)) return 0;
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
            if (isinf (result.Real) || isinf (result.Imaginary))printf ("The result exceeds float range!\n");
            else printf ("Addition       :%f %fi\n", result.Real, result.Imaginary);
            result = Sub (op1, op2);
            if (isinf (result.Real) || isinf (result.Imaginary))printf ("The result exceeds float range!\n");
            else printf ("Subtraction   :%f %f\n", result.Real, result.Imaginary);
            result = Multi (op1, op2);
            if (isinf (result.Real) || isinf (result.Imaginary))printf ("The result exceeds float range!\n");
            else printf ("Multiplication:%f %f\n", result.Real, result.Imaginary);
            float output = Mod (op1);
            if (isinf (output))printf ("The result exceeds float range!.\n");
            else printf ("Modulus1       :%f\n", output);
            output = Mod (op2);
            if (isinf (output))printf ("The result exceeds float range!.\n");
            else printf ("Modulus2       :%f\n", output);
            result = Conjugate (op1);
            if (isinf (result.Real) || isinf (result.Imaginary))printf ("The result exceeds float range!\n");
            else printf ("Conjugate1     :%f %fi\n", result.Real, result.Imaginary);
            result = Conjugate (op2);
            if (isinf (result.Real) || isinf (result.Imaginary))printf ("The result exceeds float range!\n");
            else printf ("Conjugate2     :%f %fi\n", result.Real, result.Imaginary);
         }
      } else printf ("Invalid choice!\n");
   } while (true);
}

int AutomationTest () {
   float op1Real[] = { 121.2324f,324.2334f,32.3324f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op1Imaginary[] = { -324.00f,-3423.00f,-34.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op2Real[] = { 23.00f,324.00f,32.324f,-340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };
   float op2Imaginary[] = { 534.345f,435.43f,4353.00f,340000000000000000000000000000000000000.00f,0.000000000000000000000000000000000000034f };

   float expRealAdd[] = { 144.23f,648.23f,64.66f,1.0f,0.0f }, expImaginaryAdd[] = { 210.35f ,-2987.57f,4319.00f,1.0f,0.0f };
   float expRealSub[] = { 98.23f,0.23f,0.01f,1.0f,0.0f }, expImaginarySub[] = { -858.35f,-3858.43f,-4387.00f,1.0f,0.0f };
   float expRealMulti[] = { 175916.13f,1595528.51f,149047.11f,1.0f,0.0f }, expImaginaryMulti[] = { 57327.93f,-967871.05f,139643.92f,1.0f,0.0f };
   float expImaginaryMod1[] = { 345.94f,3438.32f,46.92f,1.0f,0.0f }, expImaginaryMod2[] = { 534.84f,542.75f,4353.12f,1.0f,0.0f };
   float expConjImaginary1[] = { 324.00f,3423.00f,34.00f,-340000000000000000000000000000000000000.00f,-0.000000000000000000000000000000000000034f };
   float expConjImaginary2[] = { -534.345f,-435.43f,-4353.00f,-340000000000000000000000000000000000000.00f,-0.000000000000000000000000000000000000034f };

   Complexop op1;
   Complexop op2;
   Complexop result;

   printf ("\nTest Cases:");
   for (int i = 0; i < 5; i++) {
      op1.Real = op1Real[i];
      op1.Imaginary = op1Imaginary[i];
      op2.Real = op2Real[i];
      op2.Imaginary = op2Imaginary[i];

      result = Add (op1, op2);
      bool ret = isinf (result.Real) || isinf (result.Imaginary);
      if (!ret) {
         if (round (result.Real) != round (expRealAdd[i]) || round (result.Imaginary) != round (expImaginaryAdd[i])) {
            printf ("Addition failed!\nComplex number1:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imaginary[i]);
            printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imaginary[i]);
            return 0;
         }
      }

      result = Sub (op1, op2);
      ret = isinf (result.Real) || isinf (result.Imaginary);
      if (!ret) {
         if (round (result.Real) != round (expRealSub[i]) || round (result.Imaginary) != round (expImaginarySub[i])) {
            printf ("Subtraction failed!\nComplex number1:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imaginary[i]);
            printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imaginary[i]);
            return 0;
         }
      }

      result = Multi (op1, op2);
      ret = isinf (result.Real) || isinf (result.Imaginary);
      if (!ret) {
         if (round (result.Real) != round (expRealMulti[i]) || round (result.Imaginary) != round (expImaginaryMulti[i])) {
            printf ("Multiplication failed!\nComplex number1:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imaginary[i]);
            printf ("Complex number2:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imaginary[i]);
            return 0;
         }
      }

      float output = Mod (op1);
      ret = isinf (output);
      if (!ret) {
         if (round (output) != round (expImaginaryMod1[i])) {
            printf ("Modulus failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imaginary[i]);
            return 0;
         }
      }

      float output1 = Mod (op2);
      ret = isinf (output1);
      if (!ret) {
         if (round (output1) != round (expImaginaryMod2[i])) {
            printf ("Modulus failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imaginary[i]);
            return 0;
         }
      }

      result = Conjugate (op1);
      ret = isinf (result.Real) || isinf (result.Imaginary);
      if (!ret) {
         if (round (result.Real) != round (op1Real[i]) || round (result.Imaginary) != round (expConjImaginary1[i])) {
            printf ("Conjugate failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op1Real[i], op1Imaginary[i]);
            return 0;
         }
      }

      result = Conjugate (op2);
      ret = isinf (result.Real) || isinf (result.Imaginary);
      if (!ret) {
         if (round (result.Real) != round (op2Real[i]) || round (result.Imaginary) != round (expConjImaginary2[i])) {
            printf ("Conjugate failed!\nComplex number:\nInput real number:%f\nInput imaginary number:%f\n", op2Real[i], op2Imaginary[i]);
            return 0;
         }
      }
   }
   printf ("Passed!\n");
   return 1;
}