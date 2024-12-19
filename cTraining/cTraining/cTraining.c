﻿// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// cTraining.c
// The program is implemented to display the chessboard with all the pieces.
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <stdbool.h>
#include <string.h>

#pragma warning (disable : 4996)

#define GREEN_COLOR   "\x1b[32m"
#define YELLO_COLOR   "\x1b[33m"
#define RESET_COLOR   "\x1b[0m"

void DrawChess ();
void DrawPieces (wchar_t pieces[], FILE* actualOut);
void DrawSoldiers (FILE* actualOut);
void DrawGrit (FILE* actualOut);

/// <summary>Print the unicode in console and actual output file.</summary>
void Print (wchar_t string[], FILE* actualout);

/// <summary>To check all the characters printing correctly in order.</summary>
void Test ();

int main () {
   DrawChess ();
   Test ();
}

void DrawChess () {
   wchar_t blackPieces[] = { L'♖',L'♘',L'♗',L'♔',L'♕' };
   wchar_t whitePieces[] = { L'♜',L'♞',L'♝',L'♚',L'♛' };
   wchar_t gridPieces[] = L"\n┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n";
   int a = _setmode (_fileno (stdout), _O_U16TEXT);
   FILE* actualOut = fopen ("ActualOut.txt", "w, ccs=UTF-8");
   Print (L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n", actualOut);
   DrawPieces (blackPieces, actualOut);
   Print (gridPieces, actualOut);
   DrawSoldiers (actualOut);
   DrawGrit (actualOut);
   DrawSoldiers (actualOut);
   Print (gridPieces, actualOut);
   DrawPieces (whitePieces, actualOut);
   Print (L"\n┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛", actualOut);
   fclose (actualOut);
}

void DrawPieces (wchar_t uniCode[], FILE* actualOut) {
   wchar_t string[] = L"┃   ";
   for (int index = 0, backTrack = 3; backTrack >= 0; index = index < 4 && backTrack == 3 ? index + 1 : --backTrack) {
      string[2] = uniCode[index];
      Print (string, actualOut);
   }
   Print (L"┃", actualOut);
}

void DrawSoldiers (FILE* actualOut) {
   for (int i = 0; i < 8; i++)
      Print (L"┃ ♙ ", actualOut);
   Print (L"┃", actualOut);
}

void DrawGrit (FILE* actualOut) {
   wchar_t gridPieces[] = L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n", box[71];
   wcscpy (box, gridPieces);
   wcscat (box, L"┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃\n");
   Print (L"\n", actualOut);
   for (int i = 0; i < 4; i++)
      Print (box, actualOut);
   Print (gridPieces, actualOut);
}

void Print (wchar_t string[], FILE* actualOut) {
   wprintf (string);
   fputws (string, actualOut);
}

void Test () {
   wprintf (L"\nTest:");
   wchar_t expChar[34], outChar[34];
   bool isEqual = true;
   FILE* expOut = fopen ("ExpectedOutput.txt", "r, ccs=UTF-8"), * actOut = fopen ("ActualOut.txt", "r, ccs=UTF-8");
   if (expOut) {
      fgetws (expChar, 34, expOut);
      fclose (expOut);
      if (actOut) {
         fgetws (outChar, 34, actOut);
         fclose (actOut);
         wprintf (wcscmp (expChar, outChar) == 0 ? L"Passed\n" : L"Failed\n");
      }
   }
}