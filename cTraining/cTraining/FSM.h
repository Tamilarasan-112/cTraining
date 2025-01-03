#ifndef FSM_H_
#define FSM_H_

#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS  1

// Define states of the Mealy machine
typedef enum {
   ST0, S1, S2, S3, S4, T1, T2, T3, T4, ERRORST
} State;

/// <summary>Mealy machine that detects the pattern '0110' or '1101' in an input stream and write the output.</summary>
void Mealy (char* inputFP, char* outputFP);

/// <summary>Function to get the next state and output based on the current state and input.</summary>
State NextMealyState (State currentState, int input, int* output);

#endif