// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// cTraning.c
//The program is implemented to display the chessboard with all the pieces.
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <stdbool.h>
#include <locale.h>
#pragma warning (disable : 4996)

void DrawChess ();
void DrawPieces (wchar_t pieces[], FILE* actualOut);
void DrawSoldiers (wchar_t uniCode, bool black, FILE* actualOut);
void DrawGrit (FILE* actualOut);

/// <summary>Print the unicode in console and actual output file.</summary?
void print (wchar_t string[], FILE* actualout);

void Test ();

int main () {
   DrawChess ();
   Test ();
}

void DrawChess () {
   setlocale (LC_ALL, "");
   bool black = true;
   wchar_t blackPieces[7] = { L'♖',L'♘',L'♗',L'♔',L'♕',L'♙' };
   wchar_t whitePieces[7] = { L'♜',L'♞',L'♝',L'♚',L'♛',L'♟' };
   int a = _setmode (_fileno (stdout), _O_U16TEXT);
   FILE* actualOut = fopen ("ActualOut.txt", "w, ccs=UTF-8");
   print (L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n", actualOut);
   DrawPieces (blackPieces, actualOut);
   print (L"\n┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n", actualOut);
   DrawSoldiers (blackPieces[5], black, actualOut);
   DrawGrit (actualOut);
   black = false;
   DrawSoldiers (whitePieces[5], black, actualOut);
   print (L"\n┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n", actualOut);
   DrawPieces (whitePieces, actualOut);
   print (L"\n┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛", actualOut);
   fclose (actualOut);
}

void DrawPieces (wchar_t uniCode[], FILE* actualOut) {
   int j = 2, i = 0, it = i;
   wchar_t string[5] = L"┃   ";
   while (j >= -1) {
      string[2] = uniCode[it];
      print (string, actualOut);
      if (i < 4) it = ++i;
      else {
         it = j;
         j--;
      }
   }
   print (L"┃", actualOut);
}

void DrawSoldiers (wchar_t uniCode, bool black, FILE* actualOut) {
   wchar_t string[5] = L"┃   ";
   string[2] = uniCode;
   for (int i = 0; i < 8; i++) {
      if (!black) string[3] = '\0';
      print (string, actualOut);
   }
   print (L"┃", actualOut);
}

void DrawGrit (FILE* actualOut) {
   print (L"\n", actualOut);
   for (int i = 0; i < 4; i++) {
      print (L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃\n", actualOut);
   }
   print (L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n", actualOut);
}

void print (wchar_t string[], FILE* actualOut) {
   wprintf (string);
   fputws (string, actualOut);
}

void Test () {
   wchar_t ec,ac;
   FILE* expOut = fopen ("ExpectedOutput.txt", "r, ccs=UTF-8"),*actOut = fopen ("ActualOut.txt", "r, ccs=UTF-8");
   if (actOut && expOut) {
      while ((fread (&ec, sizeof (wchar_t), 1, expOut) && fread (&ac, sizeof (wchar_t), 1, actOut)) == 1) {
         bool isEqual = true;
         wprintf (L"%lc  and %lc    ->", ec, ac);
         if (ec != ac) isEqual = false;
         if (isEqual) wprintf (L"pass\n");
         else wprintf (L"fail\n");
      }
   }
}