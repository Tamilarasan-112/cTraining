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

#pragma warning(disable : 4996)

/// <summary>Display the board.</summary>
void InitBoard (char board[][4]);

/// <summary>Get the input from the player.</summary>
void Input (int* player);

/// <summary>Marks the player's symbol on the board.</summary>
/// <param name="player">Player input</param>
/// <param name="board">Contains Board data</param>
/// <param name="sym">Player symbol</param>
int MarkSymbols (int player, char board[][4], char sym);

/// <summary>To manually test all the methods.</summary>
void StartGame ();

/// <summary>To automatically test all the methods.</summary>
void AutomationTest ();

/// <summary>To test the MarkSymbols method.</summary>
int TestMarkSymbols (int input[], char expOut[][4]);

/// <summary>To test the Check method.</summary>
void TestCheckWin (char markedBoard[][4], int exp);

int main () {
   StartGame ();
   //AutomationTest ();
}

int MarkSymbols (int player, char board[][4], char sym) {
   int row = player <= 3 ? 0 : player <= 6 ? 1 : 2;
   int col = player <= 3 ? player - 1 : player <= 6 ? player - 4 : player - 7;
   if (isdigit (board[row][col])) {
      board[row][col] = sym;
      return 1;
   }
   return 0;
}

int CheckWin (char board[][4], char sym) {
   for (int i = 0; i < 3; i++) {
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

void InitBoard (char board[][4]) {
   printf ("\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++)
         printf ("|%c", board[i][j]);
   }
}

void Input (int* player) {
   char playerInput;
   do {
      playerInput = getch ();
   } while (!(playerInput >= '1' && playerInput <= '9'));
   *player = playerInput - '0';
}

void StartGame () {
   printf ("\nPlayers can enter a number between 1 to 9.\nPlayer 1's symbol is 'O'\nPlayer 2's symbol is 'X'\n");
   char board[][4] = { { '1','2','3','\n' },{ '4','5','6','\n' },{ '7','8','9','\n' } };
   int player, it = 0, ret, i = 0, j = 0;
   bool isGameOver = false;
   char sym;
   InitBoard (board);
   while (!isGameOver) {
      sym = i ? 'X' : 'O';
      it++;
      do {
         printf ("\nPlayer%d:", i + 1);
         Input (&player);
         ret = MarkSymbols (player, board, sym);
         if (!ret)printf ("Position is occupied!\n");
      } while (!ret);
      InitBoard (board);
      if (it >= 5) {
         ret = CheckWin (board, sym);
         if (ret) {
            printf ("\nPlayer%d is win\n", i + 1);
            isGameOver = true;
         } else if (it == 9) {
            printf ("\nMatch draw!");
            isGameOver = true;
         }
      }
      i++;
      if (i > 1) i = 0;
   }
}

void AutomationTest () {
   int input1[9] = { 1,2,3,4,5,6,7,8,9 }, input2[9] = { 2,3,1,4,6,8,7,5,9 };
   int input3[9] = { 1,2,2,1,3,4,3,5,6 };
   char expOut1[][4] = { { 'O','X','O','\n' },{ 'X','O','X','\n' },{ 'O','X','O','\n' } };
   char expOut2[][4] = { { 'O','O','X','\n' },{ 'X','X','O','\n' },{ 'O','X','O','\n' } };
   char expOut3[][4] = { {'O','X','O','\n' },{ 'X','X','O','\n' },{ '7','8','9','\n' } };

   printf ("\nTest MarkSymbols Method:\n");
   printf ("\nCase 1:\n");
   TestMarkSymbols (input1, expOut1);
   printf ("\nCase 2:\n");
   TestMarkSymbols (input2, expOut2);
   printf ("\nCase 3:\n");
   TestMarkSymbols (input3, expOut3);

   printf ("\nTest Check Method:\n");
   printf ("\nCase 1:\n");
   TestCheckWin (expOut1, 1);
   printf ("\nCase 2:\n");
   TestCheckWin (expOut2, 0);
   printf ("\nCase 2:\n");
   TestCheckWin (expOut3, 0);
}

int TestMarkSymbols (int input[], char expOut[][4]) {
   char board[][4] = { { '1','2','3','\n' },{ '4','5','6','\n' },{ '7','8','9','\n' } };
   char sym;
   int j = 0, i = 0;
   while (i < 9) {
      sym = j ? 'X' : 'O';
      printf ("Player%d:%d\n", j + 1, input[i]);
      MarkSymbols (input[i], board, sym);
      j++;
      i++;
      if (j > 1) j = 0;
   }
   printf ("\nActual Output:\n");
   InitBoard (board);
   printf ("\nExpected OutPut:\n");
   InitBoard (expOut);
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (board[i][j] != expOut[i][j]) {
            printf ("Failed!\n");
            return 0;
         }
      }
   }
   printf ("Passed!\n");
   return 1;
}

void TestCheckWin (char markedBoard[][4], int exp) {
   int ret;
   char sym;
   printf ("\nInput:\n");
   InitBoard (markedBoard);
   for (int i = 0; i < 2; i++) {
      sym = i ? 'X' : 'O';
      ret = CheckWin (markedBoard, sym);
      printf ("\nExpected output:\n");
      exp ? printf ("Player%d is win", i + 1) : printf ("Match draw!");
      printf ("\nActual output:\n");
      if (ret) {
         printf ("Player%d is win", i + 1);
         break;
      } else {
         i ? printf ("Match draw!") : printf ("Wait...");
      }
   }
   printf (ret == exp ? "\nPassed!\n" : "\nFailed!\n");
}