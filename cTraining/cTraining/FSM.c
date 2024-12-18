// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// FSM.c
// Implemented a Mealy machine that detects the pattern '0110' or '1101' in an input stream
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS  1

// Define states of the Mealy machine
typedef enum {
   ST0, S1, S2, S3, S4, T1, T2, T3, T4
} State;

/// <summary>Mealy machine that detects the pattern '0110' or '1101' in an input stream and write the output.</summary>
void Mealy (char* inputFP, char* outputFP);

/// <summary>Function to get the next state and output based on the current state and input.</summary>
State NextMealyState (State currentState, int input, int* output);

void main (int argc, char** argv) {
   Mealy (argv[1], argv[2]);
}

State NextMealyState (State currentState, int input, int* output) {
   switch (currentState) {
   case ST0:
      *output = 0;
      return input ? S1 : T1; // Transition to S1 after '1' / T1 after '0'

   case S1:
      *output = 0;
      return input ? S2 : T1; // Transition to S2 after '11' /  Stay in T1 after '0'

   case T1:
      *output = 0;
      return input ? T2 : T1; // Transition to T2 after '01' / Stay in T1 after '0'

   case S2:
      *output = 0;
      return input ? S2 : S3; // Stay in S2 after '11' /  Transition to S3 after '110'

   case T2:
      *output = 0;
      return input ? T3 : T1; // Transition to T3 after '011' / Stay in T1 after '0'

   case S3:
      *output = input ? 1 : 0; // Output '1' upon seeing '1101' / Output '0' upon seeing '1100'
      return input ? S4 : T1;  // Move to S4 after recognizing '1101' / Stay in T1 after '0'

   case T3:
      *output = input ? 0 : 1; // Output '0' upon seeing '0111' / Output '1' upon seeing '0110'
      return input ? S2 : T4;  // Transition to S2 after '11' / Move to T4 after recognizing '0110'

   case S4:
      *output = 0;
      return input ? T3 : T1; // Transition to T3 after '011' / Stay in T1 after '0'

   case T4:
      *output = input ? 1 : 0;  // Output '1' upon seeing '1101'
      return input ? S4 : T1;  // Move to T4 after recognizing '1101'

   default:
      *output = 0;
      return input ? S1 : T1;  // Default return to initial state
   }
}

void Mealy (char* inputFP, char* outputFP) {
   char inputStream[18], outputStream[18];
   State currentState = ST0;
   int input, output = 0, i = 0;
   FILE* ipFile = fopen (inputFP, "r"), * opFile = fopen (outputFP, "w");
   if (ipFile) {
      fgets (inputStream, 18, ipFile);
      fclose (ipFile);
      if (opFile) {
         while (i < 17) {
            input = inputStream[i] - 48;
            if (input == 0 || input == 1) {
               currentState = NextMealyState (currentState, input, &output);
               outputStream[i++] = output + 48;
            }
         }
         outputStream[i] = '\0';
         fprintf (opFile, "%s", outputStream);
         fclose (opFile);
      }
   }
}