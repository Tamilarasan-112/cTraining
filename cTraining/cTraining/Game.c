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
#include <malloc.h>
#define MAXCELLS 9 //Assuming a 3x3 matrix.
#define ROWCOUNT 3 //Number of rows: it's a cubic matrix, so the number of rows equals the number of columns.

#pragma warning(disable : 4996)

/// <summary>Display the board.</summary>
void InitBoard (char board[][ROWCOUNT]);

/// <summary>Get the input from the player.</summary>
void Input (int* player);

/// <summary>Marks the player's symbol on the board.</summary>
/// <param name="player">Player input</param>
/// <param name="board">Contains Board data</param>
/// <param name="sym">Player symbol</param>
int MarkSymbols (int cellNumber, char board[][ROWCOUNT], char sym);

/// <summary>Return 1 ,if the any one of the player is win,else return 0.</summary>
int CheckWin (char board[][ROWCOUNT], char sym);

/// <summary>To manually test all the methods.</summary>
void StartGame ();

/// <summary>To automatically test all the methods.</summary>
int AutomationTest ();

/// <summary>To test the MarkSymbols method.</summary>
int TestMarkSymbols (char* input, char* expOut);

/// <summary>Test the CheckWin method.</summary>
int TestCheckWin (char* bord, char sym, int exp);

/// <summary>Display the character array.</summary>
void DisplayArray (char* arr);

int main () {
   StartGame ();
   //AutomationTest ();
}

int MarkSymbols (int cellNumber, char board[][ROWCOUNT], char sym) {
   int row = cellNumber <= 3 ? 0 : cellNumber <= 6 ? 1 : 2;
   int col = cellNumber <= 3 ? cellNumber - 1 : cellNumber <= 6 ? cellNumber - 4 : cellNumber - 7;
   if (isdigit (board[row][col])) {
      board[row][col] = sym;
      return 1;
   }
   return 0;
}

int CheckWin (char board[][ROWCOUNT], char sym) {
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

void InitBoard (char board[][ROWCOUNT]) {
   printf ("\n");
   for (int i = 0; i < ROWCOUNT; i++) {
      for (int j = 0; j < ROWCOUNT; j++)
         printf ("|%c", board[i][j]);
      printf ("|\n");
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
   char board[][ROWCOUNT] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } }, sym;
   int cellNumber, cellsOccupied = 0, ret, i = 0;
   InitBoard (board);
   while (true) {
      sym = i ? 'X' : 'O';
      cellsOccupied++;
      do {
         printf ("\nPlayer%d:", i + 1);
         Input (&cellNumber);
         ret = MarkSymbols (cellNumber, board, sym);
         if (!ret) printf ("Position is occupied!\n");
      } while (!ret);
      InitBoard (board);
      if (cellsOccupied >= 5) {
         ret = CheckWin (board, sym);
         if (ret) {
            printf ("\nPlayer%d is win\n", i + 1);
            break;
         } else if (cellsOccupied == MAXCELLS) {
            printf ("\nMatch draw!");
            break;
         }
      }
      i = !i;
   }
}

int AutomationTest () {
#define NTEST 3
   char inputFP[14], expOutFP[16]; //assuming the file name length 13 and 15
   FILE* inputsCheckWin = fopen ("Input/IpSym.txt", "r"), * expWin = fopen ("ExpOut/ExpWin.txt", "r");
   if (inputsCheckWin && expWin) {
      fseek (inputsCheckWin, 0L, SEEK_END);
      fseek (expWin, 0L, SEEK_END);
      int ipLength = ftell (inputsCheckWin), opLength = ftell (expWin);
      fseek (inputsCheckWin, 0L, SEEK_SET);
      fseek (expWin, 0L, SEEK_SET);
      char* inputStream = malloc ((ipLength + 1) * sizeof (char));
      char* outputStream = malloc ((opLength + 1) * sizeof (char));
      if (inputStream && outputStream) {
         fgets (inputStream, ipLength + 1, inputsCheckWin);
         fgets (outputStream, opLength + 1, expWin);
         for (int i = 0; i < NTEST; i++) {
            sprintf (inputFP, "Input/Ip%d.txt", i + 1);
            sprintf (expOutFP, "ExpOut/EOp%d.txt", i + 1);
            FILE* inputFile = fopen (inputFP, "r"), * outputFile = fopen (expOutFP, "r");
            if (inputFile && outputFile) {
               fseek (inputFile, 0L, SEEK_END);
               fseek (outputFile, 0L, SEEK_END);
               int ipLength1 = ftell (inputFile), opLength1 = ftell (outputFile);
               fseek (inputFile, 0L, SEEK_SET);
               fseek (outputFile, 0L, SEEK_SET);
               char* inputStream1 = malloc ((ipLength1 + 1) * sizeof (char));
               char* outputStream1 = malloc ((opLength1 + 1) * sizeof (char));
               if (inputStream1 && outputStream1) {
                  fgets (inputStream1, ipLength1 + 1, inputFile);
                  fgets (outputStream1, opLength1 + 1, outputFile);
                  if (!TestMarkSymbols (inputStream1, outputStream1)) {
                     printf ("Test MarkSymbol method: Failed!\nAt input: ");
                     DisplayArray (inputStream1);
                     return 0;
                  }
                  if (!TestCheckWin (outputStream1, inputStream[i], outputStream[i] - '0')) {
                     printf ("Test CheckWin method: Failed!\nAt input as above board and symbol: % c", inputStream[i]);
                     return 0;
                  }
                  fclose (inputFile);
                  fclose (outputFile);
                  free (inputStream1);
                  free (outputStream1);
               } else {
                  printf ("\nTest failed!,due to memory allocation is failed!...\n");
                  return 0;
               }
            } else {
               printf ("\nTest failed!,when file handling...\n");
               return 0;
            }
         }
         fclose (inputsCheckWin);
         fclose (expWin);
         free (inputStream);
         free (outputStream);
      } else {
         printf ("\nTest failed!,due to memory allocation is failed!...\n");
         return 0;
      }
   } else {
      printf ("\nTest failed!,when file handling...\n");
      return 0;
   }
   printf ("\nPassed!\n");
   return 1;
}

int TestMarkSymbols (char* input, char* expOut) {
   char board[][ROWCOUNT] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } }, sym;
   for (int i = 0, j = 0; i < MAXCELLS; i++, j = !j) {
      sym = j ? 'X' : 'O';
      MarkSymbols (input[i] - '0', board, sym);
   }
   for (int i = 0, k = 0; i < ROWCOUNT; i++) {
      for (int j = 0; j < ROWCOUNT; j++)
         if (board[i][j] != expOut[k++]) return 0;
   }
   return 1;
}

int TestCheckWin (char* board, char sym, int exp) {
   char input[ROWCOUNT][ROWCOUNT];
   for (int i = 0, k = 0; i < ROWCOUNT; i++) {
      for (int j = 0; j < ROWCOUNT; j++)
         input[i][j] = board[k++];
   }
   if (CheckWin (input, sym) != exp) {
      InitBoard (input);
      return 0;
   }
   return 1;
}

void DisplayArray (char* arr) {
   for (int i = 0; i < MAXCELLS; i++)
      printf ("%c ", arr[i]);
}