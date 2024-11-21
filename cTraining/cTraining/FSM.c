// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// FSM.c
// State diagram reference:file://c:/work/cTraining/cTraining/StateDiagram.jpg
//Implemented a Mealy machine that detects the pattern '0110' or '1101' in an input stream
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS  1

// Define states of the Mealy machine
typedef enum {
   ST0, S1, S2, S3, S4, T1, T2, T3, T4
} State;

int Mealy (char* inputFP, char* outputFP);

void main (int argc,char** argv) {
   Mealy (argv[1], argv[2]);
}

// Function to get the next state and output based on the current state and input
State nextMealyState (State currentState, int input, int* output) {
   switch (currentState) {
   case ST0:
      if (input == 1) {
         *output = 0;
         return S1;  // Transition to S1 after '1'
      } else {
         *output = 0;
         return T1;  // Transition to T1 after '0'
      }
   case S1:
      if (input == 1) {
         *output = 0;
         return S2;  // Transition to S2 after '11'
      } else {
         *output = 0;
         return T1;  // Transition to T1 after '10'
      }
   case T1:
      if (input == 1) {
         *output = 0;
         return T2;  // Transition to T2 after '01'
      } else {
         *output = 0;
         return T1;  // Stay in T1 if input is '0'
      }
   case S2:
      if (input == 1) {
         *output = 0;
         return S2;   // Stay in S2, if input is '1'
      } else {
         *output = 0;
         return S3;  // Transition to S3 after '110'
      }
   case T2:
      if (input == 1) {
         *output = 0;
         return T3;  // Transition to T3 after '011'
      } else {
         *output = 0;
         return T1;  // stay in T1 ,if input is '0'
      }
   case S3:
      if (input == 1) {
         *output = 1;  // Output '1' upon seeing '1101'
         return S4;  // Move to S4 after recognizing '1101'
      } else {
         *output = 0;
         return T1;  //return to T1 ,if input is '0'
      }
   case T3:
      if (input == 1) {
         *output = 0;
         return S2;  // Transition to S2 after '11'
      } else {
         *output = 1;  // Output '1' upon seeing '0110'
         return T4;  // Move to T4 after recognizing '0110'
      }
   case S4:
      if (input == 1) {
         *output = 0;
         return T3;  // Transition to T3 after '011' 
      } else {
         *output = 0;
         return T1;  // Return to T1,if input is 0;
      }
   case T4:
      if (input == 1) {
         *output = 1;  // Output '1' upon seeing '1101'
         return S4;  // Move to T4 after recognizing '1101'
      } else {
         *output = 0;
         return T1;  // Return to T1,if input is 0
      }
   }
   return ST0;  // Default return to initial state
}

int Mealy (char* inputFP, char* outputFP) {
   char c;
   State currentState = ST0;
   int input, output = 0;
   FILE* ipFile = fopen (inputFP, "r");
   FILE* opFile = fopen (outputFP, "w");
   if (ipFile && opFile) {
      while (fread (&c, sizeof(char), 1, ipFile)) {
         input = c - '0';
         if (input == 0 || input == 1) {
            currentState = nextMealyState (currentState, input, &output);
            fprintf (opFile, "%d", output);
         }
      }
   }
   return 0;
}