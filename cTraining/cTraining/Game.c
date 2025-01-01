// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Game.c
// Implemented the game for 2 players.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <cType.h>
#include <conio.h>
#define ROWCOLUMNCOUNT 9 //Assuming a 3x3 matrix.
#define ROWCOUNT 3 //Number of rows: it's a cubic matrix, so the number of rows equals the number of columns.

#pragma warning(disable : 4996)

/// <summary>Display the board.</summary>
void InitBoard (char board[][ROWCOUNT + 1]);

/// <summary>Get the input from the player.</summary>
void Input (int* player);

/// <summary>Marks the player's symbol on the board.</summary>
/// <param name="player">Player input</param>
/// <param name="board">Contains Board data</param>
/// <param name="sym">Player symbol</param>
int MarkSymbols (int player, char board[][ROWCOUNT + 1], char sym);

/// <summary>Return 1 ,if the any one of the player is win,else return 0.</summary>
int CheckWin (char board[][ROWCOUNT + 1], char sym);

/// <summary>To manually test all the methods.</summary>
void StartGame ();

/// <summary>To automatically test all the methods.</summary>
int AutomationTest ();

/// <summary>To test the MarkSymbols method.</summary>
int TestMarkSymbols (int input[], char expOut[][ROWCOUNT + 1]);

/// <summary>Test the CheckWin method.</summary>
int TestCheckWin (char board[][ROWCOUNT + 1], char sym, int exp);

/// <summary>Display the integer array.</summary>
void DisplayArray (int arr[]);

int main () {
   StartGame ();
   //AutomationTest ();
}

int MarkSymbols (int player, char board[][ROWCOUNT + 1], char sym) {
   int row = player <= 3 ? 0 : player <= 6 ? 1 : 2;
   int col = player <= 3 ? player - 1 : player <= 6 ? player - 4 : player - 7;
   if (isdigit (board[row][col])) {
      board[row][col] = sym;
      return 1;
   }
   return 0;
}

int CheckWin (char board[][ROWCOUNT + 1], char sym) {
   for (int i = 0; i < ROWCOUNT; i++) {
      //checking columns and rows
      if ((board[i][0] == sym && board[i][1] == sym && board[i][2] == sym) ||
         (board[0][i] == sym && board[1][i] == sym && board[2][i] == sym))
         return 1;
   }
   //checking diagonals
   if ((board[0][2] == sym && board[1][1] == sym && board[2][0] == sym) ||
      (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym))
      return 1;
   return 0;
}

void InitBoard (char board[][ROWCOUNT + 1]) {
   printf ("\n");
   for (int i = 0; i < ROWCOUNT; i++) {
      for (int j = 0; j < ROWCOUNT + 1; j++)
         printf ("|%c", board[i][j]);
   }
}

void Input (int* player) {
   char playerInput;
   do
      playerInput = getch ();
   while (!(playerInput >= '1' && playerInput <= '9'));
   *player = playerInput - '0';
}

void StartGame () {
   printf ("\nPlayers can enter a number between 1 to 9.\nPlayer 1's symbol is 'O'\nPlayer 2's symbol is 'X'\n");
   char board[][ROWCOUNT + 1] = { { '1','2','3','\n' },{ '4','5','6','\n' },{ '7','8','9','\n' } }, sym;
   int player, it = 0, ret, i = 0;
   InitBoard (board);
   while (true) {
      sym = i ? 'X' : 'O';
      it++;
      do {
         printf ("\nPlayer%d:", i + 1);
         Input (&player);
         ret = MarkSymbols (player, board, sym);
         if (!ret) printf ("Position is occupied!\n");
      } while (!ret);
      InitBoard (board);
      if (it >= 5) {
         ret = CheckWin (board, sym);
         if (ret) {
            printf ("\nPlayer%d is win\n", i + 1);
            break;
         } else if (it == ROWCOLUMNCOUNT) {
            printf ("\nMatch draw!");
            break;
         }
      }
      i++;
      if (i > 1) i = 0;
   }
}

int AutomationTest () {
   int input1[] = { 1,2,3,4,5,6,7,8,9 }, input2[] = { 2,3,1,4,6,8,7,5,9 };
   int input3[] = { 1,2,2,1,3,4,3,5,6 };
   char expOut1[][ROWCOUNT + 1] = { { 'O','X','O','\n' },{ 'X','O','X','\n' },{ 'O','X','O','\n' } };
   char expOut2[][ROWCOUNT + 1] = { { 'O','O','X','\n' },{ 'X','X','O','\n' },{ 'O','X','O','\n' } };
   char expOut3[][ROWCOUNT + 1] = { {'O','X','O','\n' },{ 'X','X','O','\n' },{ '7','8','9','\n' } };
   if (!TestMarkSymbols (input1, expOut1) || !TestMarkSymbols (input2, expOut2) || !TestMarkSymbols (input3, expOut3)) return 0;
   if (!TestCheckWin (expOut1, 'O', 1) || !TestCheckWin (expOut2, 'X', 0) || !TestCheckWin (expOut3, 'O', 0)) return 0;
   printf ("Test cases: Passed!\n");
   return 1;
}

int TestMarkSymbols (int input[], char expOut[][ROWCOUNT + 1]) {
   char board[][ROWCOUNT + 1] = { { '1','2','3','\n' },{ '4','5','6','\n' },{ '7','8','9','\n' } }, sym;
   for (int i = 0, j = 0; i < ROWCOLUMNCOUNT; i++) {
      sym = j++ ? 'X' : 'O';
      MarkSymbols (input[i], board, sym);
      if (j > 1) j = 0;
   }
   for (int i = 0; i < ROWCOUNT; i++) {
      for (int j = 0; j < ROWCOUNT; j++)
         if (board[i][j] != expOut[i][j]) {
            printf ("Test MarkSymbol method: Failed!\nAt input: ");
            DisplayArray (input);
            return 0;
         }
   }
   return 1;
}

int TestCheckWin (char board[][ROWCOUNT + 1], char sym, int exp) {
   if (CheckWin (board, sym) != exp) {
      printf ("\nTest CheckWin method: Failed!\nAt input: ");
      InitBoard (board);
      return 0;
   }
   return 1;
}

void DisplayArray (int arr[]) {
   for (int i = 0; i < ROWCOLUMNCOUNT; i++)
      printf ("%d ", arr[i]);
}