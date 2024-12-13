// ------------------------------------------------------------------------------------------------
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
   wchar_t blackPieces[6] = { L'♖',L'♘',L'♗',L'♔',L'♕' };
   wchar_t whitePieces[6] = { L'♜',L'♞',L'♝',L'♚',L'♛' };
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
   int j = 3, i = 0;
   wchar_t string[5] = L"┃   ";
   while (j >= 0) {
      string[2] = uniCode[i];
      Print (string, actualOut);
      i = i < 4 && j == 3 ? ++i : --j;
   }
   Print (L"┃", actualOut);
}

void DrawSoldiers (FILE* actualOut) {
   for (int i = 0; i < 8; i++)
      Print (L"┃ ♙ ", actualOut);
   Print (L"┃", actualOut);
}

void DrawGrit (FILE* actualOut) {
   wchar_t gridPieces[] = L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n";
   wchar_t box[71];
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
   wchar_t expChar, outChar;
   bool isEqual = true;
   FILE* expOut = fopen ("ExpectedOutput.txt", "r, ccs=UTF-8"), * actOut = fopen ("ActualOut.txt", "r, ccs=UTF-8");
   if (actOut && expOut) {
      while ((fread (&expChar, sizeof (wchar_t), 1, expOut) && fread (&outChar, sizeof (wchar_t), 1, actOut)) == 1)
         if (expChar != outChar) isEqual = false;
      isEqual ? wprintf (L"Passed\n") : wprintf (L"Failed\n");
   }
}